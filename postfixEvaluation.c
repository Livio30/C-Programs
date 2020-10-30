#include <stdio.h>
#include<string.h>
#define MAX_SIZE 100

int TOP = 0;
int STACK[MAX_SIZE];

void push(int sym){
    if(isStackFull())
    {
        printf("Stack is full\n");
        return;
    }
    STACK[TOP++] = sym;
    
    
}

int isStackFull(){
    if(TOP == MAX_SIZE)
    {
        return 1;
    }else{
        return 0;
    }
}

int pop(){
    if(isStackEmpty()){
        printf("Stack is empty\n");
        return -1;
    }
    return STACK[--TOP];
}

int isStackEmpty()
{
    if(TOP==0)
        return 1;
    return 0;    
}

void evalPost(char expres[]){
	int i;
	int a , b;
	char ch;
	int val;
	for(i=0; i<strlen(expres);i++){
		ch = expres[i];
		if(ch>=48 && ch <=57){
			push(ch -'0');
		}else if (ch == '+' || ch == '-' || ch == '*' || ch == '/'){
			a = pop();
			b = pop();
			
			switch(ch){
				case '+': val = b + a;
							break;
				case '-': val = b - a;
							break;
				case '*': val = b * a;
							break;
				case '/': val = b / a;
							break;
				default : printf("invalid operator\n");												
			}
			push(val);
		}
	}
	printf("Result: %d\n",pop());
}

int main(){
	char expres[MAX_SIZE];
	
	printf("Enter the expression: ");
	scanf("%s",expres);
	evalPost(expres);
	return 0;	
}