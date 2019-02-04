
#include<stdio.h>
#include<windows.h>
#include "Global.h"
#include "PieceCount.h" 

//int blackCnt;
//int whiteCnt;
//‘¼‚ÌblackCnt‚Ì’l‚ğGameOver‚É‚Á‚Ä‚±‚ê‚È‚¢–â‘è”­¶’†

void GameOver() {
	TCHAR moji[11];
	
	//PieceCount();

	if (blackCnt < whiteCnt) {
		isGameOver = FALSE;
		MessageBox(NULL, TEXT("”’"), TEXT("ŸÒ"), MB_OK);
	}
	else if (blackCnt > whiteCnt) {
		isGameOver = FALSE;
		MessageBox(NULL, TEXT("•"), TEXT("ŸÒ"), MB_OK);
	}
	else if (blackCnt == whiteCnt) {
		MessageBox(NULL, TEXT("ˆø‚«•ª‚¯"), TEXT("ŸÒ"), MB_OK);
		wsprintf(moji, TEXT("”’‚Í%d@•‚Í%d\n"), whiteCnt, blackCnt);
	}
	
}