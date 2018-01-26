#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"

#include"GameHead.h"
#include"ObjSyasyou.h"
#include<stdlib.h>
#include<time.h>

using namespace GameL;

void CObjSyasyou::Init()
{
	m_px = 500.0f;
	m_py = 0.0f;
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_posture = 1.0f;//�E����1�@������0
	m_ani_time = 0;
	m_ani_frame = 0;

	ka = 0;
	tomeru = 0;
	kougeki = 0;
	kuukou = 0;

	hisatu = 0;
	hisatue = 0;
	hcount = 0;
	stoph = 0;

	r = 0;
	muteki = 0;
	mutekie = 0;
	yarare = 0;
	m_speed_power = 0.5f;
	m_ani_max_time = 8;

	m_ani_time2 = 0;
	muteki_time = 0;
	m_ani_frame2 = 3;

	kira = 0;
	kira1 = 0;
	kira2 = 0;
	kiraa = 0;
	kiratime = 0;

	K = 0;
	koukan = 0;
	koukan2 = 0;

	toba = 0;
	kabet = 0;
	T = 0;

	HP = 12;


	m_f = false;
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	tobu = 0;

	Hits::SetHitBox(this, m_px - 10, m_py, 34, 64, ELEMENT_ENEMY, OBJ_SYASYO, 1);
}

void CObjSyasyou::Action()
{

	if(koukan!=50&&kougeki==0 && hisatu == 0)
		koukan++;

	if (koukan >= 200)
		koukan = 0;

	if (koukan == 50&&koukan2==0 && HP != 0) {
		srand(time(NULL));
		K = rand() % 10 + 1;
		if (K > 7) {
			if (HP > 7 && m_hit_down==true) {
				hisatu = 1;
				koukan = 0;
			}
			else if(HP < 7 && m_hit_down == true){
				hisatu = 3;
				koukan = 0;
			}
		}
		else if (K < 7) {
			kougeki = 1;
			koukan2 = 1;
		}
	}

	if (tobu == 0)
		toba++;

	if (toba >= 400)
		toba = 0;

	if (toba == 200 && tobu == 0 && HP != 0) {
		srand(time(NULL));
		K = rand() % 30 + 1;

		if (T > 7) {
			toba = 0;
		}
		else if (T < 7) {
			tobu = 1;
		}
	}

	m_posture = aaaaa;

	//�X�N���[���̓����l���m��
	CObjBlock *block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll = block->GetScroll();

	/*if (m_vy<0) {
		tobu = 1;
	}

	else if (m_vy>0)
	{
		tobu = 1;
	}

	else if (m_vy == 0) {
		tobu = 0;
	}*/

	if (m_hit_down == true)
	{
		ka = 0;
	}

	//�W�����v
	if(tobu==1 && HP != 0||m_hit_left==true||m_hit_right==true)
	{
		if(m_hit_down==true)
		{
			m_vy=-18;
			tobu = 0;
			toba = 0;
		}
		else if(m_hit_left==true && kabet == 0 ||m_hit_right==true && kabet == 0)
		{

			m_vy = -13;
			tobu = 0;
			toba = 0;
		}
		kabet++;
		if (kabet == 80)
			kabet = 0;
	}

	//�U��
	if(kougeki==1 && HP != 0)
	{
		m_ani_frame=4;

		kougeki = 2;
	}

	if(hisatu==0&&kougeki==2){
		m_ani_time++;

		if(m_ani_frame==6&&kougeki==2&&tomeru==0){
			CObjKip*obj=new CObjKip(m_px,m_py);
			Objs::InsertObj(obj,OBJ_KIP,100);
			tomeru++;
		}

		if(m_ani_frame==8){
			kougeki=0;
			koukan = 0;
			K = 0;
			tomeru=0;
			koukan2 = 0;
		}
	}

	//���z�G�N�X�v���X
	if (kougeki == 0 && kuukou == 0 && hisatu == 1 && HP != 0)
	{
		hisatu = 2;
		hisatue = 1;
		m_ani_frame = 9;
	}

	if (hisatu == 2) {
		hcount++;
		if (hcount<50)
			m_py -= 3;
		if (hcount == 50) {
			m_ani_frame = 10;
		}
		if (hcount == 100) {
			m_ani_frame = 11;
			stoph = 1;

			if (m_posture == 1) {
				CObjSukima*objs = new CObjSukima(m_px + 50, m_py + 90);
				Objs::InsertObj(objs, OBJ_SUKIMA, 100);
			}

			else {
				CObjSukima*objs = new CObjSukima(m_px - 50, m_py + 90);
				Objs::InsertObj(objs, OBJ_SUKIMA, 100);
			}

			tomeru = 1;
		}
		if (hcount == 300) {
			hisatu = 0;
			hisatue = 0;
			kougeki = 0;
			hcount = 0;
			tomeru = 0;
			stoph = 0;
			koukan2 = 0;
		}
	}


	//���V�G�N�X�v���X
	if (kougeki == 0 && kuukou == 0 && hisatu == 3 && HP != 0)
	{
		hisatu = 4;
		hisatue = 1;
		m_ani_frame = 9;
	}

	if (hisatu == 4) {
		hcount++;
		if (hcount<50)
			m_py -= 3;
		if (hcount == 50) {
			m_ani_frame = 10;
		}
		if (hcount == 100) {
			m_ani_frame = 11;
			stoph = 1;

			if (m_posture == 1) {
				CObjSukima*objs = new CObjSukima(m_px + 50, m_py + 90);
				Objs::InsertObj(objs, OBJ_SUKIMA, 100);
			}

			else {
				CObjSukima*objs = new CObjSukima(m_px - 50, m_py + 90);
				Objs::InsertObj(objs, OBJ_SUKIMA, 100);
			}

			tomeru = 1;
		}

		if (hcount == 150) {

			if (m_posture == 1) {
				CObjSukima*objs = new CObjSukima(m_px + 100, m_py - 90);
				Objs::InsertObj(objs, OBJ_SUKIMA, 100);
			}

			else {
				CObjSukima*objs = new CObjSukima(m_px - 100, m_py - 90);
				Objs::InsertObj(objs, OBJ_SUKIMA, 100);
			}

		}

		if (hcount == 200) {

			if (m_posture == 1) {
				CObjSukima*objs = new CObjSukima(m_px + 50, m_py + 90);
				Objs::InsertObj(objs, OBJ_SUKIMA, 99);
			}

			else {
				CObjSukima*objs = new CObjSukima(m_px - 50, m_py + 90);
				Objs::InsertObj(objs, OBJ_SUKIMA, 99);
			}

		}

		if (hcount == 300) {
			hisatu = 0;
			hisatue = 0;
			kougeki = 0;
			hcount = 0;
			tomeru = 0;
			stoph = 0;
			koukan2 = 0;
		}
	}

	//�����`��
	if(hisatu==0 && aaaaa == 0 && HP != 0)
	{
		if(tobu==0&&kougeki==0)
			m_ani_time++;
		m_vx+=0.3;
		m_posture=0.0f;
	}

	else if(hisatu==0 && aaaaa == 1)
	{
		if(tobu==0&&kougeki==0)
			m_ani_time++;
		m_vx-=0.3f;
		m_posture=1.0f;
	}

	if (m_ani_time>8) {
		m_ani_frame++;
		m_ani_time = 0;
	}

	if (m_ani_frame >= 4 && kougeki == 0 && tobu == 0 && kuukou == 0&&hisatu==0) {
		m_ani_frame = 0;
	}


	//���G�̔���
	if (muteki == 1)
	{
		muteki_time++;
		yarare++;
		if (muteki_time == 100) {
			mutekie = 0;
			muteki = 0;
			muteki_time = 0;
			yarare = 0;

		}
		if (muteki_time % 2 == 0) {
			mutekie = 0;
		}
		if (muteki_time % 2 == 1) {
			mutekie = 1;
		}
	}

	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	int d;
	if (HP != 0) {
		pb->BlockHit(&m_px, &m_py, false,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
			&d
		);
	}

	//���C
	if (hisatu == 0) {
		m_px += m_vx;
		m_py += m_vy;
		m_vx += -(m_vx*0.098);
		m_vy += 9.8 / (16.0f);
	}

	if (HP == 0&&des<15) {
		if (des == 0) {
			m_vx = 0.0f;
			m_vy = 0.0f;
		}
		des++;
		r += 5;
		m_px += 1.0f;
		m_py -= 10.0f;
	}

	if (m_py == 800) {
		this->SetStatus(false);//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);//���g�����L����hitbox�ɍ폜����B
	}

	//hit box�X�V�p�|�C���^�[�擾
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_px + m_scroll, m_py);//hitbox�̈ʒu��e�ۂ̈ʒu�ɍX�V

	if (hit->CheckObjNameHit(OBJ_TAMA) != nullptr&&muteki == 0&&hisatu==0&&HP!=0)
	{
		m_py -= 70;
		muteki = 1;
		HP--;
	}
}

void CObjSyasyou::Draw()
{
	int AniData[16] =
	{
		1,2,1,3,4,5,6,7,2,0,1,2
	};

	int HisaData[3] =
	{
		0,1,
	};

	int KouData[8] = {

	};

	int KouData2[8] = {

	};

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//����Ƃ肢��
	src.m_top = 0.0f + (HisaData[hisatue] * 64) - (HisaData[hisatue] * 64)*(mutekie);
	src.m_left = 0.0f + (AniData[m_ani_frame] * 64) - (AniData[m_ani_frame] * 64)*(mutekie);
	src.m_right = 64.0f + (AniData[m_ani_frame] * 64) - (AniData[m_ani_frame] * 64)*(mutekie);
	src.m_bottom = 64.0f + (HisaData[hisatue] * 64) - (HisaData[hisatue] * 64)*(mutekie);
	//�Ђ傤������

	//��l���̒l���擾
	CObjLei*hero = (CObjLei*)Objs::GetObj(OBJ_LEI);
	houkou = hero->GetX();

	dst.m_top = 0.0f + m_py;
	dst.m_left = (64.0f - 64.0f*m_posture) + m_px + m_scroll;
	dst.m_right = (64.0f*m_posture) + m_px + m_scroll;
	dst.m_bottom = 64.0f + m_py;

	if (houkou>dst.m_right + 60&&stoph == 0)//��l�������g�������ɂ���ꍇ
	{
		aaaaa = 0;//�������E�����ɕύX
	}
	else if (houkou<dst.m_right -150 &&stoph == 0) {
		aaaaa = 1;//�������������ɕύX
	}

	Draw::Draw(8, &src, &dst, c, r);
}