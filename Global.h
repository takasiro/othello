#include <windows.h>


#ifndef  _GLOBAL_INCLUDE_
#define _GLOBAL_INCLUDE_

#define  REVERSE    -1
#define  BLACK      -1
#define  EMPTY       0
#define  WHITE       1

#define UP -1;
#define RIGHT 1;
#define DOWN 1;
#define LEFT -1;


extern POINT pt; //マウス座標
extern  POINT bt; //キーボード座標
extern RECT key;  //キーボードの四角

//白い駒の総数
 extern int whiteCnt;
//黒の駒の総数
 extern int blackCnt;
//現在のプレイヤーカラー
 extern int player;
//パスフラグ
 extern int passFlg;
 //マウス
 extern int mousex;
 extern int mousey;
 static int mouseStorageX;	// マウスのx座標を保存する
 static int mouseStorageY;	// マウスのy座標を保存する
 //マス
 extern int masu[10][10];
 extern int canPutMasu[10][10];
 extern POINT dot[4];

//シーン管理
 typedef enum  Judge {
	eAllJudge,
	eClickJudge,
	eReverseJudge
}Scene;

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
}Drct;

#endif _GLOBAL_INCLUDE_

