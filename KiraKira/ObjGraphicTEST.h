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
	void SetBT(int t) { m_block_type = t; }

	void SetUp(bool b) { m_hit_up = b; }
	void SetDown(bool b) { m_hit_down = b; }
	void SetLeft(bool b) { m_hit_left = b; }
	void SetRight(bool b) { m_hit_right = b; }

private:
	float m_px;//位置X
	float m_py;//位置Y
	float m_vx;//移動X(ベクトル)
	float m_vy;//移動Y(ベクトル)
	int m_time;
	int m_motion_walk;
	bool m_jump;
	bool m_dash;
	bool m_z_key;
	int m_motion_attack;

	//blockとの衝突状態確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	//踏んでいるblockの種類を確認用
	int m_block_type;
};