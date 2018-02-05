//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "Gamehead.h"
#include "ObjSynopsis.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjSynopsis::CObjSynopsis()
{
}


CObjSynopsis::~CObjSynopsis()
{
}

//�C�j�V�����C�Y
void CObjSynopsis::Init()
{
	flag = false;
	flag2 = false;
	flag3 = false;
	flag4 = false;
	flag5 = false;
	flag6 = false;
	flag7 = false;
	flag8 = false;
	m_mou_l = false;
	m_mou_r = false;
	m_f = true;
}

//�A�N�V����
void CObjSynopsis::Action()
{
	m_mou_l = Input::GetMouButtonL();
	m_mou_r = Input::GetMouButtonR();

	//���߂č��N���b�N�������ꂽ�Ƃ�
	if (m_mou_l == true && flag == false)
	{
		if (m_f == true)
		{
			flag = true;
			m_f = false;
		}
	}
	//2��ڂɍ��N���b�N�������ꂽ�Ƃ�
	else if (m_mou_l == true && flag == true && flag2 == false)
	{
		if (m_f == true)
		{
			flag2 = true;
			m_f = false;
		}
	}
	//3��ڂɍ��N���b�N�������ꂽ�Ƃ�
	else if (m_mou_l == true && flag2 == true && flag3 == false)
	{
		if (m_f == true)
		{
			flag3 = true;
			m_f = false;
		}
	}
	//4��ڂɍ��N���b�N�������ꂽ�Ƃ�
	else if (m_mou_l == true && flag3 == true && flag4 == false)
	{
		if (m_f == true)
		{
			flag4 = true;
			m_f = false;
		}
	}
	//5��ڂɍ��N���b�N�������ꂽ�Ƃ�
	else if (m_mou_l == true && flag4 == true && flag5 == false)
	{
		if (m_f == true)
		{
			flag5 = true;
			m_f = false;
		}
	}
	//6��ڂɍ��N���b�N�������ꂽ�Ƃ�
	else if (m_mou_l == true && flag5 == true && flag6 == false)
	{
		if (m_f == true)
		{
			flag6 = true;
			m_f = false;
		}
	}
	//7��ڂɍ��N���b�N�������ꂽ�Ƃ�
	else if (m_mou_l == true && flag6 == true && flag7 == false)
	{
		if (m_f == true)
		{
			flag7 = true;
			m_f = false;
		}
	}
	//8��ڂɍ��N���b�N�������ꂽ�Ƃ��i�X�e�[�W�Z���N�g�j
	else if (m_mou_l == true && flag7 == true && flag8 == false)
	{
		if (m_f == true)
		{
			Scene::SetScene(new CSceneStageSelect());
		}
	}
	else
	{
		m_f = true;
	}

	//�G���^�[�L�[�������ăX�e�[�W�Z���N�g��ʂɈڍs����
	if (m_mou_r == true)
	{
		Scene::SetScene(new CSceneStageSelect());
	}
}

//�h���[
void CObjSynopsis::Draw()
{
	float  c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float  cText[4] = { 0.0f,0.0f,0.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1010.0f;
	src.m_bottom = 1010.0f;

	//�w�i�ʒu�̐ݒ肵�`��
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(0, &src, &dst, c, 0.0f);



	if (flag == false)
	{
		Draw::LoadImageW(L"Synopsis rei2.png", 0, TEX_SIZE_1024);
		Font::StrDraw(L"���C", 130, 334, 40, cText);
		Font::StrDraw(L"�u�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�@", 120, 400, 22, cText);
		Font::StrDraw(L"�@�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�@", 120, 430, 22, cText);
		Font::StrDraw(L"�@�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�E�v", 120, 460, 22, cText);
	}
	else if (flag == true && flag2 == false)
	{
		Draw::LoadImageW(L"Synopsis rei.png", 0, TEX_SIZE_1024);
		Font::StrDraw(L"��l���̃��C�̓C���^�[�l�b�g��", 120, 400, 22, cText);
		Font::StrDraw(L"�z�M�҂Ƃ��Ċ������Ă��鍂�Z���B", 120, 430, 22, cText);
		Font::StrDraw(L"�����������ʂ�z�M�����Ă���悤���B", 120, 460, 22, cText);
	}
	else if (flag2 == true && flag3 == false)
	{
		Draw::LoadImageW(L"Synopsis reikirari2.png", 0, TEX_SIZE_1024);
		Font::StrDraw(L"�z�M�I����A���x�̓L�����̔z�M�����n�߂��B", 120, 400, 22, cText);
		Font::StrDraw(L"�L�����̓��C�̓���̔z�M�҂��B", 120, 430, 22, cText);
		Font::StrDraw(L"������...�H", 120, 460, 22, cText);
	}
	else if (flag3 == true && flag4 == false)
	{
		Draw::LoadImageW(L"Synopsis rei2kirari.png", 0, TEX_SIZE_1024);
		Font::StrDraw(L"���C", 130, 334, 40, cText);
		Font::StrDraw(L"�u...?�v", 120, 400, 22, cText);
		Font::StrDraw(L"�u�I�I�v", 120, 430, 22, cText);
	}
	else if (flag4 == true && flag5 == false)
	{
		Font::StrDraw(L"�L�����͐���̃��C�̔z�M���N���グ�΂��Ă����B", 120, 400, 22, cText);
		Font::StrDraw(L"���̌ヌ�C�͉��サ�Ă��܂��B", 120, 430, 22, cText);
	}
	else if (flag5 == true && flag6 == false)
	{
		Draw::LoadImageW(L"Synopsis.png", 0, TEX_SIZE_1024);
		Font::StrDraw(L"���΂炭�����o�߂�...", 120, 400, 22, cText);
	}
	else if (flag6 == true && flag7 == false)
	{
		Draw::LoadImageW(L"Synopsis rei.png", 0, TEX_SIZE_1024);
		Font::StrDraw(L"���C�̕�", 90, 334, 40, cText);
		Font::StrDraw(L"�u���O�̂����ŉƒ�͂߂��Ⴍ���Ⴞ�I", 120, 400, 22, cText);
		Font::StrDraw(L"�@�Z���܂Ńo���Ĉ��Y�d�b������ςȂ������A", 120, 430, 22, cText);
		Font::StrDraw(L"�@��Ђł����g�������B", 120, 460, 22, cText);
		Font::StrDraw(L"�@�ǂ����Ă����񂾁I�v", 120, 490, 22, cText);
	}
	else if (flag7 == true && flag8 == false)
	{
		Draw::LoadImageW(L"Synopsis rei2.png", 0, TEX_SIZE_1024);
		Font::StrDraw(L"���C�̓L�����ɕ��Q���邽�߂ɉw�܂Ō������悤���B", 120, 400, 22, cText);
	}
}