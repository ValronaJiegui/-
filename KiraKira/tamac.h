#pragma once

#include"GameL\SceneObjManager.h"

using namespace GameL;

class CObjTamac : public CObj
{
public:
	CObjTamac(float x, float y);
	~CObjTamac(){};
	void Init();
	void Action();
	void Draw();
private:
	float m_px;
	float m_py;
	float m_vx;
	float m_vy;

	int tada;
	int a;
	int ad;
	int m_ani_frame;
	int m_ani_time;
};