#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	int ID = 0;
	int PW = 0;
	printf("���̵�� �н����带 4�ڸ� ���ڷ� �Է��ϼ��� :\n");
	printf("ID :____\b\b\b\b");
	scanf("%d", &ID);
	printf("PW :____\b\b\b\b");
	scanf("%d", &PW);

	printf("�Էµ� ID�� \"%d\"�̰�, �н������ \"%d\"�Դϴ�.\n", ID, PW);

	return 0;
}