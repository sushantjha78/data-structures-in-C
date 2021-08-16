#include <stdio.h>
int digitalRoot(int n);


int main(){
	int num=0, root = 0;
	printf("enter any number:\n");
	scanf("%d",&num);
	root = digitalRoot(num);
	printf("%d",root);
	return 0;
}

int digitalRoot(int n){
	if (n/10 == 0){
		return n;
	}
	else {
		return digitalRoot((n%10)+ digitalRoot(n/10));
	}
}
