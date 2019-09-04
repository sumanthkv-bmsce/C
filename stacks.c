#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAXSIZE 15

char *pop(char sub[][MAXSIZE],int *k) {
    return sub[(*k)--];
}
void rpop(int rem[],int *j) {
    (*j)--;
}


int main(void) {
    unsigned long int n,i,rem[1000000],num,j=0,k=-1,min,l,diff,pos,count,o;
    char sub[MAXSIZE][MAXSIZE],*str;
    scanf("%lu\n",&n);
    for(i=0;i<n;i++) {
        scanf("%lu\n",&num);
        if(num!=-1) {
            rem[j++] = num;
            scanf("%s",sub[++k]);
        }
    else {
        min = rem[0];
        for(l=1;l<j;l++) {
            if(min>rem[l]) {
                min = rem[l];
                pos = l;
            }
        }
        diff = k-pos;
        printf("%lu ",diff);
        count = 0;
        while(count<=diff) {
            rpop(rem,&j);
            count++;
        }
        count = 0;
        while(count<diff) {
            str = pop(sub,&k);
            count++;
        }
        printf("%s\n",sub[k--]);
    }

    }
}


