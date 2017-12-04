//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "SceneMain.h"
#include "ObjItemWing.h"
#include "ObjGraphicTEST.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

void CObjItemWing::Init()
{
	m_time = 0;
	Flag = false;
	animation = 0;
}

void CObjItemWing::Action()
{
	//��l���̍��W�̒l���m��
	CObjGraphicTEST *hero = (CObjGraphicTEST*)Objs::GetObj(OBJ_TEST);
	float m_x = hero->GetX();
	float m_y = hero->GetY();

	//�A�j���[�V�����������p
	m_time++;

	if (m_time >= 30)
	{
		animation += 1;
		if (animation >= 2)
			animation = 0;
		m_time = 0;
	}

	//�Q�b�g����i�e�X�g�p�j
	if (m_x <= 364.0f && m_x >= 280.0f)
	{
		if (m_y >= 450.0f && m_y <= 569.0f) {
			Flag = true;
		}
	}
}

void CObjItemWing::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؎�ʒu
	RECT_F dst;//�`�挳�\���ʒu

	//�؎�ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 192.0f + animation * 32;
	src.m_right = 224.0f + animation * 32;
	src.m_bottom = 32.0f;

	if (Flag == false) {
		//�\���ʒu�̐ݒ�
		dst.m_top = 485.0f;
		dst.m_left = 300.0f;
		dst.m_right = 364.0f;
		dst.m_bottom = 549.0f;
	}

	Draw::Draw(0, &src, &dst, c, 0.0f);
}