#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

class CObjwindow :public CObj
{
public:
	CObjwindow();
	~CObjwindow();
	void Init();
	void Action();
	void Draw();
private:

};

