#pragma once
#include"GameL\SceneObjManager.h"
#include"GameHead.h"
#include"GameL\DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�^�C�g��
class CObjTitle :public CObj
{
public:
	CObjTitle() {};
	~CObjTitle() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
private:
	float m_mou_x;	//�}�E�X�̈ʒuX
	float m_mou_y;	//�}�E�X�̈ʒuY
	bool m_mou_l;	//�}�E�X�̍��{�^��
};