//使用するヘッダーファイル
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "Gamehead.h"
#include "ObjTitle.h"
#include "SceneMain.h"
#include"Stage1.h"

#include "GameL\DrawTexture.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjTitle::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;

	m_mou_l = false;
}

//アクション
void CObjTitle::Action()
{
	bool NEW = false;
	bool LOAD = false;
	bool FINISH = false;

	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//マウスの位置確認
	if (m_mou_x > 30 && m_mou_x < 512 && m_mou_y>293 && m_mou_y < 357&& m_mou_l == false)
			NEW = true;
	else if (m_mou_x > 30 && m_mou_x < 512 && m_mou_y>398 && m_mou_y < 462&& m_mou_l == false)
			LOAD = true;
	else if (m_mou_x > 30 && m_mou_x < 512 && m_mou_y>507 && m_mou_y < 571&& m_mou_l == false)
			FINISH = true;

	//マウスのボタンの状態
	m_mou_l = Input::GetMouButtonL();

	//_NEW_GAME_が押されたらメインに切り替える
	if (m_mou_l == true && NEW == true)
	{
		Scene::SetScene(new CStage1());
	}
	//_LOAD_GAME_が押されたら
	else if (m_mou_l == true && LOAD == true)
	{
		//ここに処理を書く
	}
	//_FINISH_GAME_が押されたらゲームを終了する
	else if (m_mou_l == true && FINISH == true)
	{
		exit(1);
	}

}

//ドロー
void CObjTitle::Draw()
{
	//カーソルが特定の箇所ならへこませる
	if (m_mou_x > 30 && m_mou_x < 512 && m_mou_y>293 && m_mou_y < 357)
		Draw::LoadImageW(L"NEW GAME.png", 0, TEX_SIZE_1024);
	else if (m_mou_x > 30 && m_mou_x < 512 && m_mou_y>398 && m_mou_y < 462)
		Draw::LoadImageW(L"LOAD GAME.png", 0, TEX_SIZE_1024);
	else if (m_mou_x > 30 && m_mou_x < 512 && m_mou_y>507 && m_mou_y < 571)
		Draw::LoadImageW(L"FINISH GAME.png", 0, TEX_SIZE_1024);
	else
		Draw::LoadImageW(L"Title.png", 0, TEX_SIZE_1024);

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画先切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1010.0f;
	src.m_bottom = 1000.0f;

	//背景位置の設定し描画
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}