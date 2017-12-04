#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjGraphicTEST.h"

using namespace GameL;

//初期設定(イニシャライズ)////////////////////
void CObjGraphicTEST::Init()
{
	m_px = 0.0f;
	m_py = 0.0f;
	m_vx = 0.0f;
	m_vy = 10.0f;
	m_time = 0;
	m_aruku = 0;
	m_jump = false;
	m_dash = false;
	m_z_key = false;
	m_f = false;
}
//動作内容(アクション)////////////////////////
void CObjGraphicTEST::Action()
{
	//翼が取れたとき、フラグを立てる
	CObjItemWing *wing = (CObjItemWing*)Objs::GetObj(OBJ_ITEM_WING);
	bool Flag = wing->GetFlag();

	if (m_py >= 480.0f) {
		m_vy = -9.8 / (16.0f);
		m_jump = false;
	}

	//キー入力されたときの処理
	if (Input::GetVKey(VK_RIGHT) == true)
	{ 
		m_vx = 5.0f;

		//左右同時押しされたら停止
		if (Input::GetVKey(VK_LEFT) == true)
		{
			m_vx = 0.0f;
		}
	}
	if (Input::GetVKey(VK_LEFT) == true)
	{ 
		m_vx = -5.0f;
		if (Input::GetVKey(VK_RIGHT) == true)
		{
			m_vx = 0.0f;
		}
		if (Input::GetVKey(VK_SHIFT) == true)
		{
			m_vx = -4.0f;
		}
	}
	if (Input::GetVKey(VK_UP) == true)
	{
		if (m_f == false)
		{
			if (Flag == false)
			{
				if (m_jump == false) {
					m_vy = -10.0f;
					m_jump = true;
				}
			}
			else
			{
				if (m_jump == false)
				{
					m_vy = -25.0f;
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

	if (Flag == true && m_jump == true)
	{
		if(m_time <= 40)
			m_time++;
		if (m_time >= 40 && m_time <= 200)
			if (Input::GetVKey(VK_UP) == true)
			{
				m_vy = 0;
				m_time++;
			}
	}
	else
		m_time = 0;

	m_vx += -(m_vx*0.098);
	m_vy += 9.8 / (16.0f);

	//移動を位置に反映する
	m_px += m_vx;
	m_py += m_vy;
}
//描画情報(ドロー)////////////////////////////
void CObjGraphicTEST::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切取位置
	RECT_F dst;//描画元表示位置

	//切取位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 32.0f;
	src.m_bottom = 32.0f;

	//表示位置の設定
	dst.m_top	 =   0.0f + m_py;
	dst.m_left	 =   0.0f + m_px;
	dst.m_right	 = 64.0f + m_px;
	dst.m_bottom = 64.0f + m_py;

	Draw::Draw(1, &src, &dst, c, 0.0f);
}