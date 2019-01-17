#pragma once
#include <stdio.h>
#ifndef _PLAYER_REVERSE_
#define _PLAYER_REVERSE_
/************************************************
関 数 名 :PlayerReverse()
処理内容 :プレイヤーを交代
引    数 :player
返 却 値 :変更した色
備　　考 :#define　REVERSE　-1を使用
　　　　　playerにREVERSEをかけてターンを変更
*************************************************/
int PlayerReverse(int);

#endif _PLAYER_REVERSE_