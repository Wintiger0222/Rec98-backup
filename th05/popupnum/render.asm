PUBLIC POPUP_NUMBER_RENDER
popup_number_render	proc near
		push	si
		push	di
		mov	di, offset _popup_number_index
		mov	si, [di]
		or	si, si
		jz	short loc_C3B6
		push	bp
		mov	ax, GRAM_400
		mov	es, ax
		mov	dx, 7Eh	
		mov	al, 0FFh
		cli
		out	dx, al
		out	dx, al
		out	dx, al
		out	dx, al
		sti

@@loop:
		cmp	si, _popup_number_yellow_index
		jnz	short loc_C377
;set color yellow
		mov	dx, 7Eh	
		mov	al, 0FFh
		cli
		out	dx, al
		out	dx, al
		not	al
		out	dx, al
		not	al
		out	dx, al
		sti

loc_C377:
		mov	bp, [si+popup_number_t.curW]
		shr	bp, 1
		mov	dx, [si+popup_number_t.curX]
		sar	dx, 4
		add	dx, 20h	; ' '
		sub	dx, bp
		shr	bp, 2
		sub	bp, 2
		mov	ax, [si+popup_number_t.curY]
		add	ax, (12 shl 4)
		call	scroll_subpixel_y_to_vram_seg1 pascal, ax
		add	si, popup_number_t.digits
		add	si, bp

loc_C39C:
		xor	ch, ch
		mov	cl, [si]
		call	numerals_draw
		dec	si
		dec	bp
		jns	short loc_C39C
		xor	cx, cx;0
		call	numerals_draw
		add	di, 2
		mov	si, [di]
		or	si, si
		jnz	short @@loop
		pop	bp

loc_C3B6:
		pop	di
		pop	si
		retn
popup_number_render	endp