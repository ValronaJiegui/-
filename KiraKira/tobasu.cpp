#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"tobasu.h"

using namespace GameL;

void CObjTobasu::Init()
{
	m_px=450.0f;
	m_py=5.0f;
	m_vx=0.0f;
	m_vy=0.0f;

	m_posture=0.0f;//右向き０　左向き１

	m_ani_time=0;//切り取り位置変更にかかる時間変数
	m_ani_frame=0;//切り取り位置の変更の変数
	kit=0;//攻撃開始時、グラフィック変更にかかる時間変数
	ton=0;//攻撃開始時、ドローンを出すために必要な変数
	ka=0;//自身の死亡変数
	r=0;
	hando=0;//攻撃後、しばらくの間攻撃が出来なくなる変数
	m_speed_power=0.5f;
	m_ani_max_time=8;

	doro=false;//ドローンを出している判定
	sibou=false;//自身の死亡判定

	m_ani_time2=0;//攻撃を出すまでにかかる時間の変数
	m_ani_frame2=3;

	Hits::SetHitBox(this, m_px, m_py, 32, 64, ELEMENT_ENEMY, OBJ_TOBASU, 1);

	CObjLei*hero=(CObjLei*)Objs::GetObj(OBJ_LEI);//主人公のリスト取得
	houkou=hero->GetX();//主人公の方向を取得
}

void CObjTobasu::Action()
{

	//スクロールの動く値を確保
	CObjBlock *block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll = block->GetScroll();

	if(doro==true)//ドローンが死亡した場合、ドローンファイルからtrueが送られる。そのとき、ドローン出現に関する変数を全て０にする
	{
		doro=false;
		m_ani_frame=0;
		kit=0;
		m_ani_time=0;
		m_ani_time2=0;
		hando=0;
	}

	if(kit==0)
	{
		m_ani_time2++;
	}

	if(kit==1){
		m_ani_time++;
	}


	if(m_ani_frame==8&&ton==2&&ka==0&&doro==false&&hando==0)
	{
		CObjDoron*obj=new CObjDoron(m_px+400.0f- m_scroll,100.0f);
		Objs::InsertObj(obj,OBJ_DORON,100);

		ton=0;
		hando=1;
	}

	if (m_ani_time2==40&&kit==0&&ka==0&&doro==false)
	{
		kit=1;
		ton=2;
	}

	if(m_ani_time>m_ani_max_time){
		m_ani_frame+=1;
		m_ani_time=0;
	}

	if(m_ani_frame==9){
		m_ani_frame=3;
		m_ani_time2=0;
		ton=0;
	}
	//弾丸用のhit box更新用ポインター取得
	CHitBox*hit = Hits::GetHitBox(this);
	if(ka==0){
		hit->SetPos(m_px + block->GetScroll(), m_py);//hitboxの位置を更新
	}

	if(hit->CheckObjNameHit(OBJ_TAMA) != nullptr)
	{
		sibou=true;//ドローンファイルに死亡判定を送るため、死亡フラグをオンにする
		ka++;
		r=25;
		hit->SetPos(-256,-256);//hitboxの位置を更新
	}

	if(ka>=1)
	{
		m_py-=10.0f;
		m_px+=4;
		r+=3;
		if(m_py==800){
			this->SetStatus(false);//自身に削除命令を出す
		    Hits::DeleteHitBox(this);//自身が所有するhitboxに削除する。
		}
	}

	m_px+=m_vx;
	m_py+=m_vy;

	m_vx += -(m_vx*0.098);
	m_vy += 9.8 / (16.0f);

	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	int d;
	if (ka<=0) {
		pb->BlockHit(&m_px, &m_py, false,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
			&d
		);
	}
}

void CObjTobasu::Draw()
{
	int AniData[16]=
	{
		0,0,0,1,1,1,2,2,2
	};

	int KouData[8]={

	};

	int KouData2[8]={

	};

	float c[4]={1.0f,1.0f,1.0f,1.0f};

	RECT_F src;
	RECT_F dst;

	//きりとりいち
	src.m_top =64.0f*3;
	src.m_left=0.0f+AniData[m_ani_frame]*64;
	src.m_right=64.0f+AniData[m_ani_frame]*64;
	src.m_bottom=64.0f*4;

	//ひょうじいち

	//主人公の値を取得
	CObjLei*hero = (CObjLei*)Objs::GetObj(OBJ_LEI);
	houkou = hero->GetX();

	dst.m_top =0.0f+m_py;
	dst.m_left=(64.0f - 64.0f*m_posture)+m_px+ m_scroll;
	dst.m_right=(64.0f*m_posture)+m_px+m_scroll;
	dst.m_bottom=64.0f+m_py;

	if (houkou>dst.m_right)//主人公が自身よりも左にいる場合
	{
		m_posture = 0;//向きを右向きに変更
	}
	else if (houkou<dst.m_right) {
		m_posture = 1;//向きを左向きに変更
	}

	if (dst.m_right <= -1500.0f)//主人公が自身よりも左にいる場合
	{
		sibou = true;//ドローンファイルに死亡判定を送るため、死亡フラグをオンにする
		hando = 1;
	}

	Draw::Draw(6,&src,&dst,c,r);
}