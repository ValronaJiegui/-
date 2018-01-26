#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"tobasu.h"

using namespace GameL;

void CObjTobasu::Init()
{
	m_px=450.0f;
	m_py=5.0f;
	m_vx=0.0f;
	m_vy=0.0f;

	m_posture=0.0f;//�E�����O�@�������P

	m_ani_time=0;//�؂���ʒu�ύX�ɂ����鎞�ԕϐ�
	m_ani_frame=0;//�؂���ʒu�̕ύX�̕ϐ�
	kit=0;//�U���J�n���A�O���t�B�b�N�ύX�ɂ����鎞�ԕϐ�
	ton=0;//�U���J�n���A�h���[�����o�����߂ɕK�v�ȕϐ�
	ka=0;//���g�̎��S�ϐ�
	r=0;
	hando=0;//�U����A���΂炭�̊ԍU�����o���Ȃ��Ȃ�ϐ�
	m_speed_power=0.5f;
	m_ani_max_time=8;

	doro=false;//�h���[�����o���Ă��锻��
	sibou=false;//���g�̎��S����

	m_ani_time2=0;//�U�����o���܂łɂ����鎞�Ԃ̕ϐ�
	m_ani_frame2=3;

	Hits::SetHitBox(this, m_px, m_py, 32, 64, ELEMENT_ENEMY, OBJ_TOBASU, 1);

	CObjLei*hero=(CObjLei*)Objs::GetObj(OBJ_LEI);//��l���̃��X�g�擾
	houkou=hero->GetX();//��l���̕������擾
}

void CObjTobasu::Action()
{

	//�X�N���[���̓����l���m��
	CObjBlock *block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll = block->GetScroll();

	if(doro==true)//�h���[�������S�����ꍇ�A�h���[���t�@�C������true��������B���̂Ƃ��A�h���[���o���Ɋւ���ϐ���S�ĂO�ɂ���
	{
		doro=false;
		m_ani_frame=0;
		kit=0;
		m_ani_time=0;
		m_ani_time2=0;
		hando=0;
	}

	if(kit==0)
	{
		m_ani_time2++;
	}

	if(kit==1){
		m_ani_time++;
	}


	if(m_ani_frame==8&&ton==2&&ka==0&&doro==false&&hando==0)
	{
		CObjDoron*obj=new CObjDoron(m_px+400.0f- m_scroll,100.0f);
		Objs::InsertObj(obj,OBJ_DORON,100);

		ton=0;
		hando=1;
	}

	if (m_ani_time2==40&&kit==0&&ka==0&&doro==false)
	{
		kit=1;
		ton=2;
	}

	if(m_ani_time>m_ani_max_time){
		m_ani_frame+=1;
		m_ani_time=0;
	}

	if(m_ani_frame==9){
		m_ani_frame=3;
		m_ani_time2=0;
		ton=0;
	}
	//�e�ۗp��hit box�X�V�p�|�C���^�[�擾
	CHitBox*hit = Hits::GetHitBox(this);
	if(ka==0){
		hit->SetPos(m_px + block->GetScroll(), m_py);//hitbox�̈ʒu���X�V
	}

	if(hit->CheckObjNameHit(OBJ_TAMA) != nullptr)
	{
		sibou=true;//�h���[���t�@�C���Ɏ��S����𑗂邽�߁A���S�t���O���I���ɂ���
		ka++;
		r=25;
		hit->SetPos(-256,-256);//hitbox�̈ʒu���X�V
	}

	if(ka>=1)
	{
		m_py-=10.0f;
		m_px+=4;
		r+=3;
		if(m_py==800){
			this->SetStatus(false);//���g�ɍ폜���߂��o��
		    Hits::DeleteHitBox(this);//���g�����L����hitbox�ɍ폜����B
		}
	}

	m_px+=m_vx;
	m_py+=m_vy;

	m_vx += -(m_vx*0.098);
	m_vy += 9.8 / (16.0f);

	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	int d;
	if (ka<=0) {
		pb->BlockHit(&m_px, &m_py, false,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
			&d
		);
	}
}

void CObjTobasu::Draw()
{
	int AniData[16]=
	{
		0,0,0,1,1,1,2,2,2
	};

	int KouData[8]={

	};

	int KouData2[8]={

	};

	float c[4]={1.0f,1.0f,1.0f,1.0f};

	RECT_F src;
	RECT_F dst;

	//����Ƃ肢��
	src.m_top =64.0f*3;
	src.m_left=0.0f+AniData[m_ani_frame]*64;
	src.m_right=64.0f+AniData[m_ani_frame]*64;
	src.m_bottom=64.0f*4;

	//�Ђ傤������

	//��l���̒l���擾
	CObjLei*hero = (CObjLei*)Objs::GetObj(OBJ_LEI);
	houkou = hero->GetX();

	dst.m_top =0.0f+m_py;
	dst.m_left=(64.0f - 64.0f*m_posture)+m_px+ m_scroll;
	dst.m_right=(64.0f*m_posture)+m_px+m_scroll;
	dst.m_bottom=64.0f+m_py;

	if (houkou>dst.m_right)//��l�������g�������ɂ���ꍇ
	{
		m_posture = 0;//�������E�����ɕύX
	}
	else if (houkou<dst.m_right) {
		m_posture = 1;//�������������ɕύX
	}

	if (dst.m_right <= -1500.0f)//��l�������g�������ɂ���ꍇ
	{
		sibou = true;//�h���[���t�@�C���Ɏ��S����𑗂邽�߁A���S�t���O���I���ɂ���
		hando = 1;
	}

	Draw::Draw(6,&src,&dst,c,r);
}