#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：きらり
class CObjKirari : public CObj
{
public:
	CObjKirari(float x, float y);
	~CObjKirari() {};
	void Init();
	void Action();
	void Draw();

private:
	int m_hp;

	float m_x;
	float m_y;
	float m_vx;
	float m_vy;

};