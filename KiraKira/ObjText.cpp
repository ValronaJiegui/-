//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjText.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjText::CObjText()
{
}


CObjText::~CObjText()
{
}

//�C�j�V�����C�Y
void CObjText::Init()
{
	m_time = 0;
}

//�A�N�V����
void CObjText::Action()
{
		if (Input::GetVKey(VK_RETURN) == true)
		{
			m_time -= 0.01f;
		}
}

//�h���[
void CObjText::Draw()
{
	float  c1[4] = { 1.0f,1.0f,1.0f,1.0f };
	float  cText[4] = { 0.0f,0.0f,0.0f,1.0f};
	float  cTextOut[4] = { 0.0f,0.0f,0.0f,1.0f + m_time };

	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 256.0f;
	src.m_bottom = 256.0f;

	dst.m_top = 0.0f;
	dst.m_left = -90.0f;
	dst.m_right = 880.0f;
	dst.m_bottom = 850.0f;

	Draw::Draw(3, &src, &dst, c1, 0.0f);


	//�G���^�[�L�[�������ăt�F�[�h�A�E�g
	if (Input::GetVKey(VK_RETURN) == true)
	{
		Font::StrDraw(L"�����Q�O�{���炢������b�ɂȂ肽���I�I", 30, 400, 32, cTextOut);
		Font::StrDraw(L"���̌�ɂ��܂ڂ������ɂ��ꂽ���I�I", 30, 450, 32, cTextOut);
	}
	else
	{
	Font::StrDraw(L"�����Q�O�{���炢������b�ɂȂ肽���I�I", 30, 400, 32, cText);
	Font::StrDraw(L"���̌�ɂ��܂ڂ������ɂ��ꂽ���I�I", 30, 450, 32, cText);
	}
}
