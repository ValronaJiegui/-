#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：テキスト
class CObjText:public CObj
{
public:
	CObjText();
	~CObjText();
	void Init();
	void Action();
	void Draw();
private:
};

