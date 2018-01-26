#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：アイテム
class CObjItemTea : public CObj
{
public:
	CObjItemTea() {};
	~CObjItemTea() {};
	void Init() ;
	void Action() ;
	void Draw() ;

	void SetItemTea(float rx, float lx, float ty, float by);
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