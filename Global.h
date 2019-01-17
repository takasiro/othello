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

BYTE masu[10][10] = {
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,1,2,0,0,0,0 },
	{ 0,0,0,0,2,1,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0 }
};


static POINT dot[4] = {
	{ 100,100 },
	{ 300,100 },
	{ 100,300 },
	{ 300,300 }
};

/************************************************
関 数 名 :GetMasu()
処理内容 :masuの先頭アドレスを受け取る
引    数 :無し
返 却 値 :BYTE*
備　　考 :戻り値がBYTE*なことに注意
*************************************************/
BYTE* GetMasu() {
	return masu;
}

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
void SetMasu(int i ,int j,int color) {
	masu[i][j] = color;
}

#endif _GLOBAL_INCLUDE_

