#include <stdio.h>
#define MAXSIZE 20
void enqueue(int[],int *);
void dequeue(int[],int *,int *);
void new(int[],int *,int *);

int main(void) {
	int queue[MAXSIZE],front=0,rear=-1,ch;
	do{
        printf("Enter 1 to enqueue or 2 to dequeue or 3 to display new updated queue\n");
	    scanf("%d",&ch);
	    switch(ch) {
	        case 1:enqueue(queue,&rear);
	                break;
	         case 2:dequeue(queue,&front,&rear);
	                break;
	         case 3:new(queue,&front,&rear);
	                break;

	    }
	}while(ch==1 || ch==2 ||ch==3);

}

void enqueue(int queue[],int *rear) {
    int item;
    if(*rear==MAXSIZE-1) {
        printf("Overflow\n");
    }
else {
    printf("Enter the item to be inserted: \n");
    scanf("%d",&item);
    queue[++(*rear)] = item;
}
}

void dequeue(int queue[],int *front,int *rear) {
    if(*front>*rear) {
        printf("Underflow\n");
    }
else {
    (*front)++;
}
}

void new(int queue[],int *front,int *rear) {
    int ele,i,flag,j,newqueue[MAXSIZE],k=0;
    if(*front>*rear) {
        printf("Empty\n");
    }
else {
    for(i=*front;i<=*rear;i++) {
        flag=1;
        ele = queue[i];
        for(j=1;j<=10;j++) {
            if(ele%j!=0) {
                flag=0;
                break;
            }
        }
        if(flag==1) {
            newqueue[k++] = ele;
        }
    }
}
    if(k==0) {
        printf("No such elements present!!!!\n");
    }
else {
    for(i=0;i<k;i++) {
    printf("%d ",newqueue[i]);
    }
}
printf("--------------------------------------------------------------------------------");
}

