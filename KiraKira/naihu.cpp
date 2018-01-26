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
	x2 = 0;
	stop = 0;
	tada=0;
	m_ani_frame=0;
	m_ani_time=0;
	m_posture=0;//ナイフの方向

	//当たり判定用hitboxを作成
	Hits::SetHitBox(this, m_px, m_py, 35, 32, ELEMENT_ENEMY, OBJ_ENEMY, 1);

	CObjNage*nage=(CObjNage*)Objs::GetObj(OBJ_NAIHU);//なげるくんのリスト取得
	a=nage->m_posture;//ナイフの方向を決めるための変数

}

void CObjNaihu::Action()
{

	//スクロールの動く値を確保
	CObjBlock *block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll = block->GetScroll();


	//弾丸用のhit box更新用ポインター取得
	CHitBox*hit = Hits::GetHitBox(this);

	if(a==0&&m_py<=520.0f&&tada==0){//なげるくんが左向きだった場合
	m_px += 6.0f;
	if(m_px==800){
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//弾丸が所有するhitboxに削除する。
	}
	}

	else if(a==1&&m_py<=520.0f&&tada==0){//なげるくんが右向きだった場合
	m_posture=1;
	m_px -= 6.0f;
	if(m_px==-80){
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//自身が所有するhitboxに削除する。
	}
	}

	int data[2] =
	{
		OBJ_LEI,
		OBJ_TAMA
	};

	for (int i=0;i<2;i++) {
		if (hit->CheckObjNameHit(data[i]) != nullptr)//主人公の攻撃判定に当たった場合
		{
			m_vx = 0;
			m_vy = 0;
			tada = 1;
			this->SetStatus(false);//自身に削除命令を出す
			Hits::DeleteHitBox(this);//自身が所有するhitboxに削除する。
			return;
		}
	}

	hit->SetPos(m_px + m_scroll, m_py + 20);//hitboxの位置を自身の位置に更新

}

void CObjNaihu::Draw()
{

	CObjLei*hero = (CObjLei*)Objs::GetObj(OBJ_LEI);
	stop = hero->GetX();

	int AniData[8]=
	{
		0,1,2,3
	};

	float c[4]={1.0f,1.0f,1.0f,1.0f};

	RECT_F src;
	RECT_F dst;
	//きりとりいち
	src.m_top =448.0f;
	src.m_left=0.0f+AniData[m_ani_frame]*64;
	src.m_right=64.0f+AniData[m_ani_frame]*64;
	src.m_bottom=512.0f;


	//ひょうじいち
	dst.m_top =0.0f+m_py;
	dst.m_left=(64.0f-64.0f*m_posture)+m_px + m_scroll;
	dst.m_right=(64.0f*m_posture)+m_px + m_scroll;
	dst.m_bottom=64.0f+m_py;

	Draw::Draw(6,&src,&dst,c,0.0f);
}