
#include<stdio.h>
#include<windows.h>
#include "Global.h"
#include "PieceCount.h" 

//int blackCnt;
//int whiteCnt;
//‘¼‚ÌblackCnt‚Ì’l‚ğGameOver‚É‚Á‚Ä‚±‚ê‚È‚¢–â‘è”­¶’†

void GameOver() {
	int r;
	
	//PieceCount();

	if (blackCnt < whiteCnt) {
		
		r = MessageBox(NULL, TEXT("”’"), TEXT("ŸÒ"), MB_OK);
		//isDestroy = TRUE;
		
	}
	else if (blackCnt > whiteCnt) {
		r = MessageBox(NULL, TEXT("•"), TEXT("ŸÒ"), MB_OK);
	}
	else if (blackCnt == whiteCnt) {
		r = MessageBox(NULL, TEXT("ˆø‚«•ª‚¯"), TEXT("ŸÒ"), MB_OK);
	}
	if (r == IDOK) { 
		Destroy();
		
	}

}