PUBLIC POPUP_NUMBER_RENDER
popup_number_render proc near
		push	bp
		push	si
		push	di
		mov	dx, 7Eh	
		mov	al, 0FFh
		cli
		out	dx, al
		out	dx, al
		out	dx, al
		out	dx, al
		sti
		mov	ax, GRAM_400
		mov	es, ax
		mov	di, offset _popup_number_index
		mov	si, [di]
		cmp	si, 0
		jz	short loc_BDFA

@@loop:
		cmp	si, _popup_number_yellow_index
		jnz	short loc_BD96
;set color yellow
		mov	dx, 7Eh	
		mov	al, 0FFh
		cli
		out	dx, al
		out	dx, al
		xor	al, al
		out	dx, al
		mov	al, 0FFh
		out	dx, al
		sti

loc_BD96:
		mov	dx, [si+popup_number_t.curX]
		sar	dx, 4
		add	dx, 0Ch
		mov	ax, [si+popup_number_t.curY]
		add	ax, (12 shl 4)
		call	main_01:scroll_subpixel_y_to_vram_seg1 pascal, ax
		mov	bp, POPUPNUMBER_MAX_DIGIT
		add	si, popup_number_t.digits+3

loc_BDAF:
		cmp	byte ptr [si], 0
		jnz	short loc_BDBB
		add	dx, 4
		dec	si
		dec	bp
		jnz	short loc_BDAF

loc_BDBB:
		mov	cx, bp
		inc	cx
		shl	cx, 3
		mov	word ptr cs:loc_BDD6+3, cx

loc_BDC6:
		xor	cx, cx
		mov	cl, [si]
		call	main_01:numerals_draw
		dec	si
		dec	bp
		jnz	short loc_BDC6
		xor	cx, cx
		call	main_01:numerals_draw

loc_BDD6:
		mov	word ptr [si+5], 8*5 ;curW
		cmp	byte ptr [si+7], 0 ;double_times
		jz	short @@not_double
		add	word ptr [si+5], 16 ;curW
		mov	cx, 0Ah
		call	main_01:numerals_draw
		mov	cx, 0Bh
		call	main_01:numerals_draw

@@not_double:
		add	di, 2
		mov	si, [di]
		or	si, si
		jnz	short @@loop

loc_BDFA:
		pop	di
		pop	si
		pop	bp
		retn
popup_number_render	endp