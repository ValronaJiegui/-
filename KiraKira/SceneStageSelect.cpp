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
#include "SceneStageSelect.h"
#include "Gamehead.h"
#include "ObjStageSelect.h"

//�R���X�g���N�^
CSceneStageSelect::CSceneStageSelect()
{

}

//�f�X�g���N�_
CSceneStageSelect::~CSceneStageSelect()
{

}

//�Q�[�����C�����������\�b�h
void CSceneStageSelect::InitScene()
{
	Draw::LoadImageW(L"STAGE1.png", 0, TEX_SIZE_1024);


	//�e�X�g�O���t�B�b�N�쐬
	CObjStageSelect* obj = new CObjStageSelect();
	Objs::InsertObj(obj, OBJ_STAGE_SELECT, 0);
}

//�Q�[�����C�����s�����\�b�h
void CSceneStageSelect::Scene()
{

}