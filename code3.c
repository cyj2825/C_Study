#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	int ID = 0;
	int PW = 0;
	printf("아이디와 패스워드를 4자리 숫자로 입력하세요 :\n");
	printf("ID :____\b\b\b\b");
	scanf("%d", &ID);
	printf("PW :____\b\b\b\b");
	scanf("%d", &PW);

	printf("입력된 ID는 \"%d\"이고, 패스워드는 \"%d\"입니다.\n", ID, PW);

	return 0;
}