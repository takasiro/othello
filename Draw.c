#include <stdio.h>
#include"Global.h"
#include"Windows.h"
#include"Draw.h"

void Draw() {
	pt.x = (pt.x / 50) * 50;    //���W��g���ɓ����
	pt.y = (pt.y / 50) * 50;    //�@�E�E

	for (i = 1; i < 9; i++) { 
		for (j = 1; j < 9; j++) {
			if (masu[i][j] == BLACK) { //�Q�����z�������
				SelectObject(hdc, hBrush[1]);  //��
				Ellipse(hdc, pt.x, pt.y, pt.x + 50, pt.y + 50);
			}
			else {
				SelectObject(hdc, hBrush[2]);  //��
				Ellipse(hdc, pt.x, pt.y, pt.x + 50, pt.y + 50);
			}
		}
	EndPaint(hWnd, &ps);
	return 0;
}