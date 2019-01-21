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

	int mousex;			// �}�E�X��x���W����v�Z�����}�X��
	int mousey;			// �}�E�X��y���W����v�Z�����}�X��
	int Drct;			// ����(Direction)��ۑ�����
	int mouceStarageX;	// �}�E�X��x���W��ۑ�����
	int mouceStarageY;	// �}�E�X��y���W��ۑ�����
	static int isDrctFlg = FALSE;	// ��������܂��Ă��邩 >> TRUE:��܂��Ă��� FALSE:��܂��Ă��Ȃ�
	int i = 0;

	//�}�E�X���W���v�f��������o���z��֑��
	mousex = pt.x / 50 % 8 + 1;
	mousey = pt.y / 50 % 8 + 1;

	//�}�E�X���W�̕ۑ�
	mouceStarageX = mousex;
	mouceStarageY = mousey;

	//�}�X�̒��g�𔻒f
	if (masu[mousex][mousey] != EMPTY)
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
				i++;
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
					Drct = eN;
					isDrctFlg = TRUE;
					mousex = mousex;
					mousey = mousey - 1;

					if (masu[mousex][mousey - 1] == player)
					{
						return TRUE;
					}
					else if (masu[mousex][mousey - 1] == player * REVERSE) 
					{
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
				return FALSE;
				break;
			}  //switch���I��

			// �ǂ̕������u���Ȃ��Ȃ�
			if (i == 8)
			{
				return FALSE;
			}

		}  //while���I��
	}  //else�I��
}