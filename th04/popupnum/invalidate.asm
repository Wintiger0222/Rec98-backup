public POPUP_NUMBER_INVALIDATE
popup_number_invalidate	proc near
		push	si
		push	di
		mov	_tile_invalidate_box.y, 8
		mov	si, offset _popup_number
		mov	di, POPUPNUMBER_COUNT

@@loop:
		cmp	[si+popup_number_t.flag], 0
		jz	short @@skip
		mov	ax, [si+popup_number_t.curW]
		mov	_tile_invalidate_box.x, ax
		mov	ax, [si+popup_number_t.curX]
if GAME eq 4
		cmp	[si+popup_number_t.double_times], 0
		jz	short @@not_double
		add	ax, (8 shl 4)

@@not_double:
		call	main_01:tiles_invalidate_around pascal, [si+popup_number_t.lastY], ax ;remove this later...
else
		call	tiles_invalidate_around pascal, [si+popup_number_t.lastY], ax
endif
@@skip:
		add	si, size popup_number_t
		dec	di
		jnz	short @@loop
		pop	di
		pop	si
		retn
popup_number_invalidate	endp