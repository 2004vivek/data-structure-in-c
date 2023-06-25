// Online C compiler to run C program online
#include <stdio.h>
#include<stdbool.h>
#define size 100
char stack[size];
int top=-1;
void Push(char val){
    if(top==size-1){
        printf("stack overflow");
    }
    else{
        top++;
        stack[top]=val;
    }
}
char pop(){
    if(top==-1){
        return -1;
    }
    else{
        int res=stack[top];
        top--;
        return res;
    }
}
int Top(){
    if(top==-1){
        return -1;
    }
    else{
        int res=stack[top];
        return res;
    }
}
bool isempty(){
   return top==-1;
}
int precedence(char c){
    if(c=='^')return 3;
    else if(c=='*' ||c=='/')return 2;
    else if(c=='+' ||c=='-')return 1;
    else return -1;
}
void Infix_to_Postfix(char infix[]){
   char postfix[100];
    int i=0;
    int j=0;
    while(infix[i]!='\0'){
        if(infix[i]>='a' && infix[i]<='z' || infix[i]>='A' && infix[i]<='Z'){
            postfix[j]=infix[i];
            i++;
            j++;
        }
        else if(infix[i]=='('){
            Push(infix[i]);
            i++;
        }
        else if(infix[i]==')'){
            while(Top()!='('){
                postfix[j]=pop();
                j++;
            }
            pop();
            i++;
        }
        else{
            if(precedence(infix[i])>precedence(Top())){
                Push(infix[i]);
                i++;
            }
            else{
            	while(precedence(infix[i])<=precedence(Top())){
            		postfix[j]=pop();
            		j++;
				}
				Push(infix[i]);
				i++;
			}
            //   Push(infix[i]);
            
        }
    }
        while(!isempty()){
            postfix[j]=pop();
            j++;
        }
        postfix[j]='\0';
         for(i = 0 ; postfix[i]!='\0' ; i++){
             printf("%c ",postfix[i]);
             }
}

int main() {
    char infix[100];
    scanf("%s",infix);
    Infix_to_Postfix(infix);
}
