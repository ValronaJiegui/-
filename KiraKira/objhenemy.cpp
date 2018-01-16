#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"objhenemy.h"

using namespace GameL;

void CObjHenemy::Init()
{
	m_px=500.0f;
	m_py=515.0f;
	m_vx=0.0f;
	m_vy=0.0f;
	ki=0;
	ka=0;
	r=0;
	m_posture=1.0f;//右向き０　左向き１
	m_ani_time=0;
	m_ani_frame=3;
	m_speed_power=0.5f;
	m_ani_max_time=8;

	m_ani_time2=0;
	m_ani_frame2=3;

	Hits::SetHitBox(this, m_px, m_py, 32, 64, ELEMENT_ENEMY, OBJ_HENEMY, 1);
}

void CObjHenemy::Action()
{
	//スクロールの動く値を確保
	CObjBlock *block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll = block->GetScroll();

	m_ani_time+=1;

	if(m_px==0.0f){
		ki=1;
		m_posture=0.0f;
	}
	else if(m_px==740.0f){
		ki=0;
		m_posture=1.0f;
	}

	if(ki==0){//仮組みではこうなっているが、本当はブロックの左側にぶつかった場合
		m_px-=4.0f;
	}
	else if(ki==1){//仮組みではこうなっているが、本当はブロックの右側にぶつかった場合
		m_px+=4.0f;
	}

	if(m_ani_time>m_ani_max_time){
		m_ani_frame+=1;
		m_ani_time=0;
	}

	if(m_ani_frame==4){
		m_ani_frame=0;
	}
	
	CHitBox*hit = Hits::GetHitBox(this);

	if (hit->CheckObjNameHit(OBJ_TAMA) != nullptr)
	{
		ka=1;
		hit->SetPos(-256,-256);//hitboxの位置を更新
	}

	if(ka==1)
	{
		r+=10;
		m_py-=10.0f;
		//摩擦
		m_vx+=-(m_vx*0.098);
		m_vy+=9.8/(16.0f);
		if(m_py==800){
			this->SetStatus(false);//自身に削除命令を出す
		    Hits::DeleteHitBox(this);//自身が所有するhitboxに削除する。
		}
	}

	m_px+=m_vx;
	m_py+=m_vy;

	if (ka == 0) {
		hit->SetPos(m_px + block->GetScroll(), m_py);//hitboxの位置を更新
	}
}

void CObjHenemy::Draw()
{
	int AniData[4]=
	{
		2,0,2,0
	};

	int KouData[4]={

	};

	int KouData2[4]={

	};

	float c[4]={1.0f,1.0f,1.0f,1.0f};

	RECT_F src;
	RECT_F dst;
	//きりとりいち
	src.m_top =0.0f;
	src.m_left=0.0f+AniData[m_ani_frame]*64;
	src.m_right=64.0f+AniData[m_ani_frame]*64;
	src.m_bottom=64.0f;

	//主人公の値を取得
	CObjLei*hero = (CObjLei*)Objs::GetObj(OBJ_LEI);
	kyori = hero->GetX();

	//ひょうじいち
	dst.m_top = 0.0f + m_py;
	dst.m_left = (64.0f - 64.0f*m_posture) + m_px + m_scroll;
	dst.m_right = (64.0f*m_posture) + m_px + m_scroll;
	dst.m_bottom = 64.0f + m_py;

	if (dst.m_right <= -300.0f)//主人公が自身よりも左にいる場合
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//自身が所有するhitboxに削除する。
	}

	Draw::Draw(6,&src,&dst,c,r);
}