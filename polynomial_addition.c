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
Node *poly_addition(Node *poly1,Node *poly2){
	Node *t1,*t2;
	t1=poly1;
	t2=poly2;
	Node *head=NULL;
	while(t1!=NULL &&t2!=NULL){
		if(t1->expo==t2->expo){
			head=insert_a_term(head,t1->coeff+t2->coeff,t1->expo);
			t1=t1->next;
			t2=t2->next;
		}
		else if (t1->expo>t2->expo){
			head=insert_a_term(head,t1->coeff,t1->expo);
			t1=t1->next;
		}
		else{
			head=insert_a_term(head,t2->coeff,t2->expo);
			t2=t2->next;
		}
	}
	while(t1!=NULL){
		head=insert_a_term(head,t1->coeff,t1->expo);
			t1=t1->next;
	}
	while(t2!=NULL){
		head=insert_a_term(head,t2->coeff,t2->expo);
			t2=t2->next;
	}return head;
}
int main(){
	printf("Polynomial 1:\n"); 
	Node *poly1=create_polynomial();//creating polynomial
	printf("Polynomial 2:\n"); 
	Node *poly2=create_polynomial();
	Node *sum=poly_addition(poly1,poly2);
	display_polynomial(poly1);
	display_polynomial(poly2);
	display_polynomial(sum);
	
	
}
