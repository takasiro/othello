#include <stdio.h>
#include "PlayerReverse.h"

void PlayerReverse() {
	int i, j;
	int PassJudgeFlg = FALSE;	//�u����Ƃ��낪���邩�ǂ��� TRUE:�u���� FALSE:�u���Ȃ�

	//�v���C���[�̔��]
	if (player == BLACK) {
		player = WHITE;
	}
	else {
		player = BLACK;
	}

	//�v���C���[�͕ς���Ă���͂������Ȃ���
	//�u����ꏊ�̕\�������葤�̕��ɂȂ��Ă���

	//�u���邩���f
	AllJudge();

	//�u����Ƃ��낪����΃t���O��TRUE�ɂȂ�p�X�ɂȂ�Ȃ�
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