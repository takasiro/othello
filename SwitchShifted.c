#include <stdio.h>
#include "SwitchShifted.h"

void SwitchShift( int Direction)
{
	switch (Direction)
	{
	case eN:   // 上
		mousey = mousey + UP;
		mousex = mousex;
		break;
	case eNE: // 右上
		mousey = mousey + UP;
		mousex = mousex + RIGHT;
		break;
	case eE:  // 右
		mousey = mousey;
		mousex = mousex + RIGHT;
		break;
	case eSE: // 右下
		mousey = mousey + DOWN;
		mousex = mousex + RIGHT;
		break;
	case eS:  // 下
		mousey = mousey + DOWN;
		mousex = mousex;
		break;
	case eSW: // 左下
		mousey = mousey + DOWN;
		mousex = mousex + LEFT;
		break;
	case eW:  // 左
		mousey = mousey;
		mousex = mousex + LEFT;
		break;
	case eNW: // 左上
		mousey = mousey + UP;
		mousex = mousex + LEFT;
		break;

	}  //switch文終了
}