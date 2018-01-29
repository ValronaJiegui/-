//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "Gamehead.h"
#include "ObjGameOver.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjGameOver::Init()
{
	m_time = 0;
}

//�A�N�V����
void CObjGameOver::Action()
{
	m_time++;

	//�����_�ŗp
	if (m_time == 30)
	{
		Draw::LoadImageW(L"GAME OVER2.png", 0, TEX_SIZE_1024);
	}
	if (m_time == 60)
	{
		Draw::LoadImageW(L"GAME OVER.png", 0, TEX_SIZE_1024);
		m_time = 0;
	}

	//�G���^�[�L�[�������ăX�e�[�W�Z���N�g��ʂɈڍs����
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneStageSelect());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//�h���[
void CObjGameOver::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`���؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1020.0f;
	src.m_bottom = 1020.0f;

	//�w�i�ʒu�̐ݒ肵�`��
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}