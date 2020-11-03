; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_strlen.s                                        :+:    :+:             ;
;                                                      +:+                     ;
;    By: hlin <hlin@student.codam.nl>                 +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/10/28 22:24:36 by hlin          #+#    #+#                  ;
;    Updated: 2020/10/30 21:28:03 by hlin          ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

	section .text
	global	_ft_strlen

; size_t	strlen(const char *s), return the lenght of s
; s->rdi

_ft_strlen:
	mov		rax, 0				; initial the counter, len = 0

count:
	cmp		byte [rdi + rax], 0	; compare the byte (str[i]) to NULL 
	je		exit				; if str[i] == 0, exit and return rax
	inc		rax					; len++
	jmp		count				; loop though the count function

exit:
	ret							; exit function return rax (len)