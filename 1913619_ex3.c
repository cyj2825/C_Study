#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 10

int main() {
	char choice;
	int seatnum;
	int seats[SIZE] = { 0 };
	int i;

	do {
		printf("�¼��� �����Ͻðڽ��ϱ�? (y �Ǵ� n) ");
		scanf(" %c", &choice);
		if (choice == 'n') {
			break;
		}

		printf("\n------------------------------\n");
		for (i = 0; i < 10; i++) {
			printf("%3d", i + 1);
		}
		printf("\n------------------------------\n");
		for (i = 0; i < 10; i++) {
			printf("%3d", seats[i]);
		}
		printf("\n�¼� ��ȣ�� �Է��ϼ���: ");
		scanf("%d", &seatnum);
		if (seatnum < 1 || seatnum>10) {
			printf("1���� 10������ ��ȣ�� �Է��ϼ���\n");
		}
		else if (seats[seatnum - 1] == 0) {
			printf("%d�� �¼��� ����Ǿ����ϴ�\n", seatnum);
			seats[seatnum - 1] = 1;
		}
		else {
			printf("�̹� ����� �ڸ��Դϴ�\n");
		}
	}while (choice == 'y');

	return 0;
}