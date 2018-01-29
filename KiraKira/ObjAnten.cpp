//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"

#include"GameHead.h"


CObjAnten::CObjAnten()
{

}
CObjAnten::~CObjAnten()
{

}

void CObjAnten::Init()
{
	Alpha = 1.0f;
	Kaishi= false;
}

void CObjAnten::Action()
{
	if (Kaishi == true && Alpha <= 1.0f)
	{
		Alpha += 0.1f;
	}
	if (Kaishi == false && Alpha >= 0.0f)
	{
		Alpha -= 0.1f;
	}
	if (Alpha < 0.0f)
	{
		Alpha = 0.0f;
	}
}

void CObjAnten::Draw()
{
	//暗転用黒背景読み込み
	Draw::LoadImageW(L"Black.png", 9, TEX_SIZE_512);

	float c[4] = { 1.0f,1.0f,1.0f,Alpha };

	RECT_F src;//描画先切り取り位置
	RECT_F dst;//描画先表示位置

	//切取位置設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 256.0f;
	src.m_bottom = 256.0f;

	//表示位置設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(9, &src, &dst, c, 0.0f);
}