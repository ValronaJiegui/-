//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"

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

}

//アクション
void CObjText::Action()
{

}

//ドロー
void CObjText::Draw()
{
	float  c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"しまうま", 0, 0, 32, c);
}
