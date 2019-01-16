#include <windows.h>


#ifndef  _GLOBAL_INCLUDE_
#define _GLOBAL_INCLUDE_

#define  REVERSE  -1
#define  BLACK      -1
#define  EMPTY       0
#define  WHITE       1

POINT pt; //�}�E�X���W
POINT bt; //�L�[�{�[�h���W

//������̑���
int whiteCnt;
//���̋�̑���
int blackCnt;
//���݂̃v���C���[�J���[
int player;
//�p�X�t���O
int passFlg;

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

#endif _GLOBAL_INCLUDE_

