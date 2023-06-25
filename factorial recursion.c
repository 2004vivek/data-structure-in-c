#include<stdio.h>
int fact(int n){
	if(n==1||n==0) return ;
	return n*fact(n-1);
}
int main(){
	int n;
	scanf("%d",&n);
	int x=fact(n);
	printf("%d",x);
}
