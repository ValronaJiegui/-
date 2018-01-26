#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"objsin.h"

using namespace GameL;

void CObjSin::Init()
{
	m_px=550.0f;
	m_py=260.0f;
	m_vx=0.0f;
	m_vy=0.0f;

	m_posture=1.0f;//�E����1�@������0

	m_ani_time=0;//���[�V�����ύX�p�̕ϐ�
	m_ani_frame=0;//�`��ύX�̂��߂̕ϐ�
	tdkr_kouzi=2;//�؂���ʒu�����̂��߂̕ϐ�
	kit=0;//�U���`��p�̕ϐ�
	ton=0;//���e�������Ă��邩�����Ă��Ȃ����̕ϐ�
	stop=0;//�U�������p�̕ϐ�
	ka=0;//���S����
	r=0;
	m_speed_power=0.5f;
	m_ani_max_time=8;

	m_ani_time2=0;
	m_ani_frame2=3;

	Hits::SetHitBox(this, m_px, m_py, 32, 64, ELEMENT_ENEMY, OBJ_BAKU, 1);

	CObjLei*hero=(CObjLei*)Objs::GetObj(OBJ_LEI);//��l���̃��X�g�擾
	houkou=hero->GetX();//��l���̂��ʒu���擾
}

void CObjSin::Action()
{
	//hit box�X�V�p�|�C���^�[�擾
	CHitBox*hit = Hits::GetHitBox(this);

	//�X�N���[���̓����l���m��
	CObjBlock *block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll = block->GetScroll();


	if(kit==0)//�������U�����I����Ă��邩��x���U�����Ă��Ȃ��ꍇ
	{
		m_ani_time2++;
	}

	if(kit==1){//�U�����n�܂����ꍇ
		m_ani_time++;
	}

	if(m_ani_frame==4&&ton==1)//���e�����������ꍇ
	{
		ton=2;
		kit=0;
	}

	if(m_ani_frame==8&&ton==2&&stop==0&&ka==0)//���g������ł��炸�A�U���������󂯂Ă����Ȃ��A���e�������Ă��ď������蓊���郂�[�V�����ɂȂ����Ƃ�
	{
		if(m_posture==0){//�������E�����̏ꍇ
		CObjTamac*obj=new CObjTamac(m_px+30.0f,m_py-10.0f);
		Objs::InsertObj(obj,OBJ_TAMAC,100);
		}

		else if(m_posture==1){//�������������̏ꍇ
		CObjTamac*obj=new CObjTamac(m_px-30.0f,m_py-10.0f);
		Objs::InsertObj(obj,OBJ_TAMAC,100);
		}

		ton=2;
		stop=1;
	}

	if (m_ani_time2==40&&kit==0&&ka==0)//�K��̎��ԂɒB�����ꍇ
	{
		if(ton==2){//���e���������Ă���ꍇ
			kit=1;
			m_ani_time2==0;
		}
	else{
		kit=1;
		ton=1;
		m_ani_time2==0;
		}
	}

	if(m_ani_time>m_ani_max_time){//�K��̎��ԂɂȂ����Ƃ�
		m_ani_frame+=1;
		m_ani_time=0;
	}

	if(m_ani_frame==10){//�U�����[�V�������S�ďI�������Ƃ��A�U���Ɋւ���ϐ���S��0�ɖ߂�
		m_ani_frame=0;
		m_ani_time2=0;
		kit=0;
		ton=0;
		stop=0;
	}

	if(hit->CheckObjNameHit(OBJ_TAMA) != nullptr)//�U������ɓ��������ꍇ
	{
		ka++;
		r=25;
		hit->SetPos(-256,-256);//hitbox����������
	}

	if (ka >= 1)
	{
		m_py -= 10.0f;
		m_px += 4;
		r += 3;
		if (m_py == 800) {
			this->SetStatus(false);//���g�ɍ폜���߂��o��
			Hits::DeleteHitBox(this);//���g�����L����hitbox�ɍ폜����B
		}
	}

	m_px+=m_vx;
	m_py+=m_vy;

	m_vx += -(m_vx*0.098);
	m_vy += 9.8 / (16.0f);

	if (ka == 0) {
		hit->SetPos(m_px + block->GetScroll(), m_py);//hitbox�̈ʒu���X�V
	}

	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	int d;
	if (ka <= 0) {
		pb->BlockHit(&m_px, &m_py, false,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
			&d
		);
	}

}

void CObjSin::Draw()
{
	int AniData[16]=
	{
		0,0,2,2,1,1,2,2,3,3
	};

	int KouData[8]={

	};

	int KouData2[8]={

	};

	float c[4]={1.0f,1.0f,1.0f,1.0f};

	RECT_F src;
	RECT_F dst;
	//����Ƃ肢��
	src.m_top =0.0f+tdkr_kouzi*64;
	src.m_left=0.0f+AniData[m_ani_frame]*64;
	src.m_right=64.0f+AniData[m_ani_frame]*64;
	src.m_bottom=64.0f+tdkr_kouzi*64;

	//�Ђ傤������

	//��l���̒l���擾
	CObjLei*hero = (CObjLei*)Objs::GetObj(OBJ_LEI);
	houkou = hero->GetX();

	dst.m_top = 0.0f + m_py;
	dst.m_left = (64.0f - 64.0f*m_posture) + m_px + m_scroll;
	dst.m_right = (64.0f*m_posture) + m_px + m_scroll;
	dst.m_bottom = 64.0f + m_py;

	if (houkou>dst.m_right)//��l�������g�������ɂ���ꍇ
	{
		m_posture = 0;//�������E�����ɕύX
	}

	else if (houkou<dst.m_right) {
		m_posture = 1;//�������������ɕύX
	}

	if (dst.m_right <= -300.0f)//��l�������g�������ɂ���ꍇ
	{
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//���g�����L����hitbox�ɍ폜����B
	}


	Draw::Draw(6, &src, &dst, c, r);
}