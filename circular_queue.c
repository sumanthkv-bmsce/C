#include<stdio.h>
#define MAX 3

void enqueue(int q[], int *f, int *r);
void dequeue(int q[], int *f, int *r);
void display(int q[], int *f, int *r);

void main(){
	int q[MAX], f=0, r=-1, choice, ele;
	do{
	printf("1. Enqueue\n2. Dequeue\n3. Display\n5. Exit\n");
	scanf("%d", &choice);
	
	switch(choice){
		case 1:
			enqueue(q, &f, &r);
			break;
		case 2:
			dequeue(q, &f, &r);
			break;
		case 3:
			display(q, &f, &r);
			break;
	}
	}while(choice !=5);
	
}

void enqueue(int q[], int *f, int *r){
	int ele;
	if((*r == MAX-1 && *f == 0)||(*r == (*f)-1 && *f>0)){
	        printf("%d, %d\n", *r, *f);
			printf("QUEUE IS FULL\n");
		
	}
	
	    
    else{
    	printf("%d, %d\n", *r, *f);
        printf("ENTER THE ELEMENT TO INSERT\n");
	    scanf("%d", &ele);
	    
    	if(*r==MAX-1 && *f >0){
    		*r=0;
		    q[*r] = ele;
    	}
    	
    	else{
    		if((*f==0&&*r==-1)||(*r!=*f-1)){
    			q[++(*r)] = ele;
    		}
    	}    	
	    
    }
		
}	
	


void dequeue(int q[], int *f, int *r){
	if((*f==0)&&(*r==-1)){
		printf("QUEUE EMPTY\n");
	}	
	if(*f==*r){
		printf("%d\n", q[*f]);
		*r=-1;
		*f=0;
		
	}
	else{
		if(*f==MAX -1){
			printf("%d\n", q[*f]);
			*f = 0;
			
		}
		else {
			printf("%d\n", q[(*f)++]);
		}
	}
}

void display(int q[], int *f, int *r){
	int i, j;
	if(*f==0&&*r==-1){
		printf("QUEUE EMPOTY\n");
	}
	if(*f>*r){
		for(i=0; i<=*r; i++){
			printf("%d\n", q[i]);
		}
		for(j=*f; j<=MAX-1; j++){
			printf("%d\n", q[j]);
		}
	}
	else{
		for(i=*f; i<=*r;i++){
			printf("%d\n", q[i]);
		}
	}
}