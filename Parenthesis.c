/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<stdio.h>
#include<string.h>
#define Maximum_Stack 10

char stack[Maximum_Stack];
int TOP;


void push(char s)
{
    if (TOP == (Maximum_Stack - 1))
    {
        printf ("Stack is Full\n");
    }
    else
    {
        TOP = TOP + 1;
        stack[TOP] = s;
    }
}

void pop()
{
    if (TOP == - 1)
    {
        printf ("Stack is Empty\n");
    }
    TOP--; 
}

int main()
{
    char Expression[Maximum_Stack];
    int i = 0;
    TOP = -1;
    printf("Enter the Expression : ");
    scanf("%s", Expression);
    for(i = 0;i < strlen(Expression);i++)
    {
        if(Expression[i] == '(' || Expression[i] == '[' || Expression[i] == '{')
        {
            push(Expression[i]);
            continue;
        }
        else if(Expression[i] == ')' || Expression[i] == ']' || Expression[i] == '}')
        {
            if(Expression[i] == ')')
            {
                if(stack[TOP] == '(')
                {
                    pop();
                }
                else
                {
                    printf("Unbalanced Expression\n");
                    break;
                }
            }
            if(Expression[i] == ']')
            {
                if(stack[TOP] == '[')
                {
                    pop();
                }
                else
                {
                    printf("Unbalanced Expression\n");
                    break;
                }
            }
            if(Expression[i] == '}')
            {
                if(stack[TOP] == '{')
                {
                    pop(); 
                }
                else
                {
                    printf("Unbalanced Expression\n");
                    break;
                }
            }
        }
    }
    if(TOP == -1)
    {
        printf("Balanced Expression\n");
    }
}
