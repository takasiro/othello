/************************************************
�� �� �� :PieceCount()
�������e :��𐔂���
��    �� :&whiteCount,&blackCount:
�� �p �l :0 ����
-1 ���s(���65�ȏ� && 0�����Ȃ�)
���@�@�l :�����͊e����J�E���g����ϐ��̃A�h���X
&whiteCount ���̋��
&blackCount ���̋��
*************************************************/

#include <stdio.h>
#include"Global.h"
int PieceCount(int x) {//�܂��K��(x�̂���)

	int i, j;
	int AllCount = 0;//��̑���
	int whiteCnt = 0;//���̋�
	int blackCnt = 0;//���̋�

	for (i = 0; i < 10; i++) {//�c
		for (j = 0; j < 10; j++) {//��
			if ( masu[i][j] == 1) {
				whiteCnt++;//���̋�̃J�E���g
			}
			if ( masu[i][j] == -1) {
				blackCnt++;//���̋�̃J�E���g
			}
		}
		AllCount = whiteCnt + blackCnt;
	}
	if (AllCount <= 65 && AllCount >= 0) {//���65�ȏ� && 0�����Ȃ�
		//�� �p �l : -1 ���s
		PassJudge();
	}
	else {
		//�ԋp�l : 1 ����
		//PlayerReverse();
	}
	return 0;//���C���H
	//PlayerReverse()�֍s���H
}