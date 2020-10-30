#include <stdio.h>
#include<string.h>
#define Maximum_Size 20

int TOP = 0;
int Stack[Maximum_Size];

void push(int value)
{
    if (TOP == (Maximum_Size - 1))
    {
        printf ("Stack is Full\n");
        return;
    }
    Stack[TOP++] = value;
}

int pop()
{
    if (TOP == -1)
    {
        printf ("Stack is Empty\n");
    }
    return Stack[--TOP];
}


void EvaluatePostfix(char expression[]){
	int i;
	int x , y;
	char ch;
	int val;
	for(i=0; i<strlen(expression);i++){
		ch = expression[i];
		if(ch>=48 && ch <=57){
			push(ch -'0');
		}else if (ch == '+' || ch == '-' || ch == '*' || ch == '/'){
			x = pop();
			y = pop();
			
			switch(ch){
				case '+': val = y + x;
							break;
				case '-': val = y - x;
							break;
				case '*': val = y * x;
							break;
				case '/': val = y / x;
							break;
				default : printf("invalid operator\n");												
			}
			push(val);
		}
	}
	printf("Result: %d\n",pop());
}

int main(){
	char expression[Maximum_Size];
	
	printf("Enter the expression: ");
	scanf("%s",expression);
	EvaluatePostfix(expression);
	return 0;	
}