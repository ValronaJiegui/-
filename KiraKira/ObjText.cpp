//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjText.h"

//使用するネームスペース
using namespace GameL;

CObjText::CObjText()
{
}


CObjText::~CObjText()
{
}

//イニシャライズ
void CObjText::Init()
{
	m_time = 0;
}

//アクション
void CObjText::Action()
{
		if (Input::GetVKey(VK_RETURN) == true)
		{
			m_time -= 0.01f;
		}
}

//ドロー
void CObjText::Draw()
{
	float  c1[4] = { 1.0f,1.0f,1.0f,1.0f };
	float  cText[4] = { 0.0f,0.0f,0.0f,1.0f};
	float  cTextOut[4] = { 0.0f,0.0f,0.0f,1.0f + m_time };

	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 256.0f;
	src.m_bottom = 256.0f;

	dst.m_top = 0.0f;
	dst.m_left = -90.0f;
	dst.m_right = 880.0f;
	dst.m_bottom = 850.0f;

	Draw::Draw(3, &src, &dst, c1, 0.0f);


	//エンターキーを押してフェードアウト
	if (Input::GetVKey(VK_RETURN) == true)
	{
		Font::StrDraw(L"足が２０本ぐらいある怪獣になりたい！！", 30, 400, 32, cTextOut);
		Font::StrDraw(L"その後にかまぼこ板に磔にされたい！！", 30, 450, 32, cTextOut);
	}
	else
	{
	Font::StrDraw(L"足が２０本ぐらいある怪獣になりたい！！", 30, 400, 32, cText);
	Font::StrDraw(L"その後にかまぼこ板に磔にされたい！！", 30, 450, 32, cText);
	}
}
