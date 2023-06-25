//BST-insertion and searching
//inorder,preorder,postorder
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node treenode;
treenode *root=NULL;
void inorder(treenode *root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
void preorder(treenode *root){
	if(root!=NULL){
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(treenode *root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}
treenode *create_tree_node(int val){
	treenode *nn=(treenode *)malloc(sizeof(treenode));
	nn->data=val;
	nn->left=NULL;
	nn->right=NULL;
	return nn;
}
void insert_bst(treenode *nn){
	if(root==NULL){
		root=nn;
	}
	else{
		treenode *temp=root;
		while(1){
			if(nn->data==temp->data){
				printf("data already exist\n");
				break;
			}
			else if(nn->data>temp->data){
				if(temp->right==NULL){
					temp->right=nn;
					break;
				}
				else{
				temp=temp->right;
			    }
			}
			else{
				if(temp->left==NULL){
					temp->left=nn;
					break;
				}
				else{
				temp=temp->left;
			    }
			}
			
		}
	}
}
int search_bst(treenode *root,int key){
	treenode *temp=root;
	while(temp!=NULL){
		if(key==temp->data){
			return 1;
		}
		else if(key>temp->data){
			temp=temp->right;
		}
		else{
			temp=temp->left;
		}
	}
	return -1;
}
int main(){
	int ch;
	while(1){
		printf("enter \n1.insertion\n2.search\n3.inorder\n4.preorder\n5.postorder\n");
		scanf("%d",&ch);
		if(ch==1){
			//insertion
			int val;
			printf("enter the value for node: ");
			scanf("%d",&val);
			treenode *nn=create_tree_node(val);
			insert_bst(nn);
		}
		else if(ch==2){
			//search
			int key;
			printf("enter a key to find:");
			scanf("%d",&key);
			int res=search_bst(root,key);
			if(res==-1){
				printf("key not found");
			}
			else{
				printf("key found");
			}
		}
		else if(ch==3){
			//inorder
			inorder(root);
		}
		else if(ch==4){
			//preorder
			preorder(root);
		}
		else if(ch==5){
			//postorder
			postorder(root);
		}
		else{
			break;
		}
	}
}
