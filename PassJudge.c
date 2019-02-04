#include <stdio.h>
#include "PassJudge.h"

void PassJudge()
{
	if (passFlg == TRUE)
	{
		isGameOver = TRUE;
	}
	else
	{
		PlayerReverse();
	}
	
}
