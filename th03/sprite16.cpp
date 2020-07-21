/* ReC98
 * -----
 * SPRITE16 display calls
 */

#pragma codeseg main_02_TEXT

extern "C" {
#include <dos.h>
#include "libs/sprite16/sprite16.h"
#include "th03/sprite16.hpp"

// Register variables; declare them as local ones and remove this block when
// porting away from 16-bit x86
#define sprite_offset_local (_DI)
#define putpos_left static_cast<int>(_DX)
#define putpos_right static_cast<int>(_BX)
#define clip_left static_cast<int>(_SI)
#define clip_right static_cast<int>(_CX)
#define put_w_words (_AL)
#define should_draw_column (_SI)

#define RESULT_IS_ZERO (_FLAGS & 0x40)

#define SETUP_VARS(left, screen_top, sprite_offset) \
	sprite_offset_local = sprite_offset; \
	putpos_left = left; \
	put_w_words = sprite16_put_w.v; \
	_BH ^= _BH; /* upper 8 bits of putpos_right */ \
	static_cast<char>(putpos_right) = put_w_words; \
	putpos_right <<= 4; \
	putpos_right += putpos_left; \
	clip_left = sprite16_clip_left; \
	clip_right = sprite16_clip_right;

#define CALL_PUT(left, screen_top, put_w_words, sprite_offset) \
	_AH = SPRITE16_PUT; \
	_DX = putpos_left; \
	_BX = screen_top; \
	static_cast<int>(_BX) >>= 1; \
	_AL = put_w_words; \
	_CX = sprite16_put_h; \
	_DI = sprite_offset_local; \
	geninterrupt(SPRITE16); \

#define CLIP_LEFT_PART \
	do { \
		putpos_left += 16; \
		put_w_words--; \
		if(RESULT_IS_ZERO) { \
			return; \
		} \
		sprite_offset_local += (16 / 8); \
	} while(putpos_left < clip_left);

#define CLIP_RIGHT_PART \
	do { \
		putpos_right -= 16; \
		put_w_words--; \
		if(RESULT_IS_ZERO) { \
			return; \
		} \
	} while(putpos_right >= clip_right);

void pascal sprite16_put(int left, int screen_top, int sprite_offset)
{
	SETUP_VARS(left, screen_top, sprite_offset);
	if(putpos_right < clip_right) {
		if(putpos_left >= clip_left) {
put:
			CALL_PUT(putpos_left, screen_top, put_w_words, sprite_offset_local);
			return;
		} else if(putpos_right < clip_left) {
			return;
		}
		// Sprite starts left of `clip_left`
		CLIP_LEFT_PART;
		goto put;
	} else if(putpos_left >= clip_right) {
		return;
	}
	// Sprite ends right of `clip_right`
	CLIP_RIGHT_PART;
	goto put;
}

#pragma codestring "\x90"

void pascal sprite16_putx(
	int left, int screen_top, int sprite_offset, sprite16_put_func_t func
)
{
	SETUP_VARS(left, screen_top, sprite_offset);
	if(putpos_right < clip_right) {
		if(putpos_left >= clip_left) {
put:
			_AH = SPRITE16_PUT;
			_DX = putpos_left;
			_BX = screen_top;
			static_cast<int>(_BX) >>= 1;
			_AL = put_w_words;
			_CX = sprite16_put_h;
			_DI = sprite_offset_local;
			while(1) {
				should_draw_column = func;
				geninterrupt(SPRITE16);
				should_draw_column--;
				if(RESULT_IS_ZERO) {
					return;
				}
				_BX += _CX;
				asm cmp bx, SPRITE16_RES_Y;
				asm jge end;
			}
		} else if(putpos_right < clip_left) {
			return;
		}
		// Sprite starts left of `clip_left`
		CLIP_LEFT_PART;
		goto put;
	} else if(putpos_left >= clip_right) {
		return;
	}
	// Sprite ends right of `clip_right`
	CLIP_RIGHT_PART;
	goto put;
end:
}

#pragma codestring "\x90"

void pascal sprite16_put_noclip(int left, int screen_top, int sprite_offset)
{
	// A completely useless SETUP_VARS variant without the `put_w_words`
	// assignment, which actually makes it incorrect...
	sprite_offset_local = sprite_offset;
	putpos_left = left;
	_BH ^= _BH; /* upper 8 bits of putpos_right */
	static_cast<char>(putpos_right) = put_w_words;
	putpos_right <<= 4;
	putpos_right += putpos_left;

	CALL_PUT(putpos_left, screen_top, sprite16_put_w.v, sprite_offset_local);
}

}
