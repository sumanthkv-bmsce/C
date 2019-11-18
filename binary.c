#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
	struct node *prev;
};

typedef struct node *node;
node root = NULL;
node getnode();
node insert(node,int);
void inorder(node);
void preorder(node);
void postorder(node);

int main() {
	int ch,ele;
	do {
		printf("\n1 to insert the node\n2 to inorderdisplay\n3 to preorderdisplay\n4 to postorderdisplay\n5 to exit\n");
		scanf("%d",&ch);
		switch(ch) {
			case 1: printf("Enter val: \n");
				scanf("%d",&ele);
				root = insert(root,ele);
				break;
			case 2: inorder(root);
				break;
			case 3: preorder(root);
				break;
			case 4: postorder(root);
				break;
			case 5:printf("Thank you\n");
				break;
		}
	}while(ch!=5);
}	

node getnode() {
	node temp;
	temp=(node)malloc(sizeof(node));
	temp->next=NULL;
	temp->prev=NULL;
	return temp;
}

node insert(node root,int val) {
	node temp;
	node trav,pre;
	temp = getnode();
	temp->data=val;
	if(root==NULL) {
		root = temp;
	}
  else {
  		trav = root;
  		pre = NULL;
  		while(trav!=NULL && trav!=NULL) {
  			pre = trav;
  			if(val<trav->data) {
  				trav = trav->prev;
  			}
  		else {
  			trav = trav->next;
  			}
  		}	
  		if(val<pre->data) {
  			pre->prev = temp;
  		}
  	else {
  		pre->next=temp;
  	}
  	}
  return root;
}

void inorder(node root) {
	node temp=root;
	if(temp->prev!=NULL) {
		inorder(temp->prev);
	}
	printf("%d ",temp->data);
	if(temp->next!=NULL) {
		inorder(temp->next);
	}
	
}
	
void preorder(node root) {
	node temp=root;
	printf("%d ",temp->data);
	if(temp->prev!=NULL) {
		inorder(temp->prev);
	}
	if(temp->next!=NULL) {
		inorder(temp->next);
	}
	
}

	
void postorder(node root) {
	node temp=root;
	if(temp->prev!=NULL) {
		inorder(temp->prev);
	}
	if(temp->next!=NULL) {
		inorder(temp->next);
	}
	printf("%d ",temp->data);
}

  	 		
  	
  	
  	
	
