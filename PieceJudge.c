#include <stdio.h>
#include "PieceJudge.h"

/************************************************
関 数 名 :PieceJudge()
処理内容 :駒が置けるかどうかの判定
引    数 :無し
返 却 値 :無し
備　　考 :
*************************************************/
int PieceJudge() {

	int mousex, mousey;
	int Drct;
	int i=0;
	int tmpx, tmpy;
	static int isDrctFlg = FALSE;

	//マウス座標より要素数を割り出し配列へ代入
	mousex = pt.x / 50 % 8 + 1;
	mousey = pt.y / 50 % 8 + 1;

	tmpx = mousex;
	tmpy = mousey;

	//マスの中身を判断
	if (masu[mousex][mousey] != EMPTY)
	{
		//0以外なら置けない
		return FALSE;
	}
	//マスが0なら置けるかどうか調べる
	else
	{
		while (1)
		{

			if (isDrctFlg == FALSE) {
				Drct = drctArray[i];
				i++;
			}

			switch (Drct)
			{
			case eN:
				if (masu[mousex][mousey - 1] == player * REVERSE)
				{
					Drct = eN;
					isDrctFlg = TRUE;
					mousex = mousex;
					mousey = mousey - 1;
					if (masu[mousex][mousey - 1] == player) {
						return TRUE;
					}
					else if (masu[mousex][mousey - 1] == player * REVERSE) {
						mousex = mousex;
						mousey = mousey - 1;
					}
					else {
						mousex = tmpx;
						mousey = tmpy;
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
				break;
			}  //switch文終了
		}  //while文終了
	}  //else終了

	//方向の先が0かplayerならコンティニュー
	//方向の先がplayer * REVERSE なら更にその方向の次のマスを見る
	//先のマスがplayer * REVERSE なら繰り返す
	//先のマスが0ならコンティニュー
	//先のマスがplayerなら置ける

	//置ける:return TRUE 
	//置けない:return FALSE
}
