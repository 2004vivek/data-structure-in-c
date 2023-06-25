#include<stdio.h>
int getmax(int a[],int n){
	int i;
	int maxi=0;
	for(i=0;i<n;i++){
		if(a[i]>maxi)maxi=a[i];
	}
	return maxi;
}
void radixsort(int a[],int n){
	int b[10][n];
	int maxi=getmax(a,n);
	int val=1;
	int i,j;
	while(maxi){
		int cnt[10]={0};
		for(i=0;i<n;i++){
			int x=(a[i]/val)%10;
			b[x][cnt[x]]=a[i];
			cnt[x]++;
		}
		int k=0;
		for(i=0;i<10;i++){
			for(j=0;j<cnt[i];j++){
				a[k++]=b[i][j];
			}
		}
		maxi=maxi/10;
		val=val*10;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int a[n],i;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	radixsort(a,n);
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}
