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
#include "SceneStageSelect.h"
#include "Gamehead.h"
#include "ObjStageSelect.h"

//コンストラクタ
CSceneStageSelect::CSceneStageSelect()
{

}

//デストラクダ
CSceneStageSelect::~CSceneStageSelect()
{

}

//ゲームメイン初期化メソッド
void CSceneStageSelect::InitScene()
{
	Draw::LoadImageW(L"STAGE1.png", 0, TEX_SIZE_1024);


	//テストグラフィック作成
	CObjStageSelect* obj = new CObjStageSelect();
	Objs::InsertObj(obj, OBJ_STAGE_SELECT, 0);
}

//ゲームメイン実行中メソッド
void CSceneStageSelect::Scene()
{

}