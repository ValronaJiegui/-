//STL�f�o�b�O�@�\��OFF��
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)
////////////////////////////////////
#include"GameL\SceneObjManager.h"
using namespace GameL;
#include"SceneMain.h"
#include"GameHead.h"
#include"GameL\DrawTexture.h"

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
	Draw::LoadImageW(L"dorodoro.png", 0, TEX_SIZE_256);

	//�e�L�X�g�I�u�W�F�N�g�쐬
	CObjText* obj = new CObjText();
	Objs::InsertObj(obj, OBJ_TEXT, 10);

	//�e�X�g�O���t�B�b�N�쐬
	CObjwindow* obj3 = new CObjwindow();
	Objs::InsertObj(obj3, OBJ_WINDOW, 10);

//	Draw::LoadImageW(L"Lei.png", 0, TEX_SIZE_256);

	//�e�X�g�O���t�B�b�N�쐬
//	CObjGraphicTEST* obj = new CObjGraphicTEST();
//	Objs::InsertObj(obj, OBJ_TEST, 10);
}
//���s���̑���//////////////////////////////////
void CSceneMain::Scene()
{

}