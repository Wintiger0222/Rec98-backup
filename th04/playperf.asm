; void playperf_raise(char delta);
_playperf_raise	proc far
delta	= byte ptr 4

	mov	bx, sp
	mov	al, ss:[bx+delta]
	add	al, _playperf
	cmp	al, _playperf_max
	jbe	short @@ret
	mov	al, _playperf_max

@@ret:
	mov	_playperf, al
	retf	2
_playperf_raise	endp
	even


; void playperf_lower(char delta);
_playperf_lower	proc far
delta	= byte ptr 4

	mov	bx, sp
	mov	al, _playperf
	sub	al, ss:[bx+delta]
	cmp	al, _playperf_min
	jge	short @@ret
	mov	al, _playperf_min

@@ret:
	mov	_playperf, al
	retf	2
_playperf_lower	endp
