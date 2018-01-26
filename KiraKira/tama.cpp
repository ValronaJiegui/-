#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"tama.h"

using namespace GameL;

CObjTama::CObjTama(float x,float y)
{
	m_px=x;
	m_py=y;
}

void CObjTama::Init()
{

	m_vx=0.0f;
	m_vy=0.0f;
	tada=0;
	ad=0;
	r=0;
	m_posture=0;
	m_ani_frame=0;
	m_ani_time=0;
	koukaku=false;
	//当たり判定用hitboxを作成
	Hits::SetHitBox(this, m_px+20, m_py+20, 32, 32, ELEMENT_PLAYER, OBJ_TAMA, 1);
	CObjLei* hero = (CObjLei*) Objs::GetObj(OBJ_LEI);
	a = hero->GetMuki();

}

void CObjTama::Action()
{
	if(koukaku==true&&a==0)
	{
		m_vx += 0.5f;
		m_vy+=0.450f;
		r=330;
		m_posture=0;
	}

	else if(koukaku==true&&a==1)
	{
		m_vx -= 0.5f;
		m_vy+=0.450f;
		r=330;
		m_posture=1;
	}

	CHitBox*hit = Hits::GetHitBox(this);
	m_ani_time++;

	if(a==0&&m_py<=530.0f&&tada==0&&koukaku==false){
		m_vx += 0.5f;
		m_posture=0;
		r+=90;
	}

	else if(a==1&&m_py<=530.0f&&tada==0&&koukaku==false){
		m_vx -= 0.5f;
		m_posture=1;
		r+=90;
	}

	int data[3]=
	{
		OBJ_ENEMY,
		OBJ_NAIHU,
		OBJ_BAKU,
	};

	for(int i=0;i<3;i++){
		if(hit->CheckObjNameHit(data[i]) != nullptr)
		{
			this->SetStatus(false);//自身に削除命令を出す
			Hits::DeleteHitBox(this);//弾丸が所有するhitboxに削除する。
			return;
		}
	}

	if(m_ani_time>8)
	{
		m_ani_frame+=1;
		m_ani_time=0;
		if(m_ani_frame==2)
			m_ani_frame=0;
	}

	if(m_px==800.0f)
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//弾丸が所有するhitboxに削除する。
		return;
	}
	m_px+=m_vx;
	m_py+=m_vy;
	//弾丸用のhit box更新用ポインター取得
	hit->SetPos(m_px+20, m_py+20);//hitboxの位置を弾丸の位置に更新
}

void CObjTama::Draw()
{
	int AniData[8]=
	{
		0,1
	};

	float c[4]={1.0f,1.0f,1.0f,1.0f};

	RECT_F src;
	RECT_F dst;
	//きりとりいち
	src.m_top =128.0f;
	src.m_left=0.0f+AniData[m_ani_frame]*64;
	src.m_right=64.0f+AniData[m_ani_frame]*64;
	src.m_bottom=192.0f;

	//ひょうじいち
	dst.m_top =0.0f+m_py;
	dst.m_left=(64.0f*m_posture)+m_px;
	dst.m_right=(64-64.0f*m_posture)+m_px;
	dst.m_bottom=64.0f+m_py;

	Draw::Draw(5,&src,&dst,c,r);
}