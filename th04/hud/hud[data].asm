glEASY		db 0AEh, 0AAh, 0BCh, 0C2h, 2, 2, 2, 0
glNORMAL	db 0B7h, 0B8h, 0BBh, 0B6h, 0AAh, 0B5h, 2, 0
glHARD		db 0B1h, 0AAh, 0BBh, 0ADh, 2, 2, 2, 0
glLUNATIC	db 0B5h, 0BEh, 0B7h, 0AAh, 0BDh, 0B2h, 0ACh, 0
glEXTRA		db 0AEh, 0C1h, 0BDh, 0BBh, 0AAh, 2, 2, 0
gsSCORE		db 0D7h, 0D8h, 0D9h, 0,	0
gsHISCORE	db 0D6h, 0D7h, 0D8h, 0D9h, 0
gsREIGEKI	db 0DAh, 0DBh, 0, 0, 0
gsREIMU		db 0DCh, 0DDh, 0, 0, 0
gsREIRYOKU	db 0DEh, 0DFh, 0, 0, 0
gsBOMB		db 0E0h, 0E1h, 0, 0, 0
gsPLAYER	db 0E2h, 0E3h, 0, 0, 0
gsPOWER		db 0E4h, 0E5h, 0, 0, 0
gsENEMY		db 0EAh, 0EBh, 0ECh, 0,	0
if GAME eq 5
gsRUIKEI	db 0EDh, 0EEh, 0, 0, 0
prev_dream	db 0
HUD_DREAM_BAR_COLORS	db TX_RED
	db TX_RED
	db TX_MAGENTA
	db TX_MAGENTA
	db TX_BLUE
	db TX_GREEN
	db TX_CYAN
	db TX_YELLOW
	db TX_WHITE
endif
HUD_POWER_BAR_COLORS	db TX_RED
	db TX_RED
	db TX_RED
	db TX_MAGENTA
	db TX_MAGENTA
	db TX_BLUE
	db TX_GREEN
	db TX_CYAN
	db TX_YELLOW
	db TX_WHITE
gblank_line	db 02h,02h,02h,02h,02h,02h,02h,02h,0
HUD_BOSS_HP_BAR_COLORS	db TX_RED
	db TX_MAGENTA
	db TX_CYAN
	db TX_YELLOW
	db TX_WHITE
if GAME eq 4
public _hud_bar_max
_hud_bar_max label byte
	db g_BAR_MAX_0, g_BAR_MAX_1, g_BAR_MAX_2, g_BAR_MAX_3
	db g_BAR_MAX_4, g_BAR_MAX_5, g_BAR_MAX_6, g_BAR_MAX_7
	db 0 ; '\0'!
endif
alive_times	db '　　×　　',0
abomb_times	db '　　×　　',0