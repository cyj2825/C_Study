#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
	int a, num;
	char choice;

	while (1) {
		int count = 0;
		printf("========== ����� ���� ==========\n");
		printf("1���� 100������ �����Դϴ�.");

		srand((unsigned)time(NULL));
		a = rand() % 100 + 1;
		while (1) {
			printf("\n%d. ����� ������ ���� �����Դϱ�? ", count + 1);
			scanf("%d", &num);
			if (a == num) {
				printf("\n�¾ҽ��ϴ�. ����� �¸��Դϴ�.\n");
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
				printf("\nƲ�Ƚ��ϴ�. ���İ��� �¸��Դϴ�.\n���İ��� ���ڴ� %d�Դϴ�.\n", a);
				break;
			}
		}
		printf("====================================\n");
		printf("������ ����Ͻðڽ��ϱ� ? (y �Ǵ� n) ");
		scanf(" %c", &choice);
		if (choice == 'y') {
			continue;
		}
		else if (choice == 'n') {
			printf("������ �����մϴ�. �����մϴ�.\n");
			break;
		}
	}
	return 0;
}