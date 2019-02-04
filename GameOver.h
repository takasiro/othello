#pragma once
#include <stdio.h>
#include "Global.h"
#include "PieceCount.h" 

//GameOver
#ifndef _GAME_OVER_
#define _GAME_OVER_

/************************************************
関 数 名 :PieceJudge()
処理内容 :駒が置けるかどうかの判定
引    数 :無し
返 却 値 :FALSE:置けない TRUE:置ける
備　　考 :八方向を見るロジック
701
6P2
543		P:playerの置きたいところ
八方向を見る際はdrctArrayを使用する
enumで数字は定義されている
*************************************************/
extern int GameOver();

#endif _GAME_OVER_
