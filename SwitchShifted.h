#pragma once
#include <stdio.h>
#include "Global.h"

#ifndef _SWITCH_SHIFT_
#define _SWITCH_SHIFT_
/************************************************
関 数 名 :SwitchShift()
処理内容 :方向を指定して座標をずらす
引    数 :方向
返 却 値 :なし
備　　考 :八方向に応じてi,jをずらす
701
6P2
543		P:playerの置きたいところ
八方向を見る際はdrctArrayを使用する
enumで数字は定義されている
*************************************************/
extern void SwitchShift(int);

#endif _SWITCH_SHIFT_
