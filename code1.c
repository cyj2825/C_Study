#include <stdio.h>

int main()
{
	double vel = 300000.000000;
	double dis = 149600000.000000;
	double min;
	printf("���� �ӵ��� %f km/sec\n", vel);
	printf("�¾�� ������ �Ÿ��� %f km\n\n\n", dis);
	min = dis / vel / 60;
	printf("=> ���޽ð��� %f ��\n", min);

	return 0;
}