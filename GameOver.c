
#include<stdio.h>
#include<windows.h>
#include "Global.h"
#include "PieceCount.h" 

//int blackCnt;
//int whiteCnt;
//他のblackCntの値をGameOverに持ってこれない問題発生中

void GameOver() {
	TCHAR moji[11];
	
	//PieceCount();

	if (blackCnt < whiteCnt) {
		isGameOver = FALSE;
		MessageBox(NULL, TEXT("白"), TEXT("勝者"), MB_OK);
	}
	else if (blackCnt > whiteCnt) {
		isGameOver = FALSE;
		MessageBox(NULL, TEXT("黒"), TEXT("勝者"), MB_OK);
	}
	else if (blackCnt == whiteCnt) {
		MessageBox(NULL, TEXT("引き分け"), TEXT("勝者"), MB_OK);
		wsprintf(moji, TEXT("白は%d　黒は%d\n"), whiteCnt, blackCnt);
	}
	
}