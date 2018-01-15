#pragma once

#include"GameL\SceneObjManager.h"

using namespace GameL;

class CObjNaihu : public CObj
{
public:
	CObjNaihu(float x, float y);
	~CObjNaihu(){};
	void Init();
	void Action();
	void Draw();
private:
	float m_px;
	float m_py;
	float m_vx;
	float m_vy;

	float m_posture;
	float m_scroll;

	int tada;
	int a;
	int m_ani_frame;
	int m_ani_time;

};