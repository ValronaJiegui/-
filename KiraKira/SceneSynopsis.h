#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：あらすじ
class CSceneSynopsis :public CScene
{
public:
	CSceneSynopsis();
	~CSceneSynopsis();
	void InitScene();	//ゲームタイトルの初期化メソッド
	void Scene();		//ゲームタイトルの実行中メソッド
private:

};