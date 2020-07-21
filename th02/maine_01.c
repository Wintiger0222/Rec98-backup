
#define GAME 2
#pragma option -a2
#pragma option -O
#pragma option -ml
#pragma option -3 
#pragma option -K
#pragma option -Z
#pragma option -d
#include <stdio.h>
#include <stdarg.h>
#include <master.h>
#include <process.h>
#include "th02/th02.h"
#include "th02/initexit.h"
#include "th02/formats/pi.h"
#define END_LINE_LEN 46
void pascal sub_B07F(void);
void pascal sub_A09D(void);
void pascal sub_9B64(void);
void pascal sub_A8FA(void);
void pascal score_enter(void);
int pascal cfg_load(void);
int pascal scoredat_is_extra_unlocked(void);

char end_buf[100][END_LINE_LEN];
char text_default_fx;
char text_force_type_fast;
/*
;void pascal load_end_txt (char* fn)
load_end_txt	proc near

@@size		= word ptr -2
@@fn		= dword	ptr  4

		enter	2, 0
		pushd	[bp+@@fn]
		call	file_ropen
		call	file_size
		mov	[bp+@@size], ax
		push	ds
		push	offset end_buf
		push	ax
		call	file_read
		call	file_close
		leave
		retn	4
load_end_txt	endp


; =============== S U B	R O U T	I N E =======================================

; Attributes: bp-based frame
;void pascal gaiji_score_put (int x, int y, long? value)
gaiji_score_put	proc near

var_9		= byte ptr -9
var_8		= dword	ptr -8
var_4		= dword	ptr -4
@@value		= dword	ptr  4
@@y		= word ptr  8
@@x		= word ptr  0Ah

		enter	0Ah, 0
		push	si
		push	di
		mov	di, gb_0_
		mov	[bp+var_4], 10000000
		mov	[bp+var_9], 0
		xor	si, si
		jmp	short loc_9638
; ---------------------------------------------------------------------------

loc_95E4:
		mov	eax, [bp+@@value]
		cdq
		idiv	[bp+var_4]
		mov	ebx, 10
		cdq
		idiv	ebx
		mov	[bp+var_8], edx
		mov	eax, [bp+var_4]
		cdq
		idiv	ebx
		mov	[bp+var_4], eax
		mov	ax, word ptr [bp+var_8]
		add	ax, gb_0_
		mov	di, ax
		cmp	[bp+var_8], 0
		jz	short loc_961D
		mov	[bp+var_9], 1

loc_961D:
		cmp	[bp+var_9], 0
		jz	short loc_9637
		mov	ax, si
		shl	ax, 4
		add	ax, [bp+@@x]
		call	graph_gaiji_putc pascal, ax, [bp+@@y], di, 15

loc_9637:
		inc	si

loc_9638:
		cmp	si, 8
		jl	short loc_95E4
		pop	di
		pop	si
		leave
		retn	8
gaiji_score_put	endp


; =============== S U B	R O U T	I N E =======================================

; Attributes: bp-based frame
;void pascal graph_putsa_fx_with_typing(int x, int y. int len, char* str, int delay)
graph_putsa_fx_with_typing	proc near

@@buf		= byte ptr -50h
@@delay		= word ptr  4
@@str		= dword	ptr  6
@@len		= word ptr  0Ah
@@y		= word ptr  0Ch
@@x		= word ptr  0Eh

		enter	50h, 0
		push	si
		push	di
		lea	ax, [bp+@@buf]
		push	ss
		push	ax
		push	ds
		push	offset unk_D030
		mov	cx, size unk_D030
		call	SCOPY@
		xor	si, si
		xor	di, di
		jmp	short loc_96C4
; ---------------------------------------------------------------------------

loc_9660:
		call	_input_sense
		les	bx, [bp+@@str]
		add	bx, si
		mov	al, es:[bx]
		mov	[bp+si+@@buf],	al
		inc	si
		mov	bx, word ptr [bp+@@str]
		add	bx, si
		mov	al, es:[bx]
		mov	[bp+si+@@buf],	al
		inc	si
		mov	[bp+si+@@buf],	0
		push	ss
		lea	ax, [bp+@@buf]
		push	ax
		mov	al, text_default_fx
		cbw
		push	ax
		push	[bp+@@y]
		push	[bp+@@x]
		call	_graph_putsa_fx
		add	sp, 0Ah
		cmp	text_force_type_fast, 0
		jz	short @@type_nomal_speed
		cmp	_key_det, 0
		jz	short @@type_nomal_speed
		test	di, 3
		jz	short loc_96C1
		mov	ax, [bp+@@delay]
		mov	bx, 3
		cwd
		idiv	bx
		push	ax
		jmp	short @@type_faster
; ---------------------------------------------------------------------------

@@type_nomal_speed:
		push	[bp+@@delay]

@@type_faster:
		call	frame_delay

loc_96C1:
		add	di, 2

loc_96C4:
		cmp	di, [bp+@@len]
		jl	short loc_9660
		xor	si, si
		jmp	short loc_96EC
; ---------------------------------------------------------------------------

loc_96CD:
		call	_input_sense
		cmp	text_force_type_fast, 0
		jz	short @@type_text_faster
		cmp	_key_det, 0
		jz	short @@type_text_faster
		push	0
		jmp	short @@no_delay
; ---------------------------------------------------------------------------

@@type_text_faster:
		push	2

@@no_delay:
		call	frame_delay
		inc	si

loc_96EC:
		cmp	si, 20
		jl	short loc_96CD
		cmp	text_force_type_fast, 0
		jz	short loc_96FB
		call	sub_9A7E

loc_96FB:
		pop	di
		pop	si
		leave
		retn	0Ch
graph_putsa_fx_with_typing	endp


; =============== S U B	R O U T	I N E =======================================

; Attributes: bp-based frame

sub_9701	proc far

var_8		= word ptr -8
var_6		= word ptr -6
var_4		= word ptr -4
var_2		= word ptr -2
arg_0		= word ptr  6
arg_2		= word ptr  8
arg_4		= dword	ptr  0Ah

		enter	8, 0
		push	si
		push	di
		mov	ax, [bp+arg_0]
		sar	ax, 3
		mov	dx, [bp+arg_2]
		shl	dx, 6
		add	ax, dx
		mov	dx, [bp+arg_2]
		shl	dx, 4
		add	ax, dx
		mov	si, ax
		xor	di, di
		jmp	loc_97E6
; ---------------------------------------------------------------------------

loc_9724:
		graph_accesspage 1
		les	bx, _VRAM_PLANE_B
		add	bx, si
		mov	ax, es:[bx]
		mov	[bp+var_8], ax
		les	bx, _VRAM_PLANE_R
		add	bx, si
		mov	ax, es:[bx]
		mov	[bp+var_6], ax
		les	bx, _VRAM_PLANE_G
		add	bx, si
		mov	ax, es:[bx]
		mov	[bp+var_4], ax
		les	bx, _VRAM_PLANE_E
		add	bx, si
		mov	ax, es:[bx]
		mov	[bp+var_2], ax
		mov	al, 0
		out	dx, al
		call	grcg_setcolor pascal, (GC_RMW shl 16) + 0
		mov	ax, di
		add	ax, ax
		les	bx, [bp+arg_4]
		add	bx, ax
		mov	ax, es:[bx]
		les	bx, _VRAM_PLANE_B
		add	bx, si
		mov	es:[bx], ax
		call	grcg_off
		mov	ax, di
		add	ax, ax
		les	bx, [bp+arg_4]
		add	bx, ax
		mov	ax, es:[bx]
		and	ax, [bp+var_8]
		les	bx, _VRAM_PLANE_B
		add	bx, si
		or	es:[bx], ax
		mov	ax, di
		add	ax, ax
		les	bx, [bp+arg_4]
		add	bx, ax
		mov	ax, es:[bx]
		and	ax, [bp+var_6]
		les	bx, _VRAM_PLANE_R
		add	bx, si
		or	es:[bx], ax
		mov	ax, di
		add	ax, ax
		les	bx, [bp+arg_4]
		add	bx, ax
		mov	ax, es:[bx]
		and	ax, [bp+var_4]
		les	bx, _VRAM_PLANE_G
		add	bx, si
		or	es:[bx], ax
		mov	ax, di
		add	ax, ax
		les	bx, [bp+arg_4]
		add	bx, ax
		mov	ax, es:[bx]
		and	ax, [bp+var_2]
		les	bx, _VRAM_PLANE_E
		add	bx, si
		or	es:[bx], ax
		add	si, 80
		inc	di

loc_97E6:
		cmp	di, 16
		jl	loc_9724
		pop	di
		pop	si
		leave
		retf
sub_9701	endp


; =============== S U B	R O U T	I N E =======================================

; Attributes: bp-based frame

text_fadein_effect	proc far

var_60		= byte ptr -60h
arg_0		= word ptr  6
arg_2		= word ptr  8
arg_4		= word ptr  0Ah

		enter	60h, 0
		push	si
		push	di
		lea	ax, [bp+var_60]
		push	ss
		push	ax
		push	ds
		push	offset byte_D080
		mov	cx, 8*12
		call	SCOPY@
		xor	di, di
		jmp	short loc_983D
; ---------------------------------------------------------------------------

loc_980C:
		xor	si, si
		jmp	short loc_9830
; ---------------------------------------------------------------------------

loc_9810:
		mov	ax, di
		shl	ax, 5
		lea	dx, [bp+var_60]
		add	ax, dx
		push	ss
		push	ax
		push	[bp+arg_2]
		mov	ax, si
		shl	ax, 4
		add	ax, [bp+arg_0]
		push	ax
		call	sub_9701
		add	sp, 8
		inc	si

loc_9830:
		cmp	si, [bp+arg_4]
		jl	short loc_9810
		call	frame_delay pascal, 10
		inc	di

loc_983D:
		cmp	di, 3
		jl	short loc_980C
		pop	di
		pop	si
		leave
		retf
text_fadein_effect	endp


; =============== S U B	R O U T	I N E =======================================

; Attributes: bp-based frame

sub_9846	proc near

var_2		= byte ptr -2
var_1		= byte ptr -1
arg_0		= dword	ptr  4
arg_4		= word ptr  8

		enter	2, 0
		push	si
		push	di
		mov	di, [bp+arg_4]
		mov	si, 100
		mov	[bp+var_2], 0
		xor	cx, cx
		jmp	short loc_98A1
; ---------------------------------------------------------------------------

loc_985A:
		mov	ax, di
		cwd
		idiv	si
		mov	[bp+var_1], al
		cmp	[bp+var_2], 0
		jnz	short loc_986B
		mov	[bp+var_2], al

loc_986B:
		cmp	[bp+var_2], 0
		jnz	short loc_9876
		cmp	cx, 2
		jnz	short loc_9885

loc_9876:
		les	bx, [bp+arg_0]
		add	bx, cx
		mov	al, [bp+var_1]
		add	al, 160
		mov	es:[bx], al
		jmp	short loc_988E
; ---------------------------------------------------------------------------

loc_9885:
		les	bx, [bp+arg_0]
		add	bx, cx
		mov	byte ptr es:[bx], 0CFh 
		
loc_988E:
		mov	al, [bp+var_1]
		cbw
		imul	si
		sub	di, ax
		inc	cx
		mov	bx, 10
		mov	ax, si
		cwd
		idiv	bx
		mov	si, ax

loc_98A1:
		cmp	cx, 3
		jl	short loc_985A
		les	bx, [bp+arg_0]
		add	bx, cx
		mov	byte ptr es:[bx], 0
		pop	di
		pop	si
		leave
		retn	6
sub_9846	endp


; =============== S U B	R O U T	I N E =======================================

; Attributes: bp-based frame
; egc_quarter_put(int slot)
egc_quarter_put	proc near

var_6		= word ptr -6
var_4		= word ptr -4
var_2		= word ptr -2
arg_0		= word ptr  4

		enter	6, 0
		push	si
		push	di
		cmp	[bp+arg_0], 0
		jnz	short loc_98C5
		xor	ax, ax
		jmp	short loc_98DE
; ---------------------------------------------------------------------------

loc_98C5:
		cmp	[bp+arg_0], 1
		jnz	short loc_98D0
		mov	ax, (320 / 8)
		jmp	short loc_98DE
; ---------------------------------------------------------------------------

loc_98D0:
		cmp	[bp+arg_0], 2
		jnz	short loc_98DB
		mov	ax, (640 * 200) / 8
		jmp	short loc_98DE
; ---------------------------------------------------------------------------

loc_98DB:
		mov	ax, ((640 * 200) + 320) / 8

loc_98DE:
		mov	si, ax
		mov	di, 1F54h;someone please conver to xy cord....
		call	egc_start_copy
		mov	[bp+var_2], 0
		jmp	short loc_9930
; ---------------------------------------------------------------------------

loc_98EF:
		mov	[bp+var_4], 0
		jmp	short loc_9921
; ---------------------------------------------------------------------------

loc_98F6:
		graph_accesspage 1
		les	bx, _VRAM_PLANE_B
		add	bx, si
		mov	ax, es:[bx]
		mov	[bp+var_6], ax
		mov	al, 0
		out	dx, al
		mov	bx, word ptr _VRAM_PLANE_B
		add	bx, di
		mov	ax, [bp+var_6]
		mov	es:[bx], ax
		add	[bp+var_4], 2
		add	si, 2
		add	di, 2

loc_9921:
		cmp	[bp+var_4], (320 / 8)
		jl	short loc_98F6
		inc	[bp+var_2]
		add	di, (320 / 8)
		add	si, (320 / 8)

loc_9930:
		cmp	[bp+var_2], 200
		jl	short loc_98EF
		call	egc_off
		pop	di
		pop	si
		leave
		retn	2
egc_quarter_put	endp


; =============== S U B	R O U T	I N E =======================================

; Attributes: bp-based frame
; egc_quarter_put_x_y(int x, int y, int slot)
egc_quarter_put_x_y	proc near

var_6		= word ptr -6
var_4		= word ptr -4
var_2		= word ptr -2
arg_0		= word ptr  4
arg_2		= word ptr  6
arg_4		= word ptr  8

		enter	6, 0
		push	si
		push	di
		cmp	[bp+arg_0], 0
		jnz	short loc_9952
		xor	ax, ax
		jmp	short loc_996B
; ---------------------------------------------------------------------------

loc_9952:
		cmp	[bp+arg_0], 1
		jnz	short loc_995D
		mov	ax, (320 / 8)
		jmp	short loc_996B
; ---------------------------------------------------------------------------

loc_995D:
		cmp	[bp+arg_0], 2
		jnz	short loc_9968
		mov	ax, (640 * 200) / 8
		jmp	short loc_996B
; ---------------------------------------------------------------------------

loc_9968:
		mov	ax, ((640 * 200) + 320) / 8

loc_996B:
		mov	si, ax
		mov	ax, [bp+arg_4]
		sar	ax, 3
		mov	dx, [bp+arg_2]
		shl	dx, 6
		add	ax, dx
		mov	dx, [bp+arg_2]
		shl	dx, 4
		add	ax, dx
		mov	di, ax
		call	egc_start_copy
		mov	[bp+var_2], 0
		jmp	short loc_99D2
; ---------------------------------------------------------------------------

loc_9991:
		mov	[bp+var_4], 0
		jmp	short loc_99C3
; ---------------------------------------------------------------------------

loc_9998:
		graph_accesspage 1
		les	bx, _VRAM_PLANE_B
		add	bx, si
		mov	ax, es:[bx]
		mov	[bp+var_6], ax
		mov	al, 0
		out	dx, al
		mov	bx, word ptr _VRAM_PLANE_B
		add	bx, di
		mov	ax, [bp+var_6]
		mov	es:[bx], ax
		add	[bp+var_4], 2
		add	si, 2
		add	di, 2

loc_99C3:
		cmp	[bp+var_4], (320 / 8)
		jl	short loc_9998
		inc	[bp+var_2]
		add	di, (320 / 8)
		add	si, (320 / 8)

loc_99D2:
		cmp	[bp+var_2], 200
		jl	short loc_9991
		call	egc_off
		pop	di
		pop	si
		leave
		retn	6
egc_quarter_put_x_y	endp


; =============== S U B	R O U T	I N E =======================================

; Attributes: bp-based frame

sub_99E4	proc near

var_6		= word ptr -6
var_4		= word ptr -4
var_2		= word ptr -2
arg_0		= word ptr  4
arg_2		= word ptr  6
arg_4		= word ptr  8

		enter	6, 0
		push	si
		push	di
		cmp	[bp+arg_4], 0
		jnz	short loc_99F4
		xor	ax, ax
		jmp	short loc_9A0D
; ---------------------------------------------------------------------------

loc_99F4:
		cmp	[bp+arg_4], 1
		jnz	short loc_99FF
		mov	ax, (320 / 8)
		jmp	short loc_9A0D
; ---------------------------------------------------------------------------

loc_99FF:
		cmp	[bp+arg_4], 2
		jnz	short loc_9A0A
		mov	ax, (640 * 200) / 8
		jmp	short loc_9A0D
; ---------------------------------------------------------------------------

loc_9A0A:
		mov	ax, ((640 * 200) + 320) / 8

loc_9A0D:
		mov	si, ax
		mov	di, 1F54h
		mov	ax, [bp+arg_2]
		imul	ax, 80
		add	si, ax
		call	egc_start_copy
		mov	ax, [bp+arg_2]
		mov	[bp+var_2], ax
		jmp	short loc_9A68
; ---------------------------------------------------------------------------

loc_9A27:
		mov	[bp+var_4], 0
		jmp	short loc_9A59
; ---------------------------------------------------------------------------

loc_9A2E:
		graph_accesspage 1
		les	bx, _VRAM_PLANE_B
		add	bx, si
		mov	ax, es:[bx]
		mov	[bp+var_6], ax
		mov	al, 0
		out	dx, al
		mov	bx, word ptr _VRAM_PLANE_B
		add	bx, di
		mov	ax, [bp+var_6]
		mov	es:[bx], ax
		add	[bp+var_4], 2
		add	si, 2
		add	di, 2

loc_9A59:
		cmp	[bp+var_4], (320 / 8)
		jl	short loc_9A2E
		inc	[bp+var_2]
		add	di, (320 / 8)
		add	si, (320 / 8)

loc_9A68:
		mov	ax, [bp+arg_0]
		add	ax, [bp+arg_2]
		cmp	ax, [bp+var_2]
		jg	short loc_9A27
		call	egc_off
		pop	di
		pop	si
		leave
		retn	6
sub_99E4	endp


; =============== S U B	R O U T	I N E =======================================

; Attributes: bp-based frame

sub_9A7E	proc near

var_2		= word ptr -2

		enter	2, 0
		push	si
		push	di
		call	grcg_setcolor pascal, (GC_RMW shl 16) + 0
		mov	si, 14Ch
		jmp	short loc_9AC5
; ---------------------------------------------------------------------------

loc_9A94:
		mov	di, 90h
		jmp	short loc_9ABE
; ---------------------------------------------------------------------------

loc_9A99:
		mov	ax, di
		sar	ax, 3
		mov	dx, si
		shl	dx, 6
		add	ax, dx
		mov	dx, si
		shl	dx, 4
		add	ax, dx
		mov	[bp+var_2], ax
		les	bx, _VRAM_PLANE_B
		add	bx, [bp+var_2]
		mov	word ptr es:[bx], -1
		add	di, 10h

loc_9ABE:
		cmp	di, 1F0h
		jl	short loc_9A99
		inc	si

loc_9AC5:
		cmp	si, 15Ch
		jl	short loc_9A94
		call	grcg_off
		pop	di
		pop	si
		leave
		retn
sub_9A7E	endp


; =============== S U B	R O U T	I N E =======================================

; Attributes: bp-based frame

sub_9AD4	proc near
		push	bp
		mov	bp, sp
		push	si
		call	load_end_txt pascal, ds, offset aEnd3_txt
		call	frame_delay pascal, 30
		call	palette_white_out pascal, 1
		call	_snd_load c, offset aEnding_m, ds, SND_LOAD_SONG
		kajacall	KAJA_SONG_PLAY
		pop	cx
		call	sub_9A7E
		call	palette_white_in pascal, 4
		call	_snd_delay_until_measure stdcall, 5
		pop	cx
		mov	si, 0A0h
		jmp	short loc_9B5C
; ---------------------------------------------------------------------------

loc_9B1B:
		push	si
		push	100
		lea	ax, [si+319]
		push	ax
		push	(299 shl 16) or 4
		call	egc_shift_left
		call	grcg_setcolor pascal, (GC_RMW shl 16) + 0
		lea	ax, [si+312]
		push	ax
		push	100
		lea	ax, [si+319]
		push	ax
		push	299
		call	grcg_boxfill
		call	grcg_off
		call	frame_delay pascal, 1
		sub	si, 4

loc_9B5C:
		cmp	si, 36
		jg	short loc_9B1B
		pop	si
		pop	bp
		retn
sub_9AD4	endp


; =============== S U B	R O U T	I N E =======================================

; Attributes: bp-based frame

sub_9B64	proc near
		push	bp
		mov	bp, sp
		push	si
		call	load_end_txt pascal, ds, offset aEnd1_txt
		call	_snd_load c, offset aEnd1_m, ds, SND_LOAD_SONG
		kajacall	KAJA_SONG_PLAY
		pop	cx
		mov	PaletteTone, 0
		call	far ptr	palette_show
		graph_accesspage 1
		call	_pi_slot_load c, 0, offset aEd01_pi, ds
		call	_pi_slot_palette_apply stdcall, 0
		pop	cx
		call	_pi_slot_put c, 0, large 0
		freePISlotLarge	0
		call	palette_black_in pascal, 2
		call	frame_delay pascal, 40
		call	egc_quarter_put pascal, 0
		mov	text_default_fx, FX(15, 2, 0) 
		mov	text_force_type_fast, 1
		call	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf, 6
		call	frame_delay pascal, 20
		call	palette_black_out pascal, 1
		call	egc_quarter_put pascal, 1
		call	palette_black_in pascal, 1
		ENDTEXT_PRINT_MUTIPLE_LINE 1, 3, 6
		call	egc_quarter_put pascal, 2
		ENDTEXT_PRINT_MUTIPLE_LINE 4, 2, 6
		mov	text_default_fx, (6 or 2 shl 4)
		call	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 6), 6
		mov	text_default_fx, FX(15, 2, 0)
		ENDTEXT_PRINT_MUTIPLE_LINE 7, 3, 6
		mov	text_default_fx, (6 or 2 shl 4)
		call	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 10), 6
		mov	text_default_fx, FX(15, 2, 0)
		call	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 11), 6
		call	frame_delay pascal, 20
		call	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 12), 6
		xor	si, si
		jmp	short loc_9D10
; ---------------------------------------------------------------------------

loc_9CDE:
		graph_accesspage 0
		call	egc_shift_down pascal, (160 shl 16) or 100, (479 shl 16) or 297, 2
		push	3
		mov	ax, si
		add	ax, ax
		mov	dx, 198
		sub	dx, ax
		push	dx
		push	2
		call	sub_99E4
		call	frame_delay pascal, 1
		inc	si

loc_9D10:
		cmp	si, 100
		jl	short loc_9CDE
		call	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 13), 6
		mov	text_default_fx, (6 or 2 shl 4)
		ENDTEXT_PRINT_MUTIPLE_LINE 14, 2, 6
		mov	text_default_fx, FX(15, 2, 0)
		ENDTEXT_PRINT_MUTIPLE_LINE 16, 2, 6
		mov	text_default_fx, (6 or 2 shl 4)
		ENDTEXT_PRINT_MUTIPLE_LINE 18, 3, 6
		mov	text_default_fx, FX(15, 2, 0)
		call 	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 21), 6
		mov	text_default_fx, (6 or 2 shl 4)
		call 	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 22), 6
		mov	text_default_fx, FX(15, 2, 0)
		call 	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 23), 6
		graph_accesspage 1
		call	_pi_slot_load c, 0, offset aEd02_pi, ds
		call	_pi_slot_palette_apply stdcall, 0
		pop	cx
		call	_pi_slot_put c, 0, large 0
		freePISlotLarge	0
		call	palette_black_out pascal, 2
		les	bx, _resident
		cmp	es:[bx+mikoconfig_t.shottype], 0
		jnz	short loc_9E2A
		push	0
		jmp	short loc_9E3B
; ---------------------------------------------------------------------------

loc_9E2A:
		les	bx, _resident
		cmp	es:[bx+mikoconfig_t.shottype], 1
		jnz	short loc_9E39
		push	2
		jmp	short loc_9E3B
; ---------------------------------------------------------------------------

loc_9E39:
		push	3

loc_9E3B:
		call	egc_quarter_put
		call	palette_black_in pascal, 2
		mov	text_default_fx, (6 or 2 shl 4)
		call 	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 24), 6
		mov	text_default_fx, FX(15, 2, 0)
		ENDTEXT_PRINT_MUTIPLE_LINE 25, 2, 6
		mov	text_default_fx, (6 or 2 shl 4)
		les	bx, _resident
		cmp	es:[bx+mikoconfig_t.shottype], 0
		jnz	loc_9F22
		ENDTEXT_PRINT_MUTIPLE_LINE 27, 2, 6
		mov	text_default_fx, FX(15, 2, 0)
		ENDTEXT_PRINT_MUTIPLE_LINE 29, 2, 6
		call	egc_quarter_put pascal, 1
		mov	text_default_fx, (6 or 2 shl 4)
		call 	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 31), 6
		mov	text_default_fx, FX(15, 2, 0)
		call 	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 32), 12
		mov	text_force_type_fast, 0
		push	(144 shl 16 or 332)
		push	44
		push	ds
		push	offset end_buf + (END_LINE_LEN * 33)
		jmp	loc_A092
; ---------------------------------------------------------------------------

loc_9F22:
		les	bx, _resident
		cmp	es:[bx+mikoconfig_t.shottype], 1
		jnz	loc_9FD3
		call 	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 34), 6
		mov	text_default_fx, FX(15, 2, 0)
		call 	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 35), 6
		mov	text_default_fx, (6 or 2 shl 4)
		call 	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 36), 6
		mov	text_default_fx, FX(15, 2, 0)
		ENDTEXT_PRINT_MUTIPLE_LINE 37, 2, 6
		mov	text_default_fx, (6 or 2 shl 4)
		call 	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 39), 6
		mov	text_default_fx, FX(15, 2, 0)
		call 	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 40), 12
		mov	text_force_type_fast, 0
		push	(144 shl 16 or 332)
		push	44
		push	ds
		push	offset end_buf + (END_LINE_LEN * 41)
		jmp	loc_A092
; ---------------------------------------------------------------------------

loc_9FD3:
		les	bx, _resident
		cmp	es:[bx+mikoconfig_t.shottype], 2
		jnz	loc_A097
		call 	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 42), 6
		mov	text_default_fx, FX(15, 2, 0)
		call 	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 43), 6
		mov	text_default_fx, (6 or 2 shl 4)
		ENDTEXT_PRINT_MUTIPLE_LINE 44, 2, 6
		mov	text_default_fx, FX(15, 2, 0)
		ENDTEXT_PRINT_MUTIPLE_LINE 46, 2, 6
		mov	text_default_fx, (6 or 2 shl 4)
		call 	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 48), 6
		mov	text_default_fx, FX(15, 2, 0)
		call 	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 49), 12
		mov	text_force_type_fast, 0
		push	(144 shl 16 or 332)
		push	44
		push	ds
		push	offset end_buf + (END_LINE_LEN * 50)

loc_A092:
		push	9
		call	graph_putsa_fx_with_typing

loc_A097:
		call	sub_9AD4
		pop	si
		pop	bp
		retn
sub_9B64	endp


; =============== S U B	R O U T	I N E =======================================

; Attributes: bp-based frame

sub_A09D	proc near
		push	bp
		mov	bp, sp
		push	si
		call	load_end_txt pascal, ds, offset aEnd2_txt
		call	_snd_load c, offset aEnd1_m, ds, SND_LOAD_SONG
		kajacall	KAJA_SONG_PLAY
		pop	cx
		mov	PaletteTone, 0
		call	far ptr	palette_show
		graph_accesspage 1
		call	_pi_slot_load c, 0, offset aEd01_pi, ds
		call	_pi_slot_palette_apply stdcall, 0
		pop	cx
		call	_pi_slot_put c, 0, large 0
		freePISlotLarge	0
		call	palette_black_in pascal, 2
		call	frame_delay pascal, 40
		call	egc_quarter_put pascal, 0
		mov	text_default_fx, FX(15, 2, 0)
		mov	text_force_type_fast, 1
		call	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 0), 6
		call	frame_delay pascal, 20
		call	palette_black_out pascal, 1
		graph_accesspage 1
		call	_pi_slot_load c, 0, offset aEd03_pi, ds
		call	_pi_slot_palette_apply stdcall, 0
		pop	cx
		call	_pi_slot_put c, 0, large 0
		freePISlotLarge	0
		call	egc_quarter_put pascal, 0
		call	palette_black_in pascal, 1
		ENDTEXT_PRINT_MUTIPLE_LINE 1, 3, 6
		call	egc_quarter_put pascal, 1
		ENDTEXT_PRINT_MUTIPLE_LINE 4, 6, 6
		call	egc_quarter_put pascal, 2
		ENDTEXT_PRINT_MUTIPLE_LINE 10, 2, 6
		call	egc_quarter_put pascal, 3
		ENDTEXT_PRINT_MUTIPLE_LINE 12 ,2, 6
		call	palette_entry_rgb pascal, ds, offset aEd03a_rgb
		call	far ptr	palette_show
		mov	text_default_fx, (9 or 2 shl 4)
		ENDTEXT_PRINT_MUTIPLE_LINE 14, 2, 6
		call	palette_black_out pascal, 2
		graph_accesspage 1
		call	_pi_slot_load c, 0, offset aEd04_pi, ds
		call	_pi_slot_palette_apply stdcall, 0
		pop	cx
		call	_pi_slot_put c, 0, large 0
		freePISlotLarge	0
		graph_accesspage 0
		call	egc_quarter_put pascal, 0
		call	palette_black_in pascal, 2
		mov	text_default_fx, FX(15, 2, 0)
		call 	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 16), 6
		mov	text_default_fx, (9 or 2 shl 4)
		call 	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 17), 6
		mov	text_default_fx, FX(15, 2, 0)
		ENDTEXT_PRINT_MUTIPLE_LINE 18, 2, 6
		call	egc_quarter_put pascal, 1
		mov	text_default_fx, (9 or 2 shl 4)
		ENDTEXT_PRINT_MUTIPLE_LINE 20, 2, 6
		mov	text_default_fx, FX(15, 2, 0)
		call 	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 22), 6
		mov	text_default_fx, (9 or 2 shl 4)
		ENDTEXT_PRINT_MUTIPLE_LINE 23, 2, 6
		mov	text_default_fx, FX(15, 2, 0)
		call 	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 25), 6
		mov	text_default_fx, (9 or 2 shl 4)
		call 	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 26), 6
		call	frame_delay pascal, 10
		les	bx, _resident
		cmp	es:[bx+mikoconfig_t.shottype], 0
		jnz	loc_A4EC
		call 	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 27), 6
		call	frame_delay pascal, 30
		call	egc_quarter_put pascal, 2
		mov	text_default_fx, FX(15, 2, 0)
		call 	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 28), 6
		call	egc_quarter_put pascal, 3
		call 	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 29), 6
		mov	text_default_fx, (9 or 2 shl 4)
		ENDTEXT_PRINT_MUTIPLE_LINE 30, 2, 6
		mov	text_default_fx, FX(15, 2, 0)
		ENDTEXT_PRINT_MUTIPLE_LINE 32, 5, 6
		mov	text_default_fx, (9 or 2 shl 4)
		ENDTEXT_PRINT_MUTIPLE_LINE 37, 2, 6
		mov	text_default_fx, FX(15, 2, 0)
		call 	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 39), 6
		call	palette_black_out pascal, 2
		graph_accesspage 1
		call	_pi_slot_load c, 0, offset aEd05_pi, ds
		call	_pi_slot_palette_apply stdcall, 0
		pop	cx
		call	_pi_slot_put c, 0, large 0
		freePISlotLarge	0
		call	egc_quarter_put pascal, 0
		call	palette_black_in pascal, 2
		ENDTEXT_PRINT_MUTIPLE_LINE 40, 7, 6
		mov	text_force_type_fast, 0
		push	(144 shl 16 or 332)
		push	2Ch ; ','
		push	ds
		push	offset end_buf + (END_LINE_LEN * 47)
		jmp	loc_A869
; ---------------------------------------------------------------------------

loc_A4EC:
		les	bx, _resident
		cmp	es:[bx+mikoconfig_t.shottype], 1
		jnz	loc_A6B6
		call	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 48), 6
		call	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 49), 6
		mov	text_default_fx, FX(15, 2, 0)
		call	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 50), 6
		mov	text_default_fx, (9 or 2 shl 4)
		call	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 51), 6
		call	frame_delay pascal, 30
		call	egc_quarter_put pascal, 2
		mov	text_default_fx, FX(15, 2, 0)
		call	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 52), 6
		call	egc_quarter_put pascal, 3
		call	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 53), 6
		mov	text_default_fx, (9 or 2 shl 4)
		call	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 54), 6
		mov	text_default_fx, FX(15, 2, 0)
		call	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 55), 6
		mov	text_default_fx, (9 or 2 shl 4)
		call	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 56), 6
		mov	text_default_fx, FX(15, 2, 0)
		call	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 57), 6
		mov	text_default_fx, (9 or 2 shl 4)
		ENDTEXT_PRINT_MUTIPLE_LINE 58, 4, 6
		mov	text_default_fx, FX(15, 2, 0)
		ENDTEXT_PRINT_MUTIPLE_LINE 62, 5, 6
		call	palette_black_out pascal, 2
		graph_accesspage 1
		call	_pi_slot_load c, 0, offset aEd05_pi, ds
		call	_pi_slot_palette_apply stdcall, 0
		pop	cx
		call	_pi_slot_put c, 0, large 0
		freePISlotLarge	0
		call	egc_quarter_put pascal, 1
		call	palette_black_in pascal, 2
		ENDTEXT_PRINT_MUTIPLE_LINE 67, 2, 6
		call	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 69), 12
		mov	text_force_type_fast, 0
		push	(144 shl 16 or 332)
		push	2Ch ; ','
		push	ds
		push	offset end_buf + (END_LINE_LEN * 70)
		jmp	loc_A869
; ---------------------------------------------------------------------------

loc_A6B6:
		call	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 71), 6
		mov	text_default_fx, FX(15, 2, 0)
		call	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 72), 6
		mov	text_default_fx, (9 or 2 shl 4)
		call	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 73), 6
		call	frame_delay pascal, 30
		call	egc_quarter_put pascal, 2
		mov	text_default_fx, FX(15, 2, 0)
		call	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 74), 6
		call	egc_quarter_put pascal, 3
		call	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 75), 6
		mov	text_default_fx, (9 or 2 shl 4)
		call	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 76), 6
		mov	text_default_fx, FX(15, 2, 0)
		call	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 77), 6
		mov	text_default_fx, (9 or 2 shl 4)
		call	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 78), 6
		mov	text_default_fx, FX(15, 2, 0)
		call	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 79), 6
		mov	text_default_fx, (9 or 2 shl 4)
		call	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 80), 6
		mov	text_default_fx, FX(15, 2, 0)
		call	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 81), 6
		mov	text_default_fx, (9 or 2 shl 4)
		call	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 82), 6
		mov	text_default_fx, FX(15, 2, 0)
		call	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 83), 6
		call	palette_black_out pascal, 2
		graph_accesspage 1
		call	_pi_slot_load c, 0, offset aEd05_pi, ds
		call	_pi_slot_palette_apply stdcall, 0
		pop	cx
		call	_pi_slot_put c, 0, large 0
		freePISlotLarge	0
		call	egc_quarter_put pascal, 2
		call	palette_black_in pascal, 2
		ENDTEXT_PRINT_MUTIPLE_LINE 84, 8, 6
		call	graph_putsa_fx_with_typing pascal, LARGE (144 shl 16 or 332), 44, ds, offset end_buf + (END_LINE_LEN * 92), 6
		mov	text_force_type_fast, 0
		push	(144 shl 16 or 332)
		push	44
		push	ds
		push	offset end_buf + (END_LINE_LEN * 93)

loc_A869:
		push	12
		call	graph_putsa_fx_with_typing
		call	sub_9AD4
		pop	si
		pop	bp
		retn
sub_A09D	endp


; =============== S U B	R O U T	I N E =======================================

; Attributes: bp-based frame
;void pascal endft_btf_put(int x, int y, int index)
endft_btf_put	proc near

@@i		= word ptr -2
@@x		= word ptr  4
@@y		= word ptr  6
@@index		= word ptr  8

		enter	2, 0
		push	si
		push	di
		mov	si, [bp+@@index]
		mov	di, [bp+@@x]
		mov	[bp+@@i], 0
		jmp	short loc_A898
; ---------------------------------------------------------------------------

loc_A887:
		push	si
		push	[bp+@@y]
		push	di
		call	over_put_8
		inc	[bp+@@i]
		inc	di
		add	si, 16

loc_A898:
		cmp	[bp+@@i], 5
		jl	short loc_A887
		pop	di
		pop	si
		leave
		retn	6
endft_btf_put	endp


; =============== S U B	R O U T	I N E =======================================

; Attributes: bp-based frame

sub_A8A4	proc near
		push	bp
		mov	bp, sp
		call	grcg_setcolor pascal, (GC_RMW shl 16) + 0
		push	1A000C0h
		push	27F010Fh
		call	grcg_boxfill
		call	grcg_off
		pop	bp
		retn
sub_A8A4	endp


; =============== S U B	R O U T	I N E =======================================

; Attributes: bp-based frame
;void pascal rotrect(unsigned char angle, int slot, int rad)
rotrect	proc near

@@rad		= word ptr  4
@@slot		= word ptr  6
@@angle		= word ptr  8

		push	bp
		mov	bp, sp
		call	rotrect_animate pascal, [bp+@@angle], [bp+@@rad]
		call	egc_quarter_put_x_y pascal, (32 shl 16 or 100), [bp+@@slot] 
		call	frame_delay pascal, 4
		mov	PaletteTone, 100
		call	far ptr	palette_show
		pop	bp
		retn	6
rotrect	endp
*/

/*
void pascal sub_A8FA(void);
{
@@g_str		= byte ptr -4

	snd_delay_until_measure(6);
	for(int i=0; i<5+11; i+=5)
	{
		endft_btf_put(432, 184, i);
		frame_delay(4);
	}
	graph_putsa_fx(528, 192, FX(15, 2, 0), "ver 1.00");
	snd_delay_until_measure(8);
	for(int i=184; i<368; i+=4)
	{
		grcg_setcolor(GC_RMW,0);
		grcg_boxfill(528, i+4, 591, i+19);
		grcg_off();
		endft_btf_put(432, i, 5*10);
		graph_putsa_fx(528, i+8, FX(15, 2, 0), "ver 1.00");
		frame_delay(1);
	}
	
	snd_delay_until_measure(9);
	text_default_fx=FX(15, 2, 0);
	graph_putsa_fx_with_typing(432, 192, 20, "封魔録　　ＳＴＡＦＦ", 12);
	snd_delay_until_measure(13);
	
	graph_accesspage(1);
	{//pi_load_put_free(0,"ed06.pi");
		pi_slot_load(0, "ed06.pi");
		pi_slot_palette_apply(0); 
		pi_slot_put(0, 0, 0); 
		graph_pi_free(&pi_slot_headers[0], pi_slot_buffers[0]);
	}
	graph_accesspage(0);
	rotrect(4, 0, 41);
	sub_A8A4();
	graph_putsa_fx(416, 192, FX(15, 2, 0), "プログラム　　　ＺＵＮ");
	snd_delay_until_measure(17);
	
	palette_entry_rgb("ed06b.rgb");
	palette_show();
	rotrect(-4, 2, 41);
	snd_delay_until_measure(21);
	egc_quarter_put_x_y(32, 100, 3);
	palette_entry_rgb("ed06c.rgb");
	palette_show();
	rotrect(4, 3, 41);
	graph_accesspage(1);
	pi_slot_load(0, "ed07.pi");
	pi_slot_put(0, 0, 0); 
	graph_pi_free(&pi_slot_headers[0], pi_slot_buffers[0]);
	graph_accesspage(0);
	snd_delay_until_measure(25);
	
	sub_A8A4();
	graph_putsa_fx(416, 192, FX(15, 2, 0), "グラフィック　ＺＵＮ");
	graph_putsa_fx(416, 224, FX(15, 2, 0), "　　　　　　　高附日向");
	graph_putsa_fx(416, 240, FX(15, 2, 0), "　　　　（オールクリア画）");
	palette_entry_rgb("ed07a.rgb");
	palette_show();
	rotrect(-4, 0, 41);
	snd_delay_until_measure(29);
	palette_entry_rgb("ed07b.rgb");
	palette_show();
	rotrect(8, 1, 233);
	snd_delay_until_measure(33);
	egc_quarter_put_x_y(32 shl 16 or 100), 2
	rotrect((-8 and 255), 2, 233
	snd_delay_until_measure(37);
	
	sub_A8A4();
	graph_putsa_fx(432, 192, FX(15, 2, 0), "ＭＵＳＩＣ　　ＺＵＮ");
	palette_entry_rgb("ed07b.rgb");
	palette_show();
	rotrect(8, 3, 233);
	graph_accesspage(1);
	pi_slot_load(0, "ed08.pi");
	pi_slot_put(0, 0, 0); 
	graph_accesspage(0);
	snd_delay_until_measure(41)
	pi_slot_palette_apply(0); 
	graph_pi_free(&pi_slot_headers[0], pi_slot_buffers[0]);
	rotrect(-8, 0,  233);
	snd_delay_until_measure(45);
	
	palette_entry_rgb("ed08a.rgb");
	palette_show();
	rotrect(12, 1, 41);
	snd_delay_until_measure(49);
	
	sub_A8A4();
	graph_putsa_fx(416, 192, FX(15, 2, 0), "ＴＥＳＴ　ＰＬＡＹＥＲ");
	graph_putsa_fx(416, 224, FX(15, 2, 0), "　　　　かおる");
	graph_putsa_fx(416, 248, FX(15, 2, 0), "　　　　Ｃ－Ｗ");
	graph_putsa_fx(416, 272, FX(15, 2, 0), "　　 山田　恵一郎");
	graph_putsa_fx(416, 296, FX(15, 2, 0), " その他大勢のみなさん");
	palette_entry_rgb("ed08b.rgb");
	palette_show();
	rotrect(-12, 2, 41);
	snd_delay_until_measure(53);
	
	palette_entry_rgb("ed08c.rgb");
	palette_show();
	rotrect(12, 3, 41);
	snd_delay_until_measure(57);
	
	palette_black_out(4);
	graph_accesspage(1);
	{//pi_load_put_free(0,"ED09.pi");
		pi_slot_load(0, "ED09.pi");
		pi_slot_palette_apply(0); 
		pi_slot_put(0, 0, 0); 
		graph_pi_free(&pi_slot_headers[0], pi_slot_buffers[0]);
	}
	graph_copy_page(0);
	palette_black_in(4);
	frame_delay(100);
	graph_accesspage(1);
	graph_putsa_fx(24, 96, text_default_fx, "Ｔｈａｎｋ　ｙｏｕ　ｆｏｒ　ｐｌａｙｉｎｇ");
	text_fadein_effect(24, 96, 21);
	frame_delay(200);
	graph_accesspage(1);
	
		push	ds
		push	offset aTotal_score ; "　最終得点"
		mov	al, text_default_fx
		cbw
		push	ax
		push	64 or (128 shl 16)
	graph_putsa_fx
		add	sp, 0Ah
		call	gaiji_score_put pascal, (192 shl 16) or 128, LARGE [_score]
		call	text_fadein_effect c, 64, LARGE(128 or 16 shl 16)
		call	frame_delay pascal, 100
		graph_accesspage(1);
		push	ds
		push	offset aContinue ;	"コンティニュー"
		mov	al, text_default_fx
		cbw
		push	ax
		push	64 or (160 shl 16)
	graph_putsa_fx
		add	sp, 0Ah
		push	(256 shl 16) or 160
		les	bx, _resident
		mov	ax, es:[bx+mikoconfig_t.continues_used]
		add	ax, gb_0_
		push	ax
		push	15
		call	graph_gaiji_putc
		call	text_fadein_effect c, 64, LARGE(160 or 16 shl 16)
		call	frame_delay pascal, 100
		graph_accesspage(1);
		push	ds
		push	offset aRank ; "　 ランク"
		mov	al, text_default_fx
		cbw
		push	ax
		push	64 or (192 shl 16)
	graph_putsa_fx
		add	sp, 0Ah
		push	(208 shl 16) or 192
		push	GAIJI_W
		push	ds
		mov	al, _rank
		cbw
		shl	ax, 3
		add	ax, offset _RANKS_CENTER
		push	ax
		push	15
		call	graph_gaiji_puts
		call	text_fadein_effect c, 64, LARGE(192 or 16 shl 16)
		call	frame_delay pascal, 100
		graph_accesspage(1);
		push	ds
		push	offset aStart_lives ; "プレイヤー初期"
		mov	al, text_default_fx
		cbw
		push	ax
		push	64 or (224 shl 16)
	graph_putsa_fx
		add	sp, 0Ah
		push	(256 shl 16) or 224
		les	bx, _resident
		mov	al, es:[bx+mikoconfig_t.start_lives]
		mov	ah, 0
		add	ax, gb_1_
		push	ax
		push	15
		call	graph_gaiji_putc
		call	text_fadein_effect c, 64, LARGE(224 or 16 shl 16)
		call	frame_delay pascal, 100
		graph_accesspage(1);
		push	ds
		push	offset aStart_bombs; " 霊撃初期数"
		mov	al, text_default_fx
		cbw
		push	ax
		push	64 or (256 shl 16)
	graph_putsa_fx
		add	sp, 0Ah
		push	(256 shl 16) or 256
		les	bx, _resident
		mov	al, es:[bx+mikoconfig_t.start_bombs]
		mov	ah, 0
		add	ax, gb_0_
		push	ax
		push	15
		call	graph_gaiji_putc
		call	text_fadein_effect c, 64, LARGE(256 or 16 shl 16)
		call	frame_delay pascal, 150
		graph_accesspage(1);
		les	bx, _resident
		mov	di, es:[bx+mikoconfig_t.skill]
		cmp	di, 100
		jle	short loc_AEAC
		mov	di, 100
		jmp	short loc_AEB2
; ---------------------------------------------------------------------------

loc_AEAC:
		or	di, di
		jge	short loc_AEB2
		xor	di, di

loc_AEB2:
		push	ds
		push	offset aYour_rank ; "あなたの腕前"
		mov	al, text_default_fx
		cbw
		push	ax
		push	64 or (288 shl 16) 
	graph_putsa_fx
		add	sp, 0Ah
		push	di
		push	ss
		lea	ax, [bp+@@g_str]
		push	ax
		call	sub_9846
		push	(192 shl 16) or 288
		push	GAIJI_W
		push	ss
		lea	ax, [bp+@@g_str]
		push	ax
		push	15
		call	graph_gaiji_puts
		cmp	di, 100
		jnz	short loc_AEEF
		xor	si, si
		jmp	short loc_AF56
; ---------------------------------------------------------------------------

loc_AEEF:
		cmp	di, 90
		jl	short loc_AEF9
		mov	si, 1
		jmp	short loc_AF56
; ---------------------------------------------------------------------------

loc_AEF9:
		cmp	di, 80
		jl	short loc_AF03
		mov	si, 2
		jmp	short loc_AF56
; ---------------------------------------------------------------------------

loc_AF03:
		cmp	di, 70
		jl	short loc_AF17
		cmp	di, 77
		jnz	short loc_AF12
		mov	si, 3
		jmp	short loc_AF56
; ---------------------------------------------------------------------------

loc_AF12:
		mov	si, 4
		jmp	short loc_AF56
; ---------------------------------------------------------------------------

loc_AF17:
		cmp	di, 60
		jl	short loc_AF21
		mov	si, 5
		jmp	short loc_AF56
; ---------------------------------------------------------------------------

loc_AF21:
		cmp	di, 50
		jl	short loc_AF2B
		mov	si, 6
		jmp	short loc_AF56
; ---------------------------------------------------------------------------

loc_AF2B:
		cmp	di, 40
		jl	short loc_AF35
		mov	si, 7
		jmp	short loc_AF56
; ---------------------------------------------------------------------------

loc_AF35:
		cmp	di, 30
		jl	short loc_AF3F
		mov	si, 8
		jmp	short loc_AF56
; ---------------------------------------------------------------------------

loc_AF3F:
		cmp	di, 20
		jl	short loc_AF49
		mov	si, 9
		jmp	short loc_AF56
; ---------------------------------------------------------------------------

loc_AF49:
		cmp	di, 10
		jl	short loc_AF53
		mov	si, 10
		jmp	short loc_AF56
; ---------------------------------------------------------------------------

loc_AF53:
		mov	si, 11

loc_AF56:
		mov	ax, si
		imul	ax, END_LINE_LEN
		add	ax, offset end_buf
		push	ds
		push	ax
		mov	al, text_default_fx
		cbw
		push	ax
		push	240 or (288 shl 16)
	graph_putsa_fx
		add	sp, 0Ah
		call	text_fadein_effect c, 64, LARGE(288 or 6 shl 16)
		call	frame_delay pascal, 120
		call	text_fadein_effect c, 192, LARGE(288 or 24 shl 16)
		call	frame_delay pascal, 200
		graph_accesspage(1);
		push	ds
		push	offset a1997_ZUN ; "１９９７　ＺＵＮ  (Amusement Makers)"
		mov	al, text_default_fx
		cbw
		push	ax
		push	64 or (352 shl 16)
	graph_putsa_fx
		add	sp, 0Ah
		call	text_fadein_effect c, 64, LARGE(352 or 18 shl 16)
		key_delay();
		palette_black_out(5);
		sub_AFE7();
		graph_clear();
}
*/

void pascal sub_AFE7(void)
{
	if(scoredat_is_extra_unlocked()==0) {
		return;
	}
	if(resident->continues_used !=0){
		return;
	}
	
	{//pi_load_put_free(0,"all.pi");
line1:	pi_slot_load(0, "all.pi");
line2:	pi_slot_palette_apply(0); 
line3:	pi_slot_put(0, 0, 0); 
		graph_pi_free(&pi_slot_headers[0], pi_slot_buffers[0]);
	}
	palette_black_in(2);
	frame_delay(150);
	
	{//pi_load_put_free(0,"but.pi");
line4:	pi_slot_load(0, "but.pi");
line5:	pi_slot_palette_apply(0); 
line6:	pi_slot_put(0, 0, 0); 
		graph_pi_free(&pi_slot_headers[0], pi_slot_buffers[0]);
	}
	key_delay();
	palette_black_out(5);

}

void pascal sub_B07F(void)
{
	if(scoredat_is_extra_unlocked()==0) {
		return;
	}
	PaletteTone=0;
	palette_show();
	{//pi_load_put_free(0,"all.pi");
line1:	pi_slot_load(0, "all.pi");
line2:	pi_slot_palette_apply(0); 
line3:	pi_slot_put(0, 0, 0); 
		graph_pi_free(&pi_slot_headers[0], pi_slot_buffers[0]);
	}
	palette_black_in(2);
	frame_delay(150);
	{//pi_load_put_free(0,"extra.pi");
line4:	pi_slot_load(0, "extra.pi");
line5:	pi_slot_palette_apply(0); 
line6:	pi_slot_put(0, 0, 0); 
		graph_pi_free(&pi_slot_headers[0], pi_slot_buffers[0]);
	}
	key_delay();
	palette_black_out(5);
}


void main(void)
{
	if(cfg_load()==0) {
			return;
	}
	if(resident->stage != 0x7F) {
		return;
	}
	game_init_main();
	gaiji_backup();
	gaiji_entry_bfnt("Mikoft.bft");
	snd_pmd_resident();
	snd_mmd_resident();
	if(resident->bgm_mode == SND_BGM_OFF) {
		snd_midi_active = 0;
	} else if(resident->bgm_mode == SND_BGM_FM) {
		snd_midi_active = 0;
		snd_determine_mode();
	} else if(resident->bgm_mode == SND_BGM_MIDI) {
		snd_midi_active = snd_midi_possible;
		snd_determine_mode();
	}
	graph_accesspage(0);
	graph_showpage(0);
	super_entry_bfnt("Endft.bft");
	frame_delay(100);
	if(resident->rank !=4) {
		if(resident->continues_used !=0){
			sub_9B64();
		} else {
			sub_A09D();
		}
		sub_A8FA();	
	} else {
		sub_B07F();
	}
	PaletteTone=50;
	palette_show();
	score_enter();
	PaletteTone=0;
	palette_show();
	gaiji_restore();
	game_exit();
	execl("op", "op", 0, 0);
	return;
}