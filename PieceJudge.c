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
				Drct = drctArray[i];
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
					mousey = mousey - 1;
					mousex = mousex;

					if (masu[mousey - 1][mousex] == player)
					{
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
				}
				else
				{
					isFirstFlg = FALSE;
				}
				break;

			// �E��
			case eNE:
				if (masu[mousey - 1][mousex + 1] == player * REVERSE)
				{
					Drct = eNE;
					mousey = mousey - 1;
					mousex = mousex + 1;
					if (masu[mousey - 1][mousex + 1] == player)
					{
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
						mousey = mouseStarageY;
						mousex = mouseStarageX;
						break;
					}
				}
				else
				{
					isFirstFlg = FALSE;
				}
				break;

			// �E
			case eE:
				if (masu[mousey][mousex + 1] == player * REVERSE)
				{
					Drct = eE;
					mousey = mousey;
					mousex = mousex + 1;
					if (masu[mousey][mousex + 1] == player)
					{
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
						mousey = mouseStarageY;
						mousex = mouseStarageX;
						break;
					}
				}
				else
				{
					isFirstFlg = FALSE;
				}
				break;

			// �E��
			case eSE:
				if (masu[mousey + 1][mousex + 1] == player * REVERSE)
				{
					Drct = eSE;
					mousey = mousey + 1;
					mousex = mousex + 1;
					if (masu[mousey + 1][mousex + 1] == player)
					{
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
						mousey = mouseStarageY;
						mousex = mouseStarageX;
						break;
					}
				}
				else
				{
					isFirstFlg = FALSE;
				}
				break;

			// ��
			case eS:
				if (masu[mousey + 1][mousex] == player * REVERSE)
				{
					Drct = eS;
					mousey = mousey + 1;
					mousex = mousex;

					if (masu[mousey + 1][mousex] == player)
					{
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
						mousey = mouseStarageY;
						mousex = mouseStarageX;
						break;
					}
				}
				else
				{
					isFirstFlg = FALSE;
				}
				break;

			// ����
			case eSW:
				if (masu[mousey + 1][mousex - 1] == player * REVERSE)
				{
					Drct = eSW;
					mousey = mousey + 1;
					mousex = mousex - 1;

					if (masu[mousey + 1][mousex - 1] == player)
					{
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
						mousey = mouseStarageY;
						mousex = mouseStarageX;
						break;
					}
				}
				else
				{
					isFirstFlg = FALSE;
				}
				break;

			// ��
			case eW:
				if (masu[mousey][mousex - 1] == player * REVERSE)
				{
					Drct = eW;
					mousey = mousey;
					mousex = mousex - 1;

					if (masu[mousey][mousex - 1] == player)
					{
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
						mousey = mouseStarageY;
						mousex = mouseStarageX;
						break;
					}
				}
				else
				{
					isFirstFlg = FALSE;
				}
				break;

			// ����
			case eNW:
				if (masu[mousey - 1][mousex - 1] == player * REVERSE)
				{
					Drct = eNW;
					mousey = mousey - 1;
					mousex = mousex - 1;

					if (masu[mousey - 1][mousex - 1] == player)
					{
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
						mousey = mouseStarageY;
						mousex = mouseStarageX;
						break;
					}
				}
				else
				{
					isFirstFlg = FALSE;
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
