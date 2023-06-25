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
NODE *delet(NODE *NN){
	NODE *temp,*dn;
	if(Head==NULL && Tail==NULL){
		return NULL;
	}
	if(Head==Tail){
		dn=Head;
		Head=NULL;
		Tail=NULL;
		return dn;
	}
		temp=Head;
		while(temp->next->next){
			temp=temp->next;
		}
		temp->next=NULL;
		dn=Tail;
		Tail=temp;
		return dn;
}
int count(){
	NODE *temp;
	int ct=0;
	temp=Head;
	while(temp!=NULL){
		temp=temp->next;
		ct++;
	}
	return ct;
}
void insert_head(NODE *NN){
	if(Head==NULL && Tail==NULL){
		Head=NN;
		Tail=NN;
	}
	else{
		
		NN->next=Head;
		Head=NN;
	}
}
NODE * delete_start(NODE *NN){
	NODE *temp=Head;
	if(Head==NULL && Tail==NULL){
		return NULL;
	}
	else if(Head==Tail){
		temp=Head;
		Head=NULL;
		Tail=NULL;
		return temp;
	}
	else{
		temp=Head;
		Head->next=NN;
		Head=NN;
		temp->next=NULL;
//		Head->next=Head;
//		temp->next=NULL;
		return temp;
	}
}
int search(int val){
	NODE *temp;
	temp=Head;
	int c=0;
	while(temp){
	if(temp->data==val){
		c++;
	}
	temp=temp->next;
}
return c;
}
void reverse(int count){
	int a[count],i;
	NODE *temp;
	temp=Head;
	for(i=0;i<count;i++){
		a[i]=temp->data;
		temp=temp->next;
	}
	for(i=count-1;i>=0;i--){
		printf("%d ",a[i]);
	}
}
int main(){
	NODE *NN,*res;
	int ch,val;
	while(1){
		
		printf("1.insert 2.display 3.delete 4.count 5.insert at head 6.delete at head 7.search 8.reverse 9.exit");
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
			res=delet(NN);
			if(res==NULL){
				printf("no nodes\n");
			}
			else{
				printf("%d\n",res->data);
			}
		}
		else if(ch==4){
			printf("%d",count());
		}
		else if(ch==5){
			NN=(NODE *)malloc(sizeof(NODE));
			NN->data=val;
			NN->next=NULL;
			insert_head(NN);
		
		}
		else if(ch==6){
			NODE * res1=delete_start(NN);
			if(res1==NULL){
				printf("no nodes\n");
			}
			else{
				printf("%d\n",res1->data);
			}
		}
		else if(ch==7){
			int val;
			scanf("%d",&val);
			int x=search(val);
			printf("%d",x);
		}
		else if(ch==8){
			reverse(count());
		}
		else{
			break;
		}
	}
}
