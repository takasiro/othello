#include <stdio.h>
#include "PieceJudge.h"

/************************************************
�� �� �� :PieceJudge()
�������e :��u���邩�ǂ����̔���
��    �� :����
�� �p �l :FALSE:�u���Ȃ� TRUE:�u����
���@�@�l :�����������郍�W�b�N
			701
			6P2
			543		P:player�̒u�������Ƃ���
			������������ۂ�drctArray���g�p����
			enum�Ő����͒�`����Ă���
*************************************************/
int PieceJudge() {

	int Drct = 0;			// ����(Direction)��ۑ�����
	int mouseStorageX = 0;	// �}�E�X��x���W��ۑ�����
	int mouseStorageY = 0;	// �}�E�X��y���W��ۑ�����
	static int isDrctFlg = FALSE;	// ��������܂��Ă��邩 >> TRUE:��܂��Ă��� FALSE:��܂��Ă��Ȃ�
	int i;


	//�}�E�X���W�̑���ƕۑ�
	mousex = pt.x;
	mousey = pt.y;
	mouseStorageX = mousex;
	mouseStorageY = mousey;

	//�}�X�̒��g�𔻒f
	if (masu[mousey][mousex] != EMPTY)
	{
		return FALSE;
	}
	//�}�X��0�Ȃ�u���邩�ǂ������ׂ�
	else
	{
		for (i = 0; i <= 8; i++)
		{
			SwitchShift(i);	//�z��̗v�f�������炷

			//��悪�ِF�Ȃ��������
			if (masu[mousey][mousex] == player * REVERSE)
			{
				masu[mousey][mousex] = player;
				SwitchShift(i);
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
						masu[mousey][mousex] = player;
						SwitchShift(i);
					}
					//�悪0��������Ђ�����Ԃ��Ȃ�
					else
					{
						isDrctFlg = FALSE;
						mousey = mouseStorageY;
						mousex = mouseStorageX;
					}
				}  //while���I��
			}
			else
			{
				mousey = mouseStorageY;
				mousex = mouseStorageX;
			}


		}  //for���I��
	}  //else�I��
	return FALSE;
}