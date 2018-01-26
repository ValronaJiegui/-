#pragma once
#pragma once

#include"GameL\SceneObjManager.h"

using namespace GameL;

class CObjKip : public CObj
{
public:
	CObjKip(float x, float y);
	~CObjKip() {};
	void Init();
	void Action();
	void Draw();

	bool koukaku;
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

	int m_posture;
	float m_scroll;
};