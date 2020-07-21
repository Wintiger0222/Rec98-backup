if GAME eq 5
POPUPNUMBER_MAX_DIGIT = 5
else
POPUPNUMBER_MAX_DIGIT = 4
endif

popup_number_t struc
	flag db ?;0
	age db ?;1
	curX dw ?;2
	curY dw ?;4
	lastY dw ?;6
if GAME eq 5
	curW dw ?;8 ;width
	digits db POPUPNUMBER_MAX_DIGIT dup (?);10  
else
	digits db POPUPNUMBER_MAX_DIGIT dup (?);8
	curW dw ?;12 ;width
	double_times db ?;14
endif
	db ?;15
popup_number_t ends

POPUPNUMBER_WHITE = 200
if GAME eq 5
POPUPNUMBER_YELLOW = 80
else
POPUPNUMBER_YELLOW = 200
endif
POPUPNUMBER_COUNT = POPUPNUMBER_WHITE + POPUPNUMBER_YELLOW
public _popup_number
_popup_number	popup_number_t POPUPNUMBER_COUNT dup (<?>)