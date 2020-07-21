public POPUP_NUMBER_UPDATE
popup_number_update	proc near
		push	si
		push	di
		mov	_popup_number_yellow_index, 0
		mov	bx, offset _popup_number_index
		mov	si, offset _popup_number
		mov	di, POPUPNUMBER_COUNT

@@loop:
		cmp	[si+popup_number_t.flag], 0
		jz	short @@skip
		cmp	[si+popup_number_t.flag], 2
		jnz	short @@still_alive
		mov	[si+popup_number_t.flag], 0
		jmp	short @@skip
; ---------------------------------------------------------------------------

@@still_alive:
		mov	cl, [si+popup_number_t.age]
		mov	ax, [si+popup_number_t.curY]
		mov	[si+popup_number_t.lastY],	ax
		cmp	cl, 24
		jb	short @@not_scroll
		sub	ax, 8

@@not_scroll:
		mov	[si+popup_number_t.curY],	ax
		cmp	ax, -64
		jg	short @@y_is_not_small
		mov	[si+popup_number_t.flag], 2
		jmp	short @@skip
; ---------------------------------------------------------------------------

@@y_is_not_small:
		inc	cl
		mov	[si+popup_number_t.age],	cl
		cmp	cl, 36
		jbe	short @@not_remove
		mov	[si+popup_number_t.flag], 2
		jmp	short @@skip
; ---------------------------------------------------------------------------

@@not_remove:
		mov	[bx], si 	
		cmp	di, POPUPNUMBER_YELLOW
		ja	short @@not_yellow
		cmp	_popup_number_yellow_index, 0
		jnz	short @@not_yellow
		mov	_popup_number_yellow_index, si

@@not_yellow:
		add	bx, 2

@@skip:
		add	si, size popup_number_t
		dec	di
		jnz	short @@loop
		mov	word ptr [bx], 0
		pop	di
		pop	si
		retn
popup_number_update	endp