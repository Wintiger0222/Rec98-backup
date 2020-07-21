public CDG_PUT_PLANE_ROLL
cdg_put_plane_roll	proc far

@@plane_dst	= word ptr [bp+6]
@@plane_src	= word ptr [bp+8]
@@slot     	= word ptr [bp+10]
@@y        	= word ptr [bp+12]
@@x        	= word ptr [bp+14]

@@stride_backwards equ dx
@@h equ bx

	push	bp
	mov	bp, sp
	push	si
	push	di
	mov	ax, @@plane_dst
	mov	es, ax
	mov	si, @@slot
	shl	si, 4
	add	si, offset _cdg_slots
	mov	di, @@x
	sar	di, 3
	mov	@@h, [si+CDGSlot.pixel_height]
	mov	ax, @@y
	add	ax, @@h
	dec	ax
	shl	ax, 6
	add	di, ax
	shr	ax, 2
	add	di, ax
	mov	ax, [si+CDGSlot.width_divided_by_32]
	mov	word ptr cs:@@width_dwords, ax
	jmp	short $+2
	shl	ax, 2
	add	ax, ROW_SIZE
	mov	@@stride_backwards, ax
	push	ds
	mov	ax, [si+CDGSlot.sgm_colors]
	mov	si, [si+CDGSlot.bitplane_size]
	mov	ds, ax
	mov	cx, @@plane_src
	inc	cx
	mov	ax, si
	neg	si

@@plane_src_num_to_offset:
	add	si, ax
	loop	@@plane_src_num_to_offset
	cmp	di, (ROW_SIZE * RES_Y)
	jb	short @@start_blitting
	sub	di, (ROW_SIZE * RES_Y)

@@start_blitting:
	cld
	nop

@@next_row:
@@width_dwords equ $+1
	mov	cx, 1234h

@@blit_dword:
	mov	eax, [si]
	or	es:[di], eax
	add	si, 4
	add	di, 4
	loop	@@blit_dword
	sub	di, @@stride_backwards
	jge	short @@more_rows?
	add	di, (ROW_SIZE * RES_Y)

@@more_rows?:
	dec	@@h
	jnz	short @@next_row
	pop	ds
	pop	di
	pop	si
	pop	bp
	retf	0Ah
cdg_put_plane_roll	endp
