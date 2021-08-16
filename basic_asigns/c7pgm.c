#include <stdio.h>
void sort(int arr[], int idx, int idx2);//using bubble sort

int main(){
	int i,j,num;
	printf("Enter number of elements\n");
	scanf("%d",&num);
	int inp_arr[num];
	printf("Enter numbers with 'enter'\n");
	for(i=0;i<num;i++)
	{
		scanf("%d",&inp_arr[i]);
	}
	sort(inp_arr, 0, num-1);//calling func here
	for(j=0;j<num;j++){
		printf("%d\t",inp_arr[j]);
	}
	return 0;
}

void sort(int arr[], int idx1, int idx2){
	int temp;
	if (idx1%2){
		if ((idx2 == 1) || (idx1 == idx2)){
			return;
		}
		else {
			if (idx2-idx1>1){
				if (arr[idx1] > arr[idx1+2]){
					temp = arr[idx1];
					arr[idx1] = arr[idx1+2];
					arr[idx1+2] = temp;
				}
				sort(arr, idx1+1, idx2);
			}
			sort(arr, idx1, idx2-1);
		}
	}
	else {
		if ((idx2 == 0) || (idx1 == idx2)){
			return;
		}
		else {
			if(idx2-idx1>1){
				if(arr[idx1] < arr[idx1+2]){
					temp = arr[idx1];
					arr[idx1] = arr[idx1+2];
					arr[idx1+2] = temp;
				}
				sort(arr, idx1+1, idx2);
			}
			sort(arr, idx1, idx2-1);
		}
	}
}
