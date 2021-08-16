#include <stdio.h>
#define length 30
int const_check(char str[], int idx1, int idx2, char vowels[], int consonant);

int main(){
	int conso;
	char inp_str[length], vowels[11] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U','\0'};
	printf("enter any sentence:\n");
	gets(inp_str);
	conso = const_check(inp_str, 0, 0, vowels, 0);//this is the recursive func
	printf("%d",conso);
	return 0;
}

int const_check(char str[], int idx1, int idx2, char vowels[], int consonants){
	if (str[idx1] == '\0'){
		return (consonants);
	}
	else{
		if (str[idx1] == vowels[idx2]){
			return const_check(str, ++idx1, 0, vowels, consonants);
		}
		else {
			if (vowels[idx2] != '\0'){
				return const_check(str, idx1, ++idx2, vowels, consonants);
			}
			else {
				if ((str[idx1] >= 'a' && str[idx1] <= 'z') || (str[idx1] >= 'A' && str[idx1] <= 'Z')){
					return const_check(str, ++idx1, 0, vowels, ++consonants);
				}
				else{
					return const_check(str, ++idx1, 0, vowels, consonants);
				}
				
			}
		}
	}
}

