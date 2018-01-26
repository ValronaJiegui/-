#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"sukima.h"

using namespace GameL;

CObjSukima::CObjSukima(float x,float y)
{
	m_px=x;
	m_py=y;
}

void CObjSukima::Init()
{

	m_vx=0.0f;
	m_vy=0.0f;
	tada=0;
	ad=0;
	r=0;

	m_ani_frame=0;
	m_ani_time=0;
	taim2 = 0;
	koukaku=false;

	taim=0;

	//�����蔻��phitbox���쐬
	Hits::SetHitBox(this, m_px-20, m_py, 64, 128, ELEMENT_ENEMY, OBJ_SUKIMA, 1);
}

void CObjSukima::Action()
{
	if (taim2 == 0) {
		CObjSyasyou*hero = (CObjSyasyou*)Objs::GetObj(OBJ_SYASYO);//��l���̃��X�g�擾
		a = hero->m_posture;//��l���̕������擾
		m_asd = a;
		taim2++;
	}

	//�X�N���[���̓����l���m��
	CObjBlock *block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll = block->GetScroll();

	CHitBox*hit = Hits::GetHitBox(this);
	m_ani_time++;

	taim++;

/*
	int data[3]=
	{
		OBJ_ENEMY,
		OBJ_NAIHU,
		OBJ_BAKU,
	};

	for(int i=0;i<3;i++){
		if(hit->CheckObjNameHit(data[i]) != nullptr)
		{
			this->SetStatus(false);//���g�ɍ폜���߂��o��
			Hits::DeleteHitBox(this);//�e�ۂ����L����hitbox�ɍ폜����B
			return;
		}
	}
	*/
	if(m_ani_frame==4)
		m_ani_frame=2;

	if(taim==100)
	{
		CObjDensya*obj=new CObjDensya(m_px+20,m_py);
		Objs::InsertObj(obj,OBJ_DNSYA,101);
	}

	if(m_ani_time>8&&taim<200)
	{
		m_ani_frame+=1;
		m_ani_time=0;
	}

	else if(m_ani_time>8&&taim>200){
		m_ani_frame-=1;
		m_ani_time=0;
	}

	if(m_ani_frame==0&&m_ani_time>=4&&taim>200){
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//�e�ۂ����L����hitbox�ɍ폜����B
		return;
	}

	m_px+=m_vx;
	m_py+=m_vy;
	//�e�ۗp��hit box�X�V�p�|�C���^�[�擾
	hit->SetPos(m_px + m_scroll, m_py);//hitbox�̈ʒu��e�ۂ̈ʒu�ɍX�V
}

void CObjSukima::Draw()
{
	int AniData[8]=
	{
		0,1,2,3,3
	};

	float c[4]={1.0f,1.0f,1.0f,1.0f};

	RECT_F src;
	RECT_F dst;
	//����Ƃ肢��
	src.m_top =128.0f;
	src.m_left=0.0f+AniData[m_ani_frame]*64;
	src.m_right=64.0f+AniData[m_ani_frame]*64;
	src.m_bottom=256.0f;

	//�Ђ傤������
	dst.m_top =0.0f+m_py;
	dst.m_left=(64.0f*m_asd)+m_px + m_scroll;
	dst.m_right=(64-64.0f*m_asd)+m_px + m_scroll;
	dst.m_bottom=128.0f+m_py;

	Draw::Draw(8,&src,&dst,c,r);
}