#include <stdio.h>
#include "Global.h"
void PlayerReverse() {
	if (player == BLACK) {
		player = WHITE;
	}
	else {
		player = BLACK;
	}

	//置けなかったらパスか判断
	if (AllJudge() == FALSE) {
		PassJudge();
	}

}