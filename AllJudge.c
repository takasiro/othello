/************************************************
関 数 名 :AllJudge()
処理内容 :どこかに駒が置けるかどうかの判定
引    数 :無し
返 却 値 :1：置ける 0：置けない　
備　　考 :無し
***************************************************/

#include <stdio.h>
#include "AllJudge.h"
void AllJudge() {
	int i, j, k;
	static int isDrctFlg = FALSE;

	InitCanPutMasu();

	for (i = 1; i <= 8;i++) {
		for (j = 1; j <= 8;j++) {
			// マスがEMPTYじゃないなら次へ
			if (masu[j][i] != EMPTY) {
				continue;
			}
			// マスがEMPTYなら置けるかどうかを判断する
			else {
				for (k = 0; k < 8; k++)
				{
					mousex = j;
					mousey = i;

					SwitchShift(k);	//配列の要素数をずらす

					//一つ先が異色なら一つ先を見る
					if (masu[mousey][mousex] == player * REVERSE)
					{
						
						SwitchShift(k);
						isDrctFlg = TRUE;

						//先が同色なら
						while (isDrctFlg == TRUE)
						{
							if (masu[mousey][mousex] == player)
							{
								//return TRUE;
								canPutMasu[j][i] = TRUE;
								mousey = j;
								mousex = i;
								isDrctFlg = FALSE;
							}
							else if (masu[mousey][mousex] == player * REVERSE)
							{
								SwitchShift(k);
							}
							//先が0だったらひっくり返さない
							else
							{
								isDrctFlg = FALSE;
								mousey = j;
								mousex = i;
							}
						}  //while文終了
					}  //if文終了
					else
					{
						isDrctFlg = FALSE;
						mousey = j;
						mousex = i;
					}
				}  //for文(k)終了
			}  //else文終了
		}  //for文(j)終了
	}  //for文(i)終了
}

void InitCanPutMasu() {
	int i, j;

	for (i = 1; i <= 8;i++) {
		for (j = 1; j <= 8;j++) {
			canPutMasu[j][i] = FALSE;
		}
	}
}
