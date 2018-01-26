#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"densya.h"

using namespace GameL;

CObjDensya::CObjDensya(float x,float y)
{
	m_px=x;
	m_py=y;
}

void CObjDensya::Init()
{

	m_vx=0.0f;
	m_vy=0.0f;
	tada=0;
	ad=0;
	r=0;
	m_posture=0;
	m_ani_frame=0;
	m_ani_time=0;
	taim2 = 0;

	biuga=0;

	koukaku=false;

	//当たり判定用hitboxを作成
	Hits::SetHitBox(this, m_px, m_py, 128, 64, ELEMENT_ENEMY, OBJ_DNSYA, 1);

}

void CObjDensya::Action()
{

	if (taim2 == 0) {
		CObjSyasyou*hero = (CObjSyasyou*)Objs::GetObj(OBJ_SYASYO);
		a = hero->m_posture;
		taim2++;
	}

	//スクロールの動く値を確保
	CObjBlock *block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll = block->GetScroll();

	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_px - 256 + biuga+m_scroll, m_py);//hitboxの位置を弾丸の位置に更新

	if(biuga<=256)
		biuga+=15;

	m_ani_time++;

	if(a==0&&m_py<=530.0f&&tada==0&&biuga>=256){
		m_px += 15.0f;
		m_posture=0;
	}

	else if(a==1&&m_py<=530.0f&&tada==0){
		m_px -= 15.0f;
		m_posture=1;
	}

	if(m_px>=800.0f-m_scroll|| m_px <= -800.0f + m_scroll)
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//弾丸が所有するhitboxに削除する。
		return;
	}
	m_px+=m_vx;
	m_py+=m_vy;
}

void CObjDensya::Draw()
{
	float c[4]={1.0f,1.0f,1.0f,1.0f};

	RECT_F src;
	RECT_F dst;
	//きりとりいち
	src.m_top =128.0f;
	src.m_left=256.0f;
	src.m_right=256.0f+biuga;
	src.m_bottom=256.0f;

	//ひょうじいち
	dst.m_top =0.0f+m_py;
	dst.m_left=(biuga-biuga*m_posture)+m_px + m_scroll;
	dst.m_right=(biuga*m_posture)+m_px + m_scroll;
	dst.m_bottom=128.0f+m_py;

	Draw::Draw(8,&src,&dst,c,r);
}