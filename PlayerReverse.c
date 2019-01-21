#include <stdio.h>
#include "Global.h"
void PlayerReverse() {
	if (player == BLACK) {
		player = WHITE;
	}
	else {
		player = BLACK;
	}

}