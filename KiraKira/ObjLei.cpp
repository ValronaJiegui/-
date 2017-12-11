#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjLei.h"

using namespace GameL;

//�����ݒ�(�C�j�V�����C�Y)////////////////////
void CObjLei::Init()
{
	m_px = 0.0f;
	m_py = 0.0f;
	m_vx = 0.0f;
	m_vy = 10.0f;
	m_time = 0;
	m_motion_walk = 0;
	m_motion_attack = 0;
	m_jump = false;
	m_dash = false;
	m_key_z = false;
	m_f = false;
}
//������e(�A�N�V����)////////////////////////
void CObjLei::Action()
{
	//������ꂽ�Ƃ��A�t���O�𗧂Ă�
	CObjItemWing *wing = (CObjItemWing*)Objs::GetObj(OBJ_ITEM_WING);
	bool Flag = wing->GetFlag();

	if (m_py >= 480.0f) {
		m_vy = -9.8f / (16.0f);
		m_jump = false;
	}

	//�L�[���͂��ꂽ�Ƃ��̏���
	if (Input::GetVKey(VK_RIGHT) == true)
	{ 
		m_vx = 5.0f;

		//���E�����������ꂽ���~
		if (Input::GetVKey(VK_LEFT) == true)
		{
			m_vx = 0.0f;
		}
		if (Input::GetVKey(VK_SHIFT) == true)
		{
			m_vx += 4.0f;
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
		if (Input::GetVKey(VK_SHIFT) == true)
		{
			m_vx = -4.0f;
		}
	}
	if (Input::GetVKey(VK_UP) == true)
	{
		if (m_f == false)
		{
			if (Flag == false)
			{
				if (m_jump == false) {
					m_vy = -10.0f;
					m_jump = true;
				}
			}
			else
			{
				if (m_jump == false)
				{
					m_vy = -25.0f;
					m_jump = true;
				}
			}
			m_f = true;
		}
	}
	else
	{
		m_f = false;
	}

	if (Flag == true && m_jump == true)
	{
		if(m_time <= 40)
			m_time++;
		if (m_time >= 40 && m_time <= 200)
			if (Input::GetVKey(VK_UP) == true)
			{
				m_vy = 0;
				m_time++;
			}
	}
	else
		m_time = 0;

	m_vx += -(m_vx*0.098f);
	m_vy += 9.8f / (16.0f);

	//�ړ����ʒu�ɔ��f����
	m_px += m_vx;
	m_py += m_vy;
	if (m_vy == 0)
	{
		m_jump = false;
	}

	if (m_key_z == true)
	{
		if (m_time % 3 == 0)
		{
			m_time = 0;
			m_motion_attack++;
			if (m_motion_attack == 5)
			{
				m_motion_attack = 0;
				m_key_z = false;
			}
		}
	}

	if (m_time % 8 == 0)
	{
		m_time = 0;
		m_motion_walk++;
		if (m_motion_walk == 4)
		{
			m_motion_walk = 0;
		}
	}
}
//�`����(�h���[)////////////////////////////
void CObjLei::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؎�ʒu
	RECT_F dst;//�`�挳�\���ʒu

	//�؎�ʒu�̐ݒ�	
	if (m_key_z == true)
	{
		//�y�L�[
		src.m_top = 96.0f;
		src.m_left = 0.0f + (m_motion_attack * 32);
		src.m_right = 32.0f + (m_motion_attack * 32);;
		src.m_bottom = 128.0f;
	}
	else if (m_jump == true|| Input::GetVKey(VK_RIGHT) == true)
	{
		//�W�����v�{�E
		src.m_top = 0.0f;
		src.m_left = 128.0f;
		src.m_right = 160.0f;
		src.m_bottom = 32.0f;
	}	
	else if (m_jump == true || Input::GetVKey(VK_LEFT) == true)
	{
		//�W�����v�{��
		src.m_top = 0.0f;
		src.m_left = 160.0f;
		src.m_right = 128.0f;
		src.m_bottom = 32.0f;
	}
	else if (Input::GetVKey(VK_RIGHT) == true)
	{
		//�E�L�[
		src.m_top = 0.0f;
		src.m_left = 0.0f + (m_motion_walk * 32.0f);
		src.m_right = 32.0f + (m_motion_walk * 32.0f);
		src.m_bottom = 32.0f;
	}
	else if (Input::GetVKey(VK_LEFT) == true)
	{
		//���L�[
		src.m_top = 0.0f;
		src.m_left = 32.0f + (m_motion_walk * 32.0f);
		src.m_right = 0.0f + (m_motion_walk * 32.0f);
		src.m_bottom = 32.0f;
	}

	else
	{
		//�L�[�Ȃ�(�~�܂�)
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 32.0f;
		src.m_bottom = 32.0f;
	}


	//�\���ʒu�̐ݒ�
	dst.m_top	 =   0.0f + m_py;
	dst.m_left	 =   0.0f + m_px;
	dst.m_right	 = 64.0f + m_px;
	dst.m_bottom = 64.0f + m_py;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}

/*
��肽���������X�g
���E�ړ����قڊ����ł�
�W�����v������ɂ܂����
���n���ł��Ă܂���
�_�b�V������
�U�����r���ł�

*/