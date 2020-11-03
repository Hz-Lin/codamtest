; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_read.s                                          :+:    :+:             ;
;                                                      +:+                     ;
;    By: hlin <hlin@student.codam.nl>                 +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/10/29 17:26:06 by hlin          #+#    #+#                  ;
;    Updated: 2020/10/30 21:27:19 by hlin          ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

	section .text
	global	_ft_read
	extern	___error

; ssize_t	read(int fd, void *buf, size_t nbyte)
; read nbyte of data from object referenced fd into buf
; return bytes has been read, 0 with end-of-file, -1 with error (set errno)
; fd->rdi, buf->rsi, nbyte->rdx)

_ft_read:
	mov		rax, 0x2000003	; use the read system call
	syscall					; make system call
	jc		error			; jump if carry flag is 1 (system call failed)
	ret

error:
	push	rax				; push rax onto stack
	call	___error		; returns address of errno, saved in rax
	mov		rdi, rax		; assign rdi the address of errno
	pop		rax				; pop top of stack into rax
	mov		[rdi], rax		; assign errno value to the location in rdi
	mov		rax, -1			; return -1
	ret