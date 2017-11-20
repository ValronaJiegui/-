#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjGraphicTEST.h"

using namespace GameL;

//�����ݒ�(�C�j�V�����C�Y)////////////////////
void CObjGraphicTEST::Init()
{
	m_px = 0.0f;
	m_py = 0.0f;
	m_vx = 0.0f;
	m_vy = 0.0f;
}
//������e(�A�N�V����)////////////////////////
void CObjGraphicTEST::Action()
{
	//�ړ�������(����)
	m_vx *= 0.75f;
	m_vy *= 0.75f;

	//�L�[���͂��ꂽ�Ƃ��̏���
	if (Input::GetVKey(VK_RIGHT) == true)
	{ 
		m_vx = +5.0f; 
		//���E�����������ꂽ���~
		if (Input::GetVKey(VK_LEFT) == true)
		{
			m_vx = 0.0f;
		}
	}
	if (Input::GetVKey(VK_LEFT) == true)
	{ 
		m_vx = -5.0f; 
		//���E�����������ꂽ���~
		if (Input::GetVKey(VK_RIGHT) == true)
		{
			m_vx = 0.0f;
		}
	}
	if (Input::GetVKey(VK_UP) == true)
	{
		m_vy += 5.0f;
	}

	//�ړ����ʒu�ɔ��f����
	m_px += m_vx;
	m_py += m_vy;
}
//�`����(�h���[)////////////////////////////
void CObjGraphicTEST::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؎�ʒu
	RECT_F dst;//�`�挳�\���ʒu

	//�؎�ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 8.0f;
	src.m_bottom = 8.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top	 =   0.0f + m_py;
	dst.m_left	 =   0.0f + m_px;
	dst.m_right	 = 32.0f + m_px;
	dst.m_bottom = 32.0f + m_py;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}