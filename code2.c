#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	const double PYE = 3.3058;
	int a = 0;
	double area = 0;

	printf("평수를 입력하세요:");
	scanf("%d", &a);
	area = a * PYE;
	printf("=> %d평은 %f 제곱미터입니다.\n", a, area);

	return 0;
}