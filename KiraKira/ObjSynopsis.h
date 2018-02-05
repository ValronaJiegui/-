#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：あらすじ
class CObjSynopsis :public CObj
{
private:
	int m_time;
	bool m_mou_l;
	bool m_mou_r;
	bool m_f;
public:
	CObjSynopsis();
	~CObjSynopsis();
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
	bool flag;
	bool flag2;
	bool flag3;
	bool flag4;
	bool flag5;
	bool flag6;
	bool flag7;
	bool flag8;
};