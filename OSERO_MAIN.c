#include <windows.h>

#include"Global.h"
#include "PieceJudge.h"
#include "PieceReverse.h"
#include "PieceCount.h"
#include "PlayerReverse.h"
#include "AllJudge.h"
#include"GameOver.h"

//#define APP_NAME TEXT("OSERO");

#define APP_NAME TEXT("reversi")

void Destroy();
static HBRUSH hBrush[4];
/*******************************************************************************
関数名 : WindowProc
機能   : メッセージ処理を行う
引数   : 省略
返却値 : 省略
*******************************************************************************/
LRESULT CALLBACK WindowProc(
	//キーコードの値         ここにマウスの情報が入ってくる
	HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam
) {
	HDC hdc;
	PAINTSTRUCT ps;
	TCHAR buf[256];
	memset(buf,0x00,sizeof(buf));
	//*buf = blackCnt;
	
	
	int i, j;


	switch (uMsg) {

	case WM_CREATE:  // 初期生成時の処理（初期化）
		//ブラシデータの定義
		hBrush[0] = CreateSolidBrush(RGB(0, 0xAA, 0));          // 盤面（緑）
		hBrush[1] = CreateSolidBrush(RGB(0xFF, 0xFF, 0xFF));    // WHITE
		hBrush[2] = CreateSolidBrush(RGB(0, 0, 0));		        // BLACK
		hBrush[3] = CreateSolidBrush(RGB(0xff, 0, 0));          // 赤キーボードの現在位置表示用
		hBrush[4] = CreateSolidBrush(RGB(122, 122, 122));		    // 置ける場所

		//キーボードによる移動する四角
		key.left = 0;
		key.top = 0;
		key.right = 50;
		key.bottom = 50;

		//置ける場所の表示
		AllJudge();
		PieceCount();
		return 0;

	case WM_CLOSE:
		 PostQuitMessage(0);
		 exit(0);
		//DefWindowProc( hWnd,  uMsg,  wParam,  lParam);
		return 0;
	
	
	case WM_DESTROY:  // ウィンドウ破棄時の処理

		// ブラシの削除
		for (i = 0; i < 4; i++) DeleteObject(hBrush[i]);
		return 0;
		
	case WM_PAINT: // 描画イベント発生時　　（画面に変化があった際に頻繁に呼び出される)

		// ペイント開始
		hdc = BeginPaint(hWnd, &ps);

		//駒の数と誰のターンかの表示
		int length = wsprintf(buf, TEXT("黒の駒数:%2d "), blackCnt);
		TextOut(hdc, 480, 80, buf, length);
		 length = wsprintf(buf, TEXT("白の駒数:%2d "), whiteCnt);
		TextOut(hdc, 480, 100, buf, length);
		if (player == WHITE) {
			length = wsprintf(buf, TEXT("白のターンです "));
			TextOut(hdc, 480, 125, buf, length);
		}
		else {
			int length = wsprintf(buf, TEXT("黒のターンです "));
			TextOut(hdc, 480, 125, buf, length);
		}

		// オセロ盤の描画
		SelectObject(hdc, hBrush[0]);
		Rectangle(hdc, 0, 0, 401, 401);
		for (i = 0; i < 7; i++) {
			MoveToEx(hdc, 50 * (i + 1), 0, NULL);
			LineTo(hdc, 50 * (i + 1), 400);
			MoveToEx(hdc, 0, 50 * (i + 1), NULL);
			LineTo(hdc, 400, 50 * (i + 1));
		}

		//キーボードの選択中の場所を表示
		SelectObject(hdc, hBrush[3]);	//赤
		Rectangle(hdc, key.left, key.top, key.right + 1, key.bottom + 1);

		//ドットの描画
		SelectObject(hdc, hBrush[2]);
		for (i = 0; i < 4; i++) {
			Ellipse(hdc, dot[i].x - 5, dot[i].y - 5,
				dot[i].x + 5, dot[i].y + 5);
		}

		//置ける場所の表示
		for (i = 1; i <= 8; i++) {
			for (j = 1; j <= 8; j++) {
				if (canPutMasu[j][i] == TRUE) {
					if (player == BLACK) {
						SelectObject(hdc, hBrush[2]);
					}
					else {
						SelectObject(hdc, hBrush[1]);
					}
					//SelectObject(hdc, hBrush[4]);
					Ellipse(hdc, (i - 1) * 50 + 15, (j - 1) * 50 + 15, i * 50 - 15, j * 50 - 15);
				}
			}
		}

		//駒の描画
		for (i = 1; i <= 8; i++) {
			for (j = 1; j <= 8; j++) {
				if (masu[j][i] == WHITE) { //２次元配列を黒に
					SelectObject(hdc, hBrush[1]);  //白
					Ellipse(hdc, (i - 1) * 50, (j - 1) * 50, i * 50, j * 50);
				}
				else if (masu[j][i] == BLACK) {
					SelectObject(hdc, hBrush[2]);  //黒
					Ellipse(hdc, (i - 1) * 50, (j - 1) * 50, i * 50, j * 50);
				}
			}
		}

		EndPaint(hWnd, &ps);
		return 0;

	case WM_LBUTTONDOWN:	//マウスクリック

		//マウス座標の取得
		pt.x = LOWORD(lParam);
		pt.y = HIWORD(lParam);
		if (pt.x < 401 && pt.y < 401) {
			pt.x = (int)pt.x / 50 + 1;
			pt.y = (int)pt.y / 50 + 1;

			if (PieceJudge() == TRUE) {
				//駒をひっくり返す
				PieceReverse();
				//現在の座標をplayerに変更
				masu[mousey][mousex] = player;
				//駒をカウント
				PieceCount();
				//playerを交代
				PlayerReverse();
			}
		}

		InvalidateRect(hWnd, NULL, FALSE);
		if (isGameOver == TRUE) {
			GameOver();
		}
		return 0;

		//キーボードの処理
	case WM_KEYDOWN:
		if (wParam == VK_LEFT && bt.x > 0) {
			key.right -= 50;
			key.left -= 50;
			bt.x--;
		}
		else if (wParam == VK_RIGHT && bt.x < 7) {
			key.right += 50;
			key.left += 50;
			bt.x++;
		}
		else if (wParam == VK_UP && bt.y > 0) {
			key.top -= 50;
			key.bottom -= 50;
			bt.y--;
		}
		else if (wParam == VK_DOWN && bt.y < 7) {
			key.top += 50;
			key.bottom += 50;
			bt.y++;
		}
		else if (wParam == VK_SPACE) {
			pt.x = bt.x + 1;
			pt.y = bt.y + 1;

			if (PieceJudge() == TRUE) {
				//駒をひっくり返す
				PieceReverse();
				//現在の座標をplayerに変更
				masu[mousey][mousex] = player;
				//駒をカウント
				PieceCount();
				//playerを交代
				PlayerReverse();
			}
		}

		InvalidateRect(hWnd, NULL, FALSE);
		if (isGameOver == TRUE) {
			GameOver();
		}
		return 0;

	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

/*******************************************************************************
関数名 : WinMain
機能   : ゲームの初期化とメッセージループ
引数   : 省略
返却値 : 省略
*******************************************************************************/

int WINAPI WinMain(
	HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR lpCmdLine, int nCmdShow)
{
	WNDCLASS wc;
	MSG msg;

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;  //WindowProcedureの関数名を指定する
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_BACKGROUND + 1;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = APP_NAME;

	if (!RegisterClass(&wc)) return 0;

	if (CreateWindow(
		APP_NAME, TEXT(__FILE__),
		WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME ^ WS_MAXIMIZEBOX | WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT,
		900, 450, // ここで、ウィンドウのサイズ（Width,Height)を指定する 
		NULL, NULL, hInstance, NULL
	) == NULL) return 0;

	while (GetMessage(&msg, NULL, 0, 0) > 0) {
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

void Destroy() { 
	for (int i = 0; i < 4; i++) DeleteObject(hBrush[i]); 
	PostQuitMessage(0);
	exit(0);
}