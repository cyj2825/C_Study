#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
	int k = 0;
	char pass;
	char word;

	printf("==== k-알고리즘을 사용한 암호화 ==========\n");
	printf("k 값을 입력하세요 : ");
	scanf("%d", &k);
	
	pass = getchar();
	printf("암호화할 문자를 입력하세요 : ");
	scanf("%c", &pass);

	word = pass + k;

	printf("=> 암호문은 %c입니다.\n", word);

	return 0;
}