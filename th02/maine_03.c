/* ReC98
 * -----
 * Code segment #3 of TH02's MAINE.EXE
 */

#include "th02\th02.h"

char rank = RANK_NORMAL;
char unused_1 = 0;

resident_t *resident;
char unused_op_2_3;
char lives;
char bombs;
char unused_3;
char unused_4;
char unused_5;
long score;
int unused_6;

int pascal cfg_load(void)
{
	seg_t resident_sgm;

	file_ropen(CFG_FN);
	file_seek(offsetof(huuma_cfg_t, resident_sgm), 0);
	file_read(&resident_sgm, sizeof(resident_sgm));
	file_close();
	if(!resident_sgm) {
		return 0;
	}
	resident = MK_FP(resident_sgm, 0);
	lives = resident->rem_lives;
	bombs = resident->rem_bombs;
	rank = resident->rank;
	score = resident->score;
	return 1;
}
