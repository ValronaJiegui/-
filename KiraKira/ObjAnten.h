#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
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

