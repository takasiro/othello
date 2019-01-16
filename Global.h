#include <windows.h>


#ifndef  _GLOBAL_INCLUDE_
#define _GLOBAL_INCLUDE_

#define  REVERSE  -1
#define  BLACK      -1
#define  EMPTY       0
#define  WHITE       1

POINT pt; //マウス座標
POINT bt; //キーボード座標

//白い駒の総数
int whiteCnt;
//黒の駒の総数
int blackCnt;

typedef enum  Judge {
	eAllJudge,
	eClickJudge,
	eReverseJudge
};
int i, j;
#endif // _GLOBAL_INCLUDE_

