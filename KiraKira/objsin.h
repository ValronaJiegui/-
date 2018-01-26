#pragma once

#include"GameL\SceneObjManager.h"

using namespace GameL;

class CObjSin : public CObj
{
public:
	CObjSin(){};
	~CObjSin(){};
	void Init();
	void Action();
	void Draw();

	float m_posture;

private:
	float m_px;
	float m_py;
	float m_vx;
	float m_vy;

	int m_ani_time;
	int m_ani_frame;
	int m_ani_time2;
	int m_ani_frame2;
	int tdkr_kouzi;
	int ton;
	int kit;
	int stop;
	int ka;
	int r;
	int houkou;

	float m_scroll;

	float m_speed_power;
	float m_ani_max_time;

		//block‚Æ‚ÌÕ“Ëó‘ÔŠm”F—p
	bool m_f;
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
};