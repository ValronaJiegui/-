#pragma once
typedef class HaveItem
{
public:
	HaveItem();
	~HaveItem();
	//アイテム入手関数////(数を一個増やします！)
	void GetTea() { Tea++; }
	void GetWing() { Wing++; }
	void GetShield() { Shield++; }
	void GetBullet() { Bullet++; }

	//アイテム使用関数////(数を一個減らして何か行います！)
	void UseTea();
	void UseWing();
	void UseShield();
	void UseBullet();
private:
	//武器系
	int Sword;	//剣
	int Knife;	//ﾅｲﾌ
	int Gun;	//銃

	//補助系
	int Tea;	//茶
	int Wing;	//翼
	int Shield;	//盾
	int Bullet;	//弾
}Item;