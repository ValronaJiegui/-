#pragma once
#include"GameL\SceneObjManager.h"
using namespace GameL;

class CObjLei :public CObj
{
public:
	CObjLei() {};
	~CObjLei(){};
	void Init();	//�����ݒ�
	void Action();	//������e
	void Draw();	//�`����
	float GetX() { return m_px; }
	float GetY() { return m_py; }
	float GetVX() { return m_vx; }
	float GetVY() { return m_vy; }
	void SetX(float x) { m_px = x; return; }
	void SetY(float y) { m_py = y; return; }
	void SetVX(float vx) { m_vx = vx; return; }
	void SetVY(float vy) { m_vy = vy; return; }

private:
	float m_px;//�ʒuX
	float m_py;//�ʒuY
	float m_vx;//�ړ�X(�x�N�g��)
	float m_vy;//�ړ�Y(�x�N�g��)
	int m_time;
	int m_aruku;
	int m_motion_walk;
	int m_motion_attack;
	bool m_jump;
	bool m_dash;
	bool m_z_key;
	bool m_f;//�W�����v����p
};