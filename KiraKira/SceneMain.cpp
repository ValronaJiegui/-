//STL�f�o�b�O�@�\��OFF��
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)
////////////////////////////////////
//using namespace GameL;

#include"GameL\SceneObjManager.h"
#include"SceneMain.h"
#include"GameHead.h"
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
	//�O���f�[�^�̓ǂݍ���(�X�e�[�W���)
	unique_ptr<wchar_t>p;//�X�e�[�W���|�C���^�[
	int size;			//�X�e�[�W���̑傫��
	p = Save::ExternalDataOpen(L"TestMap1.csv", &size);//�O���f�[�^�ǂݍ���

	int map[10][100];
	int count = 1;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map[i][j] = w;
			count += 2;
		}
	}


	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImageW(L"Lei.png", 2, TEX_SIZE_256);

	//�e�X�g�O���t�B�b�N�쐬
	CObjGraphicTEST* obj = new CObjGraphicTEST();
	Objs::InsertObj(obj, OBJ_TEST, 2);

	Draw::LoadImageW(L"map.png", 0, TEX_SIZE_1024);

	Draw::LoadImageW(L"�΂�32�~32�w�i 1.png", 1, TEX_SIZE_256);

	//block�I�u�W�F�N�g�쐬
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 0);
}
//���s���̑���//////////////////////////////////
void CSceneMain::Scene()
{

}