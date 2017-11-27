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
private:
	float m_px;//位置X
	float m_py;//位置Y
	float m_vx;//移動X(ベクトル)
	float m_vy;//移動Y(ベクトル)
	int m_time;
	int m_aruku;
	bool m_jump;
	bool m_dash;
	bool m_z_key;
};