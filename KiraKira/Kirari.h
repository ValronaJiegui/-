#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�����
class CObjKirari : public CObj
{
public:
	CObjKirari(float x, float y);
	~CObjKirari() {};
	void Init();
	void Action();
	void Draw();

private:
	int m_hp;

	float m_x;
	float m_y;
	float m_vx;
	float m_vy;

};