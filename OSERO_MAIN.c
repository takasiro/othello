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
�֐��� : WindowProc
�@�\   : ���b�Z�[�W�������s��
����   : �ȗ�
�ԋp�l : �ȗ�
*******************************************************************************/
LRESULT CALLBACK WindowProc(
	//�L�[�R�[�h�̒l         �����Ƀ}�E�X�̏�񂪓����Ă���
	HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam
) {
	HDC hdc;
	PAINTSTRUCT ps;
	TCHAR buf[256];
	memset(buf,0x00,sizeof(buf));
	//*buf = blackCnt;
	
	
	int i, j;


	switch (uMsg) {

	case WM_CREATE:  // �����������̏����i�������j
		//�u���V�f�[�^�̒�`
		hBrush[0] = CreateSolidBrush(RGB(0, 0xAA, 0));          // �Ֆʁi�΁j
		hBrush[1] = CreateSolidBrush(RGB(0xFF, 0xFF, 0xFF));    // WHITE
		hBrush[2] = CreateSolidBrush(RGB(0, 0, 0));		        // BLACK
		hBrush[3] = CreateSolidBrush(RGB(0xff, 0, 0));          // �ԃL�[�{�[�h�̌��݈ʒu�\���p
		hBrush[4] = CreateSolidBrush(RGB(122, 122, 122));		    // �u����ꏊ

		//�L�[�{�[�h�ɂ��ړ�����l�p
		key.left = 0;
		key.top = 0;
		key.right = 50;
		key.bottom = 50;

		//�u����ꏊ�̕\��
		AllJudge();
		PieceCount();
		return 0;

	case WM_CLOSE:
		 PostQuitMessage(0);
		 exit(0);
		//DefWindowProc( hWnd,  uMsg,  wParam,  lParam);
		return 0;
	
	
	case WM_DESTROY:  // �E�B���h�E�j�����̏���

		// �u���V�̍폜
		for (i = 0; i < 4; i++) DeleteObject(hBrush[i]);
		return 0;
		
	case WM_PAINT: // �`��C�x���g�������@�@�i��ʂɕω����������ۂɕp�ɂɌĂяo�����)

		// �y�C���g�J�n
		hdc = BeginPaint(hWnd, &ps);

		//��̐��ƒN�̃^�[�����̕\��
		int length = wsprintf(buf, TEXT("���̋:%2d "), blackCnt);
		TextOut(hdc, 480, 80, buf, length);
		 length = wsprintf(buf, TEXT("���̋:%2d "), whiteCnt);
		TextOut(hdc, 480, 100, buf, length);
		if (player == WHITE) {
			length = wsprintf(buf, TEXT("���̃^�[���ł� "));
			TextOut(hdc, 480, 125, buf, length);
		}
		else {
			int length = wsprintf(buf, TEXT("���̃^�[���ł� "));
			TextOut(hdc, 480, 125, buf, length);
		}

		// �I�Z���Ղ̕`��
		SelectObject(hdc, hBrush[0]);
		Rectangle(hdc, 0, 0, 401, 401);
		for (i = 0; i < 7; i++) {
			MoveToEx(hdc, 50 * (i + 1), 0, NULL);
			LineTo(hdc, 50 * (i + 1), 400);
			MoveToEx(hdc, 0, 50 * (i + 1), NULL);
			LineTo(hdc, 400, 50 * (i + 1));
		}

		//�L�[�{�[�h�̑I�𒆂̏ꏊ��\��
		SelectObject(hdc, hBrush[3]);	//��
		Rectangle(hdc, key.left, key.top, key.right + 1, key.bottom + 1);

		//�h�b�g�̕`��
		SelectObject(hdc, hBrush[2]);
		for (i = 0; i < 4; i++) {
			Ellipse(hdc, dot[i].x - 5, dot[i].y - 5,
				dot[i].x + 5, dot[i].y + 5);
		}

		//�u����ꏊ�̕\��
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

		//��̕`��
		for (i = 1; i <= 8; i++) {
			for (j = 1; j <= 8; j++) {
				if (masu[j][i] == WHITE) { //�Q�����z�������
					SelectObject(hdc, hBrush[1]);  //��
					Ellipse(hdc, (i - 1) * 50, (j - 1) * 50, i * 50, j * 50);
				}
				else if (masu[j][i] == BLACK) {
					SelectObject(hdc, hBrush[2]);  //��
					Ellipse(hdc, (i - 1) * 50, (j - 1) * 50, i * 50, j * 50);
				}
			}
		}

		EndPaint(hWnd, &ps);
		return 0;

	case WM_LBUTTONDOWN:	//�}�E�X�N���b�N

		//�}�E�X���W�̎擾
		pt.x = LOWORD(lParam);
		pt.y = HIWORD(lParam);
		if (pt.x < 401 && pt.y < 401) {
			pt.x = (int)pt.x / 50 + 1;
			pt.y = (int)pt.y / 50 + 1;

			if (PieceJudge() == TRUE) {
				//����Ђ�����Ԃ�
				PieceReverse();
				//���݂̍��W��player�ɕύX
				masu[mousey][mousex] = player;
				//����J�E���g
				PieceCount();
				//player�����
				PlayerReverse();
			}
		}

		InvalidateRect(hWnd, NULL, FALSE);
		if (isGameOver == TRUE) {
			GameOver();
		}
		return 0;

		//�L�[�{�[�h�̏���
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
				//����Ђ�����Ԃ�
				PieceReverse();
				//���݂̍��W��player�ɕύX
				masu[mousey][mousex] = player;
				//����J�E���g
				PieceCount();
				//player�����
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
�֐��� : WinMain
�@�\   : �Q�[���̏������ƃ��b�Z�[�W���[�v
����   : �ȗ�
�ԋp�l : �ȗ�
*******************************************************************************/

int WINAPI WinMain(
	HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR lpCmdLine, int nCmdShow)
{
	WNDCLASS wc;
	MSG msg;

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;  //WindowProcedure�̊֐������w�肷��
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
		900, 450, // �����ŁA�E�B���h�E�̃T�C�Y�iWidth,Height)���w�肷�� 
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