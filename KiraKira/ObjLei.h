#pragma once
#include"GameL\SceneObjManager.h"
using namespace GameL;

class CObjLei :public CObj
{
public:
	CObjLei() {};
	~CObjLei() {};
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

	//ジャンピング設定設置関数！
	//説明：
	//レイのジャンピング変数の状態を
	//外部から指定するときに使えます！(Blockの判定等)
	//
	//引数のとこに true か false を入力すると
	//レイのm_jumpingが 
	//　　　　その true か false が指定されます
	void SetJumping(bool a) { if (a == true) { m_jumping = true; } else { m_jumping = false; } }

	//バウンド関数！
	//説明：
	//何か(壁や敵など)に衝突したとき
	//レイを跳ね返して
	//めり込みなどを防ぎます！
	//引数無し
	void SetVXBound() { m_vx = -m_vx / 4; }
	void SetVYBound() { m_vy = -m_vy / 4; }

	//ジャンプ初期化関数！
	//外部からジャンプ値をfalseにセットできます
	void SetJump() { m_jumping = false; m_jump = false; }

	int GetMuki() { return m_muki; }

	//セットHP関数！
	//レイのHPを 引数の分だけ加算します！
	//※※※ダメージの場合、引数をマイナス値にしてください！
	void SetHP(int i) { m_HP += i; return; }


private:
	float m_px;//位置X
	float m_py;//位置Y
	float m_vx;//移動X(ベクトル)
	float m_vy;//移動Y(ベクトル)

	bool houkou;//主人公の向きを知るためのデータ

	int m_wtime;
	int m_motion_walk;
  //2段以上ジャンプしない用
	bool m_key_z;
	bool m_f;      //ジャンプ制御
	bool z_flag;


	//blockとの衝突状態確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	//踏んでいるblockの種類を確認用
	int m_block_type;

	//状態判定(方向、浮遊など)
	bool m_jump;
	bool m_dash;
	int m_muki;
	bool m_jumping;
	bool m_live_tama;

	//無敵判定（被弾時少しの間無敵）
	int muteki;
	int muteki_time;
	int mutekie;
	bool hutobi;
	bool hantei;
	int xcount;

	//モーション描画用変数
	int m_time;
	int m_motion_attack;

	//HP!
	int m_HP;
};