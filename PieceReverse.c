#include<stdio.h>
#include "Global.h"
#include "PieceReverse.h"

void PieceReverse() {
	/*
	*/

	int mousey;			// �}�E�X��x���W����v�Z�����}�X��
	int mousex;			// �}�E�X��y���W����v�Z�����}�X��
	int Drct;			// ����(Direction)��ۑ�����
static int mouceStarageX;	// �}�E�X��x���W��ۑ�����
static	int mouceStarageY;	// �}�E�X��y���W��ۑ�����
	static int isDrctFlg = FALSE;	// ��������܂��Ă��邩 >> TRUE:��܂��Ă��� FALSE:��܂��Ă��Ȃ�
	static int isFirstFlg = TRUE;	// �ŏ����ǂ��� >> TRUE:�ŏ� FALSE:�ŏ�����Ȃ�
	static int k = 0;
	int i;
	//�}�E�X���W���v�f��������o���z��֑��
	mousey = pt.y;
	mousex = pt.x;

	//�}�E�X���W�̕ۑ�
	mouceStarageX = mousex;
	mouceStarageY = mousey;

	////�}�X�̒��g�𔻒f
	//if (masu[mousey][mousex] != EMPTY)
	//{
	//	return FALSE;
	//}
	//�}�X��0�Ȃ�u���邩�ǂ������ׂ�

	//
	//
	if (masu[mouceStarageY][mouceStarageX] != player)
		masu[mouceStarageY][mouceStarageX] = player;

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
		*/

		//�����̐�̃}�X������
		switch (Drct)
		{

		case eN:
			if (masu[mousey-1][mousex] == player * REVERSE)
			{
				//masu[mousey][mousex - 1] = player * REVERSE;
				Drct = eN;
				isDrctFlg = TRUE;
			}
				/*mousey = mousey;
				mousex = mousex - 1;*/

				if (masu[mousey-1][mousex] == player * REVERSE)
				{
					//masu[mousey][mousex - 1] = player * REVERSE;
					mousey = mousey-1;
					mousex = mousex ;
				}
				else if (masu[mousey-1][mousex] == player) {
					for (i = mousey; i < mouceStarageX+1; i++) {
					if (masu[i][mousex] != player) masu[i][mousex] =player ;
				}
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouceStarageX;
					mousex = mouceStarageY;
					break;
				}
				else
				{
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouceStarageX;
					mousex = mouceStarageY;
					break;
				}
			
			break;

		case eNE:
			if (masu[mousey + 1][mousex - 1] == player * REVERSE)
			{
				masu[mousey + 1][mousex - 1] = player * REVERSE;
				Drct = eNE;
				isDrctFlg = TRUE;
				mousey = mousey + 1;
				mousex = mousex - 1;

				if (masu[mousey + 1][mousex - 1] == player * REVERSE)
				{
					//masu[mousey + 1][mousex - 1] = player * REVERSE;
					mousey = mousey + 1;
					mousex = mousex - 1;
				}
				else if (masu[mousey + 1][mousex - 1] == player) {
					for (int i = mousex + 1; i < mouceStarageY; i++) {
						for (int j = mousey - 1; j > mouceStarageX; j--) {
							masu[j][i] = player * REVERSE;
						}
					}
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouceStarageX;
					mousex = mouceStarageY;
					break;
				}
				else
				{
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouceStarageX;
					mousex = mouceStarageY;
					break;
				}
			}
			else
			{
				isFirstFlg = FALSE;
			}
			break;


		case eE:
			if (masu[mousey + 1][mousex] == player * REVERSE)
			{
				masu[mousey + 1][mousex] = player * REVERSE;
				Drct = eE;
				isDrctFlg = TRUE;
				mousey = mousey + 1;
				mousex = mousex;
				if (masu[mousey + 1][mousex] == player * REVERSE)
				{
					masu[mousey + 1][mousex] = player * REVERSE;
					mousey = mousey + 1;
					mousex = mousex;
				}
				else if (masu[mousey + 1][mousex] == player) {
						for (int i = mousey - 1; i > mouceStarageX; i--) {
							masu[i][mousex] = player * REVERSE;
						}
						isDrctFlg = FALSE;
						isFirstFlg = FALSE;
						mousey = mouceStarageX;
						mousex = mouceStarageY;
						break;
					}
				else
				{
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouceStarageX;
					mousex = mouceStarageY;
					break;
				}
			}
			else
			{
				isFirstFlg = FALSE;
			}
			break;


		case eSE:
			if (masu[mousey + 1][mousex + 1] == player * REVERSE)
			{
				masu[mousey + 1][mousex + 1] = player * REVERSE;
				Drct = eSE;
				isDrctFlg = TRUE;
				mousey = mousey + 1;
				mousex = mousex + 1;
				if (masu[mousey + 1][mousex + 1] == player * REVERSE)
				{
					masu[mousey + 1][mousex + 1] = player * REVERSE;
					mousey = mousey + 1;
					mousex = mousex + 1;
				}
				else if (masu[mousey + 1][mousex +1] == player) {
					for (int i = mousex - 1; i < mouceStarageY; i++) {
						for (int j = mousey - 1; j > mouceStarageX; j--) {
							masu[j][i] = player * REVERSE;
						}
					}
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouceStarageX;
					mousex = mouceStarageY;
					break;
				}
				else
				{
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouceStarageX;
					mousex = mouceStarageY;
					break;
				}
			}
			else
			{
				isFirstFlg = FALSE;
			}
			break;


		case eS:
			if (masu[mousey][mousex + 1] == player * REVERSE)
			{
				masu[mousey][mousex + 1] = player * REVERSE;
				Drct = eS;
				isDrctFlg = TRUE;
				mousey = mousey;
				mousex = mousex + 1;
				if (masu[mousey][mousex + 1] == player * REVERSE)
				{
					masu[mousey][mousex + 1] = player * REVERSE;
					mousey = mousey;
					mousex = mousex + 1;
				}
				else if (masu[mousey][mousex - 1] == player) {
					for (int i = mousex + 1; i < mouceStarageY; i++) {
							masu[mousey][i] = player * REVERSE;
						}
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouceStarageX;
					mousex = mouceStarageY;
					break;
				}
				else
				{
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouceStarageX;
					mousex = mouceStarageY;
					break;
				}
			}
			else
			{
				isFirstFlg = FALSE;
			}
			break;


		case eSW:
			if (masu[mousey - 1][mousex + 1] == player * REVERSE)
			{
				masu[mousey - 1][mousex + 1] = player * REVERSE;
				Drct = eSW;
				isDrctFlg = TRUE;
				mousey = mousey - 1;
				mousex = mousex + 1;
				if (masu[mousey - 1][mousex + 1] == player * REVERSE)
				{
					masu[mousey - 1][mousex + 1] = player * REVERSE;
					mousey = mousey - 1;
					mousex = mousex + 1;
				}
				else if (masu[mousey - 1][mousex +1] == player) {
					for (int i = mousex - 1; i > mouceStarageY; i++) {
						for (int j = mousey + 1; j < mouceStarageX; j--) {
							masu[j][i] = player * REVERSE;
						}
					}
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouceStarageX;
					mousex = mouceStarageY;
					break;
				}
				else
				{
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouceStarageX;
					mousex = mouceStarageY;
					break;
				}
			}
			else
			{
				isFirstFlg = FALSE;
			}
			break;


		case eW:
			if (masu[mousey - 1][mousex] == player * REVERSE)
			{
				masu[mousey - 1][mousex] = player * REVERSE;
				Drct = eW;
				isDrctFlg = TRUE;
				mousey = mousey - 1;
				mousex = mousex;
				if (masu[mousey - 1][mousex] == player * REVERSE)
				{
					masu[mousey - 1][mousex] = player * REVERSE;
					mousey = mousey - 1;
					mousex = mousex;
				}
				else if (masu[mousey - 1][mousex] == player) {
						for (int j = mousey + 1; j < mouceStarageX; j--) {
							masu[j][mousex] = player * REVERSE;
						}
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouceStarageX;
					mousex = mouceStarageY;
					break;
				}
				else
				{
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouceStarageX;
					mousex = mouceStarageY;
					break;
				}
			}
			else
			{
				isFirstFlg = FALSE;
			}
			break;


		case eNW:
			if (masu[mousey - 1][mousex - 1] == player * REVERSE)
			{
				masu[mousey - 1][mousex - 1] = player * REVERSE;
				Drct = eNW;
				isDrctFlg = TRUE;
				mousey = mousey - 1;
				mousex = mousex - 1;
				if (masu[mousey - 1][mousex - 1] == player * REVERSE)
				{
					masu[mousey - 1][mousex - 1] = player * REVERSE;
					mousey = mousey;
					mousex = mousex - 1;
				}
				else if (masu[mousey- 1][mousex - 1] == player) {
					for (int i = mousex - 1; i > mouceStarageY; i++) {
						for (int j = mousey - 1; j > mouceStarageX; j--) {
							masu[j][i] = player * REVERSE;
						}
					}
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouceStarageX;
					mousex = mouceStarageY;
					break;
				}
				else
				{
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouceStarageX;
					mousex = mouceStarageY;
					break;
				}
			}
			else
			{
				isFirstFlg = FALSE;
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