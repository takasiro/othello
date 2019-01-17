#include<stdio.h>
#include"Global.h"
#include<windows.h>
/*左クリックの処理*/
void Mouse() {
	pt.x = LOWORD(lParam); //座標
	pt.y = HIWORD(lParam); //座標
	InvalidateRect(hWnd, NULL, TRUE);

}