#pragma once
#include"GameL\SceneObjManager.h"
using namespace GameL;

class CObjGraphicTEST :public CObj
{
public:
	CObjGraphicTEST() {};
	~CObjGraphicTEST(){};
	void Init();	//�����ݒ�
	void Action();	//������e
	void Draw();	//�`����
private:
	float m_px;//�ʒuX
	float m_py;//�ʒuY
	float m_vx;//�ړ�X(�x�N�g��)
	float m_vy;//�ړ�Y(�x�N�g��)
	int m_time;
	int m_aruku;
	bool m_jump;
	bool m_dash;
	bool m_z_key;
};