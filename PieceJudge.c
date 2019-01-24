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

	int mousex = 0;			// マウスのx座標から計算したマス目
	int mousey = 0;			// マウスのy座標から計算したマス目
	int Drct = 0;			// 方向(Direction)を保存する
	int mouseStarageX = 0;	// マウスのx座標を保存する
	int mouseStarageY = 0;	// マウスのy座標を保存する
	static int isDrctFlg = FALSE;	// 方向が定まっているか >> TRUE:定まっている FALSE:定まっていない
	static int isFirstFlg = TRUE;	// 最初かどうか >> TRUE:最初 FALSE:最初じゃない
	int count = 0;


	//マウス座標の代入と保存
	mousex = pt.x;
	mousey = pt.y;
	mouseStarageX = mousex;
	mouseStarageY = mousey;

	//マスの中身を判断
	if (masu[mousey][mousex] != EMPTY)
	{
		return FALSE;
	}
	//マスが0なら置けるかどうか調べる
	else
	{
		while (1)
		{

			if (isDrctFlg == FALSE)
			{
				Drct = drctArray[i];
				if (isFirstFlg == FALSE)
				{
					count++;
				}
			}

			/* caseの処理順序
			if( 見たい方向の先がプレイヤーと違う色なら ){
				if( その次もプレイヤーと同じ色なら ){ return TRUE; }
				else if( プレイヤーと異なる色なら次のマスを見る ){ 座標の移動 }
				else{ EMPTYなら初期化 }
			}
			*/

			//方向の先のマスを見る
			switch (Drct)
			{

			// 上
			case eN: 
				if (masu[mousey - 1][mousex] == player * REVERSE)
				{
					Drct = eN;
					isDrctFlg = TRUE;
					mousey = mousey - 1;
					mousex = mousex;

					if (masu[mousey - 1][mousex] == player)
					{
						return TRUE;
					}
					else if (masu[mousey - 1][mousex] == player * REVERSE)
					{
						mousey = mousey - 1;
						mousex = mousex;
					}
					else 
					{  
						isDrctFlg = FALSE;
						isFirstFlg = FALSE;
						mousey = mouseStarageY;
						mousex = mouseStarageX;
						break;
					}
				}
				else
				{
					isFirstFlg = FALSE;
				}
				break;

			// 右上
			case eNE:
				if (masu[mousey - 1][mousex + 1] == player * REVERSE)
				{
					Drct = eNE;
					mousey = mousey - 1;
					mousex = mousex + 1;
					if (masu[mousey - 1][mousex + 1] == player)
					{
						return TRUE;
					}
					else if (masu[mousey - 1][mousex + 1] == player * REVERSE)
					{
						mousey = mousey - 1;
						mousex = mousex + 1;
					}
					else
					{
						isDrctFlg = FALSE;
						mousey = mouseStarageY;
						mousex = mouseStarageX;
						break;
					}
				}
				else
				{
					isFirstFlg = FALSE;
				}
				break;

			// 右
			case eE:
				if (masu[mousey][mousex + 1] == player * REVERSE)
				{
					Drct = eE;
					mousey = mousey;
					mousex = mousex + 1;
					if (masu[mousey][mousex + 1] == player)
					{
						return TRUE;
					}
					else if (masu[mousey][mousex + 1] == player * REVERSE)
					{
						mousey = mousey;
						mousex = mousex + 1;
					}
					else
					{
						isDrctFlg = FALSE;
						mousey = mouseStarageY;
						mousex = mouseStarageX;
						break;
					}
				}
				else
				{
					isFirstFlg = FALSE;
				}
				break;

			// 右下
			case eSE:
				if (masu[mousey + 1][mousex + 1] == player * REVERSE)
				{
					Drct = eSE;
					mousey = mousey + 1;
					mousex = mousex + 1;
					if (masu[mousey + 1][mousex + 1] == player)
					{
						return TRUE;
					}
					else if (masu[mousey + 1][mousex + 1] == player * REVERSE)
					{
						mousey = mousey + 1;
						mousex = mousex + 1;
					}
					else
					{
						isDrctFlg = FALSE;
						mousey = mouseStarageY;
						mousex = mouseStarageX;
						break;
					}
				}
				else
				{
					isFirstFlg = FALSE;
				}
				break;

			// 下
			case eS:
				if (masu[mousey + 1][mousex] == player * REVERSE)
				{
					Drct = eS;
					mousey = mousey + 1;
					mousex = mousex;

					if (masu[mousey + 1][mousex] == player)
					{
						return TRUE;
					}
					else if (masu[mousey + 1][mousex] == player * REVERSE)
					{
						mousey = mousey + 1;
						mousex = mousex;
					}
					else
					{
						isDrctFlg = FALSE;
						mousey = mouseStarageY;
						mousex = mouseStarageX;
						break;
					}
				}
				else
				{
					isFirstFlg = FALSE;
				}
				break;

			// 左下
			case eSW:
				if (masu[mousey + 1][mousex - 1] == player * REVERSE)
				{
					Drct = eSW;
					mousey = mousey + 1;
					mousex = mousex - 1;

					if (masu[mousey + 1][mousex - 1] == player)
					{
						return TRUE;
					}
					else if (masu[mousey + 1][mousex - 1] == player * REVERSE)
					{
						mousey = mousey + 1;
						mousex = mousex - 1;
					}
					else
					{
						isDrctFlg = FALSE;
						mousey = mouseStarageY;
						mousex = mouseStarageX;
						break;
					}
				}
				else
				{
					isFirstFlg = FALSE;
				}
				break;

			// 左
			case eW:
				if (masu[mousey][mousex - 1] == player * REVERSE)
				{
					Drct = eW;
					mousey = mousey;
					mousex = mousex - 1;

					if (masu[mousey][mousex - 1] == player)
					{
						return TRUE;
					}
					else if (masu[mousey][mousex - 1] == player * REVERSE)
					{
						mousey = mousey;
						mousex = mousex - 1;
					}
					else
					{
						isDrctFlg = FALSE;
						mousey = mouseStarageY;
						mousex = mouseStarageX;
						break;
					}
				}
				else
				{
					isFirstFlg = FALSE;
				}
				break;

			// 左上
			case eNW:
				if (masu[mousey - 1][mousex - 1] == player * REVERSE)
				{
					Drct = eNW;
					mousey = mousey - 1;
					mousex = mousex - 1;

					if (masu[mousey - 1][mousex - 1] == player)
					{
						return TRUE;
					}
					else if (masu[mousey - 1][mousex - 1] == player * REVERSE)
					{
						mousey = mousey - 1;
						mousex = mousex - 1;
					}
					else
					{
						isDrctFlg = FALSE;
						mousey = mouseStarageY;
						mousex = mouseStarageX;
						break;
					}
				}
				else
				{
					isFirstFlg = FALSE;
				}
				break;


			default:
				return FALSE;
				break;
			}  //switch文終了

			// どの方向も置けないなら
			if (count == 8)
			{
				return FALSE;
			}

		}  //while文終了
	}  //else終了
}
