#pragma once

#include"GameL\SceneObjManager.h"

using namespace GameL;

class CObjHero : public CObj
{
public:
	CObjHero(){};
	~CObjHero(){};
	void Init();
	void Action();
	void Draw();

	float m_posture;

	float GetX(){return m_px;}
	float GetY(){return m_py;}
	float GetVY(){return m_vy;}
	float GetVX(){return m_vx;}
	void SetX(float x){m_px=x;}
	void SetY(float y){m_py=y;}
	void SetVY(float vy){m_vy=vy;}
	void SetVX(float vx){m_vy=vx;}

	void SetUp(bool b){m_hit_up=b;}
	void SetDown(bool b){m_hit_down=b;}
	void SetLeft(bool b){m_hit_left=b;}
	void SetRight(bool b){m_hit_right=b;}
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
	int ka;
	int r;

	int muteki;
	int muteki_time;
	int mutekie;
	int yarare;

	int kougeki;
	int kougeki2;
	int kuukou;
	int tomeru;
	int m_ani_tate;

	int kira;
	int kira1;
	int kira2;
	int kiraa;
	int kiratime;

	int tobu;

	float m_speed_power;
	float m_ani_max_time;

	//blockÇ∆ÇÃè’ìÀèÛë‘ämîFóp
	bool m_f;
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
};