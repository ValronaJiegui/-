#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"objsyasyo.h"
#include<stdlib.h>
#include<time.h>

using namespace GameL;

void CObjSyasyo::Init()
{
	m_px=500.0f;
	m_py=0.0f;
	m_vx=0.0f;
	m_vy=0.0f;
	m_posture=1.0f;//右向き1　左向き0
	m_ani_time=0;
	m_ani_frame=0;

	ka=0;
	tomeru=0;
	kougeki=0;
	kuukou=0;

	hisatu=0;
	hisatue=0;
	hcount=0;

	r=0;
	muteki=0;
	mutekie=0;
	yarare=0;
	m_speed_power=0.5f;
	m_ani_max_time=8;

	m_ani_time2=0;
	muteki_time=0;
	m_ani_frame2=3;

	kira=0;
	kira1=0;
	kira2=0;
	kiraa=0;
	kiratime=0;
	

	m_f=false;
	m_hit_up=false;
	m_hit_down=false;
	m_hit_left=false;
	m_hit_right=false;

	tobu=0;

	Hits::SetHitBox(this, m_px-10, m_py, 32, 64, ELEMENT_ENEMY, OBJ_SYASYO, 1);
}

void CObjSyasyo::Action()
{
	m_posture = aaaaa;

	//スクロールの動く値を確保
	CObjBlock *block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll = block->GetScroll();

	if(m_vy<0){
		tobu=1;
	}

	else if(m_vy>0)
	{
		tobu=1;
	}

	else if(m_vy==0){
		tobu=0;
	}

	if(m_hit_down==true)
	{
		ka=0;
	}

	//ジャンプ
	/*if(Input::GetVKey('T')==true&&kougeki==0)
	{
		if(m_hit_down==true)
		{
			m_vy=-10;
		}
	}*/

	//攻撃
	/*if(Input::GetVKey('Y')==true&&kougeki==0&&kuukou==0)
	{
		m_ani_frame=4;

		if(tobu==1){
			kuukou=1;
		}

		else{
			kougeki=1;
		}
	}

	if(hisatu==0&&kougeki==1||kuukou==1){
		m_ani_time++;

		if(m_ani_frame==6&&kuukou==1&&tomeru==0){
			CObjTama*obj=new CObjTama(m_px,m_py);
			Objs::InsertObj(obj,OBJ_TAMA,100);
			tomeru++;
		}

		else if(m_ani_frame==6&&kougeki==1&&tomeru==0){
			CObjTama*obj=new CObjTama(m_px,m_py);
			Objs::InsertObj(obj,OBJ_TAMA,100);
			tomeru++;
		}

		if(m_ani_frame==8){
			kougeki=0;
			tomeru=0;
			kuukou=0;
		}
	}*/

	//幻想エクスプレス
	if(Input::GetVKey('S')==true&&kougeki==0&&kuukou==0&&hisatu==0&&muteki==0)
	{
		hisatu=1;
		hisatue=1;
		kougeki=1;
		m_ani_frame = 9;
	}

	if(hisatu==1){
		hcount++;
		if(hcount<50)
			m_py-=3;
		if(hcount==50){
			m_ani_frame=10;
		}
		if(hcount==100){
			m_ani_frame=11;

			if(m_posture==1){
				CObjSukima*objs=new CObjSukima(m_px+50,m_py+90);
				Objs::InsertObj(objs,OBJ_SUKIMA,100);
			}

			else{
				CObjSukima*objs=new CObjSukima(m_px-50,m_py+90);
				Objs::InsertObj(objs,OBJ_SUKIMA,100);
			}

			tomeru=1;
		}
		if(hcount==300){
			hisatu=0;
			hisatue=0;
			kougeki=0;
			hcount=0;
			tomeru=0;
		}
	}


	//歩く描画
	/*if(Input::GetVKey(VK_RIGHT)==true&&hisatu==0)
	{
		if(tobu==0&&kougeki==0)
			m_ani_time++;
		m_vx+=m_speed_power;
		m_posture=1.0f;
	}

	else if(Input::GetVKey(VK_LEFT)==true&&hisatu==0)
	{
		if(tobu==0&&kougeki==0)
			m_ani_time++;
		m_vx-=m_speed_power;
		m_posture=0.0f;
	}

	else if(tobu==0&&kougeki==0&&kuukou==0){
		m_ani_time=0;
		m_ani_frame=0;
	}*/

	if(m_ani_time>8){	
		m_ani_frame++;
		m_ani_time=0;
	}

	if(m_ani_frame>=4&&kougeki==0&&tobu==0&&kuukou==0){
		m_ani_frame=0;
	}


	//無敵の判定
	if(muteki==1)
	{
		muteki_time++;
		yarare++;
		if(muteki_time==100){
			mutekie=0;
			muteki=0;
			muteki_time=0;
			yarare=0;

		}
		if(muteki_time%2==1){
			mutekie=4;
		}
		else if(muteki_time%2==0){
			mutekie=0;
		}
		if(yarare<=30)
		{
			m_ani_frame=8;
			if(yarare==30)
			{
				yarare=30;
			}
		}

	}

	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	int d;
	pb->BlockHit(&m_px, &m_py, false,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&d
	);

	//摩擦
	if(hisatu==0){
		m_px+=m_vx;
		m_py+=m_vy;
		m_vx+=-(m_vx*0.098);
		m_vy+=9.8/(16.0f);
	}

	//hit box更新用ポインター取得
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_px+m_scroll, m_py);//hitboxの位置を弾丸の位置に更新

	for(int i=0;i<3;i++){
		if(hit->CheckElementHit(ELEMENT_ENEMY) == true&&muteki==0&&hisatu==0)
		{
			m_py-=70;
			muteki=1;
		}
	}
}

void CObjSyasyo::Draw()
{
	int AniData[16]=
	{
		1,2,1,3,4,5,6,7,8,0,1,2
	};

	int HisaData[3]=
	{
		0,1,
	};

	int KouData[8]={

	};

	int KouData2[8]={

	};

	float c[4]={1.0f,1.0f,1.0f,1.0f};

	RECT_F src;
	RECT_F dst;

	//きりとりいち
	src.m_top =0.0f+(HisaData[hisatue]*64)+((64*mutekie-3));
	src.m_left=0.0f+(AniData[m_ani_frame]*64)+(1*mutekie-2);
	src.m_right=64.0f+(AniData[m_ani_frame]*64)+(64*mutekie-2);
	src.m_bottom=64.0f+(HisaData[hisatue]*64)+((64*mutekie-3));
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
		aaaaa = 0;//向きを右向きに変更
	}
	else if (houkou<dst.m_right) {
		aaaaa = 1;//向きを左向きに変更
	}

	Draw::Draw(8,&src,&dst,c,r);
}