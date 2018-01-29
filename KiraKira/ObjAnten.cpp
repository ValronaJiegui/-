//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"

#include"GameHead.h"


CObjAnten::CObjAnten()
{

}
CObjAnten::~CObjAnten()
{

}

void CObjAnten::Init()
{
	Alpha = 1.0f;
	Kaishi= false;
}

void CObjAnten::Action()
{
	if (Kaishi == true && Alpha <= 1.0f)
	{
		Alpha += 0.1f;
	}
	if (Kaishi == false && Alpha >= 0.0f)
	{
		Alpha -= 0.1f;
	}
	if (Alpha < 0.0f)
	{
		Alpha = 0.0f;
	}
}

void CObjAnten::Draw()
{
	//�Ó]�p���w�i�ǂݍ���
	Draw::LoadImageW(L"Black.png", 9, TEX_SIZE_512);

	float c[4] = { 1.0f,1.0f,1.0f,Alpha };

	RECT_F src;//�`���؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؎�ʒu�ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 256.0f;
	src.m_bottom = 256.0f;

	//�\���ʒu�ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(9, &src, &dst, c, 0.0f);
}