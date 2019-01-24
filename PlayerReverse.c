#include <stdio.h>
#include "Global.h"
void PlayerReverse() {
	if (player == BLACK) {
		player = WHITE;
	}
	else {
		player = BLACK;
	}

	//’u‚¯‚È‚©‚Á‚½‚çƒpƒX‚©”»’f
	if (AllJudge() == FALSE) {
		PassJudge();
	}

}