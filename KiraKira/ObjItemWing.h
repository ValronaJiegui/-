#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "ObjLei.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�A�C�e��
class CObjItemWing : public CObj
{
public:
	CObjItemWing() {};
	~CObjItemWing() {};
	void Init() ;
	void Action() ;
	void Draw() ;
	bool GetFlag() { return Flag; }
private:
	int m_time;
	int animation;
	bool Flag;
};