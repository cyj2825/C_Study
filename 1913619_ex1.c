#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 4
#define COLS 15

int main(void) {
	int scores[COLS][ROWS] = { 0 };

	int i, j;
	int max1, max2, max3;
	int min1, min2, min3;

	printf("학번  국어  영어  수학\n");
	printf("=======================\n");
	srand((unsigned)time(NULL));

	for (i = 0; i < COLS; i++) {
		printf("%4d", i+1);
		for (j = 1; j < ROWS; j++) {
			scores[i][j] = rand() % 100 + 1;
			printf("%6d", scores[i][j]);
		}
		j = 1;
		printf("\n");
	}
	printf("=======================\n");
	max1= scores[0][1];
	min1= scores[0][1];
	for (i = 0; i < COLS; i++) {
		if (scores[i][1] > max1)
			max1 = scores[i][1];
		if (scores[i][1] < min1)
			min1= scores[i][1];
	}
	max2 = scores[0][2];
	min2 = scores[0][2];
	for (i = 0; i < COLS; i++) {
		if (scores[i][2] > max2)
			max2 = scores[i][2];
		if (scores[i][2] < min2)
			min2 = scores[i][2];
	}
	max3 = scores[0][3];
	min3 = scores[0][3];
	for (i = 0; i < COLS; i++) {
		if (scores[i][3] > max3)
			max3 = scores[i][3];
		if (scores[i][3] < min3)
			min3 = scores[i][3];
	}
	printf("최고: %4d  %4d  %4d\n", max1, max2, max3);
	printf("최저: %4d  %4d  %4d\n", min1, min2, min3);
	printf("=======================\n");
	return 0;
}