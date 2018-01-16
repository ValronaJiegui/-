#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"objnage.h"

using namespace GameL;

void CObjNage::Init()
{
	m_px=350.0f;
	m_py=500.0f;
	m_vx=0.0f;
	m_vy=0.0f;
	m_posture=1.0f;//�E�����O�@�������P
	m_ani_time=0;
	m_ani_frame=0;
	tdkr_kouzi=0;//�؂���ʒu�ύX�p�̕ϐ�
	ka=0;//���S����
	r=0;
	a=0;
	stop=0;//�U���̐�������
	m_speed_power=0.5f;
	m_ani_max_time=8;
	Hits::SetHitBox(this, m_px, m_py, 32, 64, ELEMENT_ENEMY, OBJ_NAIHU, 1);

	m_ani_time2=0;
}

void CObjNage::Action()
{

	//�X�N���[���̓����l���m��
	CObjBlock *block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll = block->GetScroll();

	m_ani_time++;

	if(a==1)
	{
		m_ani_time2++;
	}

	if(ka==0&&a==0&&m_ani_time==50&&ka==0){
		a=1;//���[�V�����ύX�̂��߂̕ϐ����쓮
		m_ani_time=0;//�U�����邽�߂̃t���[����0�ɖ߂�
	}

	if(m_ani_frame==4&&stop==0&&ka==0)
	{
		if(m_posture==0){
		//�E�����i�C�t���쐬
		CObjNaihu*obj=new CObjNaihu(m_px+30.0f + m_scroll,m_py+3.0f);
		Objs::InsertObj(obj,OBJ_ENEMY,100);
		}

		else if(m_posture==1){
		//�������i�C�t���쐬
		CObjNaihu*obj=new CObjNaihu(m_px-30.0f + m_scroll,m_py-3.0f);
		Objs::InsertObj(obj,OBJ_ENEMY,100);
		}
		stop=1;//�U���𐧌����邽�߂Ƀt�B���^�[��������

	}

	CHitBox*hit = Hits::GetHitBox(this);

	if (hit->CheckObjNameHit(OBJ_TAMA) != nullptr)
	{
		ka=1;//���S������쐬
		Flag = 1;
		hit->SetPos(-256,-256);//hitbox�̈ʒu��e�ۂ̈ʒu�ɍX�V
	}

	if(ka==1)
	{
		r+=5;
		m_px+=3.0f;
		m_py-=5.0f;
		//���C
		m_vx+=-(m_vx*0.098);
		m_vy+=9.8/(16.0f);
		if(m_py==800){
			this->SetStatus(false);//���g�ɍ폜���߂��o��
		    Hits::DeleteHitBox(this);//���g�����L����hitbox�ɍ폜����B
		}
	}

	if(m_ani_time2>8){
		m_ani_frame++;
		m_ani_time2=0;
	}

	if(m_ani_frame==6)//���[�V�������I������ꍇ�A�U���Ɋւ���ϐ���0�ɖ߂�
	{
		m_ani_time2=0;
		m_ani_time=0;
		m_ani_frame=0;
		a=0;
		stop=0;
	}

	m_px+=m_vx;
	m_py+=m_vy;

	if (ka == 0) {
		hit->SetPos(m_px+m_scroll , m_py);//hitbox�̈ʒu��e�ۂ̈ʒu�ɍX�V
	}
}

void CObjNage::Draw()
{
	int AniData[6]=
	{
		0,0,1,1,2,2
	};

	int KouData[4]={

	};

	int KouData2[4]={

	};

	float c[4]={1.0f,1.0f,1.0f,1.0f};

	RECT_F src;
	RECT_F dst;
	//����Ƃ肢��
	src.m_top =64.0f+tdkr_kouzi*64;
	src.m_left=0.0f+AniData[m_ani_frame]*64;
	src.m_right=64.0f+AniData[m_ani_frame]*64;
	src.m_bottom=128.0f+tdkr_kouzi*64;
	//�Ђ傤������

	//��l���̒l���擾
	CObjLei*hero = (CObjLei*)Objs::GetObj(OBJ_LEI);
	houkou = hero->GetX();

	dst.m_top =0.0f+m_py;
	dst.m_left=(64.0f-64.0f*m_posture)+m_px+m_scroll;
	dst.m_right=(64.0f*m_posture)+m_px + m_scroll;
	dst.m_bottom=64.0f+m_py;

	if (houkou>dst.m_right)//��l�������g�������ɂ���ꍇ
	{
		m_posture = 0;//�������E�����ɕύX
	}
	else if(houkou<dst.m_right){
		m_posture = 1;//�������������ɕύX
	}

	if (dst.m_right<=-300.0f)//��l�������g�������ɂ���ꍇ
	{
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//���g�����L����hitbox�ɍ폜����B
	}

	Draw::Draw(6,&src,&dst,c,r);
}