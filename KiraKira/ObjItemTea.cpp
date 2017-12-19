//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "SceneMain.h"
#include "ObjLei.h"
#include "ObjItemTea.h"

//使用するネームスペース
using namespace GameL;

void CObjItemTea::Init()
{
	m_time = 0;
	animation = 0;
	Flag = false;

	//以下テスト用---
	top = 0.0f;
	left = 400.0f;
	right = 464.0f;
	bottom = 64.0f;
}

void CObjItemTea::Action()
{
	//主人公の座標の値を確保
	CObjLei *hero = (CObjLei*)Objs::GetObj(OBJ_LEI);
	float m_x = hero->GetX();
	float m_y = hero->GetY();

	m_time++;
	if (m_time >= 60)
	{
		animation += 1;
		if (animation >= 2)
			animation = 0;
		m_time = 0;
	}

	//ゲット判定（テスト用）
	if (m_x <= right - 50.0f && m_x >= left)
	{
		if (m_y >= top - 50.0f && m_y <= bottom) {
			Flag = true;
		}
	}
}

void CObjItemTea::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切取位置
	RECT_F dst;//描画元表示位置

	//切取位置の設定
	src.m_top = 0.0f;
	src.m_left = 96.0f + animation * 32;
	src.m_right = 127.0f + animation * 32;
	src.m_bottom = 32.0f;

	if (Flag == false) {
		//表示位置の設定
		dst.m_top = top;
		dst.m_left = left;
		dst.m_right = right;
		dst.m_bottom = bottom;
	}

	Draw::Draw(3, &src, &dst, c, 0.0f);
}

void CObjItemTea::SetItemTea(float rx, float lx, float ty, float by)
{
	top = ty;
	left = lx;
	right = rx;
	bottom = by;

	return;
}