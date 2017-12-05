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
	void Init();
	void Action();
	void Draw();
private:
	int m_time;
	int animation;
};