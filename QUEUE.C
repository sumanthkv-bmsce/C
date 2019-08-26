#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>
#define MAXSIZE 5
void enqueue(int[],int *);
void dequeue(int[],int *,int*);
void display(int[],int *,int *);

int main()
{
	int queue[MAXSIZE],ch,i,front=0,rear=-1;
	clrscr();
	do {
	printf("ENter the element 1 to enqueue or 2 to dequeue or 3 to display\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:enqueue(queue,&rear);
			break;
		case 2:dequeue(queue,&front,&rear);
			break;
		case 3:display(queue,&front,&rear);
			break;
		case 4: printf("Invalid\n");
			getch();
			exit(1);
	}
	}while(ch==1||ch==2||ch==3||ch==4);
	return 0;
}
void enqueue(int queue[MAXSIZE],int *rear)
{
	int item;
	if(*rear==MAXSIZE-1)
	{
		printf("QUEUE OVERFLOW\n");
	}
else {
	printf("Enter th element to be inserted\n");
	scanf("%d",&item);
	queue[++(*rear)]=item;
   }
}
void dequeue(int queue[MAXSIZE],int *front,int *rear)
{
	int item;
	if(*front>*rear)
	{
		printf("QUEUE UNDERFLOW\n");
	}
else {
	item = queue[(*front)++];
	printf("The element is %d\n",item);
	}
}
void display(int queue[MAXSIZE],int *front,int *rear)
{
	int i;
	if(*rear==-1)
	{
		printf("No elements\n");
	}
else {
	for(i=*front;i<=*rear;i++)
	{
		printf("the element is %d \n",queue[i]);
	}
  }
}