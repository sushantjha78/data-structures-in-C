#include <stdio.h>
#include <string.h>
#define length 50

int strcmp1(char str1[], char str2[], int idx);//user defined
void copy(char [], char []);

int main(){
	int i, j, num;
	printf("enter number of words\n");
	scanf("%d",&num);
	char inp_str[num][length], temp[length];
	printf("enter words \n");
	for (i=0; i<num; i++){
		scanf("%s", &inp_str[i]);
	}
	for (i=0; i < num-1; i++){
		for (j=i + 1; j < num - i; j++){
			if (strcmp1(inp_str[i], inp_str[j], 0) > 0){//func called here
				strcpy(temp, inp_str[i]);             //strcpy imported form string.h
				strcpy(inp_str[i], inp_str[j]);
				strcpy(inp_str[j], temp);
			}
		}
	}
	printf("sorted order----\n");
	for (i=0; i<num; i++){
		printf("%s\n", inp_str[i]);
	}
	return 0;
}


int strcmp1(char str1[], char str2[], int idx){
	if (str1[idx] == '\0' && str2[idx] !='\0'){
		return -1;
	}
	else{
		if (str1[idx] != '\0' && str2[idx] =='\0'){
		return 1;
		}
		else {
			if (str1[idx] == '\0' && str2[idx] =='\0'){
				return 0;
			}
			else {
				if (str1[idx] > str2[idx] ){
					return 1;
				}
				else {
					if (str1[idx] < str2[idx] ){
						return -1;
					}
					else {
						if (str1[idx] == str2[idx] ){
						return strcmp1(str1, str2, ++idx);
					}
					}
				}
			}
		}
	}
}
