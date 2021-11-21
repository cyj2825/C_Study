#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
	int num, num2, i;
	int binary[32] = { 0 };

	while (1) {
		printf("10진수를 입력하세요(종료 -1): ");
		scanf("%d", &num);
		int positional = 0;
		num2 = num;
		
		while (1) {
			binary[positional] = num % 2;
			num = num / 2;

			positional++;
			if (num == 0) {
				break;
			}
		}
		if (num2 == -1) {
			printf("--------------------------------");
			break;
		}
		if (num2 != -1) {
			printf("%d = 2진수 (", num2);
		}
		for (i = positional - 1; i >= 0; i--) {
			printf("%d", binary[i]);
		}
		if (num2 != -1) {
			printf(")\n\n");
		}
	}

	return 0;
}