//�g�p����w�b�_�[�t�@�C��
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "Gamehead.h"
#include "ObjTitle.h"
#include "SceneMain.h"

#include "GameL\DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjTitle::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;

	m_mou_l = false;
}

//�A�N�V����
void CObjTitle::Action()
{
	bool NEW = false;
	bool LOAD = false;
	bool FINISH = false;

	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//�}�E�X�̈ʒu�m�F
	if (m_mou_x > 30 && m_mou_x < 512 && m_mou_y>293 && m_mou_y < 357&& m_mou_l == false)
			NEW = true;
	else if (m_mou_x > 30 && m_mou_x < 512 && m_mou_y>398 && m_mou_y < 462&& m_mou_l == false)
			LOAD = true;
	else if (m_mou_x > 30 && m_mou_x < 512 && m_mou_y>507 && m_mou_y < 571&& m_mou_l == false)
			FINISH = true;

	//�}�E�X�̃{�^���̏��
	m_mou_l = Input::GetMouButtonL();

	//_NEW_GAME_�������ꂽ�烁�C���ɐ؂�ւ���
	if (m_mou_l == true && NEW == true)
	{
		Scene::SetScene(new CSceneSynopsis());
	}
	//_LOAD_GAME_�������ꂽ��
	else if (m_mou_l == true && LOAD == true)
	{
		//�����ɏ���������
	}
	//_FINISH_GAME_�������ꂽ��Q�[�����I������
	else if (m_mou_l == true && FINISH == true)
	{
		exit(1);
	}

}

//�h���[
void CObjTitle::Draw()
{
	//�J�[�\��������̉ӏ��Ȃ�ւ��܂���
	if (m_mou_x > 30 && m_mou_x < 512 && m_mou_y>293 && m_mou_y < 357)
		Draw::LoadImageW(L"NEW GAME.png", 0, TEX_SIZE_1024);
	else if (m_mou_x > 30 && m_mou_x < 512 && m_mou_y>398 && m_mou_y < 462)
		Draw::LoadImageW(L"LOAD GAME.png", 0, TEX_SIZE_1024);
	else if (m_mou_x > 30 && m_mou_x < 512 && m_mou_y>507 && m_mou_y < 571)
		Draw::LoadImageW(L"FINISH GAME.png", 0, TEX_SIZE_1024);
	else
		Draw::LoadImageW(L"Title.png", 0, TEX_SIZE_1024);

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`���؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1010.0f;
	src.m_bottom = 1000.0f;

	//�w�i�ʒu�̐ݒ肵�`��
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}