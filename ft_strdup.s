; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_strdup.s                                        :+:    :+:             ;
;                                                      +:+                     ;
;    By: hlin <hlin@student.codam.nl>                 +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/10/29 17:36:13 by hlin          #+#    #+#                  ;
;    Updated: 2020/10/30 21:27:57 by hlin          ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

	section .text
	global	_ft_strdup
	extern	_ft_strlen
	extern	_malloc

; char	*strdup(const char *s1)
; return a pointer to the copy of s1 or NULL (insufficient mem)
; s1->rdi

_ft_strdup:
	cmp		rdi, 0					; check if src is NULL
	je		exit					; jump to exit if src is NULL
	call	_ft_strlen				; calulate strlen, store len in rax
	push	rdi						; push rdi onto stack
									; so rdi can be used by malloc
	inc		rax						; len++ for malloc
	mov		rdi, rax				; set the first param for malloc
	call	_malloc					; use malloc function
	cmp		rax, 0					; check if malloc fails
	je		exit					; if malloc fails, jump to exit
									; errno is set to ENOMEM by malloc
	pop		rdi						; pop top of stack into rdi
	mov		rdx, 0					; set i = 0

dup:
	mov		r8b, byte [rdi + rdx]	; retrieve the character form src[i]
	mov		byte [rax + rdx], r8b	; copy src[i] to rax
	cmp		r8b, 0					; check if src[i] is NULL
	je		exit
	inc		rdx;					; i++
	jmp		dup						; loop until '\0' is reached

exit:
	ret