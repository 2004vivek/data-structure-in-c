#include<stdio.h>
int quicksort(int a[],int low,int high){
	int i=low;
	int j=high;
	int pivot=a[low];                          //7 6 4 5 8
	while(i<j){                                //0 1 2 3 4
		while(a[i]<=pivot){                    //      
			i++;
		}
		while(a[j]>pivot){
			j--;
		}
		if(i<j){
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	a[low]=a[j];
	a[j]=pivot;
	
	return j;
	
}
void quick(int a[],int low,int high){
	if(low>=high)return;                         //1 3 2 5 4
	int pivot_index=quicksort(a,low,high);      //0 1 2 3 4
	quick(a,low,pivot_index-1);
	quick(a,pivot_index+1,high);
}
int main(){
	int n,i;//5
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){         //1 3 2 5 4
		scanf("%d",&a[i]);    //0 1 2 3 4
	}
	quick(a,0,n-1);
	for(i=0;i<n;i++){
		printf("%d",a[i]);
	}
}
