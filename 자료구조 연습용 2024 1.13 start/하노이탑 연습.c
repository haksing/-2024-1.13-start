#include <stdio.h> 

void Hanoi(int n , char from , char tmp , char to) {

	if (n == 1)
		printf(" 원판 1을 %c에서 %c로 옮긴다 \n", from, to);
	else {
		Hanoi(n - 1, from, to, tmp);
		printf(" 원판 %d을 %c에서 %c로 옮긴다\n", n, from, to);
		Hanoi(n - 1, tmp, from, to);
	}

	// 1. 종단점이 항상 필요하다
	// 2. 함수 하나 당 멈추는 것은 하나임 여기서는 if ==1이 해당 나머지는
	//	  더 굴러 가도록 되어 있음.

}



int main(void) {
	Hanoi(4, 'a', 'b', 'c');
	return 0;

}