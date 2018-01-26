#pragma once

#include"GameL\SceneObjManager.h"

using namespace GameL;

class CObjSukima : public CObj
{
public:
	CObjSukima(float x, float y);
	~CObjSukima(){};
	void Init();
	void Action();
	void Draw();

	bool koukaku;
	int m_asd;
private:
	float m_px;
	float m_py;
	float m_vx;
	float m_vy;

	int tada;
	int ad;
	int a;
	int m_ani_frame;
	int m_ani_time;
	int r;

	int taim;
	int taim2;

	float m_scroll;
};