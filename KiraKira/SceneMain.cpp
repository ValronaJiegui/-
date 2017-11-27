//STLデバッグ機能をOFFに
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)
////////////////////////////////////
#include"GameL\SceneObjManager.h"
using namespace GameL;
#include"SceneMain.h"
#include"GameHead.h"
#include"GameL\DrawTexture.h"

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
	//グラフィック読み込み
	Draw::LoadImageW(L"Lei.png", 0, TEX_SIZE_256);

	//テストグラフィック作成
	CObjGraphicTEST* obj = new CObjGraphicTEST();
	Objs::InsertObj(obj, OBJ_TEST, 10);
}
//実行中の操作//////////////////////////////////
void CSceneMain::Scene()
{

}