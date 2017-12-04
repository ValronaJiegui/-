//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameHead.h"
#include"window_create.h"

//使用するネームスペース
using namespace GameL;

CObjwindow::CObjwindow()
{
}


CObjwindow::~CObjwindow()
{
}

//イニシャライズ
void CObjwindow::Init()
{

}

//アクション
void CObjwindow::Action()
{

}

//ドロー
void CObjwindow::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top    =    0.0f;
	src.m_left   =    0.0f;
	src.m_right  =  260.0f;
	src.m_bottom =  200.0f;

	dst.m_top    =  100.0f;
	dst.m_left   =  -50.0f;
	dst.m_right  =  820.0f;
	dst.m_bottom =  600.0f;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}