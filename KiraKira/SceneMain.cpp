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
	Draw::LoadImageW(L"Lei.png", 0, TEX_SIZE_256);

	//�O���t�B�b�N
	Draw::LoadImageW(L"�w�i.png",1, TEX_SIZE_1024);

	//�u���b�N�O���t�B�b�N�ǂݍ���
	Draw::LoadImageW(L"BlockGraphic4.png", 2, TEX_SIZE_256);

	//�A�C�e���O���t�B�b�N�ǂݍ���
	Draw::LoadImageW(L"item.png", 3, TEX_SIZE_256);

	Draw::LoadImageW(L"image20.png", 5, TEX_SIZE_512);

	//�U�R�O���t�B�b�N�ǂݍ���
	Draw::LoadImageW(L"ZakoData.png", 6, TEX_SIZE_512);

	//block�I�u�W�F�N�g�쐬
	CObjBlock* objBlock = new CObjBlock(map);
	Objs::InsertObj(objBlock, OBJ_BLOCK, 2);


	
	//��
	CObjItemTea* objTea = new CObjItemTea();
	Objs::InsertObj(objTea, OBJ_ITEM_TEA,3 );

	//��
	CObjItemWing* objWing = new CObjItemWing();
	Objs::InsertObj(objWing, OBJ_ITEM_WING, 3);

	//�e�X�g�O���t�B�b�N�쐬
	CObjLei* objLei = new CObjLei();
	Objs::InsertObj(objLei, OBJ_LEI, 100);

	//�i�C�t�N
	CObjNage* objnage = new CObjNage();
	Objs::InsertObj(objnage, OBJ_NAIHU, 3);



}
//���s���̑���//////////////////////////////////
void CSceneMain::Scene()
{

}