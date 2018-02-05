//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain.h"
#include "Gamehead.h"
#include "SceneSynopsis.h"

#include "ObjAnten.h"

//コンストラクタ
CSceneSynopsis::CSceneSynopsis()
{

}

//デストラクダ
CSceneSynopsis::~CSceneSynopsis()
{

}

//ゲームメイン初期化メソッド
void CSceneSynopsis::InitScene()
{
	Draw::LoadImageW(L"Synopsis.png", 0, TEX_SIZE_1024);

	CObjSynopsis* obj1 = new CObjSynopsis();
	Objs::InsertObj(obj1, OBJ_SYNOPSIS, 2);

	CObjAnten* obj2 = new CObjAnten();
	Objs::InsertObj(obj2, OBJ_ANTEN, 9);
}

//ゲームメイン実行中メソッド
void CSceneSynopsis::Scene()
{

}