#pragma once

#include"GameL\SceneObjManager.h"

using namespace GameL;

class CObjNage : public CObj
{
public:
	CObjNage(){};
	~CObjNage(){};
	void Init();
	void Action();
	void Draw();

	float m_posture;

private:
	float m_px;
	float m_py;
	float m_vx;
	float m_vy;

	int ki;
	int m_ani_time;
	int m_ani_frame;
	int m_ani_time2;
	int m_ani_frame2;
	int tdkr_kouzi;
	int houkou;
	int stop;
	int ka;
	int r;
	int a;

	float m_speed_power;
	float m_ani_max_time;
	float m_scroll;

	int Flag;

	//block‚Æ‚ÌÕ“Ëó‘ÔŠm”F—p
	bool m_f;
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
};