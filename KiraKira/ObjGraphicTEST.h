#pragma once
#include"GameL\SceneObjManager.h"
using namespace GameL;

class CObjGraphicTEST :public CObj
{
public:
	CObjGraphicTEST() {};
	~CObjGraphicTEST(){};
	void Init();	//�����ݒ�
	void Action();	//������e
	void Draw();	//�`����
};