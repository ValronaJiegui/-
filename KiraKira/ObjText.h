#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�e�L�X�g
class CObjText:public CObj
{
public:
	CObjText();
	~CObjText();
	void Init();
	void Action();
	void Draw();

	float m_time;
private:
};

