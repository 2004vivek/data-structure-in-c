#include<stdio.h>
int getmax(int a[],int n){
	int i;
	int max=0;
	for(i=0;i<n;i++){
		if(a[i]>max)max=a[i];
	}
	return max;
}
void count(int a[],int n,int pos){
	int counti[10]={0};
	int i;
	int b[n];
	for(i=0;i<n;i++){
		counti[(a[i]/pos)%10]++;
	}
	for(i=1;i<=10;i++){
		counti[i]=counti[i]+counti[i-1];
	}
	for(i=n-1;i>=0;i--){
		b[--counti[(a[i]/pos)%10]]=a[i];
	}
	for(i=0;i<n;i++){
		a[i]=b[i];
	}
}
void radix(int a[],int n){
	int max=getmax(a,n);
	int pos;
	for(pos=1;max/pos>0;pos*10){
		count(a,n,pos);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int a[n],i;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	radix(a,n);
	for(i=0;i<n;i++){
		printf("%d",a[i]);
	}
}
