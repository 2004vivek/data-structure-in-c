// leetcode 739 probelm
#include<stdio.h>
#define size 100
#define empty (-1)
int stack[size];
int top=empty;
void Push(int val){
	if(top==size-1){
		printf("stack is filled");
		return;
	}
	top++;
	stack[top]=val;
}
void pop(){
	if(top==empty){
		return;
	}
	top--;
}
int Top(){
	if(top==empty)return -1;
	else return stack[top];
}
int isempty(){
	return top==empty;
}
int main(){
	int n;
	scanf("%d",&n);
	int a[n],i;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	Push(n-1);
	int ans[100]={0};
	ans[n-1]=0;
	for( i=n-2;i>=0;i--){
	while(!isempty() && a[Top()]<a[i]){
		pop();
	}
	if(!isempty())
    {
        ans[i]=Top()-i;
    }
	else ans[i]=0;
	Push(i);
}
for(i=0;i<n;i++){
	printf("%d ",ans[i]);
}
}
