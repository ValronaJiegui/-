//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "SceneMain.h"
#include "ObjItemTea.h"

//使用するネームスペース
using namespace GameL;

void CObjItemTea::Init()
{
	m_time = 0;
	animation = 0;
}

void CObjItemTea::Action()
{
	m_time++;
	if (m_time >= 60)
	{
		animation += 1;
		if (animation >= 2)
			animation = 0;
		m_time = 0;
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

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 64.0f;
	dst.m_bottom = 64.0f;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}