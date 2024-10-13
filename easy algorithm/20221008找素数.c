#include<stdio.h>
void isprime(int);
int main() {
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		int n;
		scanf("%d",&n);
	isprime(n);	//TODO
	}

	return 0;
}
void isprime(int n) {
	
	for (int i = 2; i <= n; i++) {
		int a = 0;
		for (int j = 2; j <= i; j++) {
			if (i % j == 0 && j != i) {
				a = 1;
				break;
			}
		}

		if (a == 0) {
			printf("%d ", i);
		}
	}

}
