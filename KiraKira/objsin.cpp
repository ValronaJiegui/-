#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"objsin.h"

using namespace GameL;

void CObjSin::Init()
{
	m_px=550.0f;
	m_py=260.0f;
	m_vx=0.0f;
	m_vy=0.0f;

	m_posture=1.0f;//右向き1　左向き0

	m_ani_time=0;//モーション変更用の変数
	m_ani_frame=0;//描画変更のための変数
	tdkr_kouzi=2;//切り取り位置調整のための変数
	kit=0;//攻撃描画用の変数
	ton=0;//爆弾を持っているか持っていないかの変数
	stop=0;//攻撃制限用の変数
	ka=0;//死亡判定
	r=0;
	m_speed_power=0.5f;
	m_ani_max_time=8;

	m_ani_time2=0;
	m_ani_frame2=3;

	Hits::SetHitBox(this, m_px, m_py, 32, 64, ELEMENT_ENEMY, OBJ_BAKU, 1);

	CObjLei*hero=(CObjLei*)Objs::GetObj(OBJ_LEI);//主人公のリスト取得
	houkou=hero->GetX();//主人公のｘ位置を取得
}

void CObjSin::Action()
{
	//hit box更新用ポインター取得
	CHitBox*hit = Hits::GetHitBox(this);

	//スクロールの動く値を確保
	CObjBlock *block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll = block->GetScroll();


	if(kit==0)//もしも攻撃が終わっているか一度も攻撃していない場合
	{
		m_ani_time2++;
	}

	if(kit==1){//攻撃が始まった場合
		m_ani_time++;
	}

	if(m_ani_frame==4&&ton==1)//爆弾を所持した場合
	{
		ton=2;
		kit=0;
	}

	if(m_ani_frame==8&&ton==2&&stop==0&&ka==0)//自身が死んでおらず、攻撃制限を受けてもいなく、爆弾を持っていて尚且つ放り投げるモーションになったとき
	{
		if(m_posture==0){//向きが右向きの場合
		CObjTamac*obj=new CObjTamac(m_px+30.0f,m_py-10.0f);
		Objs::InsertObj(obj,OBJ_TAMAC,100);
		}

		else if(m_posture==1){//向きが左向きの場合
		CObjTamac*obj=new CObjTamac(m_px-30.0f,m_py-10.0f);
		Objs::InsertObj(obj,OBJ_TAMAC,100);
		}

		ton=2;
		stop=1;
	}

	if (m_ani_time2==40&&kit==0&&ka==0)//規定の時間に達した場合
	{
		if(ton==2){//爆弾を所持している場合
			kit=1;
			m_ani_time2==0;
		}
	else{
		kit=1;
		ton=1;
		m_ani_time2==0;
		}
	}

	if(m_ani_time>m_ani_max_time){//規定の時間になったとき
		m_ani_frame+=1;
		m_ani_time=0;
	}

	if(m_ani_frame==10){//攻撃モーションが全て終了したとき、攻撃に関する変数を全て0に戻す
		m_ani_frame=0;
		m_ani_time2=0;
		kit=0;
		ton=0;
		stop=0;
	}

	if(hit->CheckObjNameHit(OBJ_TAMA) != nullptr)//攻撃判定に当たった場合
	{
		ka++;
		r=25;
		hit->SetPos(-256,-256);//hitboxをかき消す
	}

	if (ka >= 1)
	{
		m_py -= 10.0f;
		m_px += 4;
		r += 3;
		if (m_py == 800) {
			this->SetStatus(false);//自身に削除命令を出す
			Hits::DeleteHitBox(this);//自身が所有するhitboxに削除する。
		}
	}

	m_px+=m_vx;
	m_py+=m_vy;

	m_vx += -(m_vx*0.098);
	m_vy += 9.8 / (16.0f);

	if (ka == 0) {
		hit->SetPos(m_px + block->GetScroll(), m_py);//hitboxの位置を更新
	}

	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	int d;
	if (ka <= 0) {
		pb->BlockHit(&m_px, &m_py, false,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
			&d
		);
	}

}

void CObjSin::Draw()
{
	int AniData[16]=
	{
		0,0,2,2,1,1,2,2,3,3
	};

	int KouData[8]={

	};

	int KouData2[8]={

	};

	float c[4]={1.0f,1.0f,1.0f,1.0f};

	RECT_F src;
	RECT_F dst;
	//きりとりいち
	src.m_top =0.0f+tdkr_kouzi*64;
	src.m_left=0.0f+AniData[m_ani_frame]*64;
	src.m_right=64.0f+AniData[m_ani_frame]*64;
	src.m_bottom=64.0f+tdkr_kouzi*64;

	//ひょうじいち

	//主人公の値を取得
	CObjLei*hero = (CObjLei*)Objs::GetObj(OBJ_LEI);
	houkou = hero->GetX();

	dst.m_top = 0.0f + m_py;
	dst.m_left = (64.0f - 64.0f*m_posture) + m_px + m_scroll;
	dst.m_right = (64.0f*m_posture) + m_px + m_scroll;
	dst.m_bottom = 64.0f + m_py;

	if (houkou>dst.m_right)//主人公が自身よりも左にいる場合
	{
		m_posture = 0;//向きを右向きに変更
	}

	else if (houkou<dst.m_right) {
		m_posture = 1;//向きを左向きに変更
	}

	if (dst.m_right <= -300.0f)//主人公が自身よりも左にいる場合
	{
		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//自身が所有するhitboxに削除する。
	}


	Draw::Draw(6, &src, &dst, c, r);
}