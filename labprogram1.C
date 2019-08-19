#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAXSIZE 3
void push(int[],int *);
void pop(int[],int *);
void display(int[],int *);

int main()
{
  int stack[MAXSIZE],i,ch,top=-1;
  clrscr();
  do{
  printf("Enter 1 to push or 2 to pop or 3 to display or 4 for exit\n");
  scanf("%d",&ch);
  switch(ch)
  {
  case 1:push(stack,&top);
	 break;
  case 2:pop(stack,&top);
	 break;
  case 3:display(stack,&top);
	 break;
  case 4:printf("Invalid");
	 getch();
	 exit(1);
  }
  }while(ch==1||ch==2||ch==3||ch==4);
  return 0;
}
void push(int stack[MAXSIZE],int *top)
{
   int item;
   if(*top==MAXSIZE-1)
   {
	printf("Stack Overflow\n");
   }
else {
	printf("Enter the item to be inserted\n");
	scanf("%d",&item);
	(*top)++;
	stack[*top] = item;
 }
}

void pop(int stack[MAXSIZE],int *top)
{
   int item;
   if(*top==-1)
   {
	printf("Stack Underflow\n");
   }
else {
	item = stack[*top];
	(*top)--;
	printf("Popped element is %d\n",item);
  }
}
void display(int stack[MAXSIZE],int *top)
{
   int i;
   if(stack[0]==NULL)
   {
	printf("No element\n");
   }
else {
    for(i=*top;i>=0;i--)
    {
	printf("the element is %d \n",stack[i]);
    }
}
}



