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
		tail->next=NN;
		NN->next=head;
		tail=NN;
		
	}
	
}
void display(NODE *NN){
	NODE *temp=head;
	while(temp!=head){
		printf("%d",temp->data);
		temp=temp->next;
	}
//	temp->next=head;
	printf("%d",temp->data);
}
NODE *delet1(NODE *NN){
	NODE *temp=head,*res;
	while(temp->next->next!=head){
		temp=temp->next;
	}
	temp->next=head;
	res=tail;
	tail=temp;
	return res;
}
void insert_start(NODE *NN){
	if(head==NULL && tail==NULL){
		head=NN;
		tail=NN;
		NN->next=head;
	}
	else{
	NN->next=head;
	NN=head;
	tail->next=head;
}
}
NODE *dele(NODE *NN){
	NODE *temp=head;
	if(head==NULL && tail==NULL){
		return NULL;
	}
	else if(head==tail){
		temp=head;
		head=NULL;
		tail=NULL;
		return temp;
	}
	else{
		
		temp=head;
		head=head->next;
		temp->next=NULL;
		return temp;
		
	}
}
int main(){
	NODE *NN,*res,*res1;
	int ch,val;
	while(1){
		printf("1.insert at end 2.display 3.delete at end 4.insert at head 5.delete at head");
		scanf("%d",&ch);
if(ch==1){
	   NN=(NODE *)malloc(sizeof(NODE));
	   scanf("%d",&val);
	   NN->data=val;
	   NN->next=NULL;
	   insert_end(NN);
	   
	}
	else if(ch==2){
		display(NN);
	}
	else if(ch==3){
		res=delet1(NN);
		if(res==NULL){
			printf("NO NODE");
		}
		else{
			printf("%d ",res->data);
			free(res);
		}
	}
	else if(ch==4){
		NN=(NODE *)malloc(sizeof(NODE));
	   scanf("%d",&val);
	   NN->data=val;
	   NN->next=NULL;
	   insert_start(NN);
	}
	else if(ch==5){
//		NODE *res1;
		res1=dele(NN);
		if(res1==NULL){
			printf("no node");
		}
		else{
			printf("%d",res1->data);
			free(res1);
		}
	}
	else{
		break;
	}
	}
	
	
	
}
