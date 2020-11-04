/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_rw.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 22:07:26 by hlin          #+#    #+#                 */
/*   Updated: 2020/11/04 10:28:57 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	test_write(int fd, char *str, int len)
{
	int		res1;
	int		res2;
	int		err1;
	int		err2;

	res1 = write(fd, str, len);
	err1 = errno;
	write(fd, "\n", 1);
	res2 = ft_write(fd, str, len);
	err2 = errno;
	ft_write(fd, "\n", 1);
	printf("src_str:        %s\n", (*str == '\0' ? "\\0" : str));
	printf("write:          %d\n", res1);
	printf("ft_write:       %d\n", res2);
	printf("errno write:    %d\n", err1);
	printf("errno ft_write: %d\n", err2);
}

static int	test_read(char *file, size_t len)
{
	int		fd;
	char	buf1[100];
	char	buf2[100];
	int		res;

	bzero(buf1, 100);
	bzero(buf2, 100);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	res = read(fd, buf1, len);
	printf("read:           %s\n", (*buf1 == '\0' ? "\\0" : buf1));
	printf("read return:    %d\n", res);
	printf("errno read:     %d\n", errno);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	res = ft_read(fd, buf2, len);
	printf("ft_read:        %s\n", (*buf2 == '\0' ? "\\0" : buf2));
	printf("ft_read return: %d\n", res);
	printf("errno ft_read:  %d\n", errno);
	close(fd);
	return (0);
}

int			write_testing(void)
{
	int		fd;

	fd = open("test_file.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	if (fd < 0)
		return (-1);
	printf("" YELLOW "====== testing write ======" RESET "\n");
	test_write(42, "Fd is 42", 8);
	errno = 0;
	test_write(1, "", 0);
	test_write(1, "This is a string test", 21);
	test_write(1, "This is a string test", 35);
	test_write(1, "This is a string test", 10);
	test_write(1, "This is a string test", -7);
	errno = 0;
	test_write(fd, "", 0);
	test_write(fd, "This is a string test", 21);
	test_write(fd, "This is a string test", 35);
	test_write(fd, "This is a string test", 10);
	test_write(fd, "This is a string test", -7);
	errno = 0;
	close(fd);
	return (0);
}

void		read_testing(void)
{
	char	buf1[100];
	char	buf2[100];
	int		res;

	bzero(buf1, 100);
	bzero(buf2, 100);
	printf("" YELLOW "====== testing read ======" RESET "\n");
	res = read(42, buf1, 20);
	printf("read:           %s\n", (*buf1 == '\0' ? "\\0" : buf1));
	printf("read return:    %d\n", res);
	printf("errno read:     %d\n", errno);
	res = ft_read(42, buf2, 20);
	printf("ft_read:        %s\n", (*buf2 == '\0' ? "\\0" : buf2));
	printf("ft_read return: %d\n", res);
	printf("errno ft_read:  %d\n", errno);
	errno = 0;
	test_read("libasm.h", 10);
	test_read("libasm.h", 0);
	test_read("libasm.h", 50);
	test_read("libasm.h", -7);
	errno = 0;
	test_read("invalidfile", 10);
}

int			main(void)
{
	str_testing();
	write_testing();
	read_testing();
	return (0);
}
