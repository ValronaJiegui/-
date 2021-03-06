//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"

#include"GameHead.h"
#include"ObjBlock.h"
#include"ObjLei.h"

//使用するネームスペース
using namespace GameL;



CObjBlock::CObjBlock(int map[10][100])
{
	//マップデータをコピー
	memcpy(m_map, map, sizeof(int)*(10 * 100));

}

//イニシャライズ
void CObjBlock::Init()
{
	m_scroll = 0.0f;

	m_x1 = 0.0f;
	m_x2 = 1024.0f;

}

//アクション
void CObjBlock::Action()
{
	//主人公の位置を取得
	CObjLei *test = (CObjLei*)Objs::GetObj(OBJ_LEI);
	hx = test->GetX();
	hy = test->GetY(); 
	//float MoveX = test->GetMoveX();

	//後方スクロールライン
	if (hx < 80)
	{
		test->SetX(80);//主人公はラインを超えないようにする
		m_scroll -= test->GetVX();//主人公が本来動くべき分の値をm_scrollに加える
	}

	//前方スクロールライン
	if (hx > 300)
	{
		test->SetX(300);
		m_scroll -= test->GetVX();
	}
	/*
	//主人公の衝突状態確認用のフラグの初期化
	test->SetUp(false);
	test->SetDown(false);
	test->SetLeft(false);
	test->SetRight(false);

	//踏んでいるblockの種類の初期化
	test->SetBT(0);

	//m_mapの全要素にアクセス
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (m_map[i][j] > 0)
			{
				//要素番号を座標に変更
				float x = j*64.0f;
				float y = i*64.0f;

				//主人公とブロックの当たり判定
				if (m_map[i][j] != 3)
				{
					if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
					{
						//上下左右判定

						//vectorの作成
						float vx = (hx + (-m_scroll)) - x;
						float vy = hy - y;

						//長さを求める
						float len = sqrt(vx*vx + vy*vy);

						//角度を求める
						float r = atan2(vy, vx);
						r = r*180.0f / 3.14f;

						if (r <= 0.0)
							r = abs(r);
						else
							r = 360.0f - abs(r);

						//lenがある一定の長さのより短い場合判定に入る
						if (len < 88.0f) {

							//角度で上下左右を判定
							if ((r < 45 && r>0) || r > 315)
							{
								//右
								test->SetRight(true);//主人公の左の部分が衝突している
								test->SetX(x + 64.0f + (m_scroll));//ブロックの位置＋主人公の幅
								//test->SetVX(-test->GetVX()*0.1f);//ーVX*反発定数
								test->SetVXBound();

							}
							if (r > 45 && r < 135)
							{
								//上
								test->SetDown(true);
								test->SetY(y - 64.0f);//ブロックの位置・主人公の幅
								//test->SetVY(0.0f);
								test->SetVYBound();
								test->SetJump();
								if (m_map[i][j] == 4)
								{
									Scene::SetScene(new CSceneTitle());
									break;
								}
								//種類を渡すのスタートとゴールのみ変更する
							   ///if (m_map[i][j] >= 4)
							   //	test->SetBT(m_map[i][j]);//ブロックの要素(type)を主人公に渡す


							}
							if (r > 135 && r < 225)
							{
								//左
								test->SetLeft(true);
								test->SetX(x - 64.0f + (m_scroll));
								//test->SetVX(-test->GetVX()*0.1f);
								test->SetVXBound();

							}
							if (r > 225 && r < 315)
							{
								//下
								test->SetUp(true);//主人公から見て、上の部分が衝突している
								test->SetY(+y + 66.0f);//ブロックの位置＋主人公の幅
								if (test->GetVY() < 0)
								{
									//test->SetVY(0.0f);
									test->SetVYBound();

								}
							}
						}
					}
				}
			}
		}

	}
	*/
}

//ドロー
void CObjBlock::Draw()
{
	//主人公の位置を取得
	CObjLei *test = (CObjLei*)Objs::GetObj(OBJ_LEI);

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//背景表示
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1024.0f;
	src.m_bottom = 540.0f;

	///////////////////////////////////背景の空
	for (int i = 1; i < 5; i++)
	{
		dst.m_top = 0.0f;
		dst.m_left = 0.0f + (m_scroll / 2) + (m_x2*(i - 1));
		dst.m_right = 1024.0f + (m_scroll / 2) + (m_x2*i);
		dst.m_bottom = 600.0f;
		Draw::Draw(7, &src, &dst, c, 0.0f);
	}
	/////////////////////////////////////////

	dst.m_top = 0.0f;
	dst.m_left = 0.0f + m_scroll;
	dst.m_right = 0.0f + m_scroll;
	dst.m_bottom = 0.0f;
	Draw::Draw(1, &src, &dst, c, 0.0f);

	for (int i = 0; i < 7; i++)
	{
		float plus_x = 0.0f;
		for (int j = 0; j < i; j++)
		{
			plus_x += m_x2;
		}
		dst.m_top = 0.0f;
		dst.m_left = 0.0f  + plus_x + m_scroll;
		dst.m_right = 1024.0f + plus_x + m_scroll;
		dst.m_bottom = 600.0f;
		Draw::Draw(1, &src, &dst, c, 0.0f);
	}
	
	/*
		dst.m_top = 0.0f;
		dst.m_left = 0.0f + m_scroll;
		dst.m_right = 965.0f + m_scroll;
		dst.m_bottom = 600.0f;
		Draw::Draw(1, &src, &dst, c, 0.0f);

		dst.m_top = 0.0f;
		dst.m_left = 965.0f + m_scroll;
		dst.m_right = 965.0f + m_x2 + m_scroll;
		dst.m_bottom = 600.0f;
		Draw::Draw(1, &src, &dst, c, 0.0f);

		dst.m_top = 0.0f;
		dst.m_left = 965.0f +965.0f+ m_scroll;
		dst.m_right = 965.0f+965.0f + m_x2 + m_scroll;
		dst.m_bottom = 600.0f;
		Draw::Draw(1, &src, &dst, c, 0.0f);

		dst.m_top = 0.0f;
		dst.m_left = 965.0f + 965.0f + 965.0f + m_scroll;
		dst.m_right = 965.0f + 965.0f + 965.0f + m_x2 + m_scroll;
		dst.m_bottom = 600.0f;
		Draw::Draw(1, &src, &dst, c, 0.0f);

		dst.m_top = 0.0f;
		dst.m_left = 965.0f + 965.0f + 965.0f + 965.0f + m_scroll;
		dst.m_right = 965.0f + 965.0f + 965.0f + 965.0f + m_x2 + m_scroll;
		dst.m_bottom = 600.0f;
		Draw::Draw(1, &src, &dst, c, 0.0f);

		dst.m_top = 0.0f;
		dst.m_left = 965.0f + 965.0f + 965.0f + 965.0f + 965.0f + m_scroll;
		dst.m_right = 965.0f + 965.0f + 965.0f + 965.0f + 965.0f + m_x2 + m_scroll;
		dst.m_bottom = 600.0f;

		dst.m_top = 0.0f;
		dst.m_left = 965.0f + 965.0f + 965.0f + 965.0f + 965.0f  + m_scroll;
		dst.m_right = 965.0f + 965.0f + 965.0f + 965.0f + 965.0f  + m_x2 + m_scroll;
		dst.m_bottom = 600.0f;
		Draw::Draw(1, &src, &dst, c, 0.0f);

		dst.m_top = 0.0f;
		dst.m_left = 965.0f + 965.0f + 965.0f + 965.0f + 965.0f + 965.0f  + m_scroll;
		dst.m_right = 965.0f + 965.0f + 965.0f + 965.0f + 965.0f + 965.0f  + m_x2 + m_scroll;
		dst.m_bottom = 600.0f;
		Draw::Draw(1, &src, &dst, c, 0.0f);
	*/


	//マップチップによるblock設置

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (m_map[i][j] > 0)
			{
				//表示位置の設定
				dst.m_top = i*64.0f;
				dst.m_left = j*64.0f + m_scroll;
				dst.m_right = dst.m_left + 64.0f;
				dst.m_bottom = dst.m_top + 64.0f;
				if (m_map[i][j] == 2)
				{
					BlockDraw(96.0f, 0.0f, &dst, c);
				}
				else if (m_map[i][j] == 3)
				{
					BlockDraw(0.0f, 32.0f, &dst, c);
				}
				else if (m_map[i][j]==4)
				{
					BlockDraw(0.0f, 192.0f, &dst, c);
				}
				else
				{
					BlockDraw(32.0f, 0.0f, &dst, c);

				}



				
			


			}
		}
	}




}
//BlockDrawMethod関数
//引数1　float x :リソース切り取り位置X
//引数2　float y :リソース切り取り位置Y
//引数3　RECT_F*F dst　:描画位置
//引数4　float c[]:カラー情報
//ブロックを64×64限定描画用。リソース切り取り位置のみx・yで
//設定できる

void CObjBlock::BlockDraw(float x, float y, RECT_F*dst, float c[])
{
	RECT_F src;
	src.m_top = y;
	src.m_left = x;
	src.m_right = src.m_left + 32.0f;
	src.m_bottom = src.m_top + 32.0f;


	//描画
	Draw::Draw(2, &src, dst, c, 0.0f);
}

//BlockHit関数
//引数1　float*x1:判定を行うobjectのX位置
//引数2　float*y2:判定を行うobjectのY位置
//引数3　bool	scroll_on:判定を行うobjectはスクロールの影響与えるかどうか（true=与える　false=与えない）
//引数4　bool*	up:上下左右の上部分に当たっているか動かを返す
//引数5　bool*	down:上下左右の下部分に当たっているか動かを返す
//引数6　bool*	left:上下左右の左部分に当たっているか動かを返す
//引数7　bool*	right:上下左右の右部分に当たっているか動かを返す
//引数8　float*vx	:左右判定時の反発による移動方向・力の値を変えて返す
//引数9　float*vy	:上下判定時の反発による移動方向・力の値を変えて返す
//引数10 int*bt		:下部分判定時、特殊なブロックのタイプを返す
//判定を行うobjectとブロック64*64限定で、当たり判定と左右当たり判定を行う
//その結果は引数4〜10に返す
void CObjBlock::BlockHit(
	float*x, float*y, bool scroll_on,
	bool*up, bool*down, bool*left, bool*right,
	float*vx, float*vy, int*bt
)
{
	//衝突状態確認用フラグの初期化
	*up = false;
	*down = false;
	*left = false;
	*right = false;
	//踏んでいるblockの種類の初期化
	*bt = 0;
	//m_mapの全要素にアクセス
	for (int i = 0; i<10; i++)
	{
		for (int j = 0; j<100; j++)
		{
			if (m_map[i][j]==1) {
				//要素番号を座標に変更
				float bx = j*64.0f;
				float by = i*64.0f;
				//スクロールの影響
				float scroll = scroll_on ? m_scroll : 0;
				//オブジェクトとブロックの当たり判定
				if ((*x + (-scroll) + 64.0f>bx) && (*x + (-scroll)<bx + 64.0f) && (*y + 64.0f>by) && (*y<by + 64.0f))
				{
					//上下左右判定

					//vectorの作成
					float rvx = (*x + (-scroll)) - bx;
					float rvy = *y - by;
					//長さを求める
					float len = sqrt(rvx*rvx + rvy*rvy);
					//角度を求める
					float r = atan2(rvy, rvx);
					r = r*180.0f / 3.14f;
					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);
					//lenがある一定の長さのより短い場合判定に入る
					if (len<88.0f) {
						//角度で上下左右を判定
						if ((r<45 && r>0) || r>315)
						{
							//右
							*right = true;//オブジェクトの左の部分が衝突している
							*x = bx + 64.0f + (scroll);//ブロックの位置＋主人公の幅
							*vx = -(*vx)*0.1f;//ーVX*反発係数
						}
						if (r>45 && r<135)
						{
							//上
							*down = true;//オブジェクトの下の部分が衝突している
							*y = by - 64.0f;//ブロックの位置ー主人公の幅
											//種類を渡すのスタートとゴールのみ変更する
							if (m_map[i][j] >= 2)
								*bt = m_map[i][j];//ブロックの要素（type）を主人公に渡す
							*vy = 0.0f;
						}
						if (r>135 && r<225)
						{
							//左
							*left = true;//オブジェクトの右の部分が衝突している
							*x = bx - 64.0f + (scroll);//ブロックの位置ー主人公の幅
							*vx = -(*vx)*0.1f;//ーVX*反発係数
						}
						if (r>225 && r<315)
						{
							//下
							*up = true;//主人公の上の部分が衝突している
							*y = by + 64.0f;//ブロックの位置＋主人公の幅
							if (*vy<0)
							{
								*vy = 0.0f;
							}
						}
					}
				}
			}
		}
	}
}