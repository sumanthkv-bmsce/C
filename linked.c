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
node del_front(node first);
node del_end(node first);
void display(node first);
node concat(node first,node first1);
node sort(node first);
node reverse(node first);
node first = NULL;
node first1=NULL;
int main(){
	int i, x, val,pos,ch;
	
	while(x != 9){
		printf("1: Enter val from front1 or front2\n");
		printf("2: Enter val from end1 or end2\n");
		printf("3: Display\n");
		printf("4: delete front\n");
		printf("5: delete end\n");
		printf("6: concat\n");
		printf("7: sort\n");
		printf("8: reverse\n");
		printf("9: exit\n");
		scanf("%d", &x);
			switch(x){
			case 1:
				printf("Enter value from front: ");
				scanf("%d", &val);
				printf("Enter 1 to 1st list or 2 to second list\n");
				scanf("%d",&ch);
				if(ch==1) {
				first = ins_front(first, val);
				printf("%d inserted successfully in list1\n",val);
				}
			else {
				first1 = ins_front(first1,val);
				printf("%d inserted successfully in list2\n",val);
			}
				break;
				
			case 2:
				printf("Enter value from back: ");
				scanf("%d", &val);
				printf("Enter 1 to 1st list or 2 to second list\n");
				scanf("%d",&ch);
				if(ch==1) {
				first = ins_end(first, val);
				printf("%d inserted successfully in list1\n",val);
				}
			else {
				first1 = ins_end(first1,val);
				printf("%d inserted successfully in list2\n",val);
			}
				break;
				
			case 3: printf("Enter 1 to 1st list or 2 to second list\n");
				scanf("%d",&ch);
				if(ch==1) {
					display(first);
				}
			else {
				display(first1);
				}
				break;
			case 4: printf("Enter 1 to 1st list or 2 to second list\n");
				scanf("%d",&ch);
				if(ch==1)
				{
				first = del_front(first);
				}
			else {
				first1 = del_front(first1);
				}
				break;
			case 5: printf("Enter 1 to 1st list or 2 to second list\n");
				scanf("%d",&ch);
				if(ch==1)
				{
				first = del_end(first);
				}
			else {
				first1 = del_end(first1);
			}
				break;
			case 6:	
				first = concat(first,first1);
				break;
			case 7:	printf("Enter 1 to 1st list or 2 to second list\n");
				scanf("%d",&ch);
				if(ch==1)
				{
				first = sort(first);
				}
			else {
				first1 = sort(first1);
			}
				break;
			case 8:printf("Enter 1 to 1st list or 2 to second list\n");
				scanf("%d",&ch);
				if(ch==1)
				{
					first = reverse(first);
				}
			else {
				first1 = reverse(first1);
			}
				break;
			case 9:printf("Invalid\n");
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

node concat(node first,node first1)
{
	node temp=first;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next = first1;
	printf("concatanated successfully\n");
	return first;
}

node sort(node first)
{
	node temp1 = first;
	node temp2 = first->next;
	int temp;
	while(temp1->next!=NULL)
	{
		while(temp2!=NULL)
		{
			if(temp1->val>temp2->val)
			{
				temp = temp1->val;
				temp1->val=temp2->val;
				temp2->val=temp;
			}
			temp2=temp2->next;
		}
		temp1=temp1->next;
		temp2=temp1->next;
	}
	printf("Sorted successfully\n");
	return first;
}

node reverse(node first)
{
	node curr = first;
	node prev = NULL;
	node link=NULL;
	while(curr!=NULL)
	{
		link =curr->next;
		curr->next = prev;
		prev = curr;
		curr = link;
	}
	first = prev;
	return first;
}
		
