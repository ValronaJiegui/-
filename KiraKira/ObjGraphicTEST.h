#pragma once
#include"GameL\SceneObjManager.h"
using namespace GameL;

class CObjGraphicTEST :public CObj
{
public:
	CObjGraphicTEST() {};
	~CObjGraphicTEST(){};
	void Init();	//初期設定
	void Action();	//動作内容
	void Draw();	//描画情報
	float GetX() { return m_px; }
	float GetY() { return m_py; }
	float GetVX() { return m_vx; }
	float GetVY() { return m_vy; }
	void SetX(float x) { m_px = x; return; }
	void SetY(float y) { m_py = y; return; }
	void SetVX(float vx) { m_vx = vx; return; }
	void SetVY(float vy) { m_vy = vy; return; }

private:
	float m_px;//位置X
	float m_py;//位置Y
	float m_vx;//移動X(ベクトル)
	float m_vy;//移動Y(ベクトル)
	int m_time;
	int m_motion_walk;
	int m_motion_attack;
	bool m_jump;
	bool m_dash;
	bool m_key_z;
};