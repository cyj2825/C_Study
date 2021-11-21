#include <stdio.h>

int main()
{
	double vel = 300000.000000;
	double dis = 149600000.000000;
	double min;
	printf("빛의 속도는 %f km/sec\n", vel);
	printf("태양과 지구의 거리는 %f km\n\n\n", dis);
	min = dis / vel / 60;
	printf("=> 도달시간은 %f 분\n", min);

	return 0;
}