#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
	int k = 0;
	char pass;
	char word;

	printf("==== k-�˰����� ����� ��ȣȭ ==========\n");
	printf("k ���� �Է��ϼ��� : ");
	scanf("%d", &k);
	
	pass = getchar();
	printf("��ȣȭ�� ���ڸ� �Է��ϼ��� : ");
	scanf("%c", &pass);

	word = pass + k;

	printf("=> ��ȣ���� %c�Դϴ�.\n", word);

	return 0;
}