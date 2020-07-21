hud_bar_max	db 40h, 41h, 42h, 43h, 44h, 0
HUD_POWER_BAR_COLORS	db TX_RED
	db TX_RED
	db TX_RED
	db TX_MAGENTA
	db TX_MAGENTA
	db TX_BLUE
	db TX_GREEN
	db TX_CYAN
	db TX_YELLOW
HUD_bar_ROW	db 0CFh, 0CFh, 0CFh, 0CFh, 0CFh,0
include th02/strings/ranks_left[data].asm ;is there somthing other use this file?
gsSCORE		db 0C4h, 0C5h, 0C6h, 0,	0
gsHISCORE	db 0CEh, 0C4h, 0C5h, 0C6h, 0
gsREIMU		db 0C9h, 0CAh, 0, 0, 0
gsREIGEKI	db 0CCh, 0CDh, 0, 0, 0
gsREIRYOKU	db 0C7h, 0C8h, 0, 0, 0