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
	tada=0;//���e�O���t�B�b�N����p
	ad=0;
	m_ani_frame=0;
	m_ani_time=0;
	//�����蔻��phitbox���쐬
	Hits::SetHitBox(this, m_px, m_py, 32, 32, ELEMENT_ENEMY, OBJ_TAMAC, 1);
	CObjSin*sin=(CObjSin*)Objs::GetObj(OBJ_ENEMY);//���e���̃��X�g�擾
	a=sin->m_posture;//���e���̌������擾
}

void CObjTamac::Action()
{

	//�e�ۗp��hit box�X�V�p�|�C���^�[�擾
	CHitBox*hit = Hits::GetHitBox(this);

	if(a==0&&m_py<=520.0f&&tada==0){//�������E�����Ȃ�
	m_vx += 0.5f;
	m_px += m_vx;

	m_vx+=-(m_vx*0.098);
	
	m_vy+=9.8/(16.0f);
	}

	else if(a==1&&m_py<=520.0f&&tada==0){//���Ȃ�
	m_vx -= 0.5f;
	m_px += m_vx;

	m_vx+=-(m_vx*0.098);
	
	m_vy+=9.8/(16.0f);
	}

	if(m_py>=520.0f||hit->CheckElementHit(ELEMENT_PLAYER) == true)
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

	hit->SetPos(m_px+14, m_py+20);//hitbox�̈ʒu��e�ۂ̈ʒu�ɍX�V
	m_px+=m_vx;
	m_py+=m_vy;
}

void CObjTamac::Draw()
{
	int AniData[8]=
	{
		0,1,2,3
	};

	float c[4]={1.0f,1.0f,1.0f,1.0f};

	RECT_F src;
	RECT_F dst;
	//����Ƃ肢��
	if(tada==1){//���e�����ꍇ
		src.m_top =192.0f;
		src.m_left=0.0f+AniData[m_ani_frame]*64;
		src.m_right=64.0f+AniData[m_ani_frame]*64+(ad*32);
		src.m_bottom=256.0f;
		}

	else{
		src.m_top =128.0f;
		src.m_left=64.0f*5;
		src.m_right=64.0f*6;
		src.m_bottom=192.0f;
	}
	//�Ђ傤������
	dst.m_top =0.0f+m_py;
	dst.m_left=0.0f+m_px;
	dst.m_right=64.0f+m_px+(ad*32);
	dst.m_bottom=64.0f+m_py;

	Draw::Draw(3,&src,&dst,c,0.0f);
}