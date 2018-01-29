#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "Kirari.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjKirari::CObjKirari(float x, float y)
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjKirari::Init()
{
	m_hp = 50;
	m_vx = 0.0f;
	m_vy = 0.0f;

	//当たり判定用HitBoxを生成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_BOSS_KIRARI, 1);
}

//アクション
void CObjKirari::Action()
{
	//ヒットボックスの内容を更新
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//弾丸と接触しているか判定
	if (hit->CheckObjNameHit(OBJ_TAMA) != nullptr)
	{
		m_hp -= 1;
	}

	if (m_hp <= 0)
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//自身が所有するhitboxに削除する。
	}

	//作成途中
}

//ドロー
void CObjKirari::Draw()
{

}