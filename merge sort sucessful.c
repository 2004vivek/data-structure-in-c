#include<stdio.h>
void mergesort(int a[],int mid,int low,int high){
	int b[1000000];
	int i=low;
	int j=mid+1;
	int k=0;
	while(i<=mid&&j<=high){
		if(a[i]<a[j]){
			b[k]=a[i];
			k++;
			i++;
		}
		else{
			b[k]=a[j];
			k++;
			j++;
		}
	}
	while(i<=mid){
		b[k]=a[i];
			k++;
			i++;
	}
	while(j<=high){
		b[k]=a[j];
			k++;
			j++;
	}
	for(i=low;i<=high;i++){
		a[i]=b[i-low];
	}
}
void merge(int a[],int low,int high){
	if(low>=high)return;
	int mid=(low+high)/2;
	merge(a,low,mid);
	merge(a,mid+1,high);
	mergesort(a,mid,low,high);
}
int main(){
	int n;
	scanf("%d",&n);
	int a[n],i;
	int low=0;
	int high=n-1;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	merge(a,low,high);
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}
