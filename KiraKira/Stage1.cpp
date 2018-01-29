//STL�f�o�b�O�@�\��OFF��
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include"GameL\SceneObjManager.h"
using namespace GameL;
#include "Stage1.h"
#include"GameHead.h"
#include"GameL\DrawTexture.h"
#include"ObjTitle.h"

#include"GameL\DrawFont.h"
#include"GameL\UserData.h"




CStage1::CStage1()
{
	
}

CStage1::~CStage1()
{

}

void CStage1::InitScene()
{
		//�O���f�[�^�̓ǂݍ���(�X�e�[�W���)
		unique_ptr<wchar_t>p;//�X�e�[�W���|�C���^�[
		int size;			//�X�e�[�W���̑傫��
		p = Save::ExternalDataOpen(L"S1.csv", &size);//�O���f�[�^�ǂݍ���

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
		Draw::LoadImageW(L"�w�i1.png", 1, TEX_SIZE_1024);


		//�u���b�N�O���t�B�b�N�ǂݍ���
		Draw::LoadImageW(L"BlockGraphic5.png", 2, TEX_SIZE_256);

		//�A�C�e���O���t�B�b�N�ǂݍ���
		Draw::LoadImageW(L"item2.png", 3, TEX_SIZE_256);

		Draw::LoadImageW(L"image20.png", 5, TEX_SIZE_512);

		//�U�R�O���t�B�b�N�ǂݍ���
		Draw::LoadImageW(L"ZakoData.png", 6, TEX_SIZE_512);

		//�w�i�O���t�B�b�N
		Draw::LoadImageW(L"��.jpg", 7, TEX_SIZE_1024);
		//block�I�u�W�F�N�g�쐬
		CObjBlock* objBlock = new CObjBlock(map);
		Objs::InsertObj(objBlock, OBJ_BLOCK, 2);



		//��
		CObjItemTea* objTea = new CObjItemTea();
		Objs::InsertObj(objTea, OBJ_ITEM_TEA, 3);

		//��
		CObjItemWing* objWing = new CObjItemWing();
		Objs::InsertObj(objWing, OBJ_ITEM_WING, 3);

		//�e�X�g�O���t�B�b�N�쐬
		CObjLei* objLei = new CObjLei();
		Objs::InsertObj(objLei, OBJ_LEI, 100);

		//�i�C�t�N
		CObjNage* objnage = new CObjNage();
		Objs::InsertObj(objnage, OBJ_NAIHU, 3);

		//���邭�����
		CObjEnemy* objenemy = new CObjEnemy();
		Objs::InsertObj(objenemy, OBJ_ENEMY, 3);

		//�͂��邿���
		CObjHenemy* objhenemy = new CObjHenemy();
		Objs::InsertObj(objhenemy, OBJ_HENEMY, 3);
}

void CStage1::Scene()
{

}

