#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"tamac.h"

using namespace GameL;

CObjTamac::CObjTamac(float x,float y)
{
	m_px=x;
	m_py=y;
}

void CObjTamac::Init()
{

	m_vx=0.0f;
	m_vy=-8.0f;
	x2 = 0;
	tada=0;//着弾グラフィック判定用
	ad=0;

	lgo = false;

	a = 0;

	m_ani_frame=0;
	m_ani_time=0;
	//当たり判定用hitboxを作成
	Hits::SetHitBox(this, m_px, m_py, 32, 32, ELEMENT_ENEMY, OBJ_TAMAC, 1);

	CObjSin*nage = (CObjSin*)Objs::GetObj(OBJ_BAKU);//なげるくんのリスト取得
	a = nage->m_posture;//ナイフの方向を決めるための変数

}

void CObjTamac::Action()
{
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	int d;
	pb->BlockHit(&m_px, &m_py, false,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&d
	);

	//スクロールの動く値を確保
	CObjBlock *block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll = block->GetScroll();

	//弾丸用のhit box更新用ポインター取得
	CHitBox*hit = Hits::GetHitBox(this);

	if(a==0&&tada==0 && m_hit_up == false && m_hit_down == false && m_hit_left == false && m_hit_right == false){//向きが右向きなら
		m_vx += 0.3f;
		m_px += m_vx;
		m_vy += 9.8 / (16.0f);
	}

	else if(a==1&&tada==0 && m_hit_up == false && m_hit_down == false && m_hit_left == false && m_hit_right == false){//左なら
		m_vx -= 0.3f;
		m_px += m_vx;
		m_vy += 9.8 / (16.0f);
	}

	if(m_hit_up == true || m_hit_down == true || m_hit_left == true || m_hit_right == true ||hit->CheckElementHit(ELEMENT_PLAYER) == true)
	{
		m_vx=0;
		m_vy=0;
		tada=1;
	}

	if(tada==1){
		m_ani_time++;
	}

	if(m_ani_time>8)
	{
		m_ani_frame+=1;
		m_ani_time=0;
		Hits::SetHitBox(this, m_px+30, m_py, m_ani_frame*32, 48, ELEMENT_ENEMY, OBJ_TAMAC, 1);
		ad++;
	}

	if(m_ani_frame==4)
	{
		for(int i=0;i<5;i++){
			this->SetStatus(false);//自身に削除命令を出す
		    Hits::DeleteHitBox(this);//弾丸が所有するhitboxに削除する。
		}
		return;
	}

	hit->SetPos(m_px+m_scroll, m_py+20);//hitboxの位置を弾丸の位置に更新
	m_px+=m_vx;
	m_py+=m_vy;
}

void CObjTamac::Draw()
{

	CObjLei*hero = (CObjLei*)Objs::GetObj(OBJ_LEI);
	lgo = hero->GetX();

	int AniData[8]=
	{
		0,1,2,3
	};

	float c[4]={1.0f,1.0f,1.0f,1.0f};

	RECT_F src;
	RECT_F dst;
	//きりとりいち
	if(tada==1){//着弾した場合

		src.m_top =64.0f*6;
		src.m_left=0.0f+AniData[m_ani_frame]*64;
		src.m_right=64.0f+AniData[m_ani_frame]*64+(ad*32);
		src.m_bottom=64.0f*7;

		//ひょうじいち
		dst.m_top = 0.0f + m_py;
		dst.m_left = 0.0f + m_px + m_scroll;
		dst.m_right = 64.0f + m_px + (ad * 32) + m_scroll;
		dst.m_bottom = 64.0f + m_py;
		}

	else{
		src.m_top =64.0*7;
		src.m_left=64.0f*2;
		src.m_right=64.0f*3;
		src.m_bottom=64.0*8;

		//ひょうじいち
		dst.m_top = 0.0f + m_py;
		dst.m_left = 0.0f + m_px + m_scroll;
		dst.m_right = 64.0f + m_px + (ad * 32) + m_scroll;
		dst.m_bottom = 64.0f + m_py;
	}


	//dst.m_left += m_scroll;
	//dst.m_right += m_scroll;

	Draw::Draw(6,&src,&dst,c,0.0f);
}