#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�^�C�g��
class CObjStageSelect :public CObj
{
public:
	CObjStageSelect() {};
	~CObjStageSelect() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[

					//�X�e�[�W�N���A������true
	bool CLEAR1;
	bool CLEAR2;

private:
	float m_mou_x;	//�}�E�X�̈ʒuX
	float m_mou_y;	//�}�E�X�̈ʒuY
	bool m_mou_l;	//�}�E�X�̍��{�^��


};