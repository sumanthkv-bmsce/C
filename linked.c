#include <stdio.h>
#include <stdlib.h>

struct node{
	int val;
	struct node *next;
	};
	
typedef struct node* node;

node get_node();
node ins_front(node first, int val);
node ins_end(node first, int val);
void display(node first);

node first = NULL;

int main(){
	int i, x, val;
	
	while(x != 4){
		printf("1: Enter val from front\n");
		printf("2: Enter val from end\n");
		printf("3: Display\n");
		printf("4: Exit\n");
		scanf("%d", &x);
			switch(x){
			case 1:
				printf("Enter value from front: ");
				scanf("%d", &val);
				first = ins_front(first, val);
				break;
				
			case 2:
				printf("Enter value from back: ");
				scanf("%d", &val);
				first = ins_end(first, val);
				break;
				
			case 3:
				display(first);
				break;
			}
		}
	}
		
node get_node(){
	node temp;
	temp = (node)malloc(sizeof(struct node));
	temp->next = NULL;
	return temp;
	}
	
	

node ins_front(node first, int val){
	node temp;
	if(first == NULL){
		first = get_node();
		first-> val = val;
		}
	else{
		temp = get_node();
		temp->val = val;
		temp->next = first;
		first = temp;
		
		}
	return first;	
	}

node ins_end(node first, int val){
	node temp, curr;
	if(first == NULL){
		first = get_node();
		first-> val = val;
		}
	else{
		curr  = first;
		while(curr->next != NULL){
			curr = curr->next;
			}
				 
		temp = get_node();
		temp->val = val;
		curr->next = temp;
		}
	return first;
	}
	
void display(node first){
	node curr;
	curr = first;
	while(curr != NULL){
		printf("%d ", curr->val);
		curr = curr->next;
		}
	}
