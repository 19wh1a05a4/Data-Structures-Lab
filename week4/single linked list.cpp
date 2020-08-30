#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data ;
	struct node * link;
};
struct node *head = NULL, *tail = NULL , *cur,*next ,*prev;



void create()
{
	int n,i;
	printf("enter the no of nodes:\n");
	scanf("%d",&n);
	for(i=0;i <n ;i++)
	{
		cur = (struct node*)malloc(sizeof(struct node));
		printf("enter current node data \n");
		scanf("%d",&(cur -> data));
		cur ->link = NULL;
		if(head == NULL)
		{
			head = tail = cur;
		}	
		else
		{
			tail -> link = cur;
			tail = cur;
		}
	}
}



void insertatbegin()
{
	cur=(struct node*)malloc(sizeof(struct node));
	printf("enter the node to be insert\n");
	scanf("%d",&(cur-> data));
	cur -> link = head;
	head = cur;
}



void insert_atpos()
{
	int pos,c=1;
	cur = (struct node*)malloc(sizeof(struct node));
	printf("\n enter the data node:\n");
	scanf("%d",&cur -> data);
	next = head;
	printf("enter the pos ");
	scanf("%d",&pos);
	while(c < pos) 
	{
		prev = next;
		next = next -> link;
		c++;
	}
	prev -> link = cur;
	cur -> link = next;
}



void insert_end()
{
	cur=(struct node*)malloc(sizeof(struct node));
	printf("enter data\n");
	scanf("%d",&(cur-> data));
	cur -> link = NULL;
	tail -> link= cur;
	tail= cur;
}


#include<stdio.h>
void insert_before()
{
	int value;
	cur = (struct node*)malloc(sizeof(struct node));
	printf("\nenter the data node:\n");
	scanf("%d",&cur -> data);
	
	printf("\nenter the value before which node we need to perform inesertion\n");
	scanf("%d",&value);
	next = head;
	while(next -> data != value && next != NULL)
	{
		prev = next;
		next = next -> link;
		
	}
	prev -> link = cur;
	cur -> link = next;
	
}



#include<stdio.h>
void insert_after()
{
	int value;
	cur = (struct node*)malloc(sizeof(struct node));
	printf("enter the data node:\n");
	scanf("%d",&cur -> data);
	
	printf("\nenter the value before which node we need to perform inesertion\n");
	scanf("%d",&value);
	next = head;
	while(next -> data != value && next != NULL)
	{
		next = next -> link;
		
	}
	cur -> link = next -> link;
	next -> link = cur;
}





void delete_atbegin()
{
	cur= head;
	head = cur -> link;
	cur -> link = NULL;
	printf("del element is %d\n",cur -> data);
	free(cur);
}



void del_atend()
{
	cur = head;
	while(cur -> link != tail)
		cur =cur -> link;
		
	cur -> link = NULL;
	next = tail;
	printf("del elements is %d ", tail -> data);
	free(next);
	tail = cur;
}




void del_atpos()
{
	int pos,c=1;
	next = head;
	printf("enter pos of deletion:\n");
	scanf("%d",&pos);
	while(c < pos) 
	{
		prev = next;
		next = next -> link;
		c++;
	}
	prev -> link = next -> link;
	printf(" del ele id %d\n", next -> data);
	next -> link = NULL;
	free(next);
}





void del_before()
{
	int value;
	next = head;
	printf("\nenter before which node we to del\n");
	scanf("%d",&value);
	while(next -> link -> data != value) 
	{
		prev = next;
		next = next -> link;
		
	}
	prev -> link = next -> link;
	next -> link = NULL;
	printf("\ndel ele id %d\n", next -> data);
	free(next);
}



void del_after()
{
	int value;
	printf("\nenter the value of data after which node should be del:\n");
	scanf("%d",&value);
	next = head;
	while(next -> data != value )
	{
		prev = next;
		next = next -> link;
	}
	prev = next -> link;
	next -> link = prev -> link;
	printf("del of elem %d", prev -> data);
	prev -> link = NULL;
	free(prev);
	
}





void display()
{
	if(head == NULL)
		printf("list is empty\n");
	else
	{
		next = head;
		printf("the data elements are");
		while(next != NULL)
		{
			printf("%d--- - >",next -> data);
			next = next -> link;
		}
	}
}



void reverse(struct node *head)
{
	prev = 0;
	cur = next = head;
	while(next != 0) 
	if(head != NULL)
	{
		next = next -> link;
		cur -> link = prev;
		prev = cur;
		cur = next;
	}
	head = prev;
	printf("/n after reversing :\n");
	display();
}




void search()
{
	int value;
	int flag = 0 ,c=0;
	printf("enter value\n");
	scanf("%d",&value);
	next = head;
	while(next != NULL)
	{
		if(next -> data ==  value)
		{
			flag = 1;
			break;
		}
		next = next -> link;
		c++;
	}
	if(flag == 1)
	{
		printf("at pos  = %d\n",c);
		
	}
	else
	{
		printf("elem not found\n");
	}
}




void sorting()
{
	struct node*p1,*p2;
	int c=0,i,t;
	p1=head;
	while(p1 != NULL)
	{
		c++;
		p1 = p1-> link;	
	}	
	for(int i = 0; i <= c ; i ++)
	{
		p2 = head;
		while(p2 -> link != NULL)
		{
			if(p2 -> data > p2 -> link -> data)
			{
				t = p2-> data;
				p2 -> data = p2 -> link ->data;
				p2 -> link -> data = t; 
			}
			
		}	
	}p2 = p2-> link;
	
	
}






int main()
{
	int ch;
	while(1)
	{
		printf("program for single list \n");
		printf("1 create\n2-insert at begin\n3-insert at position\n4-insert at end\n5-insert before");
		printf("\n6-insert after\n7 del at begin\n8-delete at end\n9- delete at pos\n10 - delete before\n");
		printf("11- delete after\n12-display\n13 - reverse\n14-search\n15-sort\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : create();
					break;
			case 2 : insertatbegin();
					break;
			case 3 : insert_atpos();
					break;
			case 4 : insert_end();
					break;
			case 5 : insert_before();
					break;
			case 6 : insert_after();
					break;
			case 7 : delete_atbegin();
					break;
			case 8 : del_atend();
					break;
			case 9 : del_atpos();
					break;
			case 10 : del_before();
					break;
			case 11 : del_after();
					break;
			case 12 :display();
					break;
			case 13 :reverse( head);
					break;	
			case 14:search();
					break;
			case 15: sorting();
					break;
			case 16: exit(0);
			
		}
		
	}
	return 0;
}


