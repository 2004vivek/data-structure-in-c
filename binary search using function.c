#include<stdio.h>
int binary_search(int a[],int n,int t){
	int low=0;
	int high=n-1;
	while(low<=high){
		int mid=(low+high)>>1;
		if(a[mid]==t)return mid;
	else if(a[mid]>t){
		high=mid-1;
	}
	else{
		low=mid+1;
	}
}
return -1;

}
int linear_search(int a[],int n,int t){
	int i;
	for(i=0;i<n;i++){
		if(a[i]==t)return 1;
	}
}
int main(){
	int i;
	int n,t;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&t);
	int x = binary_search(a,n,t);
	int y = linear_search(a,n,t);
	printf("%d\n",x);
	printf("%d\n",y);
	
	
}
