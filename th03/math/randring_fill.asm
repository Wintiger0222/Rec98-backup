; void pascal near randring_fill(void);
public RANDRING_FILL
randring_fill	proc near
	push	si
	mov	si, RANDRING_SIZE - 1

@@loop:
	call	IRand
	mov	_randring[si], al
	dec	si
	jge	short @@loop
if GAME ge 4
	mov	_randring_p, 0
endif
	pop	si
	ret
randring_fill	endp
