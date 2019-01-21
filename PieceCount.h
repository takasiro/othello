#pragma once
#include <stdio.h>
#include "Global.h"
#ifndef _PIECE_COUNT_
#define _PIECE_COUNT_

/************************************************
関 数 名 :PieceCount()
処理内容 :駒数を数える
引    数 :&whiteCount,&blackCount:
返 却 値 :0 成功
-1 失敗(駒数が65以上 && 0未満なら)
備　　考 :引数は各駒をカウントする変数のアドレス
&whiteCount 白の駒総数
&blackCount 黒の駒総数
*************************************************/

extern int PieceCount(int);

#endif _PIECE_COUNT_