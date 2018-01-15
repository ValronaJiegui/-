#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "ObjLei.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：アイテム
class CObjItemWing : public CObj
{
public:
	CObjItemWing() {};
	~CObjItemWing() {};
	void Init() ;
	void Action() ;
	void Draw() ;
	bool GetFlag() { return Flag; }

	void SetItemWing(float rx, float lx, float ty, float by);
private:
	int m_time;
	int animation;
	bool Flag;

	float top;
	float left;
	float right;
	float bottom;
	float m_scroll;
};