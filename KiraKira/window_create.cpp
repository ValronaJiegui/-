//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameHead.h"
#include"window_create.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjwindow::CObjwindow()
{
}


CObjwindow::~CObjwindow()
{
}

//�C�j�V�����C�Y
void CObjwindow::Init()
{

}

//�A�N�V����
void CObjwindow::Action()
{

}

//�h���[
void CObjwindow::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top    =    0.0f;
	src.m_left   =    0.0f;
	src.m_right  =  260.0f;
	src.m_bottom =  200.0f;

	dst.m_top    =  100.0f;
	dst.m_left   =  -50.0f;
	dst.m_right  =  820.0f;
	dst.m_bottom =  600.0f;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}