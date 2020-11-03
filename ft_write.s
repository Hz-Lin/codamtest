; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_write.s                                         :+:    :+:             ;
;                                                      +:+                     ;
;    By: hlin <hlin@student.codam.nl>                 +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/10/29 15:06:14 by hlin          #+#    #+#                  ;
;    Updated: 2020/10/30 21:28:11 by hlin          ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

	section .text
	global	_ft_write
	extern	___error

; ssize_t	write(int fd, const void *buf, size_t nbyte)
; write nbyte of data to the object referenced by fd from the
; return num has been written or -1 with error (set errno)
; fd->rdi, buf->rsi, nbyte->rdx

_ft_write:
	mov		rax, 0x2000004	; use the write system call
	syscall					; make system call
	jc		error			; jump if carry flag is 1 (system call failed)
	ret

error:
	push	rax				; push rax onto stack
	call	___error		; returns address of errno to rax
	mov		rdi, rax		; copy the address of errno to rdi
	pop		rax				; pop top of stack into rax
	mov		[rdi], rax		; assign errno value at the location in rdi
	mov		rax, -1			; return -1
	ret