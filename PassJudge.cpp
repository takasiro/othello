#include <stdio.h>
#include "PassJudge.h"

void PassJudge()
{
	if (passFlg == true)
	{
		//GAMEOVER
	}
	else
	{
		passFlg = TRUE;
		PlayerReverse();
	}
	
}
