#pragma once

#include"GameL\SceneObjManager.h"

using namespace GameL;

class CObjDoron : public CObj
{
public:
	CObjDoron(float x, float y);
	~CObjDoron(){};
	void Init();
	void Action();
	void Draw();

	bool hata;

private:
	float m_px;
	float m_py;
	float m_vx;
	float m_vy;

	float m_scroll;

	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	int tada;
	int a;
	int ad;
	int m_ani_frame;
	int m_ani_time;
	int ooo;
	int ki;
	int te;

	bool kuru;
	bool aaaa;
	bool ido;
};