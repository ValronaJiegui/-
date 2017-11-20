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
	m_vy = 0.0f;
}
//動作内容(アクション)////////////////////////
void CObjGraphicTEST::Action()
{
	//移動を減速(毎時)
	m_vx *= 0.75f;
	m_vy *= 0.75f;

	//キー入力されたときの処理
	if (Input::GetVKey(VK_RIGHT) == true)
	{ 
		m_vx = +5.0f; 
		//左右同時押しされたら停止
		if (Input::GetVKey(VK_LEFT) == true)
		{
			m_vx = 0.0f;
		}
	}
	if (Input::GetVKey(VK_LEFT) == true)
	{ 
		m_vx = -5.0f; 
		//左右同時押しされたら停止
		if (Input::GetVKey(VK_RIGHT) == true)
		{
			m_vx = 0.0f;
		}
	}
	if (Input::GetVKey(VK_UP) == true)
	{
		m_vy += 5.0f;
	}

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
	src.m_right = 8.0f;
	src.m_bottom = 8.0f;

	//表示位置の設定
	dst.m_top	 =   0.0f + m_py;
	dst.m_left	 =   0.0f + m_px;
	dst.m_right	 = 32.0f + m_px;
	dst.m_bottom = 32.0f + m_py;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}