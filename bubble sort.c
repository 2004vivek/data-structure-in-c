//bubble sort -in every time the adjacent element if they are not 
#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int a[n],i,j,temp;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++){
//		int swap=0;
		for(j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				
			}
		}
//		if(swap==0)break;
	}
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	
}
