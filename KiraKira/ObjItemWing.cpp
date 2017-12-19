//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "SceneMain.h"
#include "ObjItemWing.h"
#include "ObjLei.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

void CObjItemWing::Init()
{
	m_time = 0;
	Flag = false;
	animation = 0;

	//�e�X�g�p
	top = 485.0f;
	left = 300.0f;
	right = 364.0f;
	bottom = 549.0f;
}

void CObjItemWing::Action()
{
	//��l���̍��W�̒l���m��
	CObjLei *hero = (CObjLei*)Objs::GetObj(OBJ_LEI);
	float m_x = hero->GetX();
	float m_y = hero->GetY();

	//�X�N���[���̓����l���m��
	CObjBlock *block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll = block->GetScroll();

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
	if (m_x <= right - 50.0f + m_scroll && m_x >= left + m_scroll)
	{
		if (m_y >= top - 50.0f && m_y <= bottom) {
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
		dst.m_top = top;
		dst.m_left = left + m_scroll;
		dst.m_right = right + m_scroll;
		dst.m_bottom = bottom;
	}

	Draw::Draw(3, &src, &dst, c, 0.0f);
}

void CObjItemWing::SetItemWing(float rx, float lx, float ty, float by)
{
	top = ty;
	left = lx;
	right = rx;
	bottom = by;

	return;
}