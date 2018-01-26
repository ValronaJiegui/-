//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"

#include"GameHead.h"
#include"ObjBlock.h"
#include"ObjLei.h"

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

	m_x1 = 0.0f;
	m_x2 = 1024.0f;

}

//�A�N�V����
void CObjBlock::Action()
{
	//��l���̈ʒu���擾
	CObjLei *test = (CObjLei*)Objs::GetObj(OBJ_LEI);
	hx = test->GetX();
	hy = test->GetY(); 
	//float MoveX = test->GetMoveX();

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
	/*
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
				if (m_map[i][j] != 3)
				{
					if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
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
								//test->SetVX(-test->GetVX()*0.1f);//�[VX*�����萔
								test->SetVXBound();

							}
							if (r > 45 && r < 135)
							{
								//��
								test->SetDown(true);
								test->SetY(y - 64.0f);//�u���b�N�̈ʒu�E��l���̕�
								//test->SetVY(0.0f);
								test->SetVYBound();
								test->SetJump();
								//��ނ�n���̃X�^�[�g�ƃS�[���̂ݕύX����
							   ///if (m_map[i][j] >= 2)
							   //	test->SetBT(m_map[i][j]);//�u���b�N�̗v�f(type)����l���ɓn��


							}
							if (r > 135 && r < 225)
							{
								//��
								test->SetLeft(true);
								test->SetX(x - 64.0f + (m_scroll));
								//test->SetVX(-test->GetVX()*0.1f);
								test->SetVXBound();

							}
							if (r > 225 && r < 315)
							{
								//��
								test->SetUp(true);//��l�����猩�āA��̕������Փ˂��Ă���
								test->SetY(+y + 66.0f);//�u���b�N�̈ʒu�{��l���̕�
								if (test->GetVY() < 0)
								{
									//test->SetVY(0.0f);
									test->SetVYBound();

								}
							}
						}
					}
				}
			}
		}

	}
	*/
}

//�h���[
void CObjBlock::Draw()
{
	//��l���̈ʒu���擾
	CObjLei *test = (CObjLei*)Objs::GetObj(OBJ_LEI);

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//�w�i�\��
	src.m_top = 0.0f;
	src.m_left = 0.0f ;
	src.m_right = 1024.0f ;
	src.m_bottom = 540.0f;

	///////////////////////////////////�w�i�̋�
	for (int i = 1; i < 5; i++)
	{
		dst.m_top = 0.0f;
		dst.m_left = 0.0f + (m_scroll / 2) + (m_x2*(i - 1));
		dst.m_right = 1024.0f + (m_scroll / 2) + (m_x2*i);
		dst.m_bottom = 600.0f;
		Draw::Draw(7, &src, &dst, c, 0.0f);
	}
	/////////////////////////////////////////

	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_scroll;
	dst.m_right = 0.0f + m_scroll;
	dst.m_bottom = 0.0f;
	Draw::Draw(1, &src, &dst, c, 0.0f);

	for (int i = 0; i < 7; i++)
	{
		float plus_x = 0.0f;
		for (int j = 0; j < i; j++)
		{
			plus_x += m_x2;
		}
		dst.m_top = 0.0f;
		dst.m_left = 0.0f  + plus_x + m_scroll;
		dst.m_right = 965.0f + plus_x + m_scroll;
		dst.m_bottom = 600.0f;
		Draw::Draw(1, &src, &dst, c, 0.0f);
	}
	
	/*
		dst.m_top = 0.0f;
		dst.m_left = 0.0f + m_scroll;
		dst.m_right = 965.0f + m_scroll;
		dst.m_bottom = 600.0f;
		Draw::Draw(1, &src, &dst, c, 0.0f);

		dst.m_top = 0.0f;
		dst.m_left = 965.0f + m_scroll;
		dst.m_right = 965.0f + m_x2 + m_scroll;
		dst.m_bottom = 600.0f;
		Draw::Draw(1, &src, &dst, c, 0.0f);

		dst.m_top = 0.0f;
		dst.m_left = 965.0f +965.0f+ m_scroll;
		dst.m_right = 965.0f+965.0f + m_x2 + m_scroll;
		dst.m_bottom = 600.0f;
		Draw::Draw(1, &src, &dst, c, 0.0f);

		dst.m_top = 0.0f;
		dst.m_left = 965.0f + 965.0f + 965.0f + m_scroll;
		dst.m_right = 965.0f + 965.0f + 965.0f + m_x2 + m_scroll;
		dst.m_bottom = 600.0f;
		Draw::Draw(1, &src, &dst, c, 0.0f);

		dst.m_top = 0.0f;
		dst.m_left = 965.0f + 965.0f + 965.0f + 965.0f + m_scroll;
		dst.m_right = 965.0f + 965.0f + 965.0f + 965.0f + m_x2 + m_scroll;
		dst.m_bottom = 600.0f;
		Draw::Draw(1, &src, &dst, c, 0.0f);

		dst.m_top = 0.0f;
		dst.m_left = 965.0f + 965.0f + 965.0f + 965.0f + 965.0f + m_scroll;
		dst.m_right = 965.0f + 965.0f + 965.0f + 965.0f + 965.0f + m_x2 + m_scroll;
		dst.m_bottom = 600.0f;

		dst.m_top = 0.0f;
		dst.m_left = 965.0f + 965.0f + 965.0f + 965.0f + 965.0f  + m_scroll;
		dst.m_right = 965.0f + 965.0f + 965.0f + 965.0f + 965.0f  + m_x2 + m_scroll;
		dst.m_bottom = 600.0f;
		Draw::Draw(1, &src, &dst, c, 0.0f);

		dst.m_top = 0.0f;
		dst.m_left = 965.0f + 965.0f + 965.0f + 965.0f + 965.0f + 965.0f  + m_scroll;
		dst.m_right = 965.0f + 965.0f + 965.0f + 965.0f + 965.0f + 965.0f  + m_x2 + m_scroll;
		dst.m_bottom = 600.0f;
		Draw::Draw(1, &src, &dst, c, 0.0f);
	*/


	//�}�b�v�`�b�v�ɂ��block�ݒu

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (m_map[i][j] > 0)
			{
				//�\���ʒu�̐ݒ�
				dst.m_top = i*64.0f;
				dst.m_left = j*64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0f;
				dst.m_bottom = dst.m_top + 64.0f;
				if (m_map[i][j] == 2)
				{
					BlockDraw(96.0f, 0.0f, &dst, c);
				}
				else if (m_map[i][j] == 3)
				{
					BlockDraw(0.0f, 32.0f, &dst, c);
				}
				else
				{
					BlockDraw(32.0f, 0.0f, &dst, c);

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

//BlockHit�֐�
//����1�@float*x1:������s��object��X�ʒu
//����2�@float*y2:������s��object��Y�ʒu
//����3�@bool	scroll_on:������s��object�̓X�N���[���̉e���^���邩�ǂ����itrue=�^����@false=�^���Ȃ��j
//����4�@bool*	up:�㉺���E�̏㕔���ɓ������Ă��邩������Ԃ�
//����5�@bool*	down:�㉺���E�̉������ɓ������Ă��邩������Ԃ�
//����6�@bool*	left:�㉺���E�̍������ɓ������Ă��邩������Ԃ�
//����7�@bool*	right:�㉺���E�̉E�����ɓ������Ă��邩������Ԃ�
//����8�@float*vx	:���E���莞�̔����ɂ��ړ������E�͂̒l��ς��ĕԂ�
//����9�@float*vy	:�㉺���莞�̔����ɂ��ړ������E�͂̒l��ς��ĕԂ�
//����10 int*bt		:���������莞�A����ȃu���b�N�̃^�C�v��Ԃ�
//������s��object�ƃu���b�N64*64����ŁA�����蔻��ƍ��E�����蔻����s��
//���̌��ʂ͈���4�`10�ɕԂ�
void CObjBlock::BlockHit(
	float*x, float*y, bool scroll_on,
	bool*up, bool*down, bool*left, bool*right,
	float*vx, float*vy, int*bt
)
{
	//�Փˏ�Ԋm�F�p�t���O�̏�����
	*up = false;
	*down = false;
	*left = false;
	*right = false;
	//����ł���block�̎�ނ̏�����
	*bt = 0;
	//m_map�̑S�v�f�ɃA�N�Z�X
	for (int i = 0; i<10; i++)
	{
		for (int j = 0; j<100; j++)
		{
			if (m_map[i][j]==1) {
				//�v�f�ԍ������W�ɕύX
				float bx = j*64.0f;
				float by = i*64.0f;
				//�X�N���[���̉e��
				float scroll = scroll_on ? m_scroll : 0;
				//�I�u�W�F�N�g�ƃu���b�N�̓����蔻��
				if ((*x + (-scroll) + 64.0f>bx) && (*x + (-scroll)<bx + 64.0f) && (*y + 64.0f>by) && (*y<by + 64.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float rvx = (*x + (-scroll)) - bx;
					float rvy = *y - by;
					//���������߂�
					float len = sqrt(rvx*rvx + rvy*rvy);
					//�p�x�����߂�
					float r = atan2(rvy, rvx);
					r = r*180.0f / 3.14f;
					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);
					//len��������̒����̂��Z���ꍇ����ɓ���
					if (len<88.0f) {
						//�p�x�ŏ㉺���E�𔻒�
						if ((r<45 && r>0) || r>315)
						{
							//�E
							*right = true;//�I�u�W�F�N�g�̍��̕������Փ˂��Ă���
							*x = bx + 64.0f + (scroll);//�u���b�N�̈ʒu�{��l���̕�
							*vx = -(*vx)*0.1f;//�[VX*�����W��
						}
						if (r>45 && r<135)
						{
							//��
							*down = true;//�I�u�W�F�N�g�̉��̕������Փ˂��Ă���
							*y = by - 64.0f;//�u���b�N�̈ʒu�[��l���̕�
											//��ނ�n���̃X�^�[�g�ƃS�[���̂ݕύX����
							if (m_map[i][j] >= 2)
								*bt = m_map[i][j];//�u���b�N�̗v�f�itype�j����l���ɓn��
							*vy = 0.0f;
						}
						if (r>135 && r<225)
						{
							//��
							*left = true;//�I�u�W�F�N�g�̉E�̕������Փ˂��Ă���
							*x = bx - 64.0f + (scroll);//�u���b�N�̈ʒu�[��l���̕�
							*vx = -(*vx)*0.1f;//�[VX*�����W��
						}
						if (r>225 && r<315)
						{
							//��
							*up = true;//��l���̏�̕������Փ˂��Ă���
							*y = by + 64.0f;//�u���b�N�̈ʒu�{��l���̕�
							if (*vy<0)
							{
								*vy = 0.0f;
							}
						}
					}
				}
			}
		}
	}
}