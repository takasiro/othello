
#include<stdio.h>
#include<windows.h>
#include "Global.h"
#include "PieceCount.h" 

//int blackCnt;
//int whiteCnt;
//他のblackCntの値をGameOverに持ってこれない問題発生中

void GameOver() {
	int r;
	
	//PieceCount();

	if (blackCnt < whiteCnt) {
		
		r = MessageBox(NULL, TEXT("白"), TEXT("勝者"), MB_OK);
		//isDestroy = TRUE;
		
	}
	else if (blackCnt > whiteCnt) {
		r = MessageBox(NULL, TEXT("黒"), TEXT("勝者"), MB_OK);
	}
	else if (blackCnt == whiteCnt) {
		r = MessageBox(NULL, TEXT("引き分け"), TEXT("勝者"), MB_OK);
	}
	if (r == IDOK) { 
		Destroy();
		
	}

}