/************************************************
�� �� �� :AllJudge()
�������e :�ǂ����ɋ�u���邩�ǂ����̔���
��    �� :����
�� �p �l :1�F�u���� 0�F�u���Ȃ��@
���@�@�l :����
***************************************************/

#include <stdio.h>
#include "AllJudge.h"
void AllJudge() {
	int i, j, k;
	static int isDrctFlg = FALSE;

	InitCanPutMasu();

	for (i = 1; i <= 8;i++) {
		for (j = 1; j <= 8;j++) {
			// �}�X��EMPTY����Ȃ��Ȃ玟��
			if (masu[j][i] != EMPTY) {
				continue;
			}
			// �}�X��EMPTY�Ȃ�u���邩�ǂ����𔻒f����
			else {
				for (k = 0; k < 8; k++)
				{
					mousex = j;
					mousey = i;

					SwitchShift(k);	//�z��̗v�f�������炷

					//��悪�ِF�Ȃ��������
					if (masu[mousey][mousex] == player * REVERSE)
					{
						
						SwitchShift(k);
						isDrctFlg = TRUE;

						//�悪���F�Ȃ�
						while (isDrctFlg == TRUE)
						{
							if (masu[mousey][mousex] == player)
							{
								//return TRUE;
								canPutMasu[j][i] = TRUE;
								mousey = j;
								mousex = i;
								isDrctFlg = FALSE;
							}
							else if (masu[mousey][mousex] == player * REVERSE)
							{
								SwitchShift(k);
							}
							//�悪0��������Ђ�����Ԃ��Ȃ�
							else
							{
								isDrctFlg = FALSE;
								mousey = j;
								mousex = i;
							}
						}  //while���I��
					}  //if���I��
					else
					{
						isDrctFlg = FALSE;
						mousey = j;
						mousex = i;
					}
				}  //for��(k)�I��
			}  //else���I��
		}  //for��(j)�I��
	}  //for��(i)�I��
}

void InitCanPutMasu() {
	int i, j;

	for (i = 1; i <= 8;i++) {
		for (j = 1; j <= 8;j++) {
			canPutMasu[j][i] = FALSE;
		}
	}
}
