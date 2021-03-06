#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\DrawFont.h" //←HP表示のテスト用なのでそのうち消します！
#include"GameL\HitBoxManager.h"//←当たり判定に必要なデータ

#include"GameHead.h"
#include"ObjLei.h"

using namespace GameL;

//初期設定(イニシャライズ)////////////////////
void CObjLei::Init()
{
	m_px = 0.0f;
	m_py = 0.0f;
	m_vx = 0.0f;
	m_vy = 10.0f;
	m_time = 0;
	m_wtime = 0;
	m_motion_walk = 0;
	m_motion_attack = 0;

	houkou = false;
	hantei = false;

	muteki = 0;
	mutekie = 0;
	muteki_time = 0;
	hutobi = false;
	xcount = 0;

	m_jump = false;
	m_dash = false;
	m_key_z = false;
	m_f = false;
	m_muki = 0;
	m_live_tama = false;
	z_flag = true;

	//ブロックとの当たり判定
	m_hit_down=false ;
	m_hit_left = false;
	m_hit_right =false;
	m_hit_up = false;
	m_HP = 9999;

	Hits::SetHitBox(this, m_px - 10, m_py, 32, 64, ELEMENT_PLAYER, OBJ_LEI, 1);
}
//動作内容(アクション)////////////////////////
void CObjLei::Action()
{
	m_time++;

	
	if (Input::GetVKey('Z') == true)
	{
		if (z_flag) {
			CObjTama*obj = new CObjTama(m_px, m_py);
			Objs::InsertObj(obj, OBJ_TAMA, 100);
			m_live_tama = true;
			m_key_z = true;
			z_flag = false;
		}
	}
	else
		z_flag = true;


	//翼が取れたとき、フラグを立てる
	CObjItemWing *wing = (CObjItemWing*)Objs::GetObj(OBJ_ITEM_WING);
	bool Flag = wing->GetFlag();

	/*if (m_py >= 480.0f) {
		m_vy = -9.8f / (16.0f);
		//m_jump = false;
	}*/

	m_vx += -(m_vx*0.25f);
	m_vy += 9.8f / (16.0f);

	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&m_px, &m_py, true,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&m_block_type
	);

	//キー入力されたときの処理
	if (Input::GetVKey(VK_RIGHT) == true)
	{ 
		houkou = false;
		m_vx = 5.0f;
		m_muki = 0;
		//左右同時押しされたら停止
		if (Input::GetVKey(VK_LEFT) == true)
		{
			m_vx = 0.0f;
		}
		if (Input::GetVKey(VK_SHIFT) == true)
		{
			m_vx += 4.0f;
		}
	}
	else if (Input::GetVKey(VK_LEFT) == true)
	{ 
		houkou = true;
		m_vx = -5.0f;
		m_muki = 1;
		//左右同時押しされたら停止
		if (Input::GetVKey(VK_RIGHT) == true)
		{
			m_vx = 0.0f;
		}
		if (Input::GetVKey(VK_SHIFT) == true)
		{
			m_vx -= 4.0f;
		}
	}

	if (Input::GetVKey(VK_UP) == true)
	{
		if (m_f == false)
		{
			if (Flag == false)
			{
				if (m_jump == false) {
					m_vy = -15.0f;
					m_jump = true;
				}
			}
			else//翼をとった場合ジャンプ力を上げる
			{
				if (m_jump == false)
				{
					m_vy = -20.0f;
					m_jump = true;
				}
			}
			m_f = true;
		}
	}
	else
	{
		m_f = false;
	}

	//翼を取った時の処理---
	if (Flag == true && m_jump == true)
	{
		if(m_wtime <= 40)
			m_wtime++;
		if (m_wtime >= 40 && m_wtime <= 200)
			if (Input::GetVKey(VK_UP) == true)
			{
				m_vy = 0.5f;
				m_wtime++;
			}
	}
	//-----------------------

	else
		m_wtime = 0;

	//移動を位置に反映する
	m_px += m_vx;
	m_py += m_vy;
	if (m_vy == 0.0f)
	{
		m_jump = false;
	}

	if (m_key_z == true)
	{
		if (m_time % 3 == 0)
		{
			m_time = 0;
			m_motion_attack++;
			if (m_motion_attack == 5)
			{
				m_motion_attack = 0;
				m_key_z = false;
			}
		}
	}

	if (m_time % 8 == 0)
	{
		m_time = 0;
		m_motion_walk++;
		if (m_motion_walk == 4)
		{
			m_motion_walk = 0;
		}
	}

	//hit box更新用ポインター取得
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_px, m_py);//hitboxの位置を現在の位置に更新

	if (hit->CheckElementHit(ELEMENT_ENEMY) == true &&muteki==0)
	{
		if (hit->CheckObjNameHit(OBJ_DNSYA) != nullptr)
		{
			m_HP -= 3;
			muteki = 1;
			hutobi = true;
			m_px += 40.0f;
			m_py -= 40.0f;
		}
		else {
			m_HP -= 1;
			muteki = 1;
			hutobi = true;
			m_px += 40.0f;
			m_py -= 40.0f;
		}
	}

	//被弾したとき若干吹っ飛ぶ
	/*if (hutobi == true) {

		if (houkou == false&&xcount==0) {
			hantei = false;
		}

		else if(houkou == true && xcount == 0) {
			hantei = true;
		}

		if (hantei == true && xcount != 6) {
			m_px +=5.0f ;
			m_py -=5.0f ;
		}

		else if (hantei==false&&xcount!=6) {
			m_px -= 5.0f;
			m_py -= 5.0f;
		}

		if(xcount>6)
			xcount++;
	}*/

	//被弾したとき一定時間無敵
	if (muteki == 1)
	{
		muteki_time++;
		if (muteki_time == 100) {
			mutekie = 0;
			muteki = 0;
			muteki_time = 0;
			/*hutobi = false;
			xcount = 0;*/
		}
		if (muteki_time % 2 == 1) {
			mutekie = 196;
		}
		else if (muteki_time % 2 == 0) {
			mutekie = 0;
		}

	}

	//m_movepointX += m_px - 64.0f;

	//ゲームオーバー判定
	if(m_HP == 0)
		Scene::SetScene(new CSceneGameOver());
}
//描画情報(ドロー)////////////////////////////
void CObjLei::Draw()
{
	wchar_t HP[8];
	swprintf_s(HP, 8, L"%d", m_HP);
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float c2[4] = { 0.0f,0.8f,0.0f,1.0f };
	float c3[4] = { 0.0f,0.0f,0.0f,0.8f };

	Font::StrDraw(L"HP:", 2, 1, 50, c3);
	Font::StrDraw(HP, 82, 1, 50, c3);
	
	Font::StrDraw(L"HP:", 0, 0, 50, c2);
	Font::StrDraw(HP, 80, 0, 50, c2);
	
	RECT_F src;//描画元切取位置
	RECT_F dst;//描画元表示位置

	//切取位置の設定	
	if (m_key_z == true)
	{
		//Ｚキー
		if (m_muki == 0)
		{
		src.m_top = 96.0f;
		src.m_left = 0.0f + (m_motion_attack * 32) + (1 * mutekie);
		src.m_right = 32.0f + (m_motion_attack * 32) + (1 * mutekie);
		src.m_bottom = src.m_top + 32.0f;
		}
		else
		{
			src.m_top = 96.0f;
			src.m_left = 32.0f + (m_motion_attack * 32) + (1 * mutekie);
			src.m_right = 0.0f + (m_motion_attack * 32) + (1 * mutekie);
			src.m_bottom = src.m_top + 32.0f;
		}


	}
	else if (m_jump == true)
	{
		if (Input::GetVKey(VK_RIGHT) == true)
		{
		//ジャンプ＋右
		src.m_top = 0.0f + (1 * mutekie);
		src.m_left = 128.0f + (1 * mutekie);
		src.m_right = 160.0f + (1 * mutekie);
		src.m_bottom = 32.0f + (1 * mutekie);
		}
		else
		{
		//ジャンプ＋左
		src.m_top = 0.0f + (1 * mutekie);
		src.m_left = 160.0f + (1 * mutekie);
		src.m_right = 128.0f + (1 * mutekie);
		src.m_bottom = 32.0f + (1 * mutekie);
		}

	}	
	else if (Input::GetVKey(VK_RIGHT) == true)
	{
		//右キー
		src.m_top = 0.0f + (1 * mutekie);
		src.m_left = 0.0f + (m_motion_walk * 32.0f) + (1 * mutekie);
		src.m_right = 32.0f + (m_motion_walk * 32.0f) + (1 * mutekie);
		src.m_bottom = 32.0f + (1 * mutekie);
	}
	else if (Input::GetVKey(VK_LEFT) == true)
	{
		//左キー
		src.m_top = 0.0f + (1 * mutekie);
		src.m_left = 32.0f + (m_motion_walk * 32.0f) + (1 * mutekie);
		src.m_right = 0.0f + (m_motion_walk * 32.0f) + (1 * mutekie);
		src.m_bottom = 32.0f + (1 * mutekie);
	}
	else
	{
		if (m_muki == 0)
		{
			//止まり右
			src.m_top = 0.0f + (1 * mutekie);
			src.m_left = 0.0f + (1 * mutekie);
			src.m_right = 32.0f + (1 * mutekie);
			src.m_bottom = 32.0f + (1 * mutekie);
		}
		else
		{
			//止まり左
			src.m_top = 0.0f + (1 * mutekie);
			src.m_left = 32.0f + (1 * mutekie);
			src.m_right = 0.0f + (1 * mutekie);
			src.m_bottom = 32.0f + (1 * mutekie);
		}

	}

	//表示位置の設定
	dst.m_top	 =   0.0f + m_py;
	dst.m_left	 =   0.0f + m_px;
	dst.m_right	 = 64.0f + m_px;
	dst.m_bottom = 64.0f + m_py;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}

/*
作りたい動きリスト
左右移動→ほぼ完成です
ジャンプ→動作にまだ難あり
着地→できてません
ダッシュ→○
攻撃→途中です

*/