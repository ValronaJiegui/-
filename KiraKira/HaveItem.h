#pragma once
typedef class HaveItem
{
public:
	HaveItem();
	~HaveItem();
	//�A�C�e������֐�////(��������₵�܂��I)
	void GetTea()    { Tea++;    return; }
	void GetWing()   { Wing++;   return; }
	void GetShield() { Shield++; return; }
	void GetBullet() { Bullet++; return; }

	//�A�C�e���g�p�֐�////(��������炵�ĉ����s���܂��I)
	void UseTea();
	void UseWing();
	void UseShield();
	void UseBullet();
private:
	//����n
	int Sword;	//��
	int Knife;	//Ų�
	int Gun;	//�e

	//�⏕�n
	int Tea;	//��
	int Wing;	//��
	int Shield;	//��
	int Bullet;	//�e
}Item;