char boss_phase_timed_out = 0;

void pascal near boss_reset(void)
{
	boss_update = nullsub_1;
	boss_fg_render = nullfunc_near;
#if GAME == 5
	boss_custombullets_render = nullfunc_near;
#endif
	boss.phase = 0;
	boss.mode = 0;
	boss.mode_change = 0;
	boss.phase_frame = 0;
	boss.pos.velocity.set(0, 0);
	boss.damage_this_frame = 0;
	explosions_small_reset();
	boss_phase_timed_out = 1;
}
