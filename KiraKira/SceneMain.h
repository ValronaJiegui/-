#pragma once
#include"GameL\SceneManager.h"
using namespace GameL;

class CSceneMain :public CScene
{
public:
	CSceneMain();
	~CSceneMain();
	void InitScene();	//�������̑���(���\�b�h)
	void Scene();		//���s���̑���(���\�b�h)
private:
};