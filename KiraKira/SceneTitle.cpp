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
#include "ObjTitle.h"

//コンストラクタ
CSceneTitle::CSceneTitle()
{

}

//デストラクダ
CSceneTitle::~CSceneTitle()
{

}

//ゲームメイン初期化メソッド
void CSceneTitle::InitScene()
{
	Draw::LoadImageW(L"Title.png", 0, TEX_SIZE_1024);

	//グラフィック作成
	CObjTitle* obj = new CObjTitle();
	Objs::InsertObj(obj, OBJ_TITLE, 0);
}

//ゲームメイン実行中メソッド
void CSceneTitle::Scene()
{

}