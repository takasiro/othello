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

typedef enum  Judge {
	eAllJudge,
	eClickJudge,
	eReverseJudge
};
int i, j;
#endif // _GLOBAL_INCLUDE_

