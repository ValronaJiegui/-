//STL�f�o�b�O�@�\��OFF��
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

//�J�n���̏���//////////////////////////////////
CSceneMain::CSceneMain()
{

}
//�I�����̏���//////////////////////////////////
CSceneMain::~CSceneMain()
{

}
//�������̑���//////////////////////////////////
void CSceneMain::InitScene()
{
	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImageW(L"item.png", 0, TEX_SIZE_256);
	Draw::LoadImageW(L"Lei.png", 1, TEX_SIZE_256);

	//�e�X�g�O���t�B�b�N�쐬
	//��
	CObjItemTea* obj = new CObjItemTea();
	Objs::InsertObj(obj, OBJ_ITEM_TEA, 0);

	//��
	CObjItemWing* obj2 = new CObjItemWing();
	Objs::InsertObj(obj2, OBJ_ITEM_WING, 0);

	//��l��
	CObjGraphicTEST* obj3 = new CObjGraphicTEST();
	Objs::InsertObj(obj3, OBJ_TEST, 1);
}
//���s���̑���//////////////////////////////////
void CSceneMain::Scene()
{

}