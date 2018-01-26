#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"doron.h"

using namespace GameL;

CObjDoron::CObjDoron(float x,float y)
{
	m_px=x;
	m_py=y;
}

void CObjDoron::Init()
{
	m_vx=-1.0f;//x軸の加速度
	m_vy=0.0f;//y軸の加速度
	tada=0;
	ad=0;
	a=0;
	ki=0;//自分が死んだかの判定
	te=0;//操作主が死んだかの判定

	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	ooo=0;//フレーム

	kuru=false;
	hata=false;
	ido=false;


	m_ani_frame=0;//アニメーションの描画
	m_ani_time=0;//描画を変更する変数

	//当たり判定用hitboxを作成
	Hits::SetHitBox(this, m_px, m_py, 32, 32, ELEMENT_ENEMY, OBJ_DORON, 1);
}

void CObjDoron::Action()
{
	//スクロールの動く値を確保
	CObjBlock *block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll = block->GetScroll();

	CObjLei*obj=(CObjLei*)Objs::GetObj(OBJ_LEI);//主人公のリスト
	CObjTobasu*toba=(CObjTobasu*)Objs::GetObj(OBJ_TOBASU);//操作主のリスト

	aaaa=toba->sibou;//操作主が死んだかどうかリストで検索

	//hit box更新用ポインター取得
	CHitBox*hit = Hits::GetHitBox(this);
	if(aaaa!=true){							//操作主が死んでいない場合
	if(obj!=nullptr&&ki==0)					//自身が死んでいない場合
	{

	float ox=obj->GetX()-m_px - m_scroll;//主人公のx軸を取得
	float oy=obj->GetY()-m_py ;//主人公のy軸を取得
	float ar=atan2(-oy,ox)*180.0f/3.14;//角度の計算

	if(ar<0)
	{
		360-abs(ar);//絶対値に変更
	}

	//現在の角度を取る
	float br=atan2(-m_vy,m_vx)*180.0f/3.14;

	if(br<0)
	{
		360-abs(br);//絶対値に変更
	}

	if(ar-br>20&&ooo>=50)
	{
		//移動方向を主人公の方向にする
		m_vx=cos(3.14/180*ar);
		m_vy=-sin(3.14/180*ar);
	}

	float r=3.14/180.0f;//角度1度
	float rr=3.14/180.0f*5;//角度5度

	if(m_px>=500 - m_scroll &&m_px<=600 - m_scroll &&ooo<=100&&ido==false||kuru==true&&ooo<=100&&ido==false){
		//移動方向に5度加える
		ooo++;
		m_vx=m_vx*cos(rr)-m_vy*sin(rr);
		m_vy=m_vy*cos(rr)+m_vx*sin(rr);
		kuru=true;
	}

	if(ooo>50&&ar<br){
		//移動方向に1度加える
		m_vx=m_vx*cos(r)-m_vy*sin(r);
		m_vy=m_vy*cos(r)+m_vx*sin(r);
		ido=true;
	}

	else if(ooo>50&&ar>br){
		//移動方向に1度加える
		m_vx=m_vx*cos(-r)-m_vy*sin(-r);
		m_vy=m_vy*cos(-r)+m_vx*sin(-r);
	}

	}
	}

	else
	{
		CObjBlock *pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
		int d;

		pb->BlockHit(&m_px, &m_py, false,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
			&d
		);

		m_vx=0.0f;
		m_vy += 2 / (16.0f);
		hit->SetPos(-255, -255);
		te=1;
	}

	if(hit->CheckObjNameHit(OBJ_TAMA) != nullptr)//主人公の攻撃判定に引っかかった場合
	{
		hata=true;//操作主に送るためのフラッグをオン
		ki=1;//自身を死亡判定にオン
		hit->SetPos(-255, -255);//当たり判定を消し飛ばす
	}

	if(ki==1)
	{
		m_ani_time++;
	}



	if(m_ani_time==8)
	{
		m_ani_frame++;
		m_ani_time=0;
	}


	if(m_ani_frame==4||m_px<-500||m_py<-500)
	{
		toba->doro=true;//操作主に自身が死んだフラッグを渡す

		this->SetStatus(false);//自身に削除命令を出す
		Hits::DeleteHitBox(this);//弾丸が所有するhitboxに削除する。
		return;
	}
	if(ki==0&&te==0){
		hit->SetPos(m_px + m_scroll, m_py+20);//hitboxの位置を弾丸の位置に更新
		m_px+=m_vx*5.0f;
		m_py+=m_vy*5.0f;
	}

	if (te == 1)
	{
		m_px += m_vx;
		m_py += m_vy;
	}
}

void CObjDoron::Draw()
{

	if (m_hit_down == true && aaaa == true)//仮組みのためこうなっているが、本当は地面にぶつかった場合
	{
		CHitBox*hit = Hits::GetHitBox(this);
		hit->SetPos(-255, -255);
		m_ani_time++;
		te = 2;
	}

	int AniData[8]=
	{
		0,1,2,3
	};

	float c[4]={1.0f,1.0f,1.0f,1.0f};

	RECT_F src;
	RECT_F dst;

	if(ki==1||te==2){
		src.m_top =64.0f*6;
		src.m_left=0.0f+AniData[m_ani_frame]*64;
		src.m_right=64.0f+AniData[m_ani_frame]*64;
		src.m_bottom=64.0f*7;
	}

	else{
		src.m_top =64.0f*7;
		src.m_left=64.0f*4;
		src.m_right=64.0f*5;
		src.m_bottom=64.0f*8;
	}

	//ひょうじいち
	dst.m_top =0.0f+m_py;
	dst.m_left=0.0f+m_px + m_scroll;
	dst.m_right=64.0f+m_px + m_scroll;
	dst.m_bottom=64.0f+m_py;

	Draw::Draw(6,&src,&dst,c,0.0f);
}