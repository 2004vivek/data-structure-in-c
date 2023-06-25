#include<stdio.h>
int binary_search(int a[],int low,int high,int se){
	int mid=(low+high)/2;
	if(low>high){
		return -1;
	}
	else{
		if(se==a[mid]){
			return mid;
		}
		if(se>a[mid]){
			return binary_search(a,mid+1,high,se);
		}
		else{
			return binary_search(a,low,mid-1,se);
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int a[n],i;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int se;
	scanf("%d",&se);
	int x=binary_search(a,0,n-1,se);
	printf("%d",x);
}
