#pragma once
#include"GameL\SceneObjManager.h"
using namespace GameL;

class CObjLei :public CObj
{
public:
	CObjLei() {};
	~CObjLei() {};
	void Init();	//�����ݒ�
	void Action();	//������e
	void Draw();	//�`����
	float GetX() { return m_px; }
	float GetY() { return m_py; }
	float GetVX() { return m_vx; }
	float GetVY() { return m_vy; }
	void SetX(float x) { m_px = x; return; }
	void SetY(float y) { m_py = y; return; }
	void SetVX(float vx) { m_vx = vx; return; }
	void SetVY(float vy) { m_vy = vy; return; }
	void SetBT(int t) { m_block_type = t; }

	void SetUp(bool b) { m_hit_up = b; }
	void SetDown(bool b) { m_hit_down = b; }
	void SetLeft(bool b) { m_hit_left = b; }
	void SetRight(bool b) { m_hit_right = b; }

	//�W�����s���O�ݒ�ݒu�֐��I
	//�����F
	//���C�̃W�����s���O�ϐ��̏�Ԃ�
	//�O������w�肷��Ƃ��Ɏg���܂��I(Block�̔��蓙)
	//
	//�����̂Ƃ��� true �� false ����͂����
	//���C��m_jumping�� 
	//�@�@�@�@���� true �� false ���w�肳��܂�
	void SetJumping(bool a) { if (a == true) { m_jumping = true; } else { m_jumping = false; } }

	//�o�E���h�֐��I
	//�����F
	//����(�ǂ�G�Ȃ�)�ɏՓ˂����Ƃ�
	//���C�𒵂˕Ԃ���
	//�߂荞�݂Ȃǂ�h���܂��I
	//��������
	void SetVXBound() { m_vx = -m_vx / 4; }
	void SetVYBound() { m_vy = -m_vy / 4; }

	//�W�����v�������֐��I
	//�O������W�����v�l��false�ɃZ�b�g�ł��܂�
	void SetJump() { m_jumping = false; m_jump = false; }

	int GetMuki() { return m_muki; }

	//�Z�b�gHP�֐��I
	//���C��HP�� �����̕��������Z���܂��I
	//�������_���[�W�̏ꍇ�A�������}�C�i�X�l�ɂ��Ă��������I
	void SetHP(int i) { m_HP += i; return; }


private:
	float m_px;//�ʒuX
	float m_py;//�ʒuY
	float m_vx;//�ړ�X(�x�N�g��)
	float m_vy;//�ړ�Y(�x�N�g��)

	bool houkou;//��l���̌�����m�邽�߂̃f�[�^

	int m_wtime;
	int m_motion_walk;
  //2�i�ȏ�W�����v���Ȃ��p
	bool m_key_z;
	bool m_f;      //�W�����v����
	bool z_flag;


	//block�Ƃ̏Փˏ�Ԋm�F�p
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	//����ł���block�̎�ނ��m�F�p
	int m_block_type;

	//��Ԕ���(�����A���V�Ȃ�)
	bool m_jump;
	bool m_dash;
	int m_muki;
	bool m_jumping;
	bool m_live_tama;

	//���G����i��e�������̊Ԗ��G�j
	int muteki;
	int muteki_time;
	int mutekie;
	bool hutobi;
	bool hantei;
	int xcount;

	//���[�V�����`��p�ϐ�
	int m_time;
	int m_motion_attack;

	//HP!
	int m_HP;
};