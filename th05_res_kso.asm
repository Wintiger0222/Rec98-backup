;
; +-------------------------------------------------------------------------+
; |   This file has been generated by The Interactive Disassembler (IDA)    |
; |        Copyright (c) 2009 by Hex-Rays, <support@hex-rays.com>           |
; +-------------------------------------------------------------------------+
;
; Input	MD5   :	4985DF302FBB4A988F4F8E85A083BC00

; File Name   :	th05/ZUN.COM:-S
; Format      :	MS-DOS COM-file
; Base Address:	0h Range: 100h-1AA4h Loaded length: 19A4h
; OS type	  :  MS	DOS
; Application type:  Executable	16bit

		.286
		.model tiny
		__TINY__ equ 1

include ReC98.inc
include th05/th05.inc

; ===========================================================================

; Segment type:	Pure code
_TEXT		segment	word public 'CODE' use16
		assume cs:_TEXT
		assume es:nothing, ss:nothing, ds:_TEXT

include libs/BorlandC/c0.asm

; =============== S U B	R O U T	I N E =======================================

; Attributes: bp-based frame

sub_367		proc near

var_14		= dword	ptr -14h
var_10		= byte ptr -10h
var_F		= byte ptr -0Fh
var_E		= byte ptr -0Eh
var_D		= byte ptr -0Dh
var_C		= byte ptr -0Ch
var_B		= byte ptr -0Bh
var_7		= byte ptr -7
var_6		= byte ptr -6
arg_0		= word ptr  4

		enter	14h, 0
		push	si
		mov	si, offset aMiko_cfg ; "miko.cfg"
		lea	ax, [bp+var_6]
		push	ss
		push	ax
		push	ds
		push	offset unk_16BF
		mov	cx, 6
		call	N_SCOPY@
		mov	ax, [bp+arg_0]
		mov	word ptr [bp+var_14+2],	ax
		mov	word ptr [bp+var_14], 0
		push	si
		call	file_ropen
		or	ax, ax
		jnz	short loc_3CA

loc_391:
		push	si
		call	file_create
		or	ax, ax
		jnz	short loc_39C
		jmp	loc_48A
; ---------------------------------------------------------------------------

loc_39C:
		push	ss
		lea	ax, [bp+var_6]
		push	ax
		push	6
		call	file_write
		les	bx, [bp+var_14]
		mov	es:[bx+resident_t.rank], RANK_DEFAULT
		mov	es:[bx+resident_t.cfg_lives], 3
		mov	es:[bx+resident_t.credit_lives], 3
		mov	es:[bx+resident_t.bgm_mode], 1
		mov	es:[bx+resident_t.se_mode], 1
		mov	es:[bx+resident_t.turbo_mode], 1
		jmp	loc_47C
; ---------------------------------------------------------------------------

loc_3CA:
		push	ss
		lea	ax, [bp+var_10]
		push	ax
		push	0Ah
		call	file_read
		call	file_close
		mov	al, [bp+var_10]
		cbw
		push	ax
		mov	al, [bp+var_F]
		cbw
		pop	dx
		add	dx, ax
		mov	al, [bp+var_E]
		cbw
		add	dx, ax
		mov	al, [bp+var_D]
		cbw
		add	dx, ax
		mov	al, [bp+var_C]
		cbw
		add	dx, ax
		mov	al, [bp+var_B]
		cbw
		add	dx, ax
		mov	al, [bp+var_7]
		cbw
		cmp	dx, ax
		jnz	short loc_391
		les	bx, [bp+var_14]
		mov	al, [bp+var_10]
		mov	es:[bx+resident_t.rank], al
		mov	al, [bp+var_F]
		mov	es:[bx+resident_t.cfg_lives], al
		mov	al, [bp+var_E]
		mov	es:[bx+resident_t.credit_lives], al
		mov	al, [bp+var_D]
		mov	es:[bx+resident_t.bgm_mode], al
		mov	al, [bp+var_C]
		mov	es:[bx+resident_t.se_mode], al
		mov	al, [bp+var_B]
		mov	es:[bx+resident_t.turbo_mode], al
		cmp	es:[bx+resident_t.cfg_lives], 6
		jbe	short loc_43A
		jmp	loc_391
; ---------------------------------------------------------------------------

loc_43A:
		cmp	es:[bx+resident_t.cfg_lives], 0
		jnz	short loc_444
		jmp	loc_391
; ---------------------------------------------------------------------------

loc_444:
		les	bx, [bp+var_14]
		cmp	es:[bx+resident_t.credit_lives], 3
		jbe	short loc_451
		jmp	loc_391
; ---------------------------------------------------------------------------

loc_451:
		les	bx, [bp+var_14]
		cmp	es:[bx+resident_t.bgm_mode], 3
		jb	short loc_45E
		jmp	loc_391
; ---------------------------------------------------------------------------

loc_45E:
		les	bx, [bp+var_14]
		cmp	es:[bx+resident_t.se_mode], 3
		jb	short loc_46B
		jmp	loc_391
; ---------------------------------------------------------------------------

loc_46B:
		push	si
		call	file_append
		or	ax, ax
		jz	short loc_48A
		push	0
		push	6
		push	0
		call	file_seek

loc_47C:
		push	ss
		lea	ax, [bp+arg_0]
		push	ax
		push	2
		call	file_write
		or	ax, ax
		jnz	short loc_48E

loc_48A:
		mov	al, 1
		jmp	short loc_4A6
; ---------------------------------------------------------------------------

loc_48E:
		push	ds
		push	offset byte_16BE
		push	1
		call	file_write
		push	ss
		lea	ax, [bp+var_7]
		push	ax
		push	1
		call	file_write
		call	file_close
		mov	al, 0

loc_4A6:
		pop	si
		leave
		retn
sub_367		endp


; =============== S U B	R O U T	I N E =======================================

; Attributes: bp-based frame

; int __cdecl main(int argc, const char	**argv,	const char **envp)
_main		proc near

var_C		= word ptr -0Ch
var_A		= dword	ptr -0Ah
var_6		= dword	ptr -6
var_2		= word ptr -2
_argc		= word ptr  4
_argv		= word ptr  6
_envp		= word ptr  8

		enter	0Ch, 0
		push	si
		push	di
		mov	si, [bp+_argv]
		mov	[bp+var_C], offset aKsoconfig ;	"KSOConfig"
		push	[bp+var_C]
		push	9
		push	8
		call	resdata_exist
		mov	di, ax
		push	offset aUmx	; "\n\n東方怪綺談用　 常駐プログラム　	    "...
		call	dos_puts2
		call	graph_clear
		cmp	[bp+_argc], 2
		jnz	short loc_530
		mov	bx, [si+2]
		cmp	byte ptr [bx], '-'
		jz	short loc_4DF
		cmp	byte ptr [bx], '/'
		jnz	short loc_505

loc_4DF:
		mov	bx, [si+2]
		cmp	byte ptr [bx+1], 'R'
		jz	short loc_4EE
		cmp	byte ptr [bx+1], 'r'
		jnz	short loc_505

loc_4EE:
		or	di, di
		jnz	short loc_4F8
		push	offset aVVVvvVV	; "まだいませんよぉ\n\n"
		jmp	loc_58D
; ---------------------------------------------------------------------------

loc_4F8:
		push	di
		call	dos_free
		push	offset aVVsvqvBBavVIqv ; "じゃぁねー、また会えるよね\n\n"
		call	dos_puts2
		jmp	loc_5B0
; ---------------------------------------------------------------------------

loc_505:
		mov	bx, [si+2]
		cmp	byte ptr [bx], '-'
		jz	short loc_512
		cmp	byte ptr [bx], '/'
		jnz	short loc_528

loc_512:
		mov	bx, [si+2]
		cmp	byte ptr [bx+1], 'D'
		jz	short loc_521
		cmp	byte ptr [bx+1], 'd'
		jnz	short loc_528

loc_521:
		mov	byte_16BE, 1
		jmp	short loc_530
; ---------------------------------------------------------------------------

loc_528:
		push	offset aVV	; "そんなオプション付けられても、困るんで・...
		call	dos_puts2
		jmp	short loc_590
; ---------------------------------------------------------------------------

loc_530:
		or	di, di
		jz	short loc_53C
		push	offset aVavVBavVVVvvVV ; "わたし、すでにいますよぉ\n\n"
		call	dos_puts2
		jmp	short loc_590
; ---------------------------------------------------------------------------

loc_53C:
		push	[bp+var_C]
		push	9
		push	8
		call	resdata_create
		mov	di, ax
		or	di, di
		jnz	short loc_554
		push	offset aNVVVV	; "作れません、わたしの居場所がないの！\n\n"
		call	dos_puts2
		jmp	short loc_590
; ---------------------------------------------------------------------------

loc_554:
		mov	word ptr [bp+var_A+2], di
		mov	word ptr [bp+var_A], 0
		push	offset aVivVsvVVBVBb ; "おじゃましまーす。\n\n"
		call	dos_puts2
		mov	[bp+var_2], 0Ah
		jmp	short loc_576
; ---------------------------------------------------------------------------

loc_569:
		les	bx, [bp+var_A]
		add	bx, [bp+var_2]
		mov	byte ptr es:[bx], 0
		inc	[bp+var_2]

loc_576:
		cmp	[bp+var_2], 80h
		jl	short loc_569
		push	di
		call	sub_367
		pop	cx
		or	al, al
		jz	short loc_595
		push	di
		call	dos_free
		push	offset aGtg@gcglvkpsvl ; "ファイルが書き込めないの〜\n\n"

loc_58D:
		call	dos_puts2

loc_590:
		mov	ax, 1
		jmp	short loc_5B2
; ---------------------------------------------------------------------------

loc_595:
		mov	dx, word ptr [bp+var_A+2]
		mov	ax, word ptr [bp+var_A]
		mov	word ptr [bp+var_6+2], dx
		mov	word ptr [bp+var_6], ax
		cmp	byte_16BE, 0
		jz	short loc_5B0
		les	bx, [bp+var_6]
		mov	es:[bx+resident_t.debug_mode], 1

loc_5B0:
		xor	ax, ax

loc_5B2:
		pop	di
		pop	si
		leave
		retn
_main		endp

include libs/master.lib/graph_clear.asm
include libs/master.lib/resdata.asm
include libs/master.lib/file_read.asm
include libs/master.lib/file_close.asm
include libs/master.lib/file_ropen.asm
include libs/master.lib/file_write.asm
include libs/master.lib/file_create.asm
include libs/master.lib/file_seek.asm
include libs/master.lib/file_append.asm
include libs/master.lib/dos_free.asm
include libs/master.lib/dos_axdx.asm
include libs/master.lib/dos_puts2.asm
include libs/master.lib/dos_ropen.asm
include libs/BorlandC/_abort.asm
include libs/BorlandC/atexit.asm
include libs/BorlandC/errormsg.asm
include libs/BorlandC/exit.asm
include libs/BorlandC/ioerror.asm
include libs/BorlandC/_isatty.asm
include libs/BorlandC/lseek.asm
include libs/BorlandC/n_scopy.asm
include libs/BorlandC/setupio.asm
include libs/BorlandC/brk.asm
include libs/BorlandC/nearheap.asm
include libs/BorlandC/pathops.asm
include libs/BorlandC/fflush.asm
include libs/BorlandC/flushall.asm
include libs/BorlandC/fseek.asm
include libs/BorlandC/setvbuf.asm
include libs/BorlandC/_strlen.asm
include libs/BorlandC/write.asm
include libs/BorlandC/writea.asm
include libs/BorlandC/xfflush.asm
include libs/BorlandC/setargv.asm
		db 14 dup(0)
; ---------------------------------------------------------------------------

include libs/BorlandC/c0[data].asm

byte_16BE	db 0
unk_16BF	db 0FFh
		db    3
		db    3
		db    1
		db    1
		db    1
aMiko_cfg	db 'miko.cfg',0
aKsoconfig	db 'KSOConfig',0
aUmx		db 0Ah
		db 0Ah
		db '東方怪綺談用　 常駐プログラム　                         Version1.00 (c)zun 1998',0Ah,0
aVVVvvVV	db 'まだいませんよぉ',0Ah
		db 0Ah,0
aVVsvqvBBavVIqv	db 'じゃぁねー、また会えるよね',0Ah
		db 0Ah,0
aVV		db 'そんなオプション付けられても、困るんですけど',0Ah
		db 0Ah,0
aVavVBavVVVvvVV	db 'わたし、すでにいますよぉ',0Ah
		db 0Ah,0
aNVVVV		db '作れません、わたしの居場所がないの！',0Ah
		db 0Ah,0
aVivVsvVVBVBb	db 'おじゃましまーす。',0Ah
		db 0Ah,0
aGtg@gcglvkpsvl	db 'ファイルが書き込めないの〜',0Ah
		db 0Ah,0
include libs/master.lib/version[data].asm
include libs/master.lib/grp[data].asm
include libs/master.lib/resdata[data].asm
include libs/master.lib/fil[data].asm
include libs/master.lib/dos_ropen[data].asm
include libs/BorlandC/_abort[data].asm
include libs/BorlandC/atexit[data].asm
include libs/BorlandC/exit[data].asm
include libs/BorlandC/files[data].asm
__heaplen	dw 0
include libs/BorlandC/ioerror[data].asm
include libs/BorlandC/stklen[data].asm
include libs/BorlandC/nearheap[data].asm
include libs/BorlandC/pathops[data].asm
include libs/BorlandC/setvbuf[data].asm
include libs/BorlandC/sysnerr[data].asm
include libs/BorlandC/setargv[data].asm

InitStart	label byte
include libs/BorlandC/setupio[initdata].asm
include libs/BorlandC/pathops[initdata].asm
include libs/BorlandC/setargv[initdata].asm
InitEnd	label byte

ExitStart	label byte
ExitEnd	label byte

bdata@	label byte
include libs/master.lib/fil[bss].asm
include libs/BorlandC/atexit[bss].asm
edata@	label byte
_TEXT		ends


		end startx
