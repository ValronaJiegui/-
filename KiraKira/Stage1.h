#pragma once
#include"GameL\SceneManager.h"
using namespace GameL;

class CStage1:public CScene
{
public:
	CStage1();
	~CStage1();
	void InitScene();	//初期化の操作(メソッド)
	void Scene();
private:
	int m_map[10][100];
};

