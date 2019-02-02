#include <windows.h>


#ifndef  _GLOBAL_INCLUDE_
#define _GLOBAL_INCLUDE_

#define  REVERSE    -1
#define  BLACK      -1
#define  EMPTY       0
#define  WHITE       1

#define UP -1;
#define RIGHT 1;
#define DOWN 1;
#define LEFT -1;


extern POINT pt; //�}�E�X���W
extern  POINT bt; //�L�[�{�[�h���W
extern RECT key;  //�L�[�{�[�h�̎l�p

//������̑���
 extern int whiteCnt;
//���̋�̑���
 extern int blackCnt;
//���݂̃v���C���[�J���[
 extern int player;
//�p�X�t���O
 extern int passFlg;
//���������鏇��
 extern const int drctArray[8];

//�V�[���Ǘ�
 typedef enum  Judge {
	eAllJudge,
	eClickJudge,
	eReverseJudge
}Scene;

//���p
typedef enum Direction {
	eN,
	eNE,
	eE,
	eSE,
	eS,
	eSW,
	eW,
	eNW,
}Drct;

extern int mousex;
extern int mousey;
static int mouseStorageX;	// �}�E�X��x���W��ۑ�����
static int mouseStorageY;	// �}�E�X��y���W��ۑ�����

extern int masu[10][10];
extern int canPutMasu[10][10];


extern POINT dot[4];

/************************************************
�� �� �� :SetMasu(int i,int j,int num)
�������e :���񂾋���Ђ�����Ԃ�
��    �� :�@
�������@int  ���ꂽ���F
�������@int  ���ꂽ���F
��O�����@int  ���ꂽ���F
�� �p �l :����
���@�@�l :�}�E�X������}�X��
*************************************************/
static void SetMasu(int i, int j, int color) {
//	masu[i][j] = color;
}

#endif _GLOBAL_INCLUDE_

