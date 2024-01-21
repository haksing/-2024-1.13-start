#include <stdio.h> 

void Hanoi(int n , char from , char tmp , char to) {

	if (n == 1)
		printf(" ���� 1�� %c���� %c�� �ű�� \n", from, to);
	else {
		Hanoi(n - 1, from, to, tmp);
		printf(" ���� %d�� %c���� %c�� �ű��\n", n, from, to);
		Hanoi(n - 1, tmp, from, to);
	}

	// 1. �������� �׻� �ʿ��ϴ�
	// 2. �Լ� �ϳ� �� ���ߴ� ���� �ϳ��� ���⼭�� if ==1�� �ش� ��������
	//	  �� ���� ������ �Ǿ� ����.

}



int main(void) {
	Hanoi(4, 'a', 'b', 'c');
	return 0;

}