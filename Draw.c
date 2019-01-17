#include <stdio.h>
#include"Global.h"
#include"Windows.h"
#include"Draw.h"

void Draw() {
	pt.x = (pt.x / 50) * 50;    //座標を枠内に入れる
	pt.y = (pt.y / 50) * 50;    //　・・

	for (i = 1; i < 9; i++) { 
		for (j = 1; j < 9; j++) {
			if (masu[i][j] == BLACK) { //２次元配列を黒に
				SelectObject(hdc, hBrush[1]);  //白
				Ellipse(hdc, pt.x, pt.y, pt.x + 50, pt.y + 50);
			}
			else {
				SelectObject(hdc, hBrush[2]);  //黒
				Ellipse(hdc, pt.x, pt.y, pt.x + 50, pt.y + 50);
			}
		}
	EndPaint(hWnd, &ps);
	return 0;
}