//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"

#include "GameHead.h"
#include "ObjText.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjText::CObjText()
{
}


CObjText::~CObjText()
{
}

//�C�j�V�����C�Y
void CObjText::Init()
{

}

//�A�N�V����
void CObjText::Action()
{

}

//�h���[
void CObjText::Draw()
{
	float  c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"���܂���", 0, 0, 32, c);
}
