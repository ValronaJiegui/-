#include"HaveItem.h"
#include"ObjLei.h"
#include"GameHead.h"

//レイちゃんの情報取得！
CObjLei *Lei = (CObjLei*)Objs::GetObj(OBJ_LEI);

HaveItem::HaveItem()
{	//アイテム所持数の初期値////(テスト時に変えても大丈夫！)
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
	//消費処理////(所持数が０ならエラーを返す)
	if (Tea == 0)
	{
		//お茶の所持数が０です
		return;
	}else{Tea--;}//←正しければ一個消費！

	//////レイちゃんのＨＰを変更する関数が必要です><
}


void HaveItem::UseWing()
{
	//消費処理////(所持数が０ならエラーを返す)
	if (Wing == 0)
	{
		//翼の所持数が０です
		return;
	}
	else { Wing--; }//←正しければ一個消費！

	//////レイちゃんのジャンプ力を変更する関数が必要です><
}


void HaveItem::UseShield()
{
	//消費処理////(所持数が０ならエラーを返す)
	if (Wing == 0)
	{
		//盾の所持数が０です
		return;
	}
	else { Wing--; }//←正しければ一個消費！

	//////優先度低めで><
}


void HaveItem::UseBullet()
{
	//消費処理////(所持数が０ならエラーを返す)
	if (Bullet == 0)
	{
		//弾丸の所持数が０です
		return;
	}
	else { Bullet--; }//←正しければ一個消費！

	//////銃に入ってる残り弾丸の数を
	//////ここで定義するかObjLeiで定義するか未定なので
	//////後ででお願いします><
}