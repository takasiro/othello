
#include<stdio.h>
#include<windows.h>
#include "Global.h"
#include "PieceCount.h" 

//int blackCnt;
//int whiteCnt;
//����blackCnt�̒l��GameOver�Ɏ����Ă���Ȃ���蔭����

void GameOver() {
	TCHAR moji[11];
	
	//PieceCount();

	if (blackCnt < whiteCnt) {
		isGameOver = FALSE;
		MessageBox(NULL, TEXT("��"), TEXT("����"), MB_OK);
	}
	else if (blackCnt > whiteCnt) {
		isGameOver = FALSE;
		MessageBox(NULL, TEXT("��"), TEXT("����"), MB_OK);
	}
	else if (blackCnt == whiteCnt) {
		MessageBox(NULL, TEXT("��������"), TEXT("����"), MB_OK);
		wsprintf(moji, TEXT("����%d�@����%d\n"), whiteCnt, blackCnt);
	}
	
}