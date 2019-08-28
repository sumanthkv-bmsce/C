#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAXSIZE 20
char pop(int[],int *);
void push(int[],int *,int);
int evaluate(int,int,char);

int main(void) {
    int i,top=-1,top1,top2,dch,total,ostack[MAXSIZE];
	char stack[MAXSIZE],ch,item1,item2;
	scanf("%s",stack);
	i=0;
	while(stack[i]!='\0') {
	    ch = stack[i];
	    switch(ch) {
	        case '+':
	        case '-':
	        case '*':
	        case '/':
	        case '^':item1 = pop(ostack,&top);
	                 item2 = pop(ostack,&top);
	                 total = evaluate(item1,item2,ch);
	                 push(ostack,&top,total);
	                 break;

	       default:break;
	    }

	    switch(ch) {
	        case '0':
	        case '1':
	        case '2':
	        case '3':
	        case '4':
	        case '5':
	        case '6':
	        case '7':
	        case '8':
	        case '9':   dch = ch-48;
	                    push(ostack,&top,dch);
	                    break;
	        default:break;
	    }
	    i++;
	}
	printf("%d",ostack[0]);
}
char pop(int ostack[], int *top) {
    char item;
    if(*top==-1) {
        printf("STack underflow\n");
    }
else {
    item = ostack[(*top)--];
    return item;
}

}

void push(int ostack[],int *top,int ch) {
    if(*top==MAXSIZE-1) {
        printf("Stack Overflow");
    }
else
    ostack[++(*top)] = ch;
}

int evaluate(int x,int y,char ch) {
    switch(ch) {
        case '+':return y+x;
                break;
        case '-': return y-x;
                break;
        case '*':return y*x;
                break;
        case '/':return y/x;
                break;
        case '^':return pow(y,x);
                break;
    }
}


