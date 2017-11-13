#pragma once
#include"GameL\SceneManager.h"
using namespace GameL;

class CSceneMain :public CScene
{
public:
	CSceneMain();
	~CSceneMain();
	void InitScene();	//初期化の操作(メソッド)
	void Scene();		//実行中の操作(メソッド)
private:
};