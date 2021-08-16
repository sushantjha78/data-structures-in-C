#include <stdio.h>
#define length 30
int capital_check(char str[], int idx);


int main(){
	int i=0, cap = 0;
	char inp_str[length];
	printf("enter any sentence:\n");
	gets(inp_str);
	cap = capital_check(inp_str, cap);
	printf("%c",cap);
	return 0;
}

int capital_check(char str[], int idx){
	if (str[idx] == '\0'){
		return 0;
	}
	else{
		if ((str[idx] >= 'A') && (str[idx] <= 'Z')){
			return str[idx];
		}
		else {
			return capital_check(str, idx+1);
		}
	}
}
