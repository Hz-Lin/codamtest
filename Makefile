# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: hlin <hlin@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2020/10/27 23:36:29 by hlin          #+#    #+#                  #
#    Updated: 2020/11/04 10:31:33 by hlin          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRC = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s

OBJ = $(SRC:.s=.o)

TESTMAIN = test_str.c test_rw.c

NASM = nasm -f macho64

GCCFLAG = -Wall -Wextra -Werror

TEST = test

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\nCreating the library\n"
	ar rc $@ $^
	ranlib $@

%.o: %.s
	$(NASM) $<

bonus: $(all)

test: $(TESTMAIN) $(NAME)
	@echo "\nCompiling tests\n"
	gcc $(GCCFLAG) -L. -lasm -lc -o $(TEST) $(TESTMAIN)

clean:
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME) $(TEST) test_file.txt

re: fclean all

.PHONY: all clean fclean re bonus
