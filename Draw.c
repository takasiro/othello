#include <stdio.h>
#include"Global.h"
#include"Windows.h"

void Draw() {
	pt.x = (pt.x / 50) * 50;    //���W��g���ɓ����
	pt.y = (pt.y / 50) * 50;
	SelectObject(hdc, hBrush[1]);  //��
	Ellipse(hdc, pt.x, pt.y, pt.x + 50, pt.y + 50);



	EndPaint(hWnd, &ps);
	return 0;
}