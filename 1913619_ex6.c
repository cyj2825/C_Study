#include <stdio.h>
#define ROWS 3
#define COLS 3

void transpose(int nums[3][3], int r);
void original(int nums[3][3], int row, int col);

int main(void)
{
	int nums[ROWS][COLS] = { {1, 2, 3},{4, 5, 6},{7, 8, 9} };
	printf("Original array A\n");
	original(nums, 3, 3);

	printf("Transposed array B\n");
	transpose(nums, 3);

	printf("-----------------------");

	return 0;
}
void transpose(int nums[3][3], int r) {
	int matrix[3][3];
	int a, b;

	for (a = 0; a < 3; a++) {
		for (b = 0; b < 3; b++) {
			matrix[a][b] = nums[b][a];
		}
	}
	for (a = 0; a < 3; a++) {
		for (b = 0; b < 3; b++) {
			nums[a][b] = matrix[a][b];
		}
	}
	for (a = 0; a < 3; a++) {
		for (b = 0; b < 3; b++) {
			printf("%3d", nums[a][b]);
		}
		printf("\n");
	}
}
void original(int nums[3][3], int row, int col) {
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("%3d", nums[i][j]);
		}
		printf("\n");
	}
}