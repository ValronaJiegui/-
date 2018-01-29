#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

class CObjAnten:public CObj
{
private:
	float Alpha;
	bool Kaishi;
public:
	CObjAnten();
	~CObjAnten();
	void Init();
	void Action();
	void Draw();
	void Start() { Kaishi = true; }
	void End() { Kaishi = false; }
};

