//STLデバッグ機能をOFFに
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)
////////////////////////////////////
#include"GameL\SceneObjManager.h"
using namespace GameL;
#include"SceneMain.h"
#include"GameHead.h"
#include"GameL\DrawTexture.h"

#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
#include"GameL\DrawFont.h"
#include"GameL\UserData.h"

//開始時の処理//////////////////////////////////
CSceneMain::CSceneMain()
{

}
//終了時の処理//////////////////////////////////
CSceneMain::~CSceneMain()
{

}
//初期化の操作//////////////////////////////////
void CSceneMain::InitScene()
{
	//外部データの読み込み(ステージ情報)
	unique_ptr<wchar_t>p;//ステージ情報ポインター
	int size;			//ステージ情報の大きさ
	p = Save::ExternalDataOpen(L"TestMap1.csv", &size);//外部データ読み込み

	int map[10][500];
	int count = 1;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 500; j++)
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
	Draw::LoadImageW(L"map.png",1, TEX_SIZE_1024);

	//ブロックグラフィック読み込み
	Draw::LoadImageW(L"BlockGraphic.png", 2, TEX_SIZE_256);

	//アイテムグラフィック読み込み
	Draw::LoadImageW(L"item2.png", 3, TEX_SIZE_256);

	//blockオブジェクト作成
	CObjBlock* objBlock = new CObjBlock(map);
	Objs::InsertObj(objBlock, OBJ_BLOCK, 2);


	
	//茶
	CObjItemTea* objTea = new CObjItemTea();
	Objs::InsertObj(objTea, OBJ_ITEM_TEA,3 );

	//翼
	CObjItemWing* objWing = new CObjItemWing();
	Objs::InsertObj(objWing, OBJ_ITEM_WING, 3);

	//テストグラフィック作成
	CObjLei* objLei = new CObjLei();
	Objs::InsertObj(objLei, OBJ_LEI, 100);

	



}
//実行中の操作//////////////////////////////////
void CSceneMain::Scene()
{

}