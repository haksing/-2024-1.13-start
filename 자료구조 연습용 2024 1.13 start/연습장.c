#include <stdio.h> 
int factorial(int n) {
	printf("%d\n", n);
	if (n <= 1)
		return(1); //�ݺ����� ���� ������ ���ߴ°��� ã�� �� 
	else
		return(n * factorial(n - 1));
}
int main(){
	int a;
		a = factorial(5);
		printf("%d", a);
}