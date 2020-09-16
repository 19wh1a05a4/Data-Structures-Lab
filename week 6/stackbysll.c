#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*link;
};
struct node *top = NULL,*cur;
void push()
{
	cur =(struct node*)malloc(sizeof(struct node));
	printf("enter cuu node data:\n");
	scanf("%d",&(cur -> data));
	cur -> link = top;
	top = cur;
}
void pop()
{
	
	cur = top;
	top = cur -> link;
	printf("del elem is :%d",(cur -> data));
	cur -> link = NULL;
	free(cur);
	
}



void display()
{
	if(top == NULL)
		printf("stack underflow:\n");
	else
	{
		cur = top;
		printf("stack");
		while(cur != NULL)
		{
			printf("%d",cur -> data);
			cur = cur -> link;
		}
	}
}

void peek()
{
	if(top != NULL)
		printf("the top most element is : %d",top -> data);
	else
		exit(1);
}





int main()
{
	int ch;
	while(1)
	{
		printf("functions for stack\n");
		printf("\n1-push\n2-pop\n3-display\n4-peek\n5-exit\n");
		printf("enter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:push();
					break;
			case 2: pop();
					break;
			case 3 : display();
					break;
			case 4 : peek();
					break;
			case 5 :exit(0);
		}
	}
}
