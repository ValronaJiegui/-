//�g�p����w�b�_�[�t�@�C��
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "Gamehead.h"
#include "ObjStageSelect.h"
#include "SceneMain.h"

#include "GameL\DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjStageSelect::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;

	m_mou_l = false;

	//�X�e�[�W���N���A���ꂽ��true�ɂ���
	//��@�X�e�[�W�P�N���A��CLEAR1=true
	bool CLEAR1 = false;
	bool CLEAR2 = false;
}

//�A�N�V����
void CObjStageSelect::Action()
{
	bool TITLE = false;
	bool STAGE1 = false;
	bool STAGE2 = false;

	//�N���A����
	if (0/*�X�e�[�W�P���N���A���Ă���ꍇ�̏����������ɏ���*/)
		CLEAR1 = true;
	if (0/*�X�e�[�W�Q���N���A���Ă���ꍇ�̏����������ɏ���*/)
		CLEAR2 = true;

	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	if (m_mou_x > 25 && m_mou_x < 259 && m_mou_y>505 && m_mou_y < 569 && m_mou_l == false)
	{
		TITLE = true;
	}

	else if (m_mou_x > 143 && m_mou_x < 243 && m_mou_y>157 && m_mou_y < 257 && m_mou_l == false)
	{
		STAGE1 = true;
	}

	else if (m_mou_x > 555 && m_mou_x < 655 && m_mou_y>157 && m_mou_y < 257 && CLEAR1 == true && m_mou_l == false)
	{
		STAGE2 = true;
	}

	//�}�E�X�̃{�^���̏��
	m_mou_l = Input::GetMouButtonL();

	//�^�C�g���������ꂽ��^�C�g���ɖ߂�
	if (m_mou_l == true && TITLE == true)
	{
		Scene::SetScene(new CSceneTitle());
	}

	//�X�e�[�W�P�������ꂽ�Ƃ�
	else if (m_mou_l == true && STAGE1 == true)
	{
		//�X�e�[�W�P�֍s�������������ɏ���
		Scene::SetScene(new CSceneMain());
		//CLEAR1 = true;
	}

	//�X�e�[�W�Q�������ꂽ�Ƃ�
	else if (m_mou_l == true && STAGE2 == true)
	{
		CLEAR2 = true;
	}
}

//�h���[
void CObjStageSelect::Draw()
{
	//�J�[�\��������̉ӏ��Ȃ�ւ��܂���
	//�X�e�[�W�Q���N���A���Ă���Ƃ�
	if (CLEAR2 == true)
	{
		if (m_mou_x > 25 && m_mou_x < 259 && m_mou_y>505 && m_mou_y < 569)
		{
			Draw::LoadImageW(L"STAGEB-TITLE.png", 0, TEX_SIZE_1024);
		}
		else if (m_mou_x > 143 && m_mou_x < 243 && m_mou_y>157 && m_mou_y < 257)
		{
			Draw::LoadImageW(L"STAGEB-1.png", 0, TEX_SIZE_1024);
		}
		else if (m_mou_x > 555 && m_mou_x < 655 && m_mou_y>157 && m_mou_y < 257)
		{
			Draw::LoadImageW(L"STAGEB-2.png", 0, TEX_SIZE_1024);
		}
		else if (m_mou_x > 294 && m_mou_x < 503 && m_mou_y>296 && m_mou_y < 419)
		{
			Draw::LoadImageW(L"STAGEB-B.png", 0, TEX_SIZE_1024);
		}
		else
			Draw::LoadImageW(L"STAGEB.png", 0, TEX_SIZE_1024);
	}
	//�X�e�[�W�P���N���A���Ă���Ƃ�
	else if (CLEAR1 == true)
	{
		if (m_mou_x > 25 && m_mou_x < 259 && m_mou_y>505 && m_mou_y < 569)
		{
			Draw::LoadImageW(L"STAGE2-TITLE.png", 0, TEX_SIZE_1024);
		}
		else if (m_mou_x > 143 && m_mou_x < 243 && m_mou_y>157 && m_mou_y < 257)
		{
			Draw::LoadImageW(L"STAGE2-1.png", 0, TEX_SIZE_1024);
		}
		else if (m_mou_x > 555 && m_mou_x < 655 && m_mou_y>157 && m_mou_y < 257)
		{
			Draw::LoadImageW(L"STAGE2-2.png", 0, TEX_SIZE_1024);
		}
		else
			Draw::LoadImageW(L"STAGE2.png", 0, TEX_SIZE_1024);
	}
	//�ǂ����N���A���Ă��Ȃ��Ƃ�
	else
	{
		if (m_mou_x > 25 && m_mou_x < 259 && m_mou_y>505 && m_mou_y < 569)
		{
			Draw::LoadImageW(L"STAGE1-TITLE.png", 0, TEX_SIZE_1024);
		}
		else if (m_mou_x > 143 && m_mou_x < 243 && m_mou_y>157 && m_mou_y < 257)
		{
			Draw::LoadImageW(L"STAGE1-1.png", 0, TEX_SIZE_1024);
		}
		else
			Draw::LoadImageW(L"STAGE1.png", 0, TEX_SIZE_1024);
	}
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