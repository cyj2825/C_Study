#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
	long long won = 0;
	long long pro = 0;

	printf("매달 저축금액을 입력하세요 : ");
	scanf("%lld", &won);
	pro = won * 12 * 30;
	printf("30년 후의 재산 = %lld원\n", pro);

	return 0;
}