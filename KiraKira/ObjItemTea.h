#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�A�C�e��
class CObjItemTea : public CObj
{
public:
	CObjItemTea() {};
	~CObjItemTea() {};
	void Init() ;
	void Action() ;
	void Draw() ;

	void SetItemTea(float rx, float lx, float ty, float by);
private:
	int m_time;
	int animation;
	bool Flag;

	float top;
	float left;
	float right;
	float bottom;
};