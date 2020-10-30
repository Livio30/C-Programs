#include <stdio.h>
#define maxSize 10
//STACK 1
int isFull_1();
void push_1(int);
int isEmpty_1();
int pop_1();
void show_1();
int stack_1[maxSize];
int topOfStack_1 = 0;
//STACK 2
int isFull_2();
void push_2(int);
int isEmpty_2();
int pop_2();
void show_2();
int stack_2[maxSize];
int topOfStack_2 = 0;
//STACK 3
int isFull_3();
void push_3(int);
int isEmpty_3();
int pop_3();
int stack_3[maxSize];
int topOfStack_3 = 0;
//STACK 4
int isFull_4();
void push_4(int);
int isEmpty_4();
int pop_4();
int stack_4[maxSize];
int topOfStack_4 = 0;
//Function to Compare Stacks
char* stackEqual();

int main(){
	int ch = 0, item;
	 do{
        printf("\n1.PUSH in Stack 1\n");
        printf("2.POP from Stack 1\n");
				printf("3.Display stack 1\n");
        printf("4.PUSH in Stack 2\n");
        printf("5.POP from Stack 2\n");
        printf("6.Display stack 2\n");
        printf("7.Compare Stacks\n");
        printf("8.Exit\n");
        printf("\n Enter your choice of operations : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
         		 		printf("\nEnter the element to be pushed in Stack 1 : ");
                scanf("%d", &item);
                push_1(item);
                break;
            case 2:
            if(isEmpty_1()){
        					printf("\nStack is EMPTY\n");
            		}else{
 									printf("\nElement deleted : %d", pop_1());
            		}
                break;
            case 3:
            		show_1();
            		break;
            case 4:
            		printf("\nEnter the element to be pushed in Stack 2 : ");
                scanf("%d", &item);
                push_2(item);
                break;
            case 5:
            		if(isEmpty_2()){
        					printf("\nStack is EMPTY\n");
            		}else{
 									printf("\nElement deleted : %d", pop_2());
            		}
                break;
            case 6:
            		show_2();
            		break;
            case 7:
        				if(isEmpty_1()){
									printf("\nStack 1 is EMPTY\n");
									if(isEmpty_2()){
										printf("\nStack 2 is EMPTY\n");
									}
								}else{
										printf("\nStack 1 EQUAL TO Stack 2 : %s\n",stackEqual());
									}
                break;
            case 8:
            		ch = 8;
            		break;
            default:
                printf("\nIncorrect choice \n");
        } 
    }while( ch != 8);
    return 0;
}
//STACk 1
int isFull_1(){
    if(topOfStack_1 == maxSize)
    {
        return 1;
    }else{
        return 0;
    }
}
void push_1(int item){
    if(isFull_1())
    {
        printf("\nStack 1 is FULL\n");
        return;
    }
    stack_1[topOfStack_1++] = item;
}
int isEmpty_1()
{
    if(topOfStack_1==0)
        return 1;
    return 0;    
}
int pop_1(){
    return stack_1[--topOfStack_1];
}
void show_1(){
	int i ;
    if( isEmpty_1())
        printf("\nStack 1 is EMPTY\n");
    else{
        printf("\nStack 1 : ");
       	while(!(topOfStack_1 == 0)){
       		printf("%d ",pop_1());
				}
        printf("\n");
    }
}
//STACK 2
int isFull_2(){
    if(topOfStack_2 == maxSize)
    {
        return 1;
    }else{
        return 0;
    }
}
void push_2(int item){
    if(isFull_2())
    {
        printf("\nStack 2 is full\n");
        return;
    }
    stack_2[topOfStack_2++] = item;
}
int isEmpty_2()
{
    if(topOfStack_2 == 0)
        return 1;
    return 0;    
}
int pop_2(){
		return (stack_2[--topOfStack_2]);
}
void show_2(){
	int i ;
    if( isEmpty_2())
        printf("Stack 2 is EMPTY\n");
    else{
        printf("\nStack 2: ");
       	while(!(topOfStack_2 == 0)){
       		printf("%d ",pop_2());
				}
        printf("\n");
    }
}
//STACK 3
int isFull_3(){
    if(topOfStack_3 == maxSize)
    {
        return 1;
    }else{
        return 0;
    }
}
void push_3(int item){
    if(isFull_3())
    {
        printf("\nStack 3 is full\n");
        return;
    }
    stack_3[topOfStack_3++] = item;
}
int isEmpty_3()
{
    if(topOfStack_3 == 0)
        return 1;
    return 0;    
}
int pop_3(){
		return (stack_3[--topOfStack_3]);
}

//STACK 4
int isFull_4(){
    if(topOfStack_4 == maxSize)
    {
        return 1;
    }else{
        return 0;
    }
}
void push_4(int item){
    if(isFull_4())
    {
        printf("\nStack 4 is full\n");
        return;
    }
    stack_4[topOfStack_4++] = item;
}
int isEmpty_4()
{
    if(topOfStack_4 == 0)
        return 1;
    return 0;    
}
int pop_4(){
		return (stack_4[--topOfStack_4]);
}
//COMPARE FUNCTION	
char* stackEqual(){
	if(topOfStack_1	== topOfStack_2){
		while(!(topOfStack_1 == 0)){
			int elem_1 = pop_1();
			int elem_2 = pop_2();
			if(elem_1 == elem_2){
				push_3(elem_1);
				push_4(elem_2);
			}else{
					while(!(topOfStack_3 == 0)){
						push_1(pop_3());
						push_2(pop_4());
					}
				return "FALSE";		
			}
			continue;
		}
		while(!(topOfStack_3 == 0)){
			push_1(pop_3());
			push_2(pop_4());
		}
		return "TRUE";
	}
	return "FALSE";
}