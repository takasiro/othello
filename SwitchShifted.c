#include <stdio.h>
#include "SwitchShifted.h"

void SwitchShift( int Direction)
{
	switch (Direction)
	{
	case eN:   // ��
		mousey = mousey + UP;
		mousex = mousex;
		break;
	case eNE: // �E��
		mousey = mousey + UP;
		mousex = mousex + RIGHT;
		break;
	case eE:  // �E
		mousey = mousey;
		mousex = mousex + RIGHT;
		break;
	case eSE: // �E��
		mousey = mousey + DOWN;
		mousex = mousex + RIGHT;
		break;
	case eS:  // ��
		mousey = mousey + DOWN;
		mousex = mousex;
		break;
	case eSW: // ����
		mousey = mousey + DOWN;
		mousex = mousex + LEFT;
		break;
	case eW:  // ��
		mousey = mousey;
		mousex = mousex + LEFT;
		break;
	case eNW: // ����
		mousey = mousey + UP;
		mousex = mousex + LEFT;
		break;
	}
}