#include<stdio.h>

struct Node
{
   int data;
   struct Node *next;
};
typedef struct Node* node;
node front = NULL;
node rear = NULL;

void insert(int);
void delete();
void display();
node getnode();

void main()
{
   int choice, value;
   while(1){
      printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice){
	 case 1: printf("Enter the value to be insert: ");
            scanf("%d", &value);
            insert(value);
            break;
	 case 2: delete(); break;
	 case 3: display(); break;
	 case 4: exit(0);
	 default: printf("\nWrong selection!!! Please try again!!!\n");
      }
   }
}

node getnode()
{
    node temp = NULL;
    temp = (node)malloc(sizeof(node));
    temp->next = NULL;
    return temp;
}

void insert(int value)
{
   node newNode;
   newNode = getnode();
   newNode->data = value;
   if(front == NULL)
   {
      front  = newNode;
      rear = newNode;
   }
   else{
      rear -> next = newNode;
      rear = newNode;
   }
   printf("\nInsertion is Success!!!\n");
}
void delete()
{
   if(front == NULL)
      printf("\nQueue is Empty!!!\n");
   else{
      node temp = front;
      front = front -> next;
      printf("\nDeleted element: %d\n", temp->data);
      free(temp);
   }
}
void display()
{
    node temp = front;
   if(front == NULL)
      printf("\nQueue is Empty!!!\n");
   else{
      while(temp->next != NULL){
	 printf("%d--->",temp->data);
	 temp = temp -> next;
      }
      printf("%d--->NULL\n",temp->data);
   }
}
