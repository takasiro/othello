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

	//�u����Ƃ��낪����΃t���O��TRUE�ɂȂ�p�X�ɂ͂Ȃ�Ȃ�
	for (i = 1; i <= 8; i++) {
		for (j = 1; j <= 8; j++) {
			if (canPutMasu[j][i] == TRUE) {
				PassJudgeFlg = TRUE;
			}
		}
	}
	//�u���Ƃ��낪����������p�X
	if (PassJudgeFlg == FALSE) {
		PassJudge();
	}

}