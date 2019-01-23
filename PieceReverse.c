#include<stdio.h>
#include "Global.h"
#include "PieceReverse.h"

void PieceReverse(int i, int j) {
	/*
	*/

	int mousex;			// �}�E�X��x���W����v�Z�����}�X��
	int mousey;			// �}�E�X��y���W����v�Z�����}�X��
	int Drct;			// ����(Direction)��ۑ�����
	int mouceStarageX;	// �}�E�X��x���W��ۑ�����
	int mouceStarageY;	// �}�E�X��y���W��ۑ�����
	static int isDrctFlg = FALSE;	// ��������܂��Ă��邩 >> TRUE:��܂��Ă��� FALSE:��܂��Ă��Ȃ�
	int k = 0;

	//�}�E�X���W���v�f��������o���z��֑��
	mousex = pt.x / 50 % 8 + 1;
	mousey = pt.y / 50 % 8 + 1;

	//�}�E�X���W�̕ۑ�
	mouceStarageX = mousex;
	mouceStarageY = mousey;

	////�}�X�̒��g�𔻒f
	//if (masu[mousex][mousey] != EMPTY)
	//{
	//	return FALSE;
	//}
	//�}�X��0�Ȃ�u���邩�ǂ������ׂ�

	while (1)
	{
		if (isDrctFlg == FALSE)
		{
			Drct = drctArray[k];
			k++;
		}

		/* case�̏�������
		if( �����������̐悪�v���C���[�ƈႤ�F�Ȃ� ){
			if( ���̎����v���C���[�Ɠ����F�Ȃ� ){ return TRUE; }
			else if( �v���C���[�ƈقȂ�F�Ȃ玟�̃}�X������ ){ ���W�̈ړ� }
			else{ EMPTY�Ȃ珉���� }
		}
		*/

		//�����̐�̃}�X������
		switch (Drct)
		{

		case eN:
			if (masu[mousex][mousey - 1] == player * REVERSE)
			{
				masu[mousex][mousey - 1] = player * REVERSE;
				Drct = eN;
				isDrctFlg = TRUE;
				mousex = mousex;
				mousey = mousey - 1;

				if (masu[mousex][mousey - 1] == player * REVERSE)
				{
					masu[mousex][mousey - 1] = player * REVERSE;
					mousex = mousex;
					mousey = mousey - 1;
				}
				else
				{
					isDrctFlg = FALSE;
					mousex = mouceStarageX;
					mousey = mouceStarageY;
					break;
				}
			}
			break;


		case eNE:
			if (masu[mousex + 1][mousey - 1] == player * REVERSE)
			{
				masu[mousex + 1][mousey - 1] = player * REVERSE;
				Drct = eNE;
				isDrctFlg = TRUE;
				mousex = mousex + 1;
				mousey = mousey - 1;

				if (masu[mousex + 1][mousey - 1] == player * REVERSE)
				{
					masu[mousex + 1][mousey - 1] = player * REVERSE;
					mousex = mousex + 1;
					mousey = mousey - 1;
				}
				else
				{
					isDrctFlg = FALSE;
					mousex = mouceStarageX;
					mousey = mouceStarageY;
					break;
				}
			}
			break;


		case eE:
			if (masu[mousex + 1][mousey] == player * REVERSE)
			{
				masu[mousex + 1][mousey] = player * REVERSE;
				Drct = eE;
				isDrctFlg = TRUE;
				mousex = mousex + 1;
				mousey = mousey;
				if (masu[mousex + 1][mousey] == player * REVERSE)
				{
					masu[mousex + 1][mousey] = player * REVERSE;
					mousex = mousex + 1;
					mousey = mousey;
				}
				else
				{
					isDrctFlg = FALSE;
					mousex = mouceStarageX;
					mousey = mouceStarageY;
					break;
				}
			}
			break;


		case eSE:
			if (masu[mousex + 1][mousey + 1] == player * REVERSE)
			{
				masu[mousex + 1][mousey + 1] = player * REVERSE;
				Drct = eSE;
				isDrctFlg = TRUE;
				mousex = mousex + 1;
				mousey = mousey + 1;
				if (masu[mousex + 1][mousey + 1] == player * REVERSE)
				{
					masu[mousex + 1][mousey + 1] = player * REVERSE;
					mousex = mousex + 1;
					mousey = mousey + 1;
				}
				else
				{
					isDrctFlg = FALSE;
					mousex = mouceStarageX;
					mousey = mouceStarageY;
					break;
				}
			}
			break;


		case eS:
			if (masu[mousex][mousey + 1] == player * REVERSE)
			{
				masu[mousex][mousey + 1] = player * REVERSE;
				Drct = eS;
				isDrctFlg = TRUE;
				mousex = mousex;
				mousey = mousey + 1;
				if (masu[mousex][mousey + 1] == player * REVERSE)
				{
					masu[mousex][mousey + 1] = player * REVERSE;
					mousex = mousex;
					mousey = mousey + 1;
				}
				else
				{
					isDrctFlg = FALSE;
					mousex = mouceStarageX;
					mousey = mouceStarageY;
					break;
				}
			}
			break;


		case eSW:
			if (masu[mousex - 1][mousey + 1] == player * REVERSE)
			{
				masu[mousex - 1][mousey + 1] = player * REVERSE;
				Drct = eSW;
				isDrctFlg = TRUE;
				mousex = mousex - 1;
				mousey = mousey + 1;
				if (masu[mousex - 1][mousey + 1] == player * REVERSE)
				{
					masu[mousex - 1][mousey + 1] = player * REVERSE;
					mousex = mousex - 1;
					mousey = mousey + 1;
				}
				else
				{
					isDrctFlg = FALSE;
					mousex = mouceStarageX;
					mousey = mouceStarageY;
					break;
				}
			}
			break;


		case eW:
			if (masu[mousex - 1][mousey] == player * REVERSE)
			{
				masu[mousex - 1][mousey] = player * REVERSE;
				Drct = eW;
				isDrctFlg = TRUE;
				mousex = mousex - 1;
				mousey = mousey;
				if (masu[mousex - 1][mousey] == player * REVERSE)
				{
					masu[mousex - 1][mousey] = player * REVERSE;
					mousex = mousex - 1;
					mousey = mousey;
				}
				else
				{
					isDrctFlg = FALSE;
					mousex = mouceStarageX;
					mousey = mouceStarageY;
					break;
				}
			}
			break;


		case eNW:
			if (masu[mousex - 1][mousey - 1] == player * REVERSE)
			{
				masu[mousex - 1][mousey - 1] = player * REVERSE;
				Drct = eNW;
				isDrctFlg = TRUE;
				mousex = mousex - 1;
				mousey = mousey - 1;
				if (masu[mousex - 1][mousey - 1] == player * REVERSE)
				{
					masu[mousex - 1][mousey - 1] = player * REVERSE;
					mousex = mousex;
					mousey = mousey - 1;
				}
				else
				{
					isDrctFlg = FALSE;
					mousex = mouceStarageX;
					mousey = mouceStarageY;
					break;
				}
			}
			break;


		}  //switch���I��

		// �ǂ̕������u���Ȃ��Ȃ�
		if (k == 8)
		{
			k = 0;
			break;
		}
	}  //while���I��
}