
#include<stdio.h>
#include<windows.h>
#include "Global.h"
#include "PieceCount.h" 

//int blackCnt;
//int whiteCnt;
//����blackCnt�̒l��GameOver�Ɏ����Ă���Ȃ���蔭����

void GameOver() {
	int r;
	
	//PieceCount();

	if (blackCnt < whiteCnt) {
		
		r = MessageBox(NULL, TEXT("���v���C���[�̏����ł�"), TEXT("����"), MB_OK);
		//isDestroy = TRUE;
		
	}
	else if (blackCnt > whiteCnt) {
		r = MessageBox(NULL, TEXT("���v���C���[�̏����ł�"), TEXT("����"), MB_OK);
	}
	else if (blackCnt == whiteCnt) {
		r = MessageBox(NULL, TEXT("�u����ꏊ������܂���B\n���������ł��B"), TEXT("����"), MB_OK);
	}
	if (r == IDOK) { 
		Destroy();
		
	}

}