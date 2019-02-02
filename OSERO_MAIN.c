#include <windows.h>
#include"Global.h"
#include "PieceJudge.h"
//#include "PieceReverse.h"
#include "PieceCount.h"
#include "PlayerReverse.h"
#include "AllJudge.h"

//#define APP_NAME TEXT("OSERO");

#define APP_NAME TEXT("reversi")

// 盤面上の小さい黒丸の座標点（描画時の各中心座標）





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
	static HBRUSH hBrush[4];
	int i,j;


	switch (uMsg) {

	case WM_CREATE:  // 初期生成時の処理（初期化）

					 //ブラシデータの定義
		hBrush[0] = CreateSolidBrush(RGB(0, 0xAA, 0));          // 盤面（緑）
		hBrush[1] = CreateSolidBrush(RGB(0xFF, 0xFF, 0xFF));    // WHITE
		hBrush[2] = CreateSolidBrush(RGB(0, 0, 0));		        // BLACK
		hBrush[3] = CreateSolidBrush(RGB(0xff, 0, 0));         //赤キーボードの現在位置表示用

		return 0;

	case WM_DESTROY:  // ウィンドウ破棄時の処理


		// ブラシの削除
		for (i = 0; i < 3; i++) DeleteObject(hBrush[i]);
		PostQuitMessage(0);
		return 0;

	case WM_PAINT: // 描画イベント発生時　　（画面に変化があった際に頻繁に呼び出される)


		// ペイント開始
		hdc = BeginPaint(hWnd, &ps);

		// オセロ盤の描画

		SelectObject(hdc, hBrush[0]);
		Rectangle(hdc, 0, 0, 401, 401);


		for (i = 0; i < 7; i++) {
			MoveToEx(hdc, 50 * (i + 1), 0, NULL);
			LineTo(hdc, 50 * (i + 1), 400);
			MoveToEx(hdc, 0, 50 * (i + 1), NULL);
			LineTo(hdc, 400, 50 * (i + 1));
		}

		SelectObject(hdc, hBrush[2]);
		for (i = 0; i < 4; i++) {
			Ellipse(hdc, dot[i].x - 5, dot[i].y - 5,
				dot[i].x + 5, dot[i].y + 5);
		}


		for (i = 1; i < 9; i++) {
			for (j = 1; j < 9; j++) {
				if (masu[j][i] != EMPTY) {
					if (masu[j][i] == WHITE) { //２次元配列を黒に
						SelectObject(hdc, hBrush[1]);  //白
						//Ellipse(hdc, (j-1)*50, (i-1)*50, j* 50,i * 50);
					}
					else if (masu[j][i] == BLACK) {
						SelectObject(hdc, hBrush[2]);  //黒
						//Ellipse(hdc, (i - 1) * 50, (j - 1) * 50, j * 50, i * 50);
					}
					Ellipse(hdc, (i - 1) * 50, (j - 1) * 50, i * 50, j * 50);
				}
			}
		}

		EndPaint(hWnd, &ps);


		return 0;


	//マウスの処理
	case WM_LBUTTONDOWN:
		pt.x = LOWORD(lParam); //座標
		pt.y = HIWORD(lParam); //座標
		pt.x = (int)pt.x / 50+1;    //座標を枠内に入れる
		pt.y = (int)pt.y/ 50+1;    //　・・

		//(masu[pt.x][pt.y]) = player;

		if (PieceJudge() == TRUE) {

			//PieceReverse();
			masu[pt.y][pt.x] = player;
			PlayerReverse();
		}
		InvalidateRect(hWnd, NULL, NULL);
		return 0;

		//キーボードの処理
	case WM_KEYDOWN:
	

		return 0;

	} // switch文の終了

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