#include <stdio.h>
#include "PieceJudge.h"

/************************************************
�� �� �� :PieceJudge()
�������e :��u���邩�ǂ����̔���
��    �� :����
�� �p �l :����
���@�@�l :
*************************************************/
int PieceJudge() {

	int mousex, mousey;
	int Drct;
	int i=0;
	int tmpx, tmpy;
	static int isDrctFlg = FALSE;

	//�}�E�X���W���v�f��������o���z��֑��
	mousex = pt.x / 50 % 8 + 1;
	mousey = pt.y / 50 % 8 + 1;

	tmpx = mousex;
	tmpy = mousey;

	//�}�X�̒��g�𔻒f
	if (masu[mousex][mousey] != EMPTY)
	{
		//0�ȊO�Ȃ�u���Ȃ�
		return FALSE;
	}
	//�}�X��0�Ȃ�u���邩�ǂ������ׂ�
	else
	{
		while (1)
		{

			if (isDrctFlg == FALSE) {
				Drct = drctArray[i];
				i++;
			}

			switch (Drct)
			{
			case eN:
				if (masu[mousex][mousey - 1] == player * REVERSE)
				{
					Drct = eN;
					isDrctFlg = TRUE;
					mousex = mousex;
					mousey = mousey - 1;
					if (masu[mousex][mousey - 1] == player) {
						return TRUE;
					}
					else if (masu[mousex][mousey - 1] == player * REVERSE) {
						mousex = mousex;
						mousey = mousey - 1;
					}
					else {
						mousex = tmpx;
						mousey = tmpy;
						break;
					}
				}
				break;
			case eNE:
				if (masu[mousex + 1][mousey - 1] == player * REVERSE)
				{
					Drct = eNE;
					mousex = mousex + 1;
					mousey = mousey - 1;
				}
				break;
			case eE:
				if (masu[mousex + 1][mousey] == player * REVERSE)
				{
					Drct = eE;
					mousex = mousex + 1;
					mousey = mousey;
				}
				break;
			case eSE:
				if (masu[mousex + 1][mousey + 1] == player * REVERSE)
				{
					Drct = eSE;
					mousex = mousex + 1;
					mousey = mousey + 1;
				}
				break;
			case eS:
				if (masu[mousex][mousey + 1] == player * REVERSE)
				{
					Drct = eS;
					mousex = mousex;
					mousey = mousey + 1;
				}
				break;
			case eSW:
				if (masu[mousex - 1][mousey + 1] == player * REVERSE)
				{
					Drct = eSW;
					mousex = mousex - 1;
					mousey = mousey + 1;
				}
				break;
			case eW:
				if (masu[mousex - 1][mousey] == player * REVERSE)
				{
					Drct = eW;
					mousex = mousex - 1;
					mousey = mousey;
				}
				break;
			case eNW:
				if (masu[mousex - 1][mousey - 1] == player * REVERSE)
				{
					Drct = eNW;
					mousex = mousex - 1;
					mousey = mousey - 1;
				}
				break;
			default:
				break;
			}  //switch���I��
		}  //while���I��
	}  //else�I��

	//�����̐悪0��player�Ȃ�R���e�B�j���[
	//�����̐悪player * REVERSE �Ȃ�X�ɂ��̕����̎��̃}�X������
	//��̃}�X��player * REVERSE �Ȃ�J��Ԃ�
	//��̃}�X��0�Ȃ�R���e�B�j���[
	//��̃}�X��player�Ȃ�u����

	//�u����:return TRUE 
	//�u���Ȃ�:return FALSE
}
