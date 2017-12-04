#pragma once
#include"GameL\SceneObjManager.h"
#include"GameHead.h"
#include"GameL\DrawTexture.h"

//使用するネームスペース
using namespace GameL;

#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ブロック&背景
class CObjBlock :public CObj
{
public:
	CObjBlock(int map[10][100]);
	~CObjBlock() {};
	void Init();
	void Action();
	void Draw();

	void SetScroll(float s) { m_scroll = s; }
	float GetScroll() { return m_scroll; }

private:
	void BlockDraw(float x, float y, RECT_F* dst, float c[]);
	int m_map[10][100]; //マップ情報

	float m_scroll;//左右スクロール用
	float hx;
	float hy;
};