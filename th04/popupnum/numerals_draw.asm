public NUMERALS_DRAW
numerals_draw	proc near
		push	si
		push	di
		push	ax
		push	dx
		mov	si, dx
		mov	bx, ax
		sar	dx, 3
		shl	ax, 6
		add	dx, ax
		shr	ax, 2
		add	dx, ax
		mov	di, dx
		and	si, 7
		mov	ax, si
		shl	si, 4
		add	si, offset NUMERALS
		shl	cx, 7
		add	si, cx
		cmp	bx, 188h
		ja	short loc_BE33
		mov	cx, 8
		xor	bx, bx
		jmp	short loc_BE3E
; ---------------------------------------------------------------------------

loc_BE33:
		mov	cx, 190h	; value	table for switch statement
		sub	cx, bx
		mov	bx, 8
		sub	bx, cx		; jump table for switch	statement
		nop

loc_BE3E:
		lodsw
		or	ah, ah
		jz	short loc_BE48
		mov	es:[di], ax
		jmp	short loc_BE4F
; ---------------------------------------------------------------------------

loc_BE48:
		or	al, al
		jz	short loc_BE4F
		mov	es:[di], al

loc_BE4F:
		add	di, 50h	; 'P'
		loop	loc_BE3E
		or	bx, bx
		jz	short loc_BE60
		sub	di, 7D00h
		xchg	cx, bx
		jmp	short loc_BE3E
; ---------------------------------------------------------------------------

loc_BE60:
		pop	dx
		pop	ax
		add	dx, 8
		pop	di
		pop	si
		retn
numerals_draw	endp