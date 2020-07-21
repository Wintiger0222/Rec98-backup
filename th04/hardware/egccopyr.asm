public EGC_COPY_RECT_1_TO_0
egc_copy_rect_1_to_0	proc far

@@h	= word ptr [bp+6]
@@w	= word ptr [bp+8]
@@y	= word ptr [bp+10]
@@x	= word ptr [bp+12]

@@row equ bx
@@stride equ bp

	push	bp
	mov	bp, sp
	push	di
if GAME eq 4
	cld
endif
	call	egc_start_copy
	outw	EGC_MODE_ROP_REG, EGC_COMPAREREAD or EGC_WS_ROP or EGC_RL_MEMREAD or 0F0h
	mov	ax, @@x
	mov	dx, @@y
	mov	bx, ax
	sar	bx, 4
	shl	bx, 1
	shl	dx, 6
	add	bx, dx
	shr	dx, 2
	add	bx, dx
	mov	di, bx
	and	ax, 0Fh
	mov	cx, ax
	add	ax, @@w
	shr	ax, 4
	or	cx, cx
	jz	short @@x_on_word_boundary
	inc	ax

@@x_on_word_boundary:
	mov	_egccopyr_width_words, ax
	mov	cx, (ROW_SIZE / 2)
	sub	cx, ax
	shl	cx, 1
	mov	@@row, @@h
	mov	@@stride, cx
	mov	ax, GRAM_400
	mov	es, ax
	assume es:nothing

@@next_row:
	mov	cx, _egccopyr_width_words

@@next_word:
if GAME eq 5
	or	di, di
	js	short @@skip
	cmp	di, (ROW_SIZE * RES_Y)
	jnb	short @@skip
endif
	mov	al, 1
	out	0A6h, al
	mov	dx, es:[di]
	xor	ax, ax
	out	0A6h, al
if GAME eq 5
	mov	es:[di], dx

@@skip:
	add	di, 2
else
	mov	ax, dx
	stosw
endif
	loop	@@next_word
	add	di, @@stride
	dec	@@row
	jns	short @@next_row
	call	egc_off
	pop	di
	pop	bp
	retf	8
egc_copy_rect_1_to_0	endp
	align 2


public egc_start_copy
egc_start_copy	proc near
	push	es
	push	0
	pop	es
	pushf
	cli
	GRCG_SETMODE_VIA_MOV al, GC_TDW
	mov	es:[495h], al
	popf
	pop	es
	assume es:nothing
	mov	al, 7
	out	6Ah, al
	mov	al, 5
	out	6Ah, al
	mov	al, 6
	out	6Ah, al
	outw	EGC_ACTIVEPLANEREG, 0FFF0h
	outw	EGC_READPLANEREG, 0FFh
	outw	EGC_MASKREG, 0FFFFh
	mov	dx, EGC_ADDRRESSREG
	sub	ax, ax
	out	dx, ax
	outw	EGC_BITLENGTHREG, 0Fh
	retn
egc_start_copy	endp
