;void pascal popup_number_add_number_* (int x, int y, int number);
public POPUP_NUMBER_ADD_NUMBER_YELLOW, POPUP_NUMBER_ADD_NUMBER_WHITE
popup_number_add_number_yellow	label near
		mov	bl, _popup_number_yellow_count
		inc	_popup_number_yellow_count
		cmp	bl, POPUPNUMBER_YELLOW-1
		jb	short @@skip_reset_yellow
		mov	_popup_number_yellow_count, 0

@@skip_reset_yellow:
		xor	bh, bh
		add	bx, POPUPNUMBER_WHITE
		jmp	short @@set_flage_1

popup_number_add_number_white	label near
		mov	bl, _popup_number_white_count
		mov	bh, 0
		inc	_popup_number_white_count
		cmp	bl, POPUPNUMBER_WHITE-1
		jb	short @@skip_reset_white
		mov	_popup_number_white_count, 0

@@skip_reset_white:
@@set_flage_1:
		shl	bx, 4
		add	bx, offset _popup_number
		mov	word ptr [bx], 1 ;flag=1, age=0

;fallthrough to C part
popup_number_add_number	proc near

@@number		= word ptr  4
@@y		= word ptr  6
@@x		= word ptr  8

		push	bp
		mov	bp, sp
		mov	ax, [bp+@@x]
		mov	[bx+popup_number_t.curX],	ax
		mov	ax, [bp+@@y]
		mov	[bx+popup_number_t.curY],	ax
if GAME eq 4
		mov	[bx+popup_number_t.curW],	0
		mov	al, _popup_number_double_times
		mov	[bx+popup_number_t.double_times], al
endif
if GAME eq 5
		push	si
		mov	si, bx
endif
		lea	ax, [bx+popup_number_t.digits][POPUPNUMBER_MAX_DIGIT-1]
		push	ax
		push	[bp+@@number]
		call	popup_number_convert_number
if GAME eq 5
		mov	[si+8],	ax
		pop	si
endif
		pop	bp
		retn	6
popup_number_add_number	endp