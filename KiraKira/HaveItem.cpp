#include"HaveItem.h"
#include"ObjLei.h"
#include"GameHead.h"

//���C�����̏��擾�I
CObjLei *Lei = (CObjLei*)Objs::GetObj(OBJ_LEI);

HaveItem::HaveItem()
{	//�A�C�e���������̏����l////(�e�X�g���ɕς��Ă����v�I)
	Tea = 2;
	Wing = 2;
	Shield = 2;
	Bullet = 2;
}

HaveItem::~HaveItem()
{
}

void HaveItem::UseTea()
{
	//�����////(���������O�Ȃ�G���[��Ԃ�)
	if (Tea == 0)
	{
		//�����̏��������O�ł�
		return;
	}else{Tea--;}//����������Έ����I

	//////���C�����̂g�o��ύX����֐����K�v�ł�><
}


void HaveItem::UseWing()
{
	//�����////(���������O�Ȃ�G���[��Ԃ�)
	if (Wing == 0)
	{
		//���̏��������O�ł�
		return;
	}
	else { Wing--; }//����������Έ����I

	//////���C�����̃W�����v�͂�ύX����֐����K�v�ł�><
}


void HaveItem::UseShield()
{
	//�����////(���������O�Ȃ�G���[��Ԃ�)
	if (Wing == 0)
	{
		//���̏��������O�ł�
		return;
	}
	else { Wing--; }//����������Έ����I

	//////�D��x��߂�><
}


void HaveItem::UseBullet()
{
	//�����////(���������O�Ȃ�G���[��Ԃ�)
	if (Bullet == 0)
	{
		//�e�ۂ̏��������O�ł�
		return;
	}
	else { Bullet--; }//����������Έ����I

	//////�e�ɓ����Ă�c��e�ۂ̐���
	//////�����Œ�`���邩ObjLei�Œ�`���邩����Ȃ̂�
	//////��łł��肢���܂�><
}