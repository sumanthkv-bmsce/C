#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node *node;
node top = NULL;
node push(node,int);
node pop(node);
void display(node);
int main()
{
    int ch,item;
    do {
        printf(" 1 to push\n 2 to pop \n 3 display\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the item to insert\n");
                    scanf("%d",&item);
                    top = push(top,item);
                    break;
            case 2: top = pop(top);
                    //printf("%d",item);
                    break;
            case 3: display(top);
                    break;
            default: exit(1);
        }

    }while(ch!=4);
}

node getnode()
{
    node temp = NULL;
    temp = (node)malloc(sizeof(node));
    temp->next=NULL;
    return temp;
}
node push(node top,int item)
{
    node temp;
    temp=NULL;
    temp = getnode();
    temp->data = item;
    if(top==NULL) {
        top = temp;
    }
else {
    temp->next=top;
    top = temp;
}
return top;
}

node pop(node top)
{
    node temp=top;
    int item;
    if(top==NULL) {
        printf("Empty\n");
    }
else {
    top = top->next;
    item = temp->data;
    //temp->next=NULL;
    printf("popped element is %d \n",item);
    free(temp);
}
return  top;
}

void display(node top)
{
    node temp;
    if(top==NULL) {
        printf("Empty\n");
    }
else {
    temp=top;
    while(temp!=NULL) {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
printf("\n");

}
