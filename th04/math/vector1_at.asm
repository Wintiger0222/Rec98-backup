public VECTOR1_AT
vector1_at	proc far

@@angle	= word ptr  6
@@length	= word ptr  8
@@origin	= word ptr  0Ah

	push	bp
	mov	bp, sp
	movsx	eax, [bp+@@length]
	movsx	edx, [bp+@@angle]
	imul	eax, edx
	sar	eax, 8
	add	ax, [bp+@@origin]
	pop	bp
	retf	6
vector1_at	endp
