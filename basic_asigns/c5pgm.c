#include <stdio.h>
void series(int first, int pow);


int main(){
	series(1, 0);
	return 0;
}

void series(int first, int pow){
	if (pow <= 10){
		printf("%d, ",first);
		series(first*2, ++pow);
		return ;
	}
	else {
		if (pow <= 21){
		printf("%d, ",first/2);
		series(first/2, ++pow);
		return ;
		}
	}
}
