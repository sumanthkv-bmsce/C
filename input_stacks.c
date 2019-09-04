#include <stdio.h>
#include <string.h>
#define MAXSIZE 10
void push(int[],int *);
void pop(int[],int *);
void display(int[],int *);

int main(void) {
    int stack[MAXSIZE],top=-1,ch;
    do{
        printf("Enter 1 to push or 2 to pop or 3 to display\n");
        scanf("%d",&ch);
        switch(ch) {
            case 1:push(stack,&top);
                   break;
            case 2:pop(stack,&top);
                   break;
            case 3:display(stack,&top);
                   break;
            default: break;
        }

    }while(ch==1|| ch==2 || ch==3);
}

void push(int stack[],int *top) {
    int item;
    if(*top==MAXSIZE-1) {
        printf("Full\n");
    }
else {
    printf("Enter the item: \n");
    scanf("%d",&item);
    stack[++(*top)] = item;
}
}

void pop(int stack[],int *top) {
    if(*top==-1) {
        printf("Empty\n");
    }
else {
    (*top)--;
}
}

void display(int stack[],int *top) {
    int i,min,count=0,pos[100],j=0,p,k;
    min = stack[0];
    for(i=1;i<=*top;i++) {
        if(min>stack[i]) {
            min = stack[i];
        }
    }
    for(i=0;i<=*top;i++) {
        if(min==stack[i]) {
            count++;
            pos[j++] = i;
        }
    }
    for(i=0;i<j;i++) {
        p = pos[i];
        for(k=p;k<=(*top-1);k++) {
            stack[k] = stack[k+1];
        }
        stack[*top] = min;
    }
    for(i=0;i<=*top;i++) {
        printf("%d ",stack[i]);
    }
    printf("\n");
}

