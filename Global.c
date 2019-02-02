#include <windows.h>
#include"Global.h"



//白い駒の総数
extern int whiteCnt;
//黒の駒の総数
extern int blackCnt;
//現在のプレイヤーカラー
extern int player = BLACK;
//パスフラグ
extern int passFlg = FALSE;
//八方向見る順番
extern const int drctArray[8] = { 0,1,2,3,4,5,6,7 };

extern int mousex = 0;
extern int mousey = 0;
extern int mouseStorageX = 0;
extern int mouceStorageY = 0;


POINT pt; //マウス座標
POINT bt;

POINT dot[4] = {
   { 100,100 },
   { 300,100 },
   { 100,300 },
   { 300,300 }
};

//初期
int masu[10][10] = {
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,1,-1,0,0,0,0 },
	{ 0,0,0,0,-1,1,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0 }
};

//全方位
//int masu[10][10] = {
//{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//{ 0,-1, 0, 0,-1, 0, 0,-1, 0, 0 },
//{ 0, 0, 1, 0, 1, 0, 1, 0, 0, 0 },
//{ 0, 0, 0, 1, 1, 1, 0, 0, 0, 0 },
//{ 0,-1, 1, 1, 0, 1, 1, 1,-1, 0 },
//{ 0, 0, 0, 1, 1, 1, 0, 0, 0, 0 },
//{ 0, 0, 1, 0, 1, 0, 1, 0, 0, 0 },
//{ 0,-1, 0, 0, 1, 0, 0, 1, 0, 0 },
//{ 0, 0, 0, 0,-1, 0, 0, 0,-1, 0 },
//{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//};

//上,右上,右
//int masu[10][10] = {
//	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//	{ 0,-1,-1,-1,-1,-1,-1,-1,-1, 0 },
//	{ 0, 1, 0, 0, 0, 0, 0, 1,-1, 0 },
//	{ 0, 1, 0, 0, 0, 0, 1, 0,-1, 0 },
//	{ 0, 1, 0, 0, 0, 1, 0, 0,-1, 0 },
//	{ 0, 1, 0, 0, 1, 0, 0, 0,-1, 0 },
//	{ 0, 1, 0, 1, 0, 0, 0, 0,-1, 0 },
//	{ 0, 1, 1, 0, 0, 0, 0, 0,-1, 0 },
//	{ 0, 0, 1, 1, 1, 1, 1, 1,-1, 0 },
//	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//};

//下,右下,右
//int masu[10][10] = {
//{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//{ 0, 0, 1, 1, 1, 1, 1, 1,-1, 0 },
//{ 0, 1, 1, 0, 0, 0, 0, 0,-1, 0 },
//{ 0, 1, 0, 1, 0, 0, 0, 0,-1, 0 },
//{ 0, 1, 0, 0, 1, 0, 0, 0,-1, 0 },
//{ 0, 1, 0, 0, 0, 1, 0, 0,-1, 0 },
//{ 0, 1, 0, 0, 0, 0, 1, 0,-1, 0 },
//{ 0, 1, 0, 0, 0, 0, 0, 1,-1, 0 },
//{ 0,-1,-1,-1,-1,-1,-1,-1,-1, 0 },
//{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//};

//下,左下,左
//int masu[10][10] = {
//{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//{ 0,-1, 1, 1, 1, 1, 1, 1, 0, 0 },
//{ 0,-1, 0, 0, 0, 0, 0, 1, 1, 0 },
//{ 0,-1, 0, 0, 0, 0, 1, 0, 1, 0 },
//{ 0,-1, 0, 0, 0, 1, 0, 0, 1, 0 },
//{ 0,-1, 0, 0, 1, 0, 0, 0, 1, 0 },
//{ 0,-1, 0, 1, 0, 0, 0, 0, 1, 0 },
//{ 0,-1, 1, 0, 0, 0, 0, 0, 1, 0 },
//{ 0,-1,-1,-1,-1,-1,-1,-1,-1, 0 },
//{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//};

//下, 右下, 右
//int masu[10][10] = {
//{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//{ 0,-1,-1,-1,-1,-1,-1,-1,-1, 0 },
//{ 0,-1, 1, 0, 0, 0, 0, 0, 1, 0 },
//{ 0,-1, 0, 1, 0, 0, 0, 0, 1, 0 },
//{ 0,-1, 0, 0, 1, 0, 0, 0, 1, 0 },
//{ 0,-1, 0, 0, 0, 1, 0, 0, 1, 0 },
//{ 0,-1, 0, 0, 0, 0, 1, 0, 1, 0 },
//{ 0,-1, 0, 0, 0, 0, 0, 1, 1, 0 },
//{ 0,-1, 1, 1, 1, 1, 1, 1, 0, 0 },
//{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//};

