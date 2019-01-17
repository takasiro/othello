#include <stdio.h>
#include "Global.h"
int PlayerReverse(int player) {
	if (player == BLACK) {
		player = WHITE;
	}
	else {
		player = BLACK;
	}
	return player;
}