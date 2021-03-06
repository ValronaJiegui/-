#pragma once

//オブジェクトネーム------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//オブジェクト名無し(禁止)
	//ゲームで使うオブジェクトの名前
	//OBJ_○○と表記
	OBJ_LEI,
	OBJ_ITEM_TEA,
	OBJ_ITEM_WING,
	OBJ_BLOCK,
	OBJ_TITLE,
	OBJ_STAGE_SELECT,
	OBJ_GAME_OVER,
	OBJ_TAMA,
	OBJ_TAMAC,
	OBJ_ENEMY,
	OBJ_HENEMY,
	OBJ_NAIHU,
	OBJ_HATU,
	OBJ_TOBASU,
	OBJ_DORON,
	OBJ_SYASYO,
	OBJ_SUKIMA,
	OBJ_DNSYA,
	OBJ_KIP,
	OBJ_BAKU,
	OBJ_BOSS_KIRARI,
	OBJ_ANTEN,
	OBJ_SYNOPSIS,
};
//------------------------------------------------

//当たり判定属性----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//属性無し 全ての属性と当たり判定が実行される
	//以下　同じ属性同士では当たり判定は実行されない
	//属性は追加可能だが、デバック時の色は初期設定分しか無い
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
};
//------------------------------------------------

//------------------------------------------------
//セーブ＆ロードとシーン間のやり取りするデータ
struct UserData
{
	int mSeveData;	//サンプルセーブデータ
	
};
//------------------------------------------------


//ゲーム内で使用されるグローバル変数・定数・列挙--



//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------


//------------------------------------------------

//ゲームシーンオブジェクトヘッダ------------------
#include"ObjLei.h"
#include"ObjItemTea.h"
#include"ObjItemWing.h"
#include"ObjBlock.h"
#include "ObjTitle.h"
#include "ObjStageSelect.h"
#include "ObjGameOver.h"
#include"tama.h"
#include"tamac.h"

#include"objnage.h"
#include"naihu.h"
#include"objenemy.h"
#include"objhenemy.h"
#include"doron.h"
#include"objsin.h"
#include"tobasu.h"
#include"ObjSyasyou.h"
#include "ObjSynopsis.h"
#include"densya.h"
#include"sukima.h"
#include"kip.h"

#include"ObjAnten.h"
#include"Kirari.h"
//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include "SceneMain.h"
#include "SceneTitle.h"
#include"SceneStageSelect.h"
#include "SceneGameOver.h"
#include"Stage1.h"
#include "SceneSynopsis.h"
//-----------------------------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
#define SET_GAME_START CSceneTitle
//-----------------------------------------------