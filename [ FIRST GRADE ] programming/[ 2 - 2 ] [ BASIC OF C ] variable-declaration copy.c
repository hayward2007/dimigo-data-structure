// int max = 2147483648; 
// max 을 출력하면 논리적인 오류가 발생할 수 있다.
// 논리적인 오류가 발생하지 않도록 max값을 수정하여 작성하고, 실행해보시오.

#include <stdio.h>

int main() {
	int a = 16;
	float b = 3.14;
	char c = 'q';
	char d[6] = "DIMIGO";
	printf("%d %f %c %s",a,b,c,d);
	return 0;
}
