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
	//グラフィック読み込み
	Draw::LoadImageW(L"item.png", 0, TEX_SIZE_256);
	Draw::LoadImageW(L"Lei.png", 1, TEX_SIZE_256);

	//テストグラフィック作成
	//茶
	CObjItemTea* obj = new CObjItemTea();
	Objs::InsertObj(obj, OBJ_ITEM_TEA, 0);

	//翼
	CObjItemWing* obj2 = new CObjItemWing();
	Objs::InsertObj(obj2, OBJ_ITEM_WING, 0);

	//主人公
	CObjLei* obj3 = new CObjLei();
	Objs::InsertObj(obj3, OBJ_LEi, 1);
}
//実行中の操作//////////////////////////////////
void CSceneMain::Scene()
{

}