#include<stdio.h>
#include"Global.h"
#include<windows.h>
/*���N���b�N�̏���*/
void Mouse() {
	pt.x = LOWORD(lParam); //���W
	pt.y = HIWORD(lParam); //���W
	InvalidateRect(hWnd, NULL, TRUE);

}