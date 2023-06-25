
#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
typedef struct Node NODE;
NODE *Head=NULL,*Tail=NULL;
void insert(NODE *NN){
	if(Head==NULL && Tail==NULL){
		Head=NN;
		Tail=NN;
	}
	else{
		Tail->next=NN;
		Tail=NN;
	}
}
void display(NODE *NN){
	NODE *temp=Head;
	while (temp!=NULL){
	printf("%d ",temp->data);
	temp=temp->next;
}
}
void delet(NODE *NN){
	NODE *temp;
	if(Head==NULL && Tail==NULL){
		printf("-1");
	}
	else if(Head==Tail){
		Head=NULL;
		Tail=NULL;
	}
	else{
		temp=Head;
		while(temp->next->next){
			temp=temp->next;
		}
		temp->next=NULL;
		printf("%d\n",Tail->data);
		Tail=temp;
	}
}
int main(){
	NODE *NN;
	int ch,val;
	while(1){
		printf("1.insert 2.display 3.delete 4.exit");
		scanf("%d",&ch);
		if(ch==1){//insert
			scanf("%d",&val);
			NN=(NODE *)malloc(sizeof(NODE));
			NN->data=val;
			NN->next=NULL;
			insert(NN);
			
		}
		else if(ch==2){//display
		display(NN);
		
		}
		else if(ch==3){
			delet(NN);
		}
		else{
			break;
		}
	}
}
