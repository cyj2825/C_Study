#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
	int a, num;
	char choice;

	while (1) {
		int count = 0;
		printf("========== 히어로 게임 ==========\n");
		printf("1부터 100사이의 숫자입니다.");

		srand((unsigned)time(NULL));
		a = rand() % 100 + 1;
		while (1) {
			printf("\n%d. 당신이 생각한 값은 무엇입니까? ", count + 1);
			scanf("%d", &num);
			if (a == num) {
				printf("\n맞았습니다. 당신의 승리입니다.\n");
				break;
			}
			else if (a > num) {
				printf("=> high");
			}
			else if (a < num) {
				printf("=> low");
			}
			count++;
			if (count == 5) {
				printf("\n틀렸습니다. 알파고의 승리입니다.\n알파고의 숫자는 %d입니다.\n", a);
				break;
			}
		}
		printf("====================================\n");
		printf("게임을 계속하시겠습니까 ? (y 또는 n) ");
		scanf(" %c", &choice);
		if (choice == 'y') {
			continue;
		}
		else if (choice == 'n') {
			printf("게임을 종료합니다. 감사합니다.\n");
			break;
		}
	}
	return 0;
}