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

	int mousex;			// マウスのx座標から計算したマス目
	int mousey;			// マウスのy座標から計算したマス目
	int Drct;			// 方向(Direction)を保存する
	int mouceStarageX;	// マウスのx座標を保存する
	int mouceStarageY;	// マウスのy座標を保存する
	static int isDrctFlg = FALSE;	// 方向が定まっているか >> TRUE:定まっている FALSE:定まっていない
	int i = 0;

	//マウス座標より要素数を割り出し配列へ代入
	mousex = pt.x / 50 % 8 + 1;
	mousey = pt.y / 50 % 8 + 1;

	//マウス座標の保存
	mouceStarageX = mousex;
	mouceStarageY = mousey;

	//マスの中身を判断
	if (masu[mousex][mousey] != EMPTY)
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
				i++;
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

			case eN:
				if (masu[mousex][mousey - 1] == player * REVERSE)
				{
					Drct = eN;
					isDrctFlg = TRUE;
					mousex = mousex;
					mousey = mousey - 1;

					if (masu[mousex][mousey - 1] == player)
					{
						return TRUE;
					}
					else if (masu[mousex][mousey - 1] == player * REVERSE) 
					{
						mousex = mousex;
						mousey = mousey - 1;
					}
					else 
					{  
						isDrctFlg = FALSE;
						mousex = mouceStarageX;
						mousey = mouceStarageY;
						break;
					}
				}
				break;


			case eNE:
				if (masu[mousex + 1][mousey - 1] == player * REVERSE)
				{
					Drct = eNE;
					mousex = mousex + 1;
					mousey = mousey - 1;
				}
				break;


			case eE:
				if (masu[mousex + 1][mousey] == player * REVERSE)
				{
					Drct = eE;
					mousex = mousex + 1;
					mousey = mousey;
				}
				break;


			case eSE:
				if (masu[mousex + 1][mousey + 1] == player * REVERSE)
				{
					Drct = eSE;
					mousex = mousex + 1;
					mousey = mousey + 1;
				}
				break;


			case eS:
				if (masu[mousex][mousey + 1] == player * REVERSE)
				{
					Drct = eS;
					mousex = mousex;
					mousey = mousey + 1;
				}
				break;


			case eSW:
				if (masu[mousex - 1][mousey + 1] == player * REVERSE)
				{
					Drct = eSW;
					mousex = mousex - 1;
					mousey = mousey + 1;
				}
				break;


			case eW:
				if (masu[mousex - 1][mousey] == player * REVERSE)
				{
					Drct = eW;
					mousex = mousex - 1;
					mousey = mousey;
				}
				break;


			case eNW:
				if (masu[mousex - 1][mousey - 1] == player * REVERSE)
				{
					Drct = eNW;
					mousex = mousex - 1;
					mousey = mousey - 1;
				}
				break;


			default:
				return FALSE;
				break;
			}  //switch文終了

			// どの方向も置けないなら
			if (i == 8)
			{
				return FALSE;
			}

		}  //while文終了
	}  //else終了
}
