#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
	long long won = 0;
	long long pro = 0;

	printf("�Ŵ� ����ݾ��� �Է��ϼ��� : ");
	scanf("%lld", &won);
	pro = won * 12 * 30;
	printf("30�� ���� ��� = %lld��\n", pro);

	return 0;
}