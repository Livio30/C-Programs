#include <stdio.h>
#define maxSize 10
//INIT QUEUE
int isFull();
int isEmpty();
void enqueue(int);
int dequeue();
void show();
int queue[maxSize];
int qRear = -1;
int qFront = -1;
// INIT STACK
int isStackFull();
void push(int);
int isStackEmpty();
int pop();
int stack[maxSize];
int topOfStack = 0;
// QUEUE REVERSE
void qReverse();
// MAIN
int main(){
    int ch, item;
    do{
        printf("\n1.Enqueue Operation\n");
        printf("2.Dequeue Operation\n");
        printf("3.Display the Queue\n");
        printf("4.Reverse Queue\n");
        printf("5.Exit\n");
        printf("\n Enter your choice of operations : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("\nEnter the element to be inserted in the Queue : ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                printf("Element deleted : %d", dequeue());
                break;
            case 3:
                show();
                break;
            case 4:
                qReverse();
                break;
            case 5:
                ch = 5;
                break;
            default:
                printf("Incorrect choice \n");
        } 
    }while( ch != 5);
    return 0;
}
// QUEUE SECTION
int isFull(){
    if(qRear == maxSize -1)
        return 1;
    return 0;
}
void enqueue(int item){
    if(isFull()){
        printf("\nQueue is FULL\n");
    }
    else{
        if (qFront == -1)
            qFront = 0;
        qRear = qRear + 1;
        queue[qRear] = item;
    }
}

int isEmpty(){
    if(qFront == -1 || qFront > qRear)
        return 1;
    return 0;
}

int dequeue(){
    if(isEmpty()){
        printf("Queue is EMPTY");
    }else{
        return ( queue[qFront++]);
    }
}

void show(){
    if( isEmpty())
        printf("\nQueue is EMPTY\n");
    else{
        printf("\nQueue : ");
       	while(qFront <= qRear){
       		printf("%d ",dequeue());
				}
        printf("\n");
    }
}
//STACK SECTION
int isStackFull(){
    if(topOfStack == maxSize)
    {
        return 1;
    }else{
        return 0;
    }
}
void push(int item){
    if(isStackFull())
    {
        printf("Stack is full\n");
        return;
    }
    stack[topOfStack++] = item;
}
int isStackEmpty()
{
    if(topOfStack==0)
        return 1;
    return 0;    
}
int pop(){
    if(isStackEmpty()){
        printf("Stack is empty\n");
        return -1;
    }
    return stack[--topOfStack];
}
//QUEUE REVERSE
void qReverse(){
    if(isEmpty())
        printf("Queue is EMPTY\n");
    while(!(qFront == qRear + 1)){
        push(dequeue());
    }
		qRear = -1;
		qFront = -1;
  	while(!(isStackEmpty())){
        enqueue(pop());
    }
    printf("\nQueue Reversed\n");
}

