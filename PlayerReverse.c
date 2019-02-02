#include <stdio.h>
#include "PlayerReverse.h"

void PlayerReverse() {
	int i, j;
	int PassJudgeFlg = FALSE;

	if (player == BLACK) {
		player = WHITE;
	}
	else {
		player = BLACK;
	}

	AllJudge();

	//置けるところがあればフラグがTRUEになりパスにはならない
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