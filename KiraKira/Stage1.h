#pragma once
#include"GameL\SceneManager.h"
using namespace GameL;

class CStage1:public CScene
{
public:
	CStage1();
	~CStage1();
	void InitScene();	//�������̑���(���\�b�h)
	void Scene();
private:
	int m_map[10][100];
};

