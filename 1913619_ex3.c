#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 10

int main() {
	char choice;
	int seatnum;
	int seats[SIZE] = { 0 };
	int i;

	do {
		printf("좌석을 예약하시겠습니까? (y 또는 n) ");
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
		printf("\n좌석 번호를 입력하세요: ");
		scanf("%d", &seatnum);
		if (seatnum < 1 || seatnum>10) {
			printf("1부터 10사이의 번호를 입력하세요\n");
		}
		else if (seats[seatnum - 1] == 0) {
			printf("%d번 좌석이 예약되었습니다\n", seatnum);
			seats[seatnum - 1] = 1;
		}
		else {
			printf("이미 예약된 자리입니다\n");
		}
	}while (choice == 'y');

	return 0;
}