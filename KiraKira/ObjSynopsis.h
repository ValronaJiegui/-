#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F���炷��
class CObjSynopsis :public CObj
{
private:
	int m_time;
	bool m_mou_l;
	bool m_mou_r;
	bool m_f;
public:
	CObjSynopsis();
	~CObjSynopsis();
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
	bool flag;
	bool flag2;
	bool flag3;
	bool flag4;
	bool flag5;
	bool flag6;
	bool flag7;
	bool flag8;
};