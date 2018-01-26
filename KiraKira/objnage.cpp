#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"objnage.h"

using namespace GameL;

void CObjNage::Init()
{
	m_px=350.0f;
	m_py=500.0f;
	m_vx=0.0f;
	m_vy=0.0f;
	m_posture=1.0f;//右向き０　左向き１
	m_ani_time=0;
	m_ani_frame=0;
	tdkr_kouzi=0;//切り取り位置変更用の変数
	ka=0;//死亡判定
	r=0;
	a=0;
	stop=0;//攻撃の制限判定
	m_speed_power=0.5f;
	m_ani_max_time=8;
	Hits::SetHitBox(this, m_px, m_py, 32, 64, ELEMENT_ENEMY, OBJ_NAIHU, 1);

	m_ani_time2=0;
}

void CObjNage::Action()
{

	//スクロールの動く値を確保
	CObjBlock *block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll = block->GetScroll();

	m_ani_time++;

	if(a==1)
	{
		m_ani_time2++;
	}

	if(ka==0&&a==0&&m_ani_time==50&&ka==0){
		a=1;//モーション変更のための変数を作動
		m_ani_time=0;//攻撃するためのフレームを0に戻す
	}

	if(m_ani_frame==4&&stop==0&&ka==0)
	{
		if(m_posture==0){
		//右向きナイフを作成
		CObjNaihu*obj=new CObjNaihu(m_px+30.0f + m_scroll,m_py+3.0f);
		Objs::InsertObj(obj,OBJ_ENEMY,100);
		}

		else if(m_posture==1){
		//左向きナイフを作成
		CObjNaihu*obj=new CObjNaihu(m_px-30.0f + m_scroll,m_py-3.0f);
		Objs::InsertObj(obj,OBJ_ENEMY,100);
		}
		stop=1;//攻撃を制限するためにフィルターをかける

	}

	CHitBox*hit = Hits::GetHitBox(this);

	if (hit->CheckObjNameHit(OBJ_TAMA) != nullptr)
	{
		ka=1;//死亡判定を作成
		Flag = 1;
		hit->SetPos(-256,-256);//hitboxの位置を弾丸の位置に更新
	}

	if(ka==1)
	{
		r+=5;
		m_px+=3.0f;
		m_py-=5.0f;
		//摩擦
		m_vx+=-(m_vx*0.098);
		m_vy+=9.8/(16.0f);
		if(m_py==800){
			this->SetStatus(false);//自身に削除命令を出す
		    Hits::DeleteHitBox(this);//自身が所有するhitboxに削除する。
		}
	}

	if(m_ani_time2>8){
		m_ani_frame++;
		m_ani_time2=0;
	}

	if(m_ani_frame==6)//モーションが終わった場合、攻撃に関する変数を0に戻す
	{
		m_ani_time2=0;
		m_ani_time=0;
		m_ani_frame=0;
		a=0;
		stop=0;
	}

	m_px+=m_vx;
	m_py+=m_vy;

	if (ka == 0) {
		hit->SetPos(m_px + block->GetScroll(), m_py);//hitboxの位置を更新
	}
}

void CObjNage::Draw()
{
	int AniData[6]=
	{
		0,0,1,1,2,2
	};

	int KouData[4]={

	};

	int KouData2[4]={

	};

	float c[4]={1.0f,1.0f,1.0f,1.0f};

	RECT_F src;
	RECT_F dst;
	//きりとりいち
	src.m_top =64.0f+tdkr_kouzi*64;
	src.m_left=0.0f+AniData[m_ani_frame]*64;
	src.m_right=64.0f+AniData[m_ani_frame]*64;
	src.m_bottom=128.0f+tdkr_kouzi*64;
	//ひょうじいち

	//主人公の値を取得
	CObjLei*hero = (CObjLei*)Objs::GetObj(OBJ_LEI);
	houkou = hero->GetX();

	dst.m_top =0.0f+m_py;
	dst.m_left=(64.0f-64.0f*m_posture)+m_px + m_scroll;
	dst.m_right=(64.0f*m_posture)+m_px + m_scroll;
	dst.m_bottom=64.0f+m_py;

	if (houkou>dst.m_right)//主人公が自身よりも左にいる場合
	{
		m_posture = 0;//向きを右向きに変更
	}
	else if(houkou<dst.m_right){
		m_posture = 1;//向きを左向きに変更
	}

	if (dst.m_right<=-300.0f)//主人公が自身よりも左にいる場合
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//自身が所有するhitboxに削除する。
	}

	Draw::Draw(6,&src,&dst,c,r);
}