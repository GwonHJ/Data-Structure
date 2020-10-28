#include<stdio.h>
#include<stdlib.h>


// recursion 방식의 factorial 구하기
int fact(int);//프로토타입선언

int main(void) {
	int n = 5;
	for (int i = 1; i <= n; i++) {
	if (i < n) {
		printf("%d != %d\n", i, fact(i));//1!~4!까지의 값 출력
	}
	else if(i==n)
		printf("fact(%d)= %d\n", n,fact(5));//5!의 값 출력
}
}

int fact(int n)
{
	if (n <= 1) return 1;
	else return n*fact(n - 1);
}// factorial 함수
