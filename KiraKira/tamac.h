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

	float x2;
	int lgo;

	int tada;
	int a;
	int ad;
	int m_ani_frame;
	int m_ani_time;

	float m_scroll;

	//blockとの衝突状態確認用
	bool m_f;
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
};