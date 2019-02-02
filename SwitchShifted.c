#include <stdio.h>
#include "SwitchShifted.h"

void SwitchShift( int Direction)
{
	switch (Direction)
	{
	case eN:   // ã
		mousey = mousey + UP;
		mousex = mousex;
		break;
	case eNE: // Eã
		mousey = mousey + UP;
		mousex = mousex + RIGHT;
		break;
	case eE:  // E
		mousey = mousey;
		mousex = mousex + RIGHT;
		break;
	case eSE: // Eº
		mousey = mousey + DOWN;
		mousex = mousex + RIGHT;
		break;
	case eS:  // º
		mousey = mousey + DOWN;
		mousex = mousex;
		break;
	case eSW: // ¶º
		mousey = mousey + DOWN;
		mousex = mousex + LEFT;
		break;
	case eW:  // ¶
		mousey = mousey;
		mousex = mousex + LEFT;
		break;
	case eNW: // ¶ã
		mousey = mousey + UP;
		mousex = mousex + LEFT;
		break;

	}  //switch¶I¹
}