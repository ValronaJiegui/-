//使用するヘッダーファイル
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "Gamehead.h"
#include "ObjSynopsis.h"

//使用するネームスペース
using namespace GameL;

CObjSynopsis::CObjSynopsis()
{
}


CObjSynopsis::~CObjSynopsis()
{
}

//イニシャライズ
void CObjSynopsis::Init()
{
	flag = false;
	flag2 = false;
	flag3 = false;
	flag4 = false;
	flag5 = false;
	flag6 = false;
	flag7 = false;
	flag8 = false;
	m_mou_l = false;
	m_mou_r = false;
	m_f = true;
}

//アクション
void CObjSynopsis::Action()
{
	m_mou_l = Input::GetMouButtonL();
	m_mou_r = Input::GetMouButtonR();

	//初めて左クリックが押されたとき
	if (m_mou_l == true && flag == false)
	{
		if (m_f == true)
		{
			flag = true;
			m_f = false;
		}
	}
	//2回目に左クリックが押されたとき
	else if (m_mou_l == true && flag == true && flag2 == false)
	{
		if (m_f == true)
		{
			flag2 = true;
			m_f = false;
		}
	}
	//3回目に左クリックが押されたとき
	else if (m_mou_l == true && flag2 == true && flag3 == false)
	{
		if (m_f == true)
		{
			flag3 = true;
			m_f = false;
		}
	}
	//4回目に左クリックが押されたとき
	else if (m_mou_l == true && flag3 == true && flag4 == false)
	{
		if (m_f == true)
		{
			flag4 = true;
			m_f = false;
		}
	}
	//5回目に左クリックが押されたとき
	else if (m_mou_l == true && flag4 == true && flag5 == false)
	{
		if (m_f == true)
		{
			flag5 = true;
			m_f = false;
		}
	}
	//6回目に左クリックが押されたとき
	else if (m_mou_l == true && flag5 == true && flag6 == false)
	{
		if (m_f == true)
		{
			flag6 = true;
			m_f = false;
		}
	}
	//7回目に左クリックが押されたとき
	else if (m_mou_l == true && flag6 == true && flag7 == false)
	{
		if (m_f == true)
		{
			flag7 = true;
			m_f = false;
		}
	}
	//8回目に左クリックが押されたとき（ステージセレクト）
	else if (m_mou_l == true && flag7 == true && flag8 == false)
	{
		if (m_f == true)
		{
			Scene::SetScene(new CSceneStageSelect());
		}
	}
	else
	{
		m_f = true;
	}

	//エンターキーを押してステージセレクト画面に移行する
	if (m_mou_r == true)
	{
		Scene::SetScene(new CSceneStageSelect());
	}
}

//ドロー
void CObjSynopsis::Draw()
{
	float  c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float  cText[4] = { 0.0f,0.0f,0.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1010.0f;
	src.m_bottom = 1010.0f;

	//背景位置の設定し描画
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(0, &src, &dst, c, 0.0f);



	if (flag == false)
	{
		Draw::LoadImageW(L"Synopsis rei2.png", 0, TEX_SIZE_1024);
		Font::StrDraw(L"レイ", 130, 334, 40, cText);
		Font::StrDraw(L"「・・・・・・・・・・・・・・・・・・・・　", 120, 400, 22, cText);
		Font::StrDraw(L"　・・・・・・・・・・・・・・・・・・・・　", 120, 430, 22, cText);
		Font::StrDraw(L"　・・・・・・・・・・・・・・・・・・・・」", 120, 460, 22, cText);
	}
	else if (flag == true && flag2 == false)
	{
		Draw::LoadImageW(L"Synopsis rei.png", 0, TEX_SIZE_1024);
		Font::StrDraw(L"主人公のレイはインターネットで", 120, 400, 22, cText);
		Font::StrDraw(L"配信者として活動している高校生。", 120, 430, 22, cText);
		Font::StrDraw(L"今日もいつも通り配信をしているようだ。", 120, 460, 22, cText);
	}
	else if (flag2 == true && flag3 == false)
	{
		Draw::LoadImageW(L"Synopsis reikirari2.png", 0, TEX_SIZE_1024);
		Font::StrDraw(L"配信終了後、今度はキラリの配信を見始めた。", 120, 400, 22, cText);
		Font::StrDraw(L"キラリはレイの憧れの配信者だ。", 120, 430, 22, cText);
		Font::StrDraw(L"しかし...？", 120, 460, 22, cText);
	}
	else if (flag3 == true && flag4 == false)
	{
		Draw::LoadImageW(L"Synopsis rei2kirari.png", 0, TEX_SIZE_1024);
		Font::StrDraw(L"レイ", 130, 334, 40, cText);
		Font::StrDraw(L"「...?」", 120, 400, 22, cText);
		Font::StrDraw(L"「！！」", 120, 430, 22, cText);
	}
	else if (flag4 == true && flag5 == false)
	{
		Font::StrDraw(L"キラリは先程のレイの配信を晒し上げ笑っていた。", 120, 400, 22, cText);
		Font::StrDraw(L"その後レイは炎上してしまう。", 120, 430, 22, cText);
	}
	else if (flag5 == true && flag6 == false)
	{
		Draw::LoadImageW(L"Synopsis.png", 0, TEX_SIZE_1024);
		Font::StrDraw(L"しばらく日が経過し...", 120, 400, 22, cText);
	}
	else if (flag6 == true && flag7 == false)
	{
		Draw::LoadImageW(L"Synopsis rei.png", 0, TEX_SIZE_1024);
		Font::StrDraw(L"レイの父", 90, 334, 40, cText);
		Font::StrDraw(L"「お前のせいで家庭はめちゃくちゃだ！", 120, 400, 22, cText);
		Font::StrDraw(L"　住所までバレて悪戯電話も鳴りっぱなしだし、", 120, 430, 22, cText);
		Font::StrDraw(L"　会社でも肩身が狭い。", 120, 460, 22, cText);
		Font::StrDraw(L"　どうしてくれるんだ！」", 120, 490, 22, cText);
	}
	else if (flag7 == true && flag8 == false)
	{
		Draw::LoadImageW(L"Synopsis rei2.png", 0, TEX_SIZE_1024);
		Font::StrDraw(L"レイはキラリに復讐するために駅まで向かうようだ。", 120, 400, 22, cText);
	}
}