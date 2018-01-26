#pragma once

#include"GameL\SceneObjManager.h"

using namespace GameL;

class CObjTobasu : public CObj
{
public:
	CObjTobasu(){};
	~CObjTobasu(){};
	void Init();
	void Action();
	void Draw();

	float m_posture;
	bool doro;
	bool sibou;

private:
	float m_px;
	float m_py;
	float m_vx;
	float m_vy;

	int m_ani_time;
	int m_ani_frame;
	int m_ani_time2;
	int m_ani_frame2;
	int ton;
	int kit;
	int ka;
	int r;
	int houkou;
	int hataa;
	int hando;

	float m_scroll;

	bool aiueo;

	float m_speed_power;
	float m_ani_max_time;

	//blockÇ∆ÇÃè’ìÀèÛë‘ämîFóp
	bool m_f;
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
};