#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"doron.h"

using namespace GameL;

CObjDoron::CObjDoron(float x,float y)
{
	m_px=x;
	m_py=y;
}

void CObjDoron::Init()
{
	m_vx=-1.0f;//x���̉����x
	m_vy=0.0f;//y���̉����x
	tada=0;
	ad=0;
	a=0;
	ki=0;//���������񂾂��̔���
	te=0;//����傪���񂾂��̔���

	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	ooo=0;//�t���[��

	kuru=false;
	hata=false;
	ido=false;


	m_ani_frame=0;//�A�j���[�V�����̕`��
	m_ani_time=0;//�`���ύX����ϐ�

	//�����蔻��phitbox���쐬
	Hits::SetHitBox(this, m_px, m_py, 32, 32, ELEMENT_ENEMY, OBJ_DORON, 1);
}

void CObjDoron::Action()
{
	//�X�N���[���̓����l���m��
	CObjBlock *block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll = block->GetScroll();

	CObjLei*obj=(CObjLei*)Objs::GetObj(OBJ_LEI);//��l���̃��X�g
	CObjTobasu*toba=(CObjTobasu*)Objs::GetObj(OBJ_TOBASU);//�����̃��X�g

	aaaa=toba->sibou;//����傪���񂾂��ǂ������X�g�Ō���

	//hit box�X�V�p�|�C���^�[�擾
	CHitBox*hit = Hits::GetHitBox(this);
	if(aaaa!=true){							//����傪����ł��Ȃ��ꍇ
	if(obj!=nullptr&&ki==0)					//���g������ł��Ȃ��ꍇ
	{

	float ox=obj->GetX()-m_px - m_scroll;//��l����x�����擾
	float oy=obj->GetY()-m_py ;//��l����y�����擾
	float ar=atan2(-oy,ox)*180.0f/3.14;//�p�x�̌v�Z

	if(ar<0)
	{
		360-abs(ar);//��Βl�ɕύX
	}

	//���݂̊p�x�����
	float br=atan2(-m_vy,m_vx)*180.0f/3.14;

	if(br<0)
	{
		360-abs(br);//��Βl�ɕύX
	}

	if(ar-br>20&&ooo>=50)
	{
		//�ړ���������l���̕����ɂ���
		m_vx=cos(3.14/180*ar);
		m_vy=-sin(3.14/180*ar);
	}

	float r=3.14/180.0f;//�p�x1�x
	float rr=3.14/180.0f*5;//�p�x5�x

	if(m_px>=500 - m_scroll &&m_px<=600 - m_scroll &&ooo<=100&&ido==false||kuru==true&&ooo<=100&&ido==false){
		//�ړ�������5�x������
		ooo++;
		m_vx=m_vx*cos(rr)-m_vy*sin(rr);
		m_vy=m_vy*cos(rr)+m_vx*sin(rr);
		kuru=true;
	}

	if(ooo>50&&ar<br){
		//�ړ�������1�x������
		m_vx=m_vx*cos(r)-m_vy*sin(r);
		m_vy=m_vy*cos(r)+m_vx*sin(r);
		ido=true;
	}

	else if(ooo>50&&ar>br){
		//�ړ�������1�x������
		m_vx=m_vx*cos(-r)-m_vy*sin(-r);
		m_vy=m_vy*cos(-r)+m_vx*sin(-r);
	}

	}
	}

	else
	{
		CObjBlock *pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
		int d;

		pb->BlockHit(&m_px, &m_py, false,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
			&d
		);

		m_vx=0.0f;
		m_vy += 2 / (16.0f);
		hit->SetPos(-255, -255);
		te=1;
	}

	if(hit->CheckObjNameHit(OBJ_TAMA) != nullptr)//��l���̍U������Ɉ������������ꍇ
	{
		hata=true;//�����ɑ��邽�߂̃t���b�O���I��
		ki=1;//���g�����S����ɃI��
		hit->SetPos(-255, -255);//�����蔻���������΂�
	}

	if(ki==1)
	{
		m_ani_time++;
	}



	if(m_ani_time==8)
	{
		m_ani_frame++;
		m_ani_time=0;
	}


	if(m_ani_frame==4||m_px<-500||m_py<-500)
	{
		toba->doro=true;//�����Ɏ��g�����񂾃t���b�O��n��

		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//�e�ۂ����L����hitbox�ɍ폜����B
		return;
	}
	if(ki==0&&te==0){
		hit->SetPos(m_px + m_scroll, m_py+20);//hitbox�̈ʒu��e�ۂ̈ʒu�ɍX�V
		m_px+=m_vx*5.0f;
		m_py+=m_vy*5.0f;
	}

	if (te == 1)
	{
		m_px += m_vx;
		m_py += m_vy;
	}
}

void CObjDoron::Draw()
{

	if (m_hit_down == true && aaaa == true)//���g�݂̂��߂����Ȃ��Ă��邪�A�{���͒n�ʂɂԂ������ꍇ
	{
		CHitBox*hit = Hits::GetHitBox(this);
		hit->SetPos(-255, -255);
		m_ani_time++;
		te = 2;
	}

	int AniData[8]=
	{
		0,1,2,3
	};

	float c[4]={1.0f,1.0f,1.0f,1.0f};

	RECT_F src;
	RECT_F dst;

	if(ki==1||te==2){
		src.m_top =64.0f*6;
		src.m_left=0.0f+AniData[m_ani_frame]*64;
		src.m_right=64.0f+AniData[m_ani_frame]*64;
		src.m_bottom=64.0f*7;
	}

	else{
		src.m_top =64.0f*7;
		src.m_left=64.0f*4;
		src.m_right=64.0f*5;
		src.m_bottom=64.0f*8;
	}

	//�Ђ傤������
	dst.m_top =0.0f+m_py;
	dst.m_left=0.0f+m_px + m_scroll;
	dst.m_right=64.0f+m_px + m_scroll;
	dst.m_bottom=64.0f+m_py;

	Draw::Draw(6,&src,&dst,c,0.0f);
}