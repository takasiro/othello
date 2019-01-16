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
//現在のプレイヤーカラー
int player;
//パスフラグ
int passFlg;

//シーン管理
typedef enum  Judge {
	eAllJudge,
	eClickJudge,
	eReverseJudge
};

//方角
typedef enum Direction {
	eN,
	eNE,
	eE,
	eSE,
	eS,
	eSW,
	eW,
	eNW,
};

#endif _GLOBAL_INCLUDE_

