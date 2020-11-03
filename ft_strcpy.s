; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_strcpy.s                                        :+:    :+:             ;
;                                                      +:+                     ;
;    By: hlin <hlin@student.codam.nl>                 +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/10/29 17:26:00 by hlin          #+#    #+#                  ;
;    Updated: 2020/10/30 21:27:48 by hlin          ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

	section .text
	global	_ft_strcpy

; char* strcpy(char * dst, const char * src), return dst, copy include '\0'
; dst->rdi, src->rsi

_ft_strcpy:
	mov		rdx, 0					; i = 0

copy:
	mov		al, byte [rsi + rdx]	; retrieve the character form src[i]
	mov		byte [rdi + rdx], al	; copy the character to dst[i]
	cmp		al, 0					; check if src[i] equal to NULL
	je		exit					; if str[i] == 0, exit and return rax
	inc		rdx						; i++
	jmp		copy					; loop though copy function

exit:
	mov		rax, rdi				; return dst
	ret