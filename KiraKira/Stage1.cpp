//STLデバッグ機能をOFFに
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include"GameL\SceneObjManager.h"
using namespace GameL;
#include "Stage1.h"
#include"GameHead.h"
#include"GameL\DrawTexture.h"
#include"ObjTitle.h"

#include"GameL\DrawFont.h"
#include"GameL\UserData.h"




CStage1::CStage1()
{
	
}

CStage1::~CStage1()
{

}

void CStage1::InitScene()
{
		//外部データの読み込み(ステージ情報)
		unique_ptr<wchar_t>p;//ステージ情報ポインター
		int size;			//ステージ情報の大きさ
		p = Save::ExternalDataOpen(L"S1.csv", &size);//外部データ読み込み

		int map[10][100];
		int count = 1;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				int w = 0;
				swscanf_s(&p.get()[count], L"%d", &w);

				map[i][j] = w;
				count += 2;
			}
		}
		//グラフィック読み込み
		Draw::LoadImageW(L"Lei.png", 0, TEX_SIZE_256);

		//グラフィック
		Draw::LoadImageW(L"背景1.png", 1, TEX_SIZE_1024);


		//ブロックグラフィック読み込み
		Draw::LoadImageW(L"BlockGraphic5.png", 2, TEX_SIZE_256);

		//アイテムグラフィック読み込み
		Draw::LoadImageW(L"item2.png", 3, TEX_SIZE_256);

		Draw::LoadImageW(L"image20.png", 5, TEX_SIZE_512);

		//ザコグラフィック読み込み
		Draw::LoadImageW(L"ZakoData.png", 6, TEX_SIZE_512);

		//背景グラフィック
		Draw::LoadImageW(L"空.jpg", 7, TEX_SIZE_1024);
		//blockオブジェクト作成
		CObjBlock* objBlock = new CObjBlock(map);
		Objs::InsertObj(objBlock, OBJ_BLOCK, 2);



		//茶
		CObjItemTea* objTea = new CObjItemTea();
		Objs::InsertObj(objTea, OBJ_ITEM_TEA, 3);

		//翼
		CObjItemWing* objWing = new CObjItemWing();
		Objs::InsertObj(objWing, OBJ_ITEM_WING, 3);

		//テストグラフィック作成
		CObjLei* objLei = new CObjLei();
		Objs::InsertObj(objLei, OBJ_LEI, 100);

		//ナイフ君
		CObjNage* objnage = new CObjNage();
		Objs::InsertObj(objnage, OBJ_NAIHU, 3);

		//あるくちゃん
		CObjEnemy* objenemy = new CObjEnemy();
		Objs::InsertObj(objenemy, OBJ_ENEMY, 3);

		//はしるちゃん
		CObjHenemy* objhenemy = new CObjHenemy();
		Objs::InsertObj(objhenemy, OBJ_HENEMY, 3);
}

void CStage1::Scene()
{

}


