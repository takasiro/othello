#include <stdio.h>
#include "PieceJudge.h"

/************************************************
関 数 名 :PieceJudge()
処理内容 :駒が置けるかどうかの判定
引    数 :無し
返 却 値 :FALSE:置けない TRUE:置ける
備　　考 :八方向を見るロジック
			701
			6P2
			543		P:playerの置きたいところ
			八方向を見る際はdrctArrayを使用する
			enumで数字は定義されている
*************************************************/
int PieceJudge() {

	static int isDrctFlg = FALSE;	// 方向が定まっているか >> TRUE:定まっている FALSE:定まっていない
	int i;
	//マウス座標の代入と保存
	mousex = (int)pt.x;
	mousey = (int)pt.y;
	mouseStorageX = mousex;
	mouseStorageY = mousey;

	//マスの中身を判断
	if (masu[mousey][mousex] != EMPTY)
	{
		return FALSE;
	}
	//マスが0なら置けるかどうか調べる
	else
	{
		for (i = 0; i < 8; i++)
		{
			SwitchShift(i);	//配列の要素数をずらす

			//一つ先が異色なら一つ先を見る
			if (masu[mousey][mousex] == player * REVERSE)
			{

				SwitchShift(i);
				isDrctFlg = TRUE;

				//先が同色なら
				while (isDrctFlg == TRUE)
				{
					if (masu[mousey][mousex] == player)
					{
						mousey = mouseStorageY;
						mousex = mouseStorageX;
						return TRUE;
					}
					else if (masu[mousey][mousex] == player * REVERSE)
					{
						SwitchShift(i);
					}
					//先が0だったらひっくり返さない
					else
					{
						isDrctFlg = FALSE;
						mousey = mouseStorageY;
						mousex = mouseStorageX;
					}
				}  //while文終了
			}
			else
			{
				mousey = mouseStorageY;
				mousex = mouseStorageX;
			}


		}  //for文終了
	}  //else終了
	return FALSE;
}