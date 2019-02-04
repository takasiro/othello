#include <stdio.h>
#include "PlayerReverse.h"

void PlayerReverse() {
	int i, j;
	int PassJudgeFlg = FALSE;	//置けるところがあるかどうか TRUE:置ける FALSE:置けない

	//プレイヤーの反転
	player = player * REVERSE;

	//置けるか判断
	AllJudge();

	//置けるところがあればフラグがTRUEになりパスにならない
	for (i = 1; i <= 8; i++) {
		for (j = 1; j <= 8; j++) {
			if (canPutMasu[j][i] == TRUE) {
				PassJudgeFlg = TRUE;
			}
		}
	}
	//置くところが無かったらパス
	if (PassJudgeFlg == FALSE) {
		PassJudge();
	}

}