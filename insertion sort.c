#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int a[n],i;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++){
		int key=a[i];
		int j=i-1;
		while(j>=0 && a[j]>key){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
}
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}

