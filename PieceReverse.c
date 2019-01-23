#include<stdio.h>
#include "Global.h"
#include "PieceReverse.h"

void PieceReverse(int i, int j) {
	/*
	*/

	int mousex;			// マウスのx座標から計算したマス目
	int mousey;			// マウスのy座標から計算したマス目
	int Drct;			// 方向(Direction)を保存する
	int mouceStarageX;	// マウスのx座標を保存する
	int mouceStarageY;	// マウスのy座標を保存する
	static int isDrctFlg = FALSE;	// 方向が定まっているか >> TRUE:定まっている FALSE:定まっていない
	int k = 0;

	//マウス座標より要素数を割り出し配列へ代入
	mousex = pt.x / 50 % 8 + 1;
	mousey = pt.y / 50 % 8 + 1;

	//マウス座標の保存
	mouceStarageX = mousex;
	mouceStarageY = mousey;

	////マスの中身を判断
	//if (masu[mousex][mousey] != EMPTY)
	//{
	//	return FALSE;
	//}
	//マスが0なら置けるかどうか調べる

	while (1)
	{
		if (isDrctFlg == FALSE)
		{
			Drct = drctArray[k];
			k++;
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
				masu[mousex][mousey - 1] = player * REVERSE;
				Drct = eN;
				isDrctFlg = TRUE;
				mousex = mousex;
				mousey = mousey - 1;

				if (masu[mousex][mousey - 1] == player * REVERSE)
				{
					masu[mousex][mousey - 1] = player * REVERSE;
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
				masu[mousex + 1][mousey - 1] = player * REVERSE;
				Drct = eNE;
				isDrctFlg = TRUE;
				mousex = mousex + 1;
				mousey = mousey - 1;

				if (masu[mousex + 1][mousey - 1] == player * REVERSE)
				{
					masu[mousex + 1][mousey - 1] = player * REVERSE;
					mousex = mousex + 1;
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


		case eE:
			if (masu[mousex + 1][mousey] == player * REVERSE)
			{
				masu[mousex + 1][mousey] = player * REVERSE;
				Drct = eE;
				isDrctFlg = TRUE;
				mousex = mousex + 1;
				mousey = mousey;
				if (masu[mousex + 1][mousey] == player * REVERSE)
				{
					masu[mousex + 1][mousey] = player * REVERSE;
					mousex = mousex + 1;
					mousey = mousey;
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


		case eSE:
			if (masu[mousex + 1][mousey + 1] == player * REVERSE)
			{
				masu[mousex + 1][mousey + 1] = player * REVERSE;
				Drct = eSE;
				isDrctFlg = TRUE;
				mousex = mousex + 1;
				mousey = mousey + 1;
				if (masu[mousex + 1][mousey + 1] == player * REVERSE)
				{
					masu[mousex + 1][mousey + 1] = player * REVERSE;
					mousex = mousex + 1;
					mousey = mousey + 1;
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


		case eS:
			if (masu[mousex][mousey + 1] == player * REVERSE)
			{
				masu[mousex][mousey + 1] = player * REVERSE;
				Drct = eS;
				isDrctFlg = TRUE;
				mousex = mousex;
				mousey = mousey + 1;
				if (masu[mousex][mousey + 1] == player * REVERSE)
				{
					masu[mousex][mousey + 1] = player * REVERSE;
					mousex = mousex;
					mousey = mousey + 1;
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


		case eSW:
			if (masu[mousex - 1][mousey + 1] == player * REVERSE)
			{
				masu[mousex - 1][mousey + 1] = player * REVERSE;
				Drct = eSW;
				isDrctFlg = TRUE;
				mousex = mousex - 1;
				mousey = mousey + 1;
				if (masu[mousex - 1][mousey + 1] == player * REVERSE)
				{
					masu[mousex - 1][mousey + 1] = player * REVERSE;
					mousex = mousex - 1;
					mousey = mousey + 1;
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


		case eW:
			if (masu[mousex - 1][mousey] == player * REVERSE)
			{
				masu[mousex - 1][mousey] = player * REVERSE;
				Drct = eW;
				isDrctFlg = TRUE;
				mousex = mousex - 1;
				mousey = mousey;
				if (masu[mousex - 1][mousey] == player * REVERSE)
				{
					masu[mousex - 1][mousey] = player * REVERSE;
					mousex = mousex - 1;
					mousey = mousey;
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


		case eNW:
			if (masu[mousex - 1][mousey - 1] == player * REVERSE)
			{
				masu[mousex - 1][mousey - 1] = player * REVERSE;
				Drct = eNW;
				isDrctFlg = TRUE;
				mousex = mousex - 1;
				mousey = mousey - 1;
				if (masu[mousex - 1][mousey - 1] == player * REVERSE)
				{
					masu[mousex - 1][mousey - 1] = player * REVERSE;
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


		}  //switch文終了

		// どの方向も置けないなら
		if (k == 8)
		{
			k = 0;
			break;
		}
	}  //while文終了
}