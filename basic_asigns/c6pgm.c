#include <stdio.h>
#include <stdbool.h>
bool teddy(int n, int goal);

int main(){
	int n, goal=42;
	bool win;
	printf("enter any number of teddys:\n");
	scanf("%d",&n);
	win = teddy(n, goal);// calling the function here
	printf(win ? "true" : "false");
	return 0;
}

bool teddy(int n, int goal){
	int a,b;
	if (n<goal){
		return false;
	}
	if (n==goal){
		return true;
	}
	if (n%4==0){
		if (teddy(n/2, goal)) return true;
		a=((n%100)/10);
		b=n%10;
		if (a !=0 && b!= 0) if (teddy(n-(a*b), goal)) return true;
	}
	if (n%2==0){
		if (teddy(n/2, goal)) return true;
	}
	if (n%3==0){
		a=((n%100)/10);
		b=n%10;
		if (a !=0 && b!= 0) if (teddy(n-(a*b), goal)) return true;
	}
	if (n%5==0){
		teddy(n-42, goal);
	}
	else {
		return false;
	}
}
