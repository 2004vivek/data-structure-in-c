//polynomial representation
#include<stdio.h>
#include<stdlib.h>
struct node{
	float coeff;
	int expo;
	struct node *next;
};
typedef struct node Node;
Node *insert_a_term(Node *head,float co,int ex){
     Node *NN;
	 NN=(Node *)malloc(sizeof(Node));
	 NN->coeff=co;
	 NN->expo=ex;
	 NN->next=NULL;
	 if(head==NULL || NN->expo > head->expo){
	 	NN->next=head;
	 	head=NN;
	 }
	 else{
	 	Node *temp=head;
	 	while(temp->next!=NULL &&temp->next->expo >ex){
	 		temp=temp->next;
		 }
		 NN->next=temp->next;
		 temp->next=NN;
	 }
	 return head;
}
Node *create_polynomial(){
	Node *head=NULL;
	int n,i;
	printf("enter the no of terms:\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		float co;
		int ex;
		printf("enter the coeff of term %d:\n",i);
		scanf("%f",&co);
		printf("enter expo of the term %d:\n",i);
		scanf("%d",&ex);
		head=insert_a_term(head,co,ex);
	}
	return head;
}
void display_polynomial(Node *head){
	Node *temp=head;
	while(temp){
		printf("%0.1fx^%d",temp->coeff,temp->expo);
		if(temp->next!=NULL){
			printf(" + ");
		}
		else{
			printf("\n");
		}
		temp=temp->next;
	}
}

int main(){
	printf("Polynomial:\n");
	Node *poly=create_polynomial();
	display_polynomial(poly);
	
}
