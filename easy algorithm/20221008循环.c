#include<stdio.h>
int main() {
	int n, sum;
	int i = 0;
	scanf("%d", &n);
	sum = 0;
	for (i = 1; i <= n; i++) {

		sum = sum + i;
	}
	printf("%d\n", sum);
	i = 0;
	sum = 0;
	while (i <= n) {

		sum += i;
		i++;//TODO
	}
	printf("%d\n", sum);
	i = 0;
	sum = 0;
	do {
		i++;

		sum += i; //TODO
	} while (i <n);
	printf("%d\n", sum);
	return 0;
}
