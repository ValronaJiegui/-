#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"naihu.h"

using namespace GameL;

CObjNaihu::CObjNaihu(float x,float y)
{
	m_px=x;
	m_py=y;
}

void CObjNaihu::Init()
{

	m_vx=0.0f;
	m_vy=-8.0f;
	tada=0;
	m_ani_frame=0;
	m_ani_time=0;
	m_posture=0;//�i�C�t�̕���

	//�����蔻��phitbox���쐬
	Hits::SetHitBox(this, m_px, m_py, 35, 32, ELEMENT_ENEMY, OBJ_ENEMY, 1);

	CObjNage*nage=(CObjNage*)Objs::GetObj(OBJ_NAIHU);//�Ȃ��邭��̃��X�g�擾
	a=nage->m_posture;//�i�C�t�̕��������߂邽�߂̕ϐ�

}

void CObjNaihu::Action()
{
	//�e�ۗp��hit box�X�V�p�|�C���^�[�擾
	CHitBox*hit = Hits::GetHitBox(this);

	if(a==0&&m_py<=520.0f&&tada==0){//�Ȃ��邭�񂪍������������ꍇ
	m_vx += 0.3f;
	m_px += m_vx;
	if(m_px==800){
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//�e�ۂ����L����hitbox�ɍ폜����B
	}
	}

	else if(a==1&&m_py<=520.0f&&tada==0){//�Ȃ��邭�񂪉E�����������ꍇ
	m_posture=1;
	m_vx -= 0.3f;
	m_px += m_vx;
	if(m_px==-80){
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//���g�����L����hitbox�ɍ폜����B
	}
	}

	int data[2] =
	{
		OBJ_LEI,
		OBJ_TAMA
	};

	for (int i=0;i<2;i++) {
		if (hit->CheckObjNameHit(data[i]) != nullptr)//��l���̍U������ɓ��������ꍇ
		{
			m_vx = 0;
			m_vy = 0;
			tada = 1;
			this->SetStatus(false);//���g�ɍ폜���߂��o��
			Hits::DeleteHitBox(this);//���g�����L����hitbox�ɍ폜����B
			return;
		}
	}

	hit->SetPos(m_px+14, m_py+20);//hitbox�̈ʒu�����g�̈ʒu�ɍX�V
}

void CObjNaihu::Draw()
{
	int AniData[8]=
	{
		0,1,2,3
	};

	float c[4]={1.0f,1.0f,1.0f,1.0f};

	RECT_F src;
	RECT_F dst;
	//����Ƃ肢��
	src.m_top =448.0f;
	src.m_left=0.0f+AniData[m_ani_frame]*64;
	src.m_right=64.0f+AniData[m_ani_frame]*64;
	src.m_bottom=512.0f;

	//�Ђ傤������
	dst.m_top =0.0f+m_py;
	dst.m_left=(64.0f-64.0f*m_posture)+m_px;
	dst.m_right=(64.0f*m_posture)+m_px;
	dst.m_bottom=64.0f+m_py;

	Draw::Draw(6,&src,&dst,c,0.0f);
}