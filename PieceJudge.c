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
	int mouceStarageX = 0;	// マウスのx座標を保存する
	int mouceStarageY = 0;	// マウスのy座標を保存する
	static int isDrctFlg = FALSE;	// 方向が定まっているか >> TRUE:定まっている FALSE:定まっていない
	static int isFirstFlg = TRUE;	// 最初かどうか >> TRUE:最初 FALSE:最初じゃない
	int i = 0;


	//マウス座標より要素数を割り出し配列へ代入
	mousex = pt.y ;
	mousey = pt.x;

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
				if (isFirstFlg == FALSE)
				{
					i++;
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
						isFirstFlg = FALSE;
						mousex = mouceStarageX;
						mousey = mouceStarageY;
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
				if (masu[mousex + 1][mousey - 1] == player * REVERSE)
				{
					Drct = eNE;
					mousex = mousex + 1;
					mousey = mousey - 1;
					if (masu[mousex + 1][mousey - 1] == player)
					{
						return TRUE;
					}
					else if (masu[mousex + 1][mousey - 1] == player * REVERSE)
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
				else
				{
					isFirstFlg = FALSE;
				}
				break;

			// 右
			case eE:
				if (masu[mousex + 1][mousey] == player * REVERSE)
				{
					Drct = eE;
					mousex = mousex + 1;
					mousey = mousey;
					if (masu[mousex + 1][mousey] == player)
					{
						return TRUE;
					}
					else if (masu[mousex + 1][mousey] == player * REVERSE)
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
				else
				{
					isFirstFlg = FALSE;
				}
				break;

			// 右下
			case eSE:
				if (masu[mousex + 1][mousey + 1] == player * REVERSE)
				{
					Drct = eSE;
					mousex = mousex + 1;
					mousey = mousey + 1;
					if (masu[mousex + 1][mousey + 1] == player)
					{
						return TRUE;
					}
					else if (masu[mousex + 1][mousey + 1] == player * REVERSE)
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
				else
				{
					isFirstFlg = FALSE;
				}
				break;

			// 下
			case eS:
				if (masu[mousex][mousey + 1] == player * REVERSE)
				{
					Drct = eS;
					mousex = mousex;
					mousey = mousey + 1;

					if (masu[mousex][mousey + 1] == player)
					{
						return TRUE;
					}
					else if (masu[mousex][mousey + 1] == player * REVERSE)
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
				else
				{
					isFirstFlg = FALSE;
				}
				break;

			// 左下
			case eSW:
				if (masu[mousex - 1][mousey + 1] == player * REVERSE)
				{
					Drct = eSW;
					mousex = mousex - 1;
					mousey = mousey + 1;

					if (masu[mousex - 1][mousey + 1] == player)
					{
						return TRUE;
					}
					else if (masu[mousex - 1][mousey + 1] == player * REVERSE)
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
				else
				{
					isFirstFlg = FALSE;
				}
				break;

			// 左
			case eW:
				if (masu[mousex - 1][mousey] == player * REVERSE)
				{
					Drct = eW;
					isDrctFlg = TRUE;
				}

					if (masu[mousex - 1][mousey] == player)
					{
						isFirstFlg = FALSE;
						isDrctFlg = FALSE;
						mousex = mouceStarageX;
						mousey = mouceStarageY;
						return TRUE;
					}
					else if (masu[mousex - 1][mousey] == player * REVERSE)
					{
						mousex = mousex-1;
						mousey = mousey ;
					}
					else
					{
						isFirstFlg = FALSE;
						isDrctFlg = FALSE;
						mousex = mouceStarageX;
						mousey = mouceStarageY;
						break;
					}
				
				
				break;

			// 左上
			case eNW:
				if (masu[mousex - 1][mousey - 1] == player * REVERSE)
				{
					Drct = eNW;
					mousex = mousex - 1;
					mousey = mousey - 1;

					if (masu[mousex - 1][mousey - 1] == player)
					{
						return TRUE;
					}
					else if (masu[mousex - 1][mousey - 1] == player * REVERSE)
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
			if (i == 8)
			{
				return FALSE;
			}

		}  //while文終了
	}  //else終了
}
