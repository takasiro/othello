#include <windows.h>


#ifndef  _GLOBAL_INCLUDE_
#define _GLOBAL_INCLUDE_

#define  REVERSE    -1
#define  BLACK      -1
#define  EMPTY       0
#define  WHITE       1

POINT pt; //�}�E�X���W
POINT bt; //�L�[�{�[�h���W

//������̑���
static int whiteCnt;
//���̋�̑���
static int blackCnt;
//���݂̃v���C���[�J���[
static int player;
//�p�X�t���O
static int passFlg;
//���������鏇��
static const int drctArray[8] = { 0,1,2,3,4,5,6,7 };

//�V�[���Ǘ�
typedef enum  Judge {
	eAllJudge,
	eClickJudge,
	eReverseJudge
};

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
};

static int masu[10][10] = {
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,1,-1,0,0,0,0 },
	{ 0,0,0,0,-1,1,0,0,0,0 },
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
	masu[i][j] = color;
}

#endif _GLOBAL_INCLUDE_

