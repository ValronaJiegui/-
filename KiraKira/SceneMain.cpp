//STLデバッグ機能をOFFに
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)
////////////////////////////////////
//using namespace GameL;

#include"GameL\SceneObjManager.h"
#include"SceneMain.h"
#include"GameHead.h"
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
	Draw::LoadImageW(L"Lei.png", 2, TEX_SIZE_256);

	//テストグラフィック作成
	CObjGraphicTEST* obj = new CObjGraphicTEST();
	Objs::InsertObj(obj, OBJ_TEST, 2);

	Draw::LoadImageW(L"map.png", 0, TEX_SIZE_1024);

	Draw::LoadImageW(L"緑の32×32背景 1.png", 1, TEX_SIZE_256);

	//blockオブジェクト作成
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 0);
}
//実行中の操作//////////////////////////////////
void CSceneMain::Scene()
{

}