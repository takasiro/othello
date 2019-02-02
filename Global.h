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
//八方向見る順番
 extern const int drctArray[8];

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

extern int mousex;
extern int mousey;
static int mouseStorageX;	// マウスのx座標を保存する
static int mouseStorageY;	// マウスのy座標を保存する

extern int masu[10][10];
extern int canPutMasu[10][10];


extern POINT dot[4];

/************************************************
関 数 名 :SetMasu(int i,int j,int num)
処理内容 :挟んだ駒をひっくり返す
引    数 :　
第一引数　int  入れたい色
第二引数　int  入れたい色
第三引数　int  入れたい色
返 却 値 :無し
備　　考 :マウスがあるマスに
*************************************************/
static void SetMasu(int i, int j, int color) {
//	masu[i][j] = color;
}

#endif _GLOBAL_INCLUDE_

