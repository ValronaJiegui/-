#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"kip.h"

using namespace GameL;

CObjKip::CObjKip(float x, float y)
{
	m_px = x;
	m_py = y;
}

void CObjKip::Init()
{

	m_vx = 0.0f;
	m_vy = 0.0f;
	tada = 0;
	ad = 0;
	r = 0;
	m_posture = 0;
	m_ani_frame = 0;
	m_ani_time = 0;

	Hits::SetHitBox(this, m_px, m_py, 32, 32, ELEMENT_ENEMY, OBJ_KIP, 1);

	//�����蔻��phitbox���쐬
	CObjSyasyou*hero = (CObjSyasyou*)Objs::GetObj(OBJ_SYASYO);//��l���̃��X�g�擾
	a = hero->m_posture;//��l���̕������擾

}

void CObjKip::Action()
{
	//�X�N���[���̓����l���m��
	CObjBlock *block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll = block->GetScroll();

	CHitBox*hit = Hits::GetHitBox(this);
	m_ani_time++;

	if (a == 0) {
		m_vx += 0.5f;
		m_posture = 0;
		r += 5;
	}

	else if (a == 1) {
		m_vx -= 0.5f;
		m_posture = 1;
		r += 5;
	}

	if (hit->CheckObjNameHit(OBJ_LEI) != nullptr)
	{
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//�e�ۂ����L����hitbox�ɍ폜����B
		return;
	}

	m_px += m_vx;
	m_py += m_vy;

	//�e�ۗp��hit box�X�V�p�|�C���^�[�擾
	hit->SetPos(m_px + m_scroll, m_py + 20);//hitbox�̈ʒu��e�ۂ̈ʒu�ɍX�V
}

void CObjKip::Draw()
{
	int AniData[8] =
	{
		0,1
	};

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;
	//����Ƃ肢��
	src.m_top = 64.0f;
	src.m_left = 192.0f;
	src.m_right = 256.0f;
	src.m_bottom = 128.0f;

	//�Ђ傤������
	dst.m_top = 0.0f + m_py;
	dst.m_left = (64.0f*m_posture) + m_px + m_scroll;
	dst.m_right = (64 - 64.0f*m_posture) + m_px + m_scroll;
	dst.m_bottom = 64.0f + m_py;

	Draw::Draw(8, &src, &dst, c, r);
}