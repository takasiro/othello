#include <stdio.h>
#include "SwitchShifted.h"

void SwitchShift( int Direction)
{
	switch (Direction)
	{
	case eN:   // è„
		mousey = mousey + UP;
		mousex = mousex;
		break;
	case eNE: // âEè„
		mousey = mousey + UP;
		mousex = mousex + RIGHT;
		break;
	case eE:  // âE
		mousey = mousey;
		mousex = mousex + RIGHT;
		break;
	case eSE: // âEâ∫
		mousey = mousey + DOWN;
		mousex = mousex + RIGHT;
		break;
	case eS:  // â∫
		mousey = mousey + DOWN;
		mousex = mousex;
		break;
	case eSW: // ç∂â∫
		mousey = mousey + DOWN;
		mousex = mousex + LEFT;
		break;
	case eW:  // ç∂
		mousey = mousey;
		mousex = mousex + LEFT;
		break;
	case eNW: // ç∂è„
		mousey = mousey + UP;
		mousex = mousex + LEFT;
		break;
	}
}