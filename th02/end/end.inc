ENDTEXT_PRINT_MUTIPLE_LINE macro linenum, passline, delay
		mov	si, linenum
		jmp	short @@endtextloop&linenum&_1


@@endtextloop&linenum&_2:
		push	(144 shl 16 or 332)
		push	44
		mov	ax, si
		imul	ax, END_LINE_LEN
		add	ax, offset end_buf
		push	ds
		push	ax
		push	delay
		call	graph_putsa_fx_with_typing
		inc	si

@@endtextloop&linenum&_1:
		cmp	si, linenum+passline-1
		jle	short @@endtextloop&linenum&_2
endm

