//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"

#include"GameHead.h"
#include"ObjBlock.h"

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

}

//アクション
void CObjBlock::Action()
{
	//主人公の位置を取得
	CObjGraphicTEST*hero = (CObjGraphicTEST*)Objs::GetObj(OBJ_TEST);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//後方スクロールライン
	if (hx < 80)
	{
		hero->SetX(80);//主人公はラインを超えないようにする
		m_scroll -= hero->GetVX();//主人公が本来動くべき分の値をm_scrollに加える
	}

	//前方スクロールライン
	if (hx > 300)
	{
		hero->SetX(300);
		m_scroll -= hero->GetVX();
	}

	//主人公の衝突状態確認用のフラグの初期化
	hero->SetUp(false);
	hero->SetDown(false);
	hero->SetLeft(false);
	hero->SetRight(false);

	//踏んでいるblockの種類の初期化
	hero->SetBT(0);

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
				if ((hx + (-m_scroll) + 64.0f>x) && (hx + (-m_scroll)<x + 64.0f) && (hy + 64.0f>y) && (hy<y + 64.0f))
				{
					//上下左右判定

					//vectorの作成
					float vx = (hx + (-m_scroll)) - x;
					float vy = hy - y;

					//長さを求める
					float len = sqrt(vx*vx + vy*vy);

					//角度を求める
					float r = atan2(vy, vx);
					r = r*180.0f / 3.14;

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
							hero->SetRight(true);//主人公の左の部分が衝突している
							hero->SetX(x + 64.0f + (m_scroll));//ブロックの位置＋主人公の幅
							hero->SetVX(-hero->GetVX()*0.1f);//ーVX*反発定数


						}
						if (r > 45 && r < 135)
						{
							//上
							hero->SetDown(true);
							hero->SetY(y - 64.0f);//ブロックの位置・主人公の幅
												  //種類を渡すのスタートとゴールのみ変更する
							if (m_map[i][j] >= 2)
								hero->SetBT(m_map[i][j]);//ブロックの要素(type)を主人公に渡す
							hero->SetVY(0.0f);

						}
						if (r > 135 && r < 225)
						{
							//左
							hero->SetLeft(true);
							hero->SetX(x - 64.0f + (m_scroll));
							hero->SetVX(-hero->GetVX()*0.1f);
						}
						if (r > 225 && r < 315)
						{
							//下
							hero->SetUp(true);//主人公から見て、上の部分が小とるしている
							hero->SetY(y + 64.0f);//ブロックの位置＋主人公の幅
							if (hero->GetVY() < 0)
							{
								hero->SetVY(0.0f);
							}
						}
					}
				}
			}
		}

	}
}

//ドロー
void CObjBlock::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//背景表示
	src.m_top = 256.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(0, &src, &dst, c, 0.0f);

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
				dst.m_right = dst.m_left + 64.0;
				dst.m_bottom = dst.m_top + 64.0;
				if (m_map[i][j] == 2)
				{
					//スタートブロック
					BlockDraw(320.0f + 64.0f, 0.0f, &dst, c);

				}
				else if (m_map[i][j] == 3)
				{
					//ゴールブロック
					BlockDraw(320.0f + 64.0f, 64.0f, &dst, c);
				}
				else
				{
					BlockDraw(320.0f, 0.0f, &dst, c);
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
	src.m_right = src.m_left + 64.0f;
	src.m_bottom = src.m_top + 64.0f;
	//描画
	Draw::Draw(0, &src, dst, c, 0.0f);
}