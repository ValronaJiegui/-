#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "Kirari.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjKirari::CObjKirari(float x, float y)
{
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void CObjKirari::Init()
{
	m_hp = 50;
	m_vx = 0.0f;
	m_vy = 0.0f;

	//�����蔻��pHitBox�𐶐�
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_BOSS_KIRARI, 1);
}

//�A�N�V����
void CObjKirari::Action()
{
	//�q�b�g�{�b�N�X�̓��e���X�V
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//�e�ۂƐڐG���Ă��邩����
	if (hit->CheckObjNameHit(OBJ_TAMA) != nullptr)
	{
		m_hp -= 1;
	}

	if (m_hp <= 0)
	{
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//���g�����L����hitbox�ɍ폜����B
	}

	//�쐬�r��
}

//�h���[
void CObjKirari::Draw()
{

}