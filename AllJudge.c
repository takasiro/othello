/************************************************
�� �� �� :AllJudge()
�������e :�ǂ����ɋ�u���邩�ǂ����̔���
��    �� :����
�� �p �l :1�F�u���� 0�F�u���Ȃ��@
���@�@�l :����
***************************************************/

#include <stdio.h>
#include "AllJudge.h"
int AllJudge() {
	int i, j, k;
	static int isDrctFlg = FALSE;

	for (i = 1; i <= 8;i++) {
		for (j = 1; j <= 8;j++) {
			// �}�X��EMPTY����Ȃ��Ȃ玟��
			if (masu[j][i] != EMPTY) {
				continue;
			}
			// �}�X��EMPTY�Ȃ�u���邩�ǂ����𔻒f����
			else {
				for (k = 0; k <= 8; k++)
				{
					mousex = j;
					mousey = i;

					SwitchShift(k);	//�z��̗v�f�������炷

					//��悪�ِF�Ȃ��������
					if (masu[mousey][mousex] == player * REVERSE)
					{
						//masu[mousey][mousex] = player;
						SwitchShift(k);
						isDrctFlg = TRUE;

						//�悪���F�Ȃ�
						while (isDrctFlg == TRUE)
						{
							if (masu[mousey][mousex] == player)
							{
								return TRUE;
							}
							else if (masu[mousey][mousex] == player * REVERSE)
							{
								SwitchShift(k);
							}
							//�悪0��������Ђ�����Ԃ��Ȃ�
							else
							{
								isDrctFlg = FALSE;
							}
						}  //while���I��
					}  //if���I��
				}  //for��(k)�I��
			}  //else���I��
		}  //for��(j)�I��
	}  //for��(i)�I��

	return FALSE;
}
