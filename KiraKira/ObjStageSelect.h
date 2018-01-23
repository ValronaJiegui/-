#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトル
class CObjStageSelect :public CObj
{
public:
	CObjStageSelect() {};
	~CObjStageSelect() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー

					//ステージクリアしたらtrue
	bool CLEAR1;
	bool CLEAR2;

private:
	float m_mou_x;	//マウスの位置X
	float m_mou_y;	//マウスの位置Y
	bool m_mou_l;	//マウスの左ボタン


};