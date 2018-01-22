//使用するヘッダーファイル
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "Gamehead.h"
#include "ObjStageSelect.h"
#include "SceneMain.h"

#include "GameL\DrawTexture.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjStageSelect::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;

	m_mou_l = false;

	//ステージがクリアされたらtrueにする
	//例　ステージ１クリア→CLEAR1=true
	bool CLEAR1 = false;
	bool CLEAR2 = false;
}

//アクション
void CObjStageSelect::Action()
{
	bool TITLE = false;
	bool STAGE1 = false;
	bool STAGE2 = false;

	//クリア判定
	if (0/*ステージ１をクリアしている場合の処理をここに書く*/)
		CLEAR1 == true;
	if (0/*ステージ２をクリアしている場合の処理をここに書く*/)
		CLEAR2 == true;

	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	if (m_mou_x > 25 && m_mou_x < 259 && m_mou_y>505 && m_mou_y < 569 && m_mou_l == false)
	{
		TITLE = true;
	}

	else if (m_mou_x > 143 && m_mou_x < 243 && m_mou_y>157 && m_mou_y < 257 && m_mou_l == false)
	{
		STAGE1 = true;
	}

	else if (m_mou_x > 555 && m_mou_x < 655 && m_mou_y>157 && m_mou_y < 257 && CLEAR1 == true && m_mou_l == false)
	{
		STAGE2 = true;
	}

	//マウスのボタンの状態
	m_mou_l = Input::GetMouButtonL();

	//タイトルが押されたらタイトルに戻る
	if (m_mou_l == true && TITLE == true)
	{
		Scene::SetScene(new CSceneTitle());
	}

	//ステージ１が押されたとき
	else if (m_mou_l == true && STAGE1 == true)
	{
		//ステージ１へ行く処理をここに書く
		Scene::SetScene(new CSceneMain());
		//CLEAR1 = true;
	}

	//ステージ２が押されたとき
	else if (m_mou_l == true && STAGE2 == true)
	{
		CLEAR2 = true;
	}
}

//ドロー
void CObjStageSelect::Draw()
{
	//カーソルが特定の箇所ならへこませる
	//ステージ２をクリアしているとき
	if (CLEAR2 == true)
	{
		if (m_mou_x > 25 && m_mou_x < 259 && m_mou_y>505 && m_mou_y < 569)
		{
			Draw::LoadImageW(L"STAGEB-TITLE.png", 0, TEX_SIZE_1024);
		}
		else if (m_mou_x > 143 && m_mou_x < 243 && m_mou_y>157 && m_mou_y < 257)
		{
			Draw::LoadImageW(L"STAGEB-1.png", 0, TEX_SIZE_1024);
		}
		else if (m_mou_x > 555 && m_mou_x < 655 && m_mou_y>157 && m_mou_y < 257)
		{
			Draw::LoadImageW(L"STAGEB-2.png", 0, TEX_SIZE_1024);
		}
		else if (m_mou_x > 294 && m_mou_x < 503 && m_mou_y>296 && m_mou_y < 419)
		{
			Draw::LoadImageW(L"STAGEB-B.png", 0, TEX_SIZE_1024);
		}
		else
			Draw::LoadImageW(L"STAGEB.png", 0, TEX_SIZE_1024);
	}
	//ステージ１をクリアしているとき
	else if (CLEAR1 == true)
	{
		if (m_mou_x > 25 && m_mou_x < 259 && m_mou_y>505 && m_mou_y < 569)
		{
			Draw::LoadImageW(L"STAGE2-TITLE.png", 0, TEX_SIZE_1024);
		}
		else if (m_mou_x > 143 && m_mou_x < 243 && m_mou_y>157 && m_mou_y < 257)
		{
			Draw::LoadImageW(L"STAGE2-1.png", 0, TEX_SIZE_1024);
		}
		else if (m_mou_x > 555 && m_mou_x < 655 && m_mou_y>157 && m_mou_y < 257)
		{
			Draw::LoadImageW(L"STAGE2-2.png", 0, TEX_SIZE_1024);
		}
		else
			Draw::LoadImageW(L"STAGE2.png", 0, TEX_SIZE_1024);
	}
	//どこもクリアしていないとき
	else
	{
		if (m_mou_x > 25 && m_mou_x < 259 && m_mou_y>505 && m_mou_y < 569)
		{
			Draw::LoadImageW(L"STAGE1-TITLE.png", 0, TEX_SIZE_1024);
		}
		else if (m_mou_x > 143 && m_mou_x < 243 && m_mou_y>157 && m_mou_y < 257)
		{
			Draw::LoadImageW(L"STAGE1-1.png", 0, TEX_SIZE_1024);
		}
		else
			Draw::LoadImageW(L"STAGE1.png", 0, TEX_SIZE_1024);
	}
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画先切り取り位置
	RECT_F dst;//描画先表示位置

			   //切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1020.0f;
	src.m_bottom = 1020.0f;

	//背景位置の設定し描画
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}