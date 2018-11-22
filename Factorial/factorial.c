#include<stdio.h>
#include<stdlib.h>

int fact(int);

int main(void) {
	int n = 5;
	for (int i = 1; i <= n; i++) {
	if (i < n) {
		printf("%d != %d\n", i, fact(i));
	}
	else if(i==n)
		printf("fact(%d)= %d\n", n,fact(5));
}
}

int fact(int n)
{
	if (n <= 1) return 1;
	else return n*fact(n - 1);
}
