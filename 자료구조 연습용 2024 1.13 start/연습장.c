#include <stdio.h> 
int factorial(int n) {
	printf("%d\n", n);
	if (n <= 1)
		return(1); //반복문의 조건 설정은 멈추는곳을 찾는 것 
	else
		return(n * factorial(n - 1));
}
int main(){
	int a;
		a = factorial(5);
		printf("%d", a);
}