#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"tamac.h"

using namespace GameL;

CObjTamac::CObjTamac(float x,float y)
{
	m_px=x;
	m_py=y;
}

void CObjTamac::Init()
{

	m_vx=0.0f;
	m_vy=-8.0f;
	x2 = 0;
	tada=0;//���e�O���t�B�b�N����p
	ad=0;

	lgo = false;

	a = 0;

	m_ani_frame=0;
	m_ani_time=0;
	//�����蔻��phitbox���쐬
	Hits::SetHitBox(this, m_px, m_py, 32, 32, ELEMENT_ENEMY, OBJ_TAMAC, 1);

	CObjSin*nage = (CObjSin*)Objs::GetObj(OBJ_BAKU);//�Ȃ��邭��̃��X�g�擾
	a = nage->m_posture;//�i�C�t�̕��������߂邽�߂̕ϐ�

}

void CObjTamac::Action()
{
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	int d;
	pb->BlockHit(&m_px, &m_py, false,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&d
	);

	//�X�N���[���̓����l���m��
	CObjBlock *block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll = block->GetScroll();

	//�e�ۗp��hit box�X�V�p�|�C���^�[�擾
	CHitBox*hit = Hits::GetHitBox(this);

	if(a==0&&tada==0 && m_hit_up == false && m_hit_down == false && m_hit_left == false && m_hit_right == false){//�������E�����Ȃ�
		m_vx += 0.3f;
		m_px += m_vx;
		m_vy += 9.8 / (16.0f);
	}

	else if(a==1&&tada==0 && m_hit_up == false && m_hit_down == false && m_hit_left == false && m_hit_right == false){//���Ȃ�
		m_vx -= 0.3f;
		m_px += m_vx;
		m_vy += 9.8 / (16.0f);
	}

	if(m_hit_up == true || m_hit_down == true || m_hit_left == true || m_hit_right == true ||hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		m_vx=0;
		m_vy=0;
		tada=1;
	}

	if(tada==1){
		m_ani_time++;
	}

	if(m_ani_time>8)
	{
		m_ani_frame+=1;
		m_ani_time=0;
		Hits::SetHitBox(this, m_px+30, m_py, m_ani_frame*32, 48, ELEMENT_ENEMY, OBJ_TAMAC, 1);
		ad++;
	}

	if(m_ani_frame==4)
	{
		for(int i=0;i<5;i++){
			this->SetStatus(false);//���g�ɍ폜���߂��o��
		    Hits::DeleteHitBox(this);//�e�ۂ����L����hitbox�ɍ폜����B
		}
		return;
	}

	hit->SetPos(m_px+m_scroll, m_py+20);//hitbox�̈ʒu��e�ۂ̈ʒu�ɍX�V
	m_px+=m_vx;
	m_py+=m_vy;
}

void CObjTamac::Draw()
{

	CObjLei*hero = (CObjLei*)Objs::GetObj(OBJ_LEI);
	lgo = hero->GetX();

	int AniData[8]=
	{
		0,1,2,3
	};

	float c[4]={1.0f,1.0f,1.0f,1.0f};

	RECT_F src;
	RECT_F dst;
	//����Ƃ肢��
	if(tada==1){//���e�����ꍇ

		src.m_top =64.0f*6;
		src.m_left=0.0f+AniData[m_ani_frame]*64;
		src.m_right=64.0f+AniData[m_ani_frame]*64+(ad*32);
		src.m_bottom=64.0f*7;

		//�Ђ傤������
		dst.m_top = 0.0f + m_py;
		dst.m_left = 0.0f + m_px + m_scroll;
		dst.m_right = 64.0f + m_px + (ad * 32) + m_scroll;
		dst.m_bottom = 64.0f + m_py;
		}

	else{
		src.m_top =64.0*7;
		src.m_left=64.0f*2;
		src.m_right=64.0f*3;
		src.m_bottom=64.0*8;

		//�Ђ傤������
		dst.m_top = 0.0f + m_py;
		dst.m_left = 0.0f + m_px + m_scroll;
		dst.m_right = 64.0f + m_px + (ad * 32) + m_scroll;
		dst.m_bottom = 64.0f + m_py;
	}


	//dst.m_left += m_scroll;
	//dst.m_right += m_scroll;

	Draw::Draw(6,&src,&dst,c,0.0f);
}