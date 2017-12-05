//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"

#include"GameHead.h"
#include"ObjBlock.h"
#include "ObjGraphicTEST.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;



CObjBlock::CObjBlock(int map[10][100])
{
	//�}�b�v�f�[�^���R�s�[
	memcpy(m_map, map, sizeof(int)*(10 * 100));

}

//�C�j�V�����C�Y
void CObjBlock::Init()
{
	m_scroll = 0.0f;

}

//�A�N�V����
void CObjBlock::Action()
{
	//��l���̈ʒu���擾
	CObjGraphicTEST *test = (CObjGraphicTEST*)Objs::GetObj(OBJ_TEST);
	hx = test->GetX();
	hy = test->GetY(); 

	//����X�N���[�����C��
	if (hx < 80)
	{
		test->SetX(80);//��l���̓��C���𒴂��Ȃ��悤�ɂ���
		m_scroll -= test->GetVX();//��l�����{�������ׂ����̒l��m_scroll�ɉ�����
	}

	//�O���X�N���[�����C��
	if (hx > 300)
	{
		test->SetX(300);
		m_scroll -= test->GetVX();
	}

	//��l���̏Փˏ�Ԋm�F�p�̃t���O�̏�����
	test->SetUp(false);
	test->SetDown(false);
	test->SetLeft(false);
	test->SetRight(false);

	//����ł���block�̎�ނ̏�����
	test->SetBT(0);

	//m_map�̑S�v�f�ɃA�N�Z�X
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (m_map[i][j] > 0)
			{
				//�v�f�ԍ������W�ɕύX
				float x = j*64.0f;
				float y = i*64.0f;

				//��l���ƃu���b�N�̓����蔻��
				if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f+0.0f> y) && (hy < y + 64.0f+0.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float vx = (hx + (-m_scroll)) - x;
					float vy = hy - y;

					//���������߂�
					float len = sqrt(vx*vx + vy*vy);

					//�p�x�����߂�
					float r = atan2(vy, vx);
					r = r*180.0f / 3.14f;

					if (r <= 0.0)
						r = abs(r);
					else
						r = 360.0f - abs(r);

					//len��������̒����̂��Z���ꍇ����ɓ���
					if (len < 88.0f) {

						//�p�x�ŏ㉺���E�𔻒�
					if ((r < 45 && r>0) || r > 315)
						{
							//�E
							test->SetRight(true);//��l���̍��̕������Փ˂��Ă���
							test->SetX(x + 64.0f + (m_scroll));//�u���b�N�̈ʒu�{��l���̕�
							test->SetVX(-test->GetVX()*0.1f);//�[VX*�����萔


						}
						if (r > 45 && r < 135)
						{
							//��
							test->SetDown(true);
							test->SetY(y - 64.0f);//�u���b�N�̈ʒu�E��l���̕�
												  //��ނ�n���̃X�^�[�g�ƃS�[���̂ݕύX����
							if (m_map[i][j] >= 2)
								test->SetBT(m_map[i][j]);//�u���b�N�̗v�f(type)����l���ɓn��
							test->SetVY(0.0f);

						}
						if (r > 135 && r < 225)
						{
							//��
							test->SetLeft(true);
							test->SetX(x - 64.0f + (m_scroll));
							test->SetVX(-test->GetVX()*0.1f);
						}
						if (r > 225 && r < 315)
						{
							//��
							test->SetUp(true);//��l�����猩�āA��̕��������Ƃ邵�Ă���
							test->SetY(y + 64.0f);//�u���b�N�̈ʒu�{��l���̕�
							if (test->GetVY() < 0)
							{
								test->SetVY(0.0f);
							}
						}
					}
				}
			}
		}

	}
}

//�h���[
void CObjBlock::Draw()
{
	//��l���̈ʒu���擾
	CObjGraphicTEST *test = (CObjGraphicTEST*)Objs::GetObj(OBJ_TEST);

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//�w�i�\��
	src.m_top = 0.0f;
	src.m_left = 0.0f + hx;
	src.m_right = 650.0f + hx;
	src.m_bottom = 900.0f;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 900.0f;
	dst.m_bottom = 600.0;
	Draw::Draw(1, &src, &dst, c, 0.0f);

	//�}�b�v�`�b�v�ɂ��block�ݒu

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (m_map[i][j] > 0)
			{
				//�\���ʒu�̐ݒ�
				dst.m_top = i*64.0f+96.0f;
				dst.m_left = j*64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0f;
				dst.m_bottom = dst.m_top + 64.0f + 0.0f;
				if (m_map[i][j] == 2)
				{
					//�X�^�[�g�u���b�N
					BlockDraw(320.0f + 64.0f, 0.0f, &dst, c);

				}
				else if (m_map[i][j] == 3)
				{
					//�S�[���u���b�N
					BlockDraw(320.0f + 64.0f, 64.0f, &dst, c);
				}
				else
				{
					BlockDraw(0.0f, 32.0f, &dst, c);
				}


			}
		}
	}




}
//BlockDrawMethod�֐�
//����1�@float x :���\�[�X�؂���ʒuX
//����2�@float y :���\�[�X�؂���ʒuY
//����3�@RECT_F*F dst�@:�`��ʒu
//����4�@float c[]:�J���[���
//�u���b�N��64�~64����`��p�B���\�[�X�؂���ʒu�̂�x�Ey��
//�ݒ�ł���

void CObjBlock::BlockDraw(float x, float y, RECT_F*dst, float c[])
{
	RECT_F src;
	src.m_top = y;
	src.m_left = x;
	src.m_right = src.m_left + 32.0f;
	src.m_bottom = src.m_top + 32.0f;


	//�`��
	Draw::Draw(2, &src, dst, c, 0.0f);
}