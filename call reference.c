//call by refernce means address of the variable passed as argument of that function is callled call by value
#include<stdio.h>
void swap(int *,int *);
int main(){
	int a,b;
	scanf("%d%d",&a,&b);//a=10  b=20
	swap(&a,&b);//function call by value  swap(10,20) actual parametr --variables in function callin
	printf("a=%d b=%d",a,b);
	
}
void swap(int *x,int *y){//formal parameter      ////change made in function definition  reflect in function calling both the given variable shows common memory location
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
	printf("x=%d y=%d\n",x,y);
	printf("x=%d y=%d\n",*x,*y);
	
}
