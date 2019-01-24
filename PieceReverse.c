#include<stdio.h>
#include "Global.h"
#include "PieceReverse.h"

void PieceReverse() {
	/*
	*/

	int mousey;			// マウスのx座標から計算したマス目
	int mousex;			// マウスのy座標から計算したマス目
	int Drct;			// 方向(Direction)を保存する
static int mouceStarageX;	// マウスのx座標を保存する
static	int mouceStarageY;	// マウスのy座標を保存する
	static int isDrctFlg = FALSE;	// 方向が定まっているか >> TRUE:定まっている FALSE:定まっていない
	static int isFirstFlg = TRUE;	// 最初かどうか >> TRUE:最初 FALSE:最初じゃない
	static int k = 0;
	int i;
	//マウス座標より要素数を割り出し配列へ代入
	mousey = pt.y;
	mousex = pt.x;

	//マウス座標の保存
	mouceStarageX = mousex;
	mouceStarageY = mousey;

	////マスの中身を判断
	//if (masu[mousey][mousex] != EMPTY)
	//{
	//	return FALSE;
	//}
	//マスが0なら置けるかどうか調べる

	//
	//
	if (masu[mouceStarageY][mouceStarageX] != player)
		masu[mouceStarageY][mouceStarageX] = player;

	while (1)
	{
		if (isDrctFlg == FALSE)
		{
			if (isFirstFlg == FALSE) {
				k++;
			}
			Drct = drctArray[k];


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
			if (masu[mousey-1][mousex] == player * REVERSE)
			{
				//masu[mousey][mousex - 1] = player * REVERSE;
				Drct = eN;
				isDrctFlg = TRUE;
			}
				/*mousey = mousey;
				mousex = mousex - 1;*/

				if (masu[mousey-1][mousex] == player * REVERSE)
				{
					//masu[mousey][mousex - 1] = player * REVERSE;
					mousey = mousey-1;
					mousex = mousex ;
				}
				else if (masu[mousey-1][mousex] == player) {
					for (i = mousey; i < mouceStarageX+1; i++) {
					if (masu[i][mousex] != player) masu[i][mousex] =player ;
				}
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouceStarageX;
					mousex = mouceStarageY;
					break;
				}
				else
				{
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouceStarageX;
					mousex = mouceStarageY;
					break;
				}
			
			break;

		case eNE:
			if (masu[mousey + 1][mousex - 1] == player * REVERSE)
			{
				masu[mousey + 1][mousex - 1] = player * REVERSE;
				Drct = eNE;
				isDrctFlg = TRUE;
				mousey = mousey + 1;
				mousex = mousex - 1;

				if (masu[mousey + 1][mousex - 1] == player * REVERSE)
				{
					//masu[mousey + 1][mousex - 1] = player * REVERSE;
					mousey = mousey + 1;
					mousex = mousex - 1;
				}
				else if (masu[mousey + 1][mousex - 1] == player) {
					for (int i = mousex + 1; i < mouceStarageY; i++) {
						for (int j = mousey - 1; j > mouceStarageX; j--) {
							masu[j][i] = player * REVERSE;
						}
					}
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouceStarageX;
					mousex = mouceStarageY;
					break;
				}
				else
				{
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouceStarageX;
					mousex = mouceStarageY;
					break;
				}
			}
			else
			{
				isFirstFlg = FALSE;
			}
			break;


		case eE:
			if (masu[mousey + 1][mousex] == player * REVERSE)
			{
				masu[mousey + 1][mousex] = player * REVERSE;
				Drct = eE;
				isDrctFlg = TRUE;
				mousey = mousey + 1;
				mousex = mousex;
				if (masu[mousey + 1][mousex] == player * REVERSE)
				{
					masu[mousey + 1][mousex] = player * REVERSE;
					mousey = mousey + 1;
					mousex = mousex;
				}
				else if (masu[mousey + 1][mousex] == player) {
						for (int i = mousey - 1; i > mouceStarageX; i--) {
							masu[i][mousex] = player * REVERSE;
						}
						isDrctFlg = FALSE;
						isFirstFlg = FALSE;
						mousey = mouceStarageX;
						mousex = mouceStarageY;
						break;
					}
				else
				{
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouceStarageX;
					mousex = mouceStarageY;
					break;
				}
			}
			else
			{
				isFirstFlg = FALSE;
			}
			break;


		case eSE:
			if (masu[mousey + 1][mousex + 1] == player * REVERSE)
			{
				masu[mousey + 1][mousex + 1] = player * REVERSE;
				Drct = eSE;
				isDrctFlg = TRUE;
				mousey = mousey + 1;
				mousex = mousex + 1;
				if (masu[mousey + 1][mousex + 1] == player * REVERSE)
				{
					masu[mousey + 1][mousex + 1] = player * REVERSE;
					mousey = mousey + 1;
					mousex = mousex + 1;
				}
				else if (masu[mousey + 1][mousex +1] == player) {
					for (int i = mousex - 1; i < mouceStarageY; i++) {
						for (int j = mousey - 1; j > mouceStarageX; j--) {
							masu[j][i] = player * REVERSE;
						}
					}
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouceStarageX;
					mousex = mouceStarageY;
					break;
				}
				else
				{
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouceStarageX;
					mousex = mouceStarageY;
					break;
				}
			}
			else
			{
				isFirstFlg = FALSE;
			}
			break;


		case eS:
			if (masu[mousey][mousex + 1] == player * REVERSE)
			{
				masu[mousey][mousex + 1] = player * REVERSE;
				Drct = eS;
				isDrctFlg = TRUE;
				mousey = mousey;
				mousex = mousex + 1;
				if (masu[mousey][mousex + 1] == player * REVERSE)
				{
					masu[mousey][mousex + 1] = player * REVERSE;
					mousey = mousey;
					mousex = mousex + 1;
				}
				else if (masu[mousey][mousex - 1] == player) {
					for (int i = mousex + 1; i < mouceStarageY; i++) {
							masu[mousey][i] = player * REVERSE;
						}
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouceStarageX;
					mousex = mouceStarageY;
					break;
				}
				else
				{
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouceStarageX;
					mousex = mouceStarageY;
					break;
				}
			}
			else
			{
				isFirstFlg = FALSE;
			}
			break;


		case eSW:
			if (masu[mousey - 1][mousex + 1] == player * REVERSE)
			{
				masu[mousey - 1][mousex + 1] = player * REVERSE;
				Drct = eSW;
				isDrctFlg = TRUE;
				mousey = mousey - 1;
				mousex = mousex + 1;
				if (masu[mousey - 1][mousex + 1] == player * REVERSE)
				{
					masu[mousey - 1][mousex + 1] = player * REVERSE;
					mousey = mousey - 1;
					mousex = mousex + 1;
				}
				else if (masu[mousey - 1][mousex +1] == player) {
					for (int i = mousex - 1; i > mouceStarageY; i++) {
						for (int j = mousey + 1; j < mouceStarageX; j--) {
							masu[j][i] = player * REVERSE;
						}
					}
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouceStarageX;
					mousex = mouceStarageY;
					break;
				}
				else
				{
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouceStarageX;
					mousex = mouceStarageY;
					break;
				}
			}
			else
			{
				isFirstFlg = FALSE;
			}
			break;


		case eW:
			if (masu[mousey - 1][mousex] == player * REVERSE)
			{
				masu[mousey - 1][mousex] = player * REVERSE;
				Drct = eW;
				isDrctFlg = TRUE;
				mousey = mousey - 1;
				mousex = mousex;
				if (masu[mousey - 1][mousex] == player * REVERSE)
				{
					masu[mousey - 1][mousex] = player * REVERSE;
					mousey = mousey - 1;
					mousex = mousex;
				}
				else if (masu[mousey - 1][mousex] == player) {
						for (int j = mousey + 1; j < mouceStarageX; j--) {
							masu[j][mousex] = player * REVERSE;
						}
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouceStarageX;
					mousex = mouceStarageY;
					break;
				}
				else
				{
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouceStarageX;
					mousex = mouceStarageY;
					break;
				}
			}
			else
			{
				isFirstFlg = FALSE;
			}
			break;


		case eNW:
			if (masu[mousey - 1][mousex - 1] == player * REVERSE)
			{
				masu[mousey - 1][mousex - 1] = player * REVERSE;
				Drct = eNW;
				isDrctFlg = TRUE;
				mousey = mousey - 1;
				mousex = mousex - 1;
				if (masu[mousey - 1][mousex - 1] == player * REVERSE)
				{
					masu[mousey - 1][mousex - 1] = player * REVERSE;
					mousey = mousey;
					mousex = mousex - 1;
				}
				else if (masu[mousey- 1][mousex - 1] == player) {
					for (int i = mousex - 1; i > mouceStarageY; i++) {
						for (int j = mousey - 1; j > mouceStarageX; j--) {
							masu[j][i] = player * REVERSE;
						}
					}
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouceStarageX;
					mousex = mouceStarageY;
					break;
				}
				else
				{
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouceStarageX;
					mousex = mouceStarageY;
					break;
				}
			}
			else
			{
				isFirstFlg = FALSE;
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