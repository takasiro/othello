#include <windows.h>
#include"Global.h"


//#define APP_NAME TEXT("OSERO");

#define APP_NAME TEXT("reversi")

// �Ֆʏ�̏��������ۂ̍��W�_�i�`�掞�̊e���S���W�j

BYTE masu[10][10] = {
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,1,2,0,0,0,0 },
	{ 0,0,0,0,2,1,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0 }
};


static POINT dot[4] = {
	{ 100,100 },
	{ 300,100 },
	{ 100,300 },
	{ 300,300 }
};




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
	static HBRUSH hBrush[4];



	switch (uMsg) {

	case WM_CREATE:  // �����������̏����i�������j

					 //�u���V�f�[�^�̒�`
		hBrush[0] = CreateSolidBrush(RGB(0, 0xAA, 0));          // �Ֆʁi�΁j
		hBrush[1] = CreateSolidBrush(RGB(0xFF, 0xFF, 0xFF));    // WHITE
		hBrush[2] = CreateSolidBrush(RGB(0, 0, 0));		        // BLACK
		hBrush[3] = CreateSolidBrush(RGB(0xff, 0, 0));         //�ԃL�[�{�[�h�̌��݈ʒu�\���p
		return 0;

	case WM_DESTROY:  // �E�B���h�E�j�����̏���


		// �u���V�̍폜
		for (i = 0; i < 3; i++) DeleteObject(hBrush[i]);
		PostQuitMessage(0);
		return 0;

	case WM_PAINT: // �`��C�x���g�������@�@�i��ʂɕω����������ۂɕp�ɂɌĂяo�����)


		// �y�C���g�J�n
		hdc = BeginPaint(hWnd, &ps);

		// �I�Z���Ղ̕`��

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


		EndPaint(hWnd, &ps);


		return 0;


		//�}�E�X�̏���
	case WM_LBUTTONDOWN:

		return 0;

		//�L�[�{�[�h�̏���
	case WM_KEYDOWN:
	

		return 0;

	} // switch���̏I��

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
	PSTR lpCmdLine, int nCmdShow
) {
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