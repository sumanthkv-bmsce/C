#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *rlink;
	struct node *llink;
};

typedef struct node* node;
node getnode();
node head = NULL;
node ins_fro(node,int);
node ins_end(node,int);
void display(node);
node ins_pos(node,int,int);
node del_fro(node);
node del_end(node);
node del_ele(node,int);
int main()
{
	int ch,ele,pos;
	do {
		printf(" 1 to insertfront\n 2 to insertend\n 3 to display\n 4 to insert pos\n 5 to deletefront\n 6 to deleteend\n 7 todelete pos\n ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the element to be inserted in front\n");
				scanf("%d",&ele);
				head = ins_fro(head,ele);
				printf("%d inserted successfully\n",ele);
				break;
			case 2: printf("Enter the element to be inserted in end\n");
				scanf("%d",&ele);
				head = ins_end(head,ele);
				printf("%d inserted successfully\n",ele);
				break;
			case 3: display(head);
				break;
			case 4: printf("Enter element to be inserted\n");
				scanf("%d",&ele);
				printf("Enter position\n");
				scanf("%d",&pos);
				head = ins_pos(head,ele,pos);
				break;
			case 5: head = del_fro(head);
				break;
			case 6: head = del_end(head);
				break;
			case 7: printf("Enter element\n");
				scanf("%d",&ele);
				head = del_ele(head,ele);
				break;
			case 8: exit(1);
		}
	}while(ch!=9);
}

node getnode()
{
	node temp;
	temp = (node)malloc(sizeof(node));
	temp->rlink = NULL;
	temp->llink = NULL;
	return temp;
}

node ins_fro(node head,int ele)
{
	node temp;
	temp = getnode();
	temp->data = ele;
	if(head==NULL)
	{
		head = temp;
	}
   else
	{
		temp->rlink=head;
		head->llink = temp;
		temp->llink = NULL;
		head = temp;
	}
	return head;
}

node ins_end(node head,int ele)
{
	node temp1;
	node temp2;
	temp1=getnode();
	temp1->data = ele;
	if(head==NULL)
	{
		head = temp1;
	}
  else
	{
		temp2 = head;
		while(temp2->rlink!=NULL)
		{
			temp2 = temp2->rlink;
		}
		temp2->rlink = temp1;
		temp1->llink = temp2;
	}
	return head;
}

void display(node head) {
	node temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->rlink;
	}
	printf("\n");
}

node ins_pos(node head,int ele,int pos) {
	node temp;
	node curr=head;
	node prev=NULL;
	int count=1;
	temp = getnode();
	temp->data = ele;
	if(head==NULL) {
		printf("Empty\n");
	}
   else {
		while(count<pos && curr!=NULL)
		{
			prev = curr;
			curr=curr->rlink;
			count++;
		}
		if(curr==NULL && count<pos) {
			printf("Not possible\n");
		}
	else if(curr==NULL && count==pos) {
		prev->rlink=temp;
		temp->llink = prev;
		printf("%d inserted successfully in %d positon\n",ele,pos);
	}
	else {
		temp->rlink = curr;
		temp->llink = (curr->llink);
		(curr->llink)->rlink = temp;
		curr->llink = temp;
		printf("%d inserted successfully in %d positon\n",ele,pos);
	     }
	}
	return head;
}

node del_fro(node head) {
	node temp=head;
	if(head==NULL) {
		printf("Empty\n");
	}
  else {
		printf("%d deleted successfully\n",head->data);
		head = head->rlink;
		head->llink = NULL;
		free(temp);
	}
	return head;
}

node del_end(node head) {
	node temp=head;
	if(head==NULL) {
		printf("Empty\n");
	}
  else {
		while(temp->rlink!=NULL)
		{
			temp=temp->rlink;
		}
		printf("%d deleted successfully\n",temp->data);
		(temp->llink)->rlink = NULL;
		free(temp);
	}
	return head;
}

node del_ele(node head,int ele) {
	node temp=head;
	if(head==NULL) {
		printf("Empty\n");
	}
  else {
		while(temp->data!=ele && temp->rlink!=NULL)
		{
			temp=temp->rlink;
		}
		if(temp->data==ele && temp->rlink==NULL) {
			printf("%d deleted successfully\n",temp->data);
			(temp->llink)->rlink=NULL;
			temp->llink = NULL;
			free(temp);
		}
	else if(temp->data!=ele && temp->rlink==NULL)
		{
 			printf("Invalid\n");
		}
	else if(temp->data==ele && temp->llink==NULL) {
		printf("%d deleted successfully\n",temp->data);
		head=temp->rlink;
		(temp->rlink)->llink=NULL;
		free(temp);
	}
	else {
		 printf("%d deleted successfully\n",temp->data);
		(temp->llink)->rlink = temp->rlink;
		(temp->rlink)->llink = temp->llink;
		free(temp);
	}
   }
	return head;
}
