//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain.h"
#include "Gamehead.h"
#include "ObjTitle.h"

#include"ObjAnten.h"

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
	////////////グラフィック

	Draw::LoadImageW(L"Title.png", 0, TEX_SIZE_1024);

	//グラフィック作成
	CObjTitle* obj = new CObjTitle();
	Objs::InsertObj(obj, OBJ_TITLE, 0);


	CObjAnten* obj2 = new CObjAnten();
	Objs::InsertObj(obj2, OBJ_ANTEN, 9);

	/////////////ミュージック
	/*音楽読込*/Audio::LoadAudio(0, L"BGMTitle.wav", SOUND_TYPE::BACK_MUSIC);
	/*音量調整*/float Volume = Audio::VolumeMaster(-0.8f);
	/*再生開始*/Audio::Start(0);
}

//ゲームメイン実行中メソッド
void CSceneTitle::Scene()
{

}