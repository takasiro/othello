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
#include "PieceCount.h"
void PieceCount() {

	int i, j;
	int AllCount = 0;//��̑���
	whiteCnt = 0;//���̋�
	blackCnt = 0;//���̋�

	for (i = 1; i <= 8; i++) {//�c
		for (j = 1; j <= 8; j++) {//��
			if ( masu[i][j] == WHITE) {
				whiteCnt++;//���̋�̃J�E���g
			}
			else if ( masu[i][j] == BLACK) {
				blackCnt++;//���̋�̃J�E���g
			}
		}
	}

	AllCount = whiteCnt + blackCnt;

	//if (AllCount <= 65 && AllCount >= 0) {//���65�ȏ� && 0�����Ȃ�
	//	//�� �p �l : -1 ���s
	//	//PassJudge();
	//}
	//else {
	//	//�ԋp�l : 1 ����
	//	//PlayerReverse();
	//}
	//return 0;//���C���H
	//PlayerReverse()�֍s���H
}