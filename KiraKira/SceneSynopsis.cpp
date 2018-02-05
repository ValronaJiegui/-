//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMain.h"
#include "Gamehead.h"
#include "SceneSynopsis.h"

#include "ObjAnten.h"

//�R���X�g���N�^
CSceneSynopsis::CSceneSynopsis()
{

}

//�f�X�g���N�_
CSceneSynopsis::~CSceneSynopsis()
{

}

//�Q�[�����C�����������\�b�h
void CSceneSynopsis::InitScene()
{
	Draw::LoadImageW(L"Synopsis.png", 0, TEX_SIZE_1024);

	CObjSynopsis* obj1 = new CObjSynopsis();
	Objs::InsertObj(obj1, OBJ_SYNOPSIS, 2);

	CObjAnten* obj2 = new CObjAnten();
	Objs::InsertObj(obj2, OBJ_ANTEN, 9);
}

//�Q�[�����C�����s�����\�b�h
void CSceneSynopsis::Scene()
{

}