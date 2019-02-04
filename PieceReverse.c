#include<stdio.h>
#include "Global.h"
#include "PieceReverse.h"

void PieceReverse() {
	int i,j;
	int isDrctFlg = FALSE;
	int changeCount = 0;
	mousex = (int)pt.x;
	mousey = (int)pt.y;
	mouseStorageX = mousex;
	mouseStorageY = mousey;

	for (i = 0; i < 8; i++)
	{
		SwitchShift(i);	//�z��̗v�f�������炷

		//��悪�ِF�Ȃ��������
		if (masu[mousey][mousex] == player * REVERSE)
		{

			SwitchShift(i);
			changeCount++;
			isDrctFlg = TRUE;

			while (isDrctFlg == TRUE)
			{
				//�悪���F�Ȃ�Ђ�����Ԃ�
				if (masu[mousey][mousex] == player)
				{
					mousey = mouseStorageY;
					mousex = mouseStorageX;

					//�Ђ�����Ԃ�����(�߂��ăJ�E���g��i�̕����֐i��łЂ�����Ԃ�)
					for (j = 0; j < changeCount;j++) {
						SwitchShift(i);
						if (masu[mousey][mousex] != EMPTY || 
							masu[mousey][mousex] == player * REVERSE) {
							masu[mousey][mousex] = player;
						}
					}

					mousey = mouseStorageY;
					mousex = mouseStorageX;
					changeCount = 0;
					isDrctFlg = FALSE;
				}
				//�悪�ِF�Ȃ玟������
				else if (masu[mousey][mousex] == player * REVERSE)
				{
					SwitchShift(i);
					changeCount++;
				}
				//�悪0��������Ђ�����Ԃ��Ȃ�
				else
				{
					isDrctFlg = FALSE;
					changeCount = 0;
					mousey = mouseStorageY;
					mousex = mouseStorageX;
				}
			}
		}
		else
		{
			changeCount = 0;
			mousey = mouseStorageY;
			mousex = mouseStorageX;
		}

	}  //for���I��
}

//for (i = mousey; i < mouseStorageY ; i++) {
//if (masu[i][mousex] != player) masu[i][mousex] = player;
//}

	/*


	int Drct;			// ����(Direction)��ۑ�����
	static int isDrctFlg = FALSE;	// ��������܂��Ă��邩 >> TRUE:��܂��Ă��� FALSE:��܂��Ă��Ȃ�
	static int isFirstFlg = TRUE;	// �ŏ����ǂ��� >> TRUE:�ŏ� FALSE:�ŏ�����Ȃ�

	int i;
	int j;
	static int k = 0;
	//�}�E�X���W���v�f��������o���z��֑��
	mousey = mouseStorageY;
	mousex = mouseStorageX;

	////�}�X�̒��g�𔻒f
	//if (masu[mousey][mousex] != EMPTY)
	//{
	//	return FALSE;
	//}
	//�}�X��0�Ȃ�u���邩�ǂ������ׂ�

	//
	//
	if (masu[mouseStorageY][mouseStorageX] != player)
		masu[mouseStorageY][mouseStorageX] = player;

	while (1)
	{
		if (isDrctFlg == FALSE)
		{
			if (isFirstFlg == FALSE) {
				k++;
			}
			Drct = drctArray[k];


		}

		/* case�̏�������
		if( �����������̐悪�v���C���[�ƈႤ�F�Ȃ� ){
			if( ���̎����v���C���[�Ɠ����F�Ȃ� ){ return TRUE; }
			else if( �v���C���[�ƈقȂ�F�Ȃ玟�̃}�X������ ){ ���W�̈ړ� }
			else{ EMPTY�Ȃ珉���� }
		}
		*

		//�����̐�̃}�X������
		switch (Drct)
		{

		case eN:
			if (masu[mousey - 1][mousex] == player * REVERSE)
			{
				Drct = eN;
				isDrctFlg = TRUE;
			}

			if (masu[mousey - 1][mousex] == player * REVERSE)
			{
				mousey = mousey - 1;
				mousex = mousex;
			}
			else if (masu[mousey - 1][mousex] == player) {
				for (i = mousey; i < mouseStorageY ; i++) {
					if (masu[i][mousex] != player) masu[i][mousex] = player;
				}
				isDrctFlg = FALSE;
				isFirstFlg = FALSE;
				mousey = mouseStorageY;
				mousex = mouseStorageX;
				break;
			}
			else
			{
				isDrctFlg = FALSE;
				isFirstFlg = FALSE;
				mousey = mouseStorageY;
				mousex = mouseStorageX;
				break;
			}

			break;

		case eNE:
			if (masu[mousey - 1][mousex + 1] == player * REVERSE)
			{
				Drct = eNE;
				isDrctFlg = TRUE;
			}

			if (masu[mousey - 1][mousex + 1] == player * REVERSE)
			{
				mousey = mousey - 1;
				mousex = mousex + 1;
			}
			else if (masu[mousey - 1][mousex + 1] == player) {
				i = mouseStorageY;
				j = mouseStorageX;
				while (i!= mousey-1 && j!= mousex+1) {
					
					if (masu[i][j] != player) masu[i][j] = player;
					i--;
					j++;
				}
				isDrctFlg = FALSE;
				isFirstFlg = FALSE;
				mousey = mouseStorageY;
				mousex = mouseStorageX;
				break;
			}
			else
			{
				isDrctFlg = FALSE;
				isFirstFlg = FALSE;
				mousey = mouseStorageY;
				mousex = mouseStorageX;
				break;
			}
			break;


		case eE:
			if (masu[mousey][mousex + 1] == player * REVERSE)
			{
				Drct = eE;
				isDrctFlg = TRUE;
			}

			if (masu[mousey][mousex + 1] == player * REVERSE)
			{
				mousey = mousey;
				mousex = mousex + 1;
			}
			else if (masu[mousey][mousex + 1] == player) {
				for (j = mouseStorageX; j < mousex+1 ; j++) {
					if (masu[mousey][j] != player) masu[mousey][j] = player;
				}
				isDrctFlg = FALSE;
				isFirstFlg = FALSE;
				mousey = mouseStorageY;
				mousex = mouseStorageX;
				break;
			}
			else
			{
				isDrctFlg = FALSE;
				isFirstFlg = FALSE;
				mousey = mouseStorageY;
				mousex = mouseStorageX;
				break;
			}
			break;

		case eSE:
			if (masu[mousey + 1][mousex + 1] == player * REVERSE)
			{
				Drct = eSE;
				isDrctFlg = TRUE;
			}
		

			if (masu[mousey + 1][mousex + 1] == player * REVERSE)
			{
				mousey = mousey + 1;
				mousex = mousex + 1;
			}
			else if (masu[mousey + 1][mousex + 1] == player) {
				for (i = mousey; i > mouseStorageY - 1; i--) {
					for (j = mousex; j > mouseStorageX - 1; j--) {
						if (masu[i][j] != player) masu[i][j] = player;
					}
				}
				isDrctFlg = FALSE;
				isFirstFlg = FALSE;
				mousey = mouseStorageY;
				mousex = mouseStorageX;
				break;
			}
			else
			{
				isDrctFlg = FALSE;
				isFirstFlg = FALSE;
				mousey = mouseStorageY;
				mousex = mouseStorageX;
				break;
			}
			break;


		case eS:
			if (masu[mousey + 1][mousex] == player * REVERSE)
			{
				Drct = eS;
				isDrctFlg = TRUE;
			}


			if (masu[mousey + 1][mousex] == player * REVERSE)
			{
				mousey = mousey + 1;
				mousex = mousex;
			}
			else if (masu[mousey + 1][mousex] == player) {
				for (i = mousey; i > mouseStorageY ; i--) {
					if (masu[i][mousex] != player) masu[i][mousex] = player;
				}
				isDrctFlg = FALSE;
				isFirstFlg = FALSE;
				mousey = mouseStorageY;
				mousex = mouseStorageX;
				break;
			}
			else
			{
				isDrctFlg = FALSE;
				isFirstFlg = FALSE;
				mousey = mouseStorageY;
				mousex = mouseStorageX;
				break;
			}
			break;


		case eSW:
			if (masu[mousey + 1][mousex - 1] == player * REVERSE)
			{
				Drct = eSW;
				isDrctFlg = TRUE;
			}

			if (masu[mousey + 1][mousex - 1] == player * REVERSE)
			{
				mousey = mousey + 1;
				mousex = mousex - 1;
			}
			else if (masu[mousey + 1][mousex - 1] == player) {
				for (i = mousey; i > mouseStorageY - 1; i--) {
					for (j = mousex; j < mouseStorageX + 1; j ++ ) {
						if (masu[i][j] != player) masu[i][j] = player;
					}
				}
			isDrctFlg = FALSE;
			isFirstFlg = FALSE;
			mousey = mouseStorageY;
			mousex = mouseStorageX;
			break;
		}
		else
		{
			isDrctFlg = FALSE;
			isFirstFlg = FALSE;
			mousey = mouseStorageY;
			mousex = mouseStorageX;
			break;
		}
		break;


		case eW:
			if (masu[mousey][mousex - 1] == player * REVERSE)
			{
				Drct = eW;
				isDrctFlg = TRUE;
			}

			if (masu[mousey][mousex - 1] == player * REVERSE)
			{
				mousey = mousey;
				mousex = mousex - 1;
			}
			else if (masu[mousey][mousex - 1] == player) {
				for (j = mousex; j < mouseStorageX + 1; j++) {
					if (masu[mousey][j] != player) masu[mousey][j] = player;
				}
				isDrctFlg = FALSE;
				isFirstFlg = FALSE;
				mousey = mouseStorageY;
				mousex = mouseStorageX;
				break;
			}
			else
			{
				isDrctFlg = FALSE;
				isFirstFlg = FALSE;
				mousey = mouseStorageY;
				mousex = mouseStorageX;
				break;
			}
			break;


		case eNW:
			if (masu[mousey - 1][mousex - 1] == player * REVERSE)
			{
				Drct = eNW;
				isDrctFlg = TRUE;
			}

			if (masu[mousey - 1][mousex - 1] == player * REVERSE)
			{
				mousey = mousey - 1;
				mousex = mousex - 1;
			}
			else if (masu[mousey - 1][mousex - 1] == player) {
				for (i = mousey; i < mouseStorageY; i++) {
					for (j = mousex; j < mouseStorageX; j++) {
						if (masu[i][j] != player) masu[i][j] = player;
					}
				}
				isDrctFlg = FALSE;
				isFirstFlg = FALSE;
				mousey = mouseStorageY;
				mousex = mouseStorageX;
				break;
			}
			else
			{
				isDrctFlg = FALSE;
				isFirstFlg = FALSE;
				mousey = mouseStorageY;
				mousex = mouseStorageX;
				break;
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
*/