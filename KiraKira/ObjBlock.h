#pragma once
#include"GameL\SceneObjManager.h"
#include"GameHead.h"
#include"GameL\DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�u���b�N&�w�i
class CObjBlock :public CObj
{
public:
	CObjBlock(int map[10][100]);
	~CObjBlock() {};
	void Init();
	void Action();
	void Draw();

	void SetScroll(float s) { m_scroll = s; }
	float GetScroll() { return m_scroll; }

private:
	void BlockDraw(float x, float y, RECT_F* dst, float c[]);
	int m_map[10][100];
	float m_scroll;//���E�X�N���[���p
	float hx;
	float hy;
};