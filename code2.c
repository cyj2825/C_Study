#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	const double PYE = 3.3058;
	int a = 0;
	double area = 0;

	printf("����� �Է��ϼ���:");
	scanf("%d", &a);
	area = a * PYE;
	printf("=> %d���� %f ���������Դϴ�.\n", a, area);

	return 0;
}