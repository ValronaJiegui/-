#pragma once

#include"GameL\SceneObjManager.h"

using namespace GameL;

class CObjHenemy : public CObj
{
public:
	CObjHenemy(){};
	~CObjHenemy(){};
	void Init();
	void Action();
	void Draw();

private:
	float m_px;
	float m_py;
	float m_vx;
	float m_vy;
	float m_posture;

	int ki;
	int ka;
	int r;
	int m_ani_time;
	int m_ani_frame;
	int m_ani_time2;
	int m_ani_frame2;
	int tdkr_kouzi;

	float m_scroll;
	float kyori;
	float m_speed_power;
	float m_ani_max_time;
};