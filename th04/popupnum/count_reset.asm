public POPUP_NUMBER_COUNT_RESET
popup_number_count_reset	proc near
		mov	_popup_number_white_count, 0
		mov	_popup_number_yellow_count, 0
		retn
popup_number_count_reset	endp
		nop