//#circular linked dispaly-placing first node address to last
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
};

typedef struct node NODE;
NODE * head=NULL,*tail=NULL;
void insert_end(NODE *NN){
	if(head==NULL && tail==NULL){
		head=NN;
		NN->next=head;
		tail=NN;
	}
//	else if(head==tail){
//		head->next=NN;
//		NN->next=head;
//		
//	}
	else{
		NN->next=head;
		tail=NN;
	}
	
}
int main(){
	NODE *NN;
	int ch,val;
	while(1){
		printf("1.insert at end");
		scanf("%d",&ch);
if(ch==1){
	   NN=malloc(sizeof(NODE));
	   scanf("%d",val);
	   NN->data=val;
	   NN->next=NULL;
	   insert_end(NN);
	   
	}
	else if(ch==2){
		
	}
	else{
		break;
	}
	}
	
	
	
}
