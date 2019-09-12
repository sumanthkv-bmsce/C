#include<stdio.h>
#include<conio.h>

void enter(int queue[], int *front, int *rear, int *count);
void leave(int queue[], int *front, int *rear);
void display(int queue[], int *front, int *rear);
void main(){
	int option = 0, queue[5], front = -1, rear = -1, count = 0;
	clrscr();
	while(option != 4){
		printf("Select one of the options:\n 1 :Walk-in\n 2 :Interview Done\n 3 :Show Waiting Room\n 4 :Leave WaitingRoom\n ");
		scanf("%d", &option);
		switch(option){
			case 1:
				enter(queue, &front, &rear, &count);
				break;
			case 2:
				leave(queue, &front, &rear);
				break;
			case 3 :
				display(queue, &front, &rear);
				break;
			}
		}
	}
void enter(int queue[5],int *front, int *rear, int *count){
	int token;
	if(((*rear) == 4 && (*front) == 0) || ((*rear) == (*front)-1))
		printf ("Room if full\nPlease come later.....\n\n");
	else{
		if(*rear == -1){
			*front = 0;
			*rear = 0;
			*count = 1;
			}
		else if(*rear == 4)
			*rear = 0;
		else
			(*rear)++;

		token = (*count);
		(*count)++;
		queue[(*rear)] = token;
		printf("Your token number: %d\n\n", token);
		}
	}
void leave(int queue[], int *front, int *rear){
	if(*front == -1)
		printf ("Room is Empty!!!\n\n");
	else{
		printf("Token number %d\nPlease proceed to the interview hall...\n\n", queue[*front]);
		if(*front==*rear){
			*front = -1;
			*rear = -1;
			}
		else if(*front==4)
			*front=0;
		else
			(*front)++;
		}
	}
void display(int queue[], int *front, int *rear){
	int i;
	if(*front == -1)
		printf ("Room is Empty!!!\n\n");
	else{
		if(*front < *rear){
			for(i = *front;i <= *rear;i++)
				printf("%d\n", queue[i]);
			}
		else{
			for(i = *front;i < 5; i++)
				printf("%d\n", queue[i]);
			for(i = 0;i <= *rear;i++)
				printf("%d\n", queue[i]);
			}
		}
	}
