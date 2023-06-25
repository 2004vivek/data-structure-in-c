#include<stdio.h>
#include<stdlib.h>
struct Student{
	char name[100];
	int roll;
};
typedef struct Student Std;
int main(){
	Std *s1[100];
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		s1[i]=(Std *)malloc(n*sizeof(Std));
		scanf(" %[^\n]s",&s1[i]->name);
		scanf("%d",&s1[i]->roll);
	}
	for(i=0;i<n;i++){
		printf("%s %d",s1[i]->name,s1[i]->roll);
	}
	
}
