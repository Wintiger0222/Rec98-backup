public POPUP_NUMBER_CONVERT_NUMBER
popup_number_convert_number	proc near
if GAME eq 5
@@number		= word ptr  4
@@ptr		= word ptr  6

		push	bp
		mov	bp, sp
		mov	dx, [bp+@@number]
		mov	bx, [bp+@@ptr]
		push	si
		xor	bp, bp
else
@@number		= word ptr  2
@@ptr		= word ptr  4

		mov	bx, sp
		mov	dx, ss:[bx+@@number]
		mov	bx, ss:[bx+@@ptr]
		push	si
endif
		mov	si, offset _FIVE_DIGIT_POWERS_OF_10+(5-POPUPNUMBER_MAX_DIGIT)*2
		mov	cx, (POPUPNUMBER_MAX_DIGIT-1)

@@loop:
		mov	ax, dx
		xor	dx, dx
		div	word ptr [si]
		mov	[bx], al
if GAME eq 5
		or	al, al
		jz	short @@skip
		or	bp, bp
		jnz	short @@skip
		mov	bp, cx
@@skip:
endif
		dec	bx
		add	si, 2
		loop	@@loop
		mov	[bx], dl
if GAME eq 5
		add	bp, 2
		shl	bp, 3
		mov	ax, bp
endif
		pop	si
if GAME eq 5 
		pop	bp
endif
		retn	4
popup_number_convert_number	endp