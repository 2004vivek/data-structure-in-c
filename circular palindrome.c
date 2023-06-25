#include<stdio.h>
int prime(int n);
int rev(int n);
int main(){
	int n,x=0;
	scanf("%d",&n);
	if (prime(n)){
		x=rev(n);
		if(prime(x)){
			printf("circluar prime");
		}
	}
	else{
		printf("not circular prime");
	}
}
int prime(int n){
	int i,c=0;
	for(i=1;i<=n;i++){
		if(n%i==0){
			c++;
		}
	}
	if(c==2){
		return 1;
	}
	else{
		return 0;
	}
	
}int rev(int n){
	int r,s=0;
	while(n!=0){
		r=n%10;
		s=s*10+r;
		n=n/10;
	}
	return s;
}
