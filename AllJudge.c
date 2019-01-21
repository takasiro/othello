/************************************************
関 数 名 :AllJudge(const int * ,int player )
処理内容 :どこかに駒が置けるかどうかの判定
引    数 :  :配列のアドレス,player
返 却 値 :無し
備　　考 :1：置ける
　　　　　0：置けない　
	 　　　　　　PassJudge();
***************************************************/

#include <stdio.h>
#include"Global.h"
#include "AllJudge.h"
int AllJudge(int x) {//まだ適当(xのこと)
	
	//二次元配列 masu[10][10]
	//先攻は黒 -1
	//後攻は白  1
	//グローバルにある変数 REVERSE  -1をかける
	int i, j;
	int ZEROcnt = 0;
	int NUM;
	int AllJudgeFlg;//置けるなら成功させる
	//player = player * REVERSE;//プレイヤーの色を変える
	static int isDrctFlg = FALSE;
	int Drct = 0;

	for (i = 1; i <= 8; i++) {
		for (j = 1; j <= 8; j++) {
			NUM = masu[i][j];
			if (masu[i][j] == 0) {//8方向を見る処理
				
				while (1)
				{

					if (isDrctFlg == FALSE) {
							Drct = drctArray[i];
						i++;
					}

					switch (Drct)
					{
					case eN:
						if (masu[i][j - 1] == player * REVERSE)
						{
							Drct = eN;
							isDrctFlg = TRUE;
							//	mousex = mousex;
							//	mousey = mousey - 1;
							if (masu[i][j - 1] == player) {
								//return TRUE;
							}
							else if (masu[i][j - 1] == player * REVERSE) {
								//		mousex = mousex;
								//		mousey = mousey - 1;
							}
							else {
								//		mousex = tmpx;
								//		mousey = tmpy;
								break;
							}
							ZEROcnt++;//0ならPassJudgeに飛ぶためのカウント
						}
						break;
					case eNE:
						if (masu[i + 1][j - 1] == player * REVERSE)
						{
							Drct = eNE;
							//	mousex = mousex + 1;
							//	mousey = mousey - 1;
							ZEROcnt++;//0ならPassJudgeに飛ぶためのカウント
						}
						break;
					case eE:
						if (masu[i + 1][j] == player * REVERSE)
						{
							Drct = eE;
							//	mousex = mousex + 1;
							//	mousey = mousey;
							ZEROcnt++;//0ならPassJudgeに飛ぶためのカウント
						}
						break;
					case eSE:
						if (masu[i + 1][j + 1] == player * REVERSE)
						{
							Drct = eSE;
							//	mousex = mousex + 1;
							//	mousey = mousey + 1;
							ZEROcnt++;//0ならPassJudgeに飛ぶためのカウント
						}
						break;
					case eS:
						if (masu[i][j + 1] == player * REVERSE)
						{
							Drct = eS;
							//	mousex = mousex;
							//	mousey = mousey + 1;
							ZEROcnt++;//0ならPassJudgeに飛ぶためのカウント
						}
						break;
					case eSW:
						if (masu[i - 1][j + 1] == player * REVERSE)
						{
							Drct = eSW;
							//	mousex = mousex - 1;
							//	mousey = mousey + 1;
							ZEROcnt++;//0ならPassJudgeに飛ぶためのカウント
						}
						break;
					case eW:
						if (masu[i - 1][j] == player * REVERSE)
						{
							Drct = eW;
							//	mousex = mousex - 1;
							//	mousey = mousey;
							ZEROcnt++;//0ならPassJudgeに飛ぶためのカウント
						}
						break;
					case eNW:
						if (masu[i - 1][j - 1] == player * REVERSE)
						{
							Drct = eNW;
							//	mousex = mousex - 1;
							//	mousey = mousey - 1;
							ZEROcnt++;//0ならPassJudgeに飛ぶためのカウント
						}
						break;
					default:
						break;
					}  //switch文終了
				}  //while文終了

				//おけるならZEROcntカウントを進める？
				//成功+1
			}

			if (masu[i][j] == player || masu[i][j] == player * REVERSE) {
				//プレイヤーと同じ色か違う色なら
					//break or コンティニューさせる
				break;
			}
		}
	}
	if (ZEROcnt <= 0) {//〇or●が置かれていないマスがなければ
		PassJudge();//PassJudge関数にとぶ
	}
	else {//カウントが1以上なら
		  //置けるならPieceJudge()?へとぶ
		return 0;
	}

/*
0の時に8方向見て空白と同じ色ならbreak
違う色ならその先を見ておけるかどうか判断する
おけるならフラグを変更してPieceJudgeへ行く
おける場所がないならPassJudegへ行く

*/
