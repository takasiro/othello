#pragma once
#include <stdio.h>
#include "Global.h"
#ifndef _ALL_JUDGE_
#define _ALL_JUDGE_

/************************************************
関 数 名 :AllJudge(const int * ,int player )
処理内容 :どこかに駒が置けるかどうかの判定
引    数 :  :配列のアドレス,player
返 却 値 :無し
備　　考 :1：置ける
　　　　　0：置けない　
	 　　　　PassJudge();
*************************************************/
int AllJudge();

#endif _ALL_JUDGE_
