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
node ins_pos(node first,int val,int pos);
node del_front(node first);
node del_end(node first);
node del_pos(node first,int val);
void display(node first);

node first = NULL;

int main(){
	int i, x, val,pos;
	
	while(x != 8){
		printf("1: Enter val from front\n");
		printf("2: Enter val from end\n");
		printf("3: Display\n");
		printf("4: insert pos\n");
		printf("5: delete front\n");
		printf("6: delete end\n");
		printf("7: delete pos\n");
		printf("8: exit\n");
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
			case 4:printf("Enter value from val: ");
				scanf("%d", &val);
				printf("Enter value from pos: ");
				scanf("%d", &pos);
				first = ins_pos(first,val,pos);
				break;
			case 5:first = del_front(first);
				break;
			case 6:first = del_end(first);
				break;
			case 7:printf("Enter value from pos: ");
				scanf("%d", &pos);
				first = del_pos(first,pos);
				break;
			case 8:printf("Invalid\n");
				exit(1);
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
		printf("\n");
	}

node ins_pos(node first,int val,int pos)
{
	node temp;
	node temp1 = first;
	node prev = NULL;
	int count=1;
	temp = get_node();
	temp->val = val;
	temp->next=NULL;
	while(count<pos && temp1->next!=NULL)
	{
		prev = temp1;
		temp1=temp1->next;
		count++;
	}
	if(temp1->next==NULL)
	{
		printf("invalid");
		return first;
	}
else {
	prev->next=temp;
	temp->next=temp1;
	return first;
	}
}

node del_front(node first)
{
	node temp=first;
	if(first==NULL) {
		printf("empty");
		return first;
	}
else {
	first=first->next;
	printf("the elements %d is deleted\n",temp->val);
	temp->next=NULL;
	free(temp);
	return first;
	}
}

node del_end(node first)
{
	node temp=first;
	node prev = NULL;
	if(first==NULL)
	{
		printf("EMpty");
		return first;
	}
else {
	while(temp->next!=NULL)
	{
		prev = temp;
		temp=temp->next;
	}
	printf("the element deleted is %d\n",temp->val);
	prev->next=NULL;
	free(temp);
	return first;
	}
}

node del_pos(node first,int pos)
{
	node temp1 = first;
	node prev = NULL;
	int count=1;
	while(count<pos && temp1->next!=NULL)
	{
		prev = temp1;
		temp1=temp1->next;
		count++;
	}
	if(temp1->next==NULL)
	{
		printf("invalid");
		return first;
	}
else {
	printf("the element deleted is %d\n",temp1->val);
	prev->next=temp1->next;
	temp1->next=NULL;
	free(temp1);
	return first;
	}
}

	
	
	 

