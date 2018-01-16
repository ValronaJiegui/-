#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"objhero.h"
#include<stdlib.h>
#include<time.h>

using namespace GameL;

void CObjHero::Init()
{
	m_px=0.0f;
	m_py=0.0f;
	m_vx=0.0f;
	m_vy=0.0f;
	m_posture=0.0f;//‰EŒü‚«‚O@¶Œü‚«‚P
	m_ani_time=0;
	m_ani_frame=0;

	ka=0;
	tomeru=0;
	kougeki=0;
	kougeki2=0;
	kuukou=0;
	m_ani_tate=0;

	r=0;
	muteki=0;
	mutekie=1;
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

	Hits::SetHitBox(this, m_px-10, m_py, 32, 64, ELEMENT_PLAYER, OBJ_HERO, 1);
}

void CObjHero::Action()
{
	CObjTama*tama=(CObjTama*)Objs::GetObj(OBJ_TAMA);

	if(kuukou==1&&tobu==1&&tomeru==1)
	{
		tama->koukaku=true;
	}

	if(m_vy<0){
		m_ani_frame=5;
		tobu=1;
	}

	else if(m_vy>0)
	{
		m_ani_frame=6;
		tobu=1;
	}

	else if(m_vy==0&&tobu==1){
		m_ani_frame=0;
		tobu=0;
	}

	if(m_py>1000.0f||Input::GetVKey('U')==true){
		Scene::SetScene(new CSceneMain());
	}

	if(kiraa==1)
	{
		kiratime++;
		if(kiratime==200)
		{
			kiraa=0;
			kiratime=0;
		}
	}

	if(m_hit_down==true)
	{
		ka=0;
	}

	//ƒWƒƒƒ“ƒv
	if(Input::GetVKey('T')==true&&kougeki==0)
	{
		if(m_hit_down==true)
		{
			m_vy=-10;
		}
	}

	//—¬¯ŒQ
	if(Input::GetVKey('A')==true&&kiraa==0)
	{
		kiraa=1;
		srand(time(NULL));
		for(int i=0;i<100;i++){
		kira1=rand()%1000+1;
		kira2=rand()%2000+1;

		kira1*=-1;
		kira2*=-1;

		CObjKira*obj=new CObjKira(kira1,kira2);
		Objs::InsertObj(obj,OBJ_HERO,100);
		}
	}

	//^‹ó”gUŒ‚
	if(Input::GetVKey('Y')==true&&tomeru==0)
	{
		if(tobu==1){
			CObjTama*obj=new CObjTama(m_px,m_py);
			Objs::InsertObj(obj,OBJ_TAMA,100);

			kuukou=1;
		}
		else{
			CObjTama*obj=new CObjTama(m_px,m_py);
			Objs::InsertObj(obj,OBJ_TAMA,100);
			kougeki=1;
		}
	}

	if(kougeki==1||kuukou==1){
		if(kuukou==1)
			m_ani_frame=7;
		else
			m_ani_frame=4;
		tomeru++;
		if(tomeru==30){
			kougeki=0;
			tomeru=0;
			kuukou=0;
		}
	}

	//‰ŠUŒ‚
	if(Input::GetVKey('R')==true&&tomeru==0&&tobu==0)
		{
			kougeki2=1;
		}

	if(kougeki2==1){
		m_ani_tate=1;
		tomeru++;
		if(tomeru>=30){
			m_ani_frame=3;
			if(tomeru==80){
				kougeki2=0;
				tomeru=0;
			}
		}
	}

	//•à‚­•`‰æ
	if(Input::GetVKey(VK_RIGHT)==true&&kougeki==0)
	{
		if(tobu==0)
			m_ani_time++;
		m_vx+=m_speed_power;
		m_posture=0.0f;
	}

	else if(Input::GetVKey(VK_LEFT)==true&&kougeki==0)
	{
		if(tobu==0)
			m_ani_time++;
		m_vx-=m_speed_power;
		m_posture=1.0f;
	}

	else if(tomeru==0){
		m_ani_time=0;
		m_ani_frame=0;
		m_ani_tate=0;
	}

	if(m_ani_time>8){	
		m_ani_frame++;
		m_ani_time=0;
	}

	if(m_ani_frame>=3&&tomeru==0){
		m_ani_frame=0;
	}


	//–³“G‚Ì”»’è
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
		if(muteki_time%2==0){
			mutekie=1;
		}
		else if(muteki_time%2==1){
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

	//–€C
	m_vx+=-(m_vx*0.098);
	m_vy+=9.8/(16.0f);

	m_px+=m_vx;
	m_py+=m_vy;

	//hit boxXV—pƒ|ƒCƒ“ƒ^[æ“¾
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_px+14, m_py);//hitbox‚ÌˆÊ’u‚ğ’eŠÛ‚ÌˆÊ’u‚ÉXV

	for(int i=0;i<3;i++){
		if(hit->CheckElementHit(ELEMENT_ENEMY) == true&&muteki==0)
		{
			m_py-=70;
			muteki=1;
		}
	}
}

void CObjHero::Draw()
{
	int AniData[16]=
	{
		1,1,2,2,3,4,5,6,7
	};

	int KouData[8]={
		0,1
	};

	int KouData2[8]={

	};

	float c[4]={1.0f,1.0f,1.0f,1.0f};

	RECT_F src;
	RECT_F dst;

	//‚«‚è‚Æ‚è‚¢‚¿
	src.m_top =0.0f+(KouData[m_ani_tate]*64);
	src.m_left=0.0f+(AniData[m_ani_frame]*64)*mutekie;
	src.m_right=64.0f+(AniData[m_ani_frame]*64)*mutekie;
	src.m_bottom=64.0f+(KouData[m_ani_tate]*64);
	//‚Ğ‚å‚¤‚¶‚¢‚¿
	dst.m_top =0.0f+m_py;
	dst.m_left=(64.0f*m_posture)+m_px;
	dst.m_right=(64-64.0f*m_posture)+m_px;
	dst.m_bottom=64.0f+m_py;

	Draw::Draw(5,&src,&dst,c,r);
}