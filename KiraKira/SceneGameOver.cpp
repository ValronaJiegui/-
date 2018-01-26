//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneGameOver.h"
#include "Gamehead.h"
#include"ObjAnten.h"

//コンストラクタ
CSceneGameOver::CSceneGameOver()
{

}

//デストラクダ
CSceneGameOver::~CSceneGameOver()
{

}

//初期化メソッド
void CSceneGameOver::InitScene()
{
	Draw::LoadImageW(L"GAME OVER.png", 0, TEX_SIZE_1024);

	//ゲームオーバーオブジェクト作成
	CObjGameOver* obj = new CObjGameOver();
	Objs::InsertObj(obj, OBJ_GAME_OVER, 0);

	CObjAnten* obj2 = new CObjAnten();
	Objs::InsertObj(obj2, OBJ_ANTEN, 9);
}

//実行中メソッド
void CSceneGameOver::Scene()
{

}