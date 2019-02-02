#pragma once
#include <stdio.h>
#include "Global.h"
#include "SwitchShifted.h"
#ifndef _ALL_JUDGE_
#define _ALL_JUDGE_

/************************************************
関 数 名 :AllJudge()
処理内容 :どこかに駒が置けるかどうかの判定
引    数 :無し
返 却 値 :無し
備　　考 :置ける場所を配列の中に保存
***************************************************/
extern void AllJudge();
extern void InitCanPutMasu();

#endif _ALL_JUDGE_