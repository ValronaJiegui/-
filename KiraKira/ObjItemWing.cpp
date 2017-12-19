//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "SceneMain.h"
#include "ObjItemWing.h"
#include "ObjLei.h"
#include"ObjBlock.h"

//使用するネームスペース
using namespace GameL;

void CObjItemWing::Init()
{
	m_time = 0;
	Flag = false;
	animation = 0;
}

void CObjItemWing::Action()
{
	//主人公の座標の値を確保
	CObjLei *hero = (CObjLei*)Objs::GetObj(OBJ_LEI);
	float m_x = hero->GetX();
	float m_y = hero->GetY();

	//アニメーション動かす用
	m_time++;

	if (m_time >= 30)
	{
		animation += 1;
		if (animation >= 2)
			animation = 0;
		m_time = 0;
	}

	//ゲット判定（テスト用）
	if (m_x <= 364.0f && m_x >= 280.0f)
	{
		if (m_y >= 450.0f && m_y <= 569.0f) {
			Flag = true;
		}
	}
}

void CObjItemWing::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切取位置
	RECT_F dst;//描画元表示位置

	//切取位置の設定
	src.m_top = 0.0f;
	src.m_left = 192.0f + animation * 32;
	src.m_right = 224.0f + animation * 32;
	src.m_bottom = 32.0f;

	if (Flag == false) {
		//表示位置の設定
		dst.m_top = 485.0f;
		dst.m_left = 300.0f;
		dst.m_right = 364.0f;
		dst.m_bottom = 549.0f;
	}

	Draw::Draw(3, &src, &dst, c, 0.0f);
}