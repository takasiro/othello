/************************************************
関 数 名 :PieceCount()
処理内容 :駒数を数える
引    数 :&whiteCount,&blackCount:
返 却 値 :0 成功
-1 失敗(駒数が65以上 && 0未満なら)
備　　考 :引数は各駒をカウントする変数のアドレス
&whiteCount 白の駒総数
&blackCount 黒の駒総数
*************************************************/

#include <stdio.h>
#include "PieceCount.h"
void PieceCount() {

	int i, j;
	int AllCount = 0;//駒の総数
	whiteCnt = 0;//白の駒
	blackCnt = 0;//黒の駒

	for (i = 1; i <= 8; i++) {//縦
		for (j = 1; j <= 8; j++) {//横
			if ( masu[i][j] == WHITE) {
				whiteCnt++;//白の駒のカウント
			}
			else if ( masu[i][j] == BLACK) {
				blackCnt++;//黒の駒のカウント
			}
		}
	}

	AllCount = whiteCnt + blackCnt;

	//if (AllCount <= 65 && AllCount >= 0) {//駒数が65以上 && 0未満なら
	//	//返 却 値 : -1 失敗
	//	//PassJudge();
	//}
	//else {
	//	//返却値 : 1 成功
	//	//PlayerReverse();
	//}
	//return 0;//メイン？
	//PlayerReverse()へ行く？
}