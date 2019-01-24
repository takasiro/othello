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

	int mousex = 0;			// �}�E�X��x���W����v�Z�����}�X��
	int mousey = 0;			// �}�E�X��y���W����v�Z�����}�X��
	int Drct = 0;			// ����(Direction)��ۑ�����
	int mouseStarageX = 0;	// �}�E�X��x���W��ۑ�����
	int mouseStarageY = 0;	// �}�E�X��y���W��ۑ�����
	static int isDrctFlg = FALSE;	// ��������܂��Ă��邩 >> TRUE:��܂��Ă��� FALSE:��܂��Ă��Ȃ�
	static int isFirstFlg = TRUE;	// �ŏ����ǂ��� >> TRUE:�ŏ� FALSE:�ŏ�����Ȃ�
	int count = 0;


	//�}�E�X���W�̑���ƕۑ�
	mousex = pt.x;
	mousey = pt.y;
	mouseStarageX = mousex;
	mouseStarageY = mousey;

	//�}�X�̒��g�𔻒f
	if (masu[mousey][mousex] != EMPTY)
	{
		return FALSE;
	}
	//�}�X��0�Ȃ�u���邩�ǂ������ׂ�
	else
	{
		while (1)
		{

			if (isDrctFlg == FALSE)
			{
				Drct = drctArray[count];
				if (isFirstFlg == FALSE)
				{
					count++;
				}
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

				// ��
			case eN:
				if (masu[mousey - 1][mousex] == player * REVERSE)
				{
					Drct = eN;
					isDrctFlg = TRUE;
				}

				if (masu[mousey - 1][mousex] == player)
				{
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouseStarageY;
					mousex = mouseStarageX;
					return TRUE;
				}
				else if (masu[mousey - 1][mousex] == player * REVERSE)
				{
					mousey = mousey - 1;
					mousex = mousex;
				}
				else
				{
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouseStarageY;
					mousex = mouseStarageX;
					break;
				}
				break;


				// �E��
			case eNE:
				if (masu[mousey - 1][mousex + 1] == player * REVERSE)
				{
					Drct = eNE;
					isDrctFlg = TRUE;
				}

				if (masu[mousey - 1][mousex + 1] == player)
				{
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouseStarageY;
					mousex = mouseStarageX;
					return TRUE;
				}
				else if (masu[mousey - 1][mousex + 1] == player * REVERSE)
				{
					mousey = mousey - 1;
					mousex = mousex + 1;
				}
				else
				{
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouseStarageY;
					mousex = mouseStarageX;
					break;
				}
				break;

				// �E
			case eE:
				if (masu[mousey][mousex + 1] == player * REVERSE)
				{
					Drct = eE;
					isFirstFlg = FALSE;
				}

				if (masu[mousey][mousex + 1] == player)
				{
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouseStarageY;
					mousex = mouseStarageX;
					return TRUE;
				}
				else if (masu[mousey][mousex + 1] == player * REVERSE)
				{
					mousey = mousey;
					mousex = mousex + 1;
				}
				else
				{
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouseStarageY;
					mousex = mouseStarageX;
					break;
				}
				break;

				// �E��
			case eSE:
				if (masu[mousey + 1][mousex + 1] == player * REVERSE)
				{
					Drct = eSE;
					isFirstFlg = FALSE;
				}

				if (masu[mousey + 1][mousex + 1] == player)
				{
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouseStarageY;
					mousex = mouseStarageX;
					return TRUE;
				}
				else if (masu[mousey + 1][mousex + 1] == player * REVERSE)
				{
					mousey = mousey + 1;
					mousex = mousex + 1;
				}
				else
				{
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouseStarageY;
					mousex = mouseStarageX;
					break;
				}
				break;

				// ��
			case eS:
				if (masu[mousey + 1][mousex] == player * REVERSE)
				{
					Drct = eS;
					isFirstFlg = FALSE;
				}

				if (masu[mousey + 1][mousex] == player)
				{
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouseStarageY;
					mousex = mouseStarageX;
					return TRUE;
				}
				else if (masu[mousey + 1][mousex] == player * REVERSE)
				{
					mousey = mousey + 1;
					mousex = mousex;
				}
				else
				{
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouseStarageY;
					mousex = mouseStarageX;
					break;
				}
				break;

				// ����
			case eSW:
				if (masu[mousey + 1][mousex - 1] == player * REVERSE)
				{
					Drct = eSW;
					isFirstFlg = FALSE;
				}

				if (masu[mousey + 1][mousex - 1] == player)
				{
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouseStarageY;
					mousex = mouseStarageX;
					return TRUE;
				}
				else if (masu[mousey + 1][mousex - 1] == player * REVERSE)
				{
					mousey = mousey + 1;
					mousex = mousex - 1;
				}
				else
				{
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouseStarageY;
					mousex = mouseStarageX;
					break;
				}
				break;

				// ��
			case eW:
				if (masu[mousey][mousex - 1] == player * REVERSE)
				{
					Drct = eW;
					isFirstFlg = FALSE;
				}

				if (masu[mousey][mousex - 1] == player)
				{
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouseStarageY;
					mousex = mouseStarageX;
					return TRUE;
				}
				else if (masu[mousey][mousex - 1] == player * REVERSE)
				{
					mousey = mousey;
					mousex = mousex - 1;
				}
				else
				{
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouseStarageY;
					mousex = mouseStarageX;
					break;
				}
				break;

				// ����
			case eNW:
				if (masu[mousey - 1][mousex - 1] == player * REVERSE)
				{
					Drct = eNW;
					isFirstFlg = FALSE;
				}

				if (masu[mousey - 1][mousex - 1] == player)
				{
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouseStarageY;
					mousex = mouseStarageX;
					return TRUE;
				}
				else if (masu[mousey - 1][mousex - 1] == player * REVERSE)
				{
					mousey = mousey - 1;
					mousex = mousex - 1;
				}
				else
				{
					isDrctFlg = FALSE;
					isFirstFlg = FALSE;
					mousey = mouseStarageY;
					mousex = mouseStarageX;
					break;
				}
				break;


			default:
				return FALSE;
				break;
			}  //switch���I��

			// �ǂ̕������u���Ȃ��Ȃ�
			if (count == 8)
			{
				return FALSE;
			}

		}  //while���I��
	}  //else�I��
}
