//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMain.h"
#include "Gamehead.h"
#include "ObjTitle.h"

#include"ObjAnten.h"

//�R���X�g���N�^
CSceneTitle::CSceneTitle()
{

}

//�f�X�g���N�_
CSceneTitle::~CSceneTitle()
{

}

//�Q�[�����C�����������\�b�h
void CSceneTitle::InitScene()
{
	////////////�O���t�B�b�N

	Draw::LoadImageW(L"Title.png", 0, TEX_SIZE_1024);

	//�O���t�B�b�N�쐬
	CObjTitle* obj = new CObjTitle();
	Objs::InsertObj(obj, OBJ_TITLE, 0);


	CObjAnten* obj2 = new CObjAnten();
	Objs::InsertObj(obj2, OBJ_ANTEN, 9);

	/////////////�~���[�W�b�N
	/*���y�Ǎ�*/Audio::LoadAudio(0, L"BGMTitle.wav", SOUND_TYPE::BACK_MUSIC);
	/*���ʒ���*/float Volume = Audio::VolumeMaster(-0.8f);
	/*�Đ��J�n*/Audio::Start(0);
}

//�Q�[�����C�����s�����\�b�h
void CSceneTitle::Scene()
{

}