/************************************************
�� �� �� :AllJudge(const int * ,int player )
�������e :�ǂ����ɋ�u���邩�ǂ����̔���
��    �� :  :�z��̃A�h���X,player
�� �p �l :����
���@�@�l :1�F�u����
�@�@�@�@�@0�F�u���Ȃ��@
	 �@�@�@�@�@�@PassJudge();
***************************************************/

#include <stdio.h>
#include"Global.h"
#include "AllJudge.h"
int AllJudge(int x) {//�܂��K��(x�̂���)
	
	//�񎟌��z�� masu[10][10]
	//��U�͍� -1
	//��U�͔�  1
	//�O���[�o���ɂ���ϐ� REVERSE  -1��������
	int i, j;
	int ZEROcnt = 0;
	int NUM;
	int AllJudgeFlg;//�u����Ȃ琬��������
	//player = player * REVERSE;//�v���C���[�̐F��ς���
	static int isDrctFlg = FALSE;
	int Drct = 0;

	for (i = 1; i <= 8; i++) {
		for (j = 1; j <= 8; j++) {
			NUM = masu[i][j];
			if (masu[i][j] == 0) {//8���������鏈��
				
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
							ZEROcnt++;//0�Ȃ�PassJudge�ɔ�Ԃ��߂̃J�E���g
						}
						break;
					case eNE:
						if (masu[i + 1][j - 1] == player * REVERSE)
						{
							Drct = eNE;
							//	mousex = mousex + 1;
							//	mousey = mousey - 1;
							ZEROcnt++;//0�Ȃ�PassJudge�ɔ�Ԃ��߂̃J�E���g
						}
						break;
					case eE:
						if (masu[i + 1][j] == player * REVERSE)
						{
							Drct = eE;
							//	mousex = mousex + 1;
							//	mousey = mousey;
							ZEROcnt++;//0�Ȃ�PassJudge�ɔ�Ԃ��߂̃J�E���g
						}
						break;
					case eSE:
						if (masu[i + 1][j + 1] == player * REVERSE)
						{
							Drct = eSE;
							//	mousex = mousex + 1;
							//	mousey = mousey + 1;
							ZEROcnt++;//0�Ȃ�PassJudge�ɔ�Ԃ��߂̃J�E���g
						}
						break;
					case eS:
						if (masu[i][j + 1] == player * REVERSE)
						{
							Drct = eS;
							//	mousex = mousex;
							//	mousey = mousey + 1;
							ZEROcnt++;//0�Ȃ�PassJudge�ɔ�Ԃ��߂̃J�E���g
						}
						break;
					case eSW:
						if (masu[i - 1][j + 1] == player * REVERSE)
						{
							Drct = eSW;
							//	mousex = mousex - 1;
							//	mousey = mousey + 1;
							ZEROcnt++;//0�Ȃ�PassJudge�ɔ�Ԃ��߂̃J�E���g
						}
						break;
					case eW:
						if (masu[i - 1][j] == player * REVERSE)
						{
							Drct = eW;
							//	mousex = mousex - 1;
							//	mousey = mousey;
							ZEROcnt++;//0�Ȃ�PassJudge�ɔ�Ԃ��߂̃J�E���g
						}
						break;
					case eNW:
						if (masu[i - 1][j - 1] == player * REVERSE)
						{
							Drct = eNW;
							//	mousex = mousex - 1;
							//	mousey = mousey - 1;
							ZEROcnt++;//0�Ȃ�PassJudge�ɔ�Ԃ��߂̃J�E���g
						}
						break;
					default:
						break;
					}  //switch���I��
				}  //while���I��

				//������Ȃ�ZEROcnt�J�E���g��i�߂�H
				//����+1
			}

			if (masu[i][j] == player || masu[i][j] == player * REVERSE) {
				//�v���C���[�Ɠ����F���Ⴄ�F�Ȃ�
					//break or �R���e�B�j���[������
				break;
			}
		}
	}
	if (ZEROcnt <= 0) {//�Zor�����u����Ă��Ȃ��}�X���Ȃ����
		PassJudge();//PassJudge�֐��ɂƂ�
	}
	else {//�J�E���g��1�ȏ�Ȃ�
		  //�u����Ȃ�PieceJudge()?�ւƂ�
		return 0;
	}

/*
0�̎���8�������ċ󔒂Ɠ����F�Ȃ�break
�Ⴄ�F�Ȃ炻�̐�����Ă����邩�ǂ������f����
������Ȃ�t���O��ύX����PieceJudge�֍s��
������ꏊ���Ȃ��Ȃ�PassJudeg�֍s��

*/
