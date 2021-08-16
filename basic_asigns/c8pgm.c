#include <stdio.h>
void merge(int [], int, int, int, int temp[], int count[]);
void mergesort(int [], int, int, int, int[], int count[]);

int main(){
    int i, num, inversions[1]={0};
	printf("Enter number of elements \n");
	scanf("%d",&num);
	int inp_arr[num], temp[num];
	printf("Enter numbers with 'enter'\n");
	for(i=0;i<num;i++){
		scanf("%d",&inp_arr[i]);
	}
	mergesort(inp_arr, num, 0, num-1, temp, inversions);
    printf(" Number of inversions are %d \n", inversions[0]);
    return 0; 
}

void mergesort(int arr[], int size, int low, int high, int temp[], int count[]){
	int mid;
	if (low<high){
		mid = (low+high)/2;
		mergesort(arr, size, low, mid, temp, count);
		mergesort(arr, size, mid+1, high, temp, count);
		merge(arr, low, mid, high, temp, count);
	}
}
void merge(int arr[], int low, int mid, int high, int temp[], int count[]){
	int i, mi, k, lo;
	lo = low;
	i = low;
	mi = mid+1;
	while ((lo <= mid) && (mi <= high)){
		if (arr[lo] <= arr[mi]){
			temp[i] = arr[lo];
			lo++;
		}
		else{
			count[0] += (mid +1 -lo);
			temp[i] = arr[mi];
			mi++;
		}
		i++;
	}
	if (lo > mid){
		for (k=mi;k<=high;k++){
			temp[i] = arr[k];
			i++;
		}
	}
	else{
		for (k=lo;k<=mid;k++){
			temp[i] = arr[k];
			i++;
		}
	}
	for (k = low; k<= high; k++){
		arr[k] = temp[k];
	}
}
