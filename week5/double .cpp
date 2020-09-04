#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data ;
	struct node*prev;
	struct node*next;
};
struct node *head = NULL, *tail = NULL , *cur,*t1,*t2;

void create()
{
	int n;
	printf("enter num of nodes\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		cur = (struct node*)malloc(sizeof(struct node));
		printf("enter cur node data\n");
		scanf("%d",&(cur -> data));
		cur -> prev= NULL;
		cur -> next = NULL;
		if(head == NULL)
			head = tail= cur;
		else
		{
			tail -> next = cur;
			cur -> prev = tail;
			tail = cur;
		}
	
	}
}

void insert_atbegin()
{
	cur=(struct node*)malloc(sizeof(struct node));
	printf("enter the node to be insert\n");
	scanf("%d",&(cur-> data));
	cur -> prev = NULL;
	cur -> next = head;
	head -> prev = cur;
	head = cur;
}

	
void insert_atend()
{
	cur=(struct node*)malloc(sizeof(struct node));
	printf("enter the node to be insert\n");
	scanf("%d",&(cur-> data));
	cur -> next = NULL;
	cur ->prev = tail;
	tail -> next = cur; 
	tail = cur;
}

void insert_atpos()
{
	int c=1,pos;
	cur = (struct node*)malloc(sizeof(struct node));
	printf("\n enter the data node:\n");
	scanf("%d",&cur -> data);
	t1 = head;
	printf("enter the pos ");
	scanf("%d",&pos);
	while(c < pos && t1 != NULL) 
	{
		t2 = t1;
		t1  = t1 -> next;
		c++;
	}
	t2 -> next = cur;
	cur -> next = t2;
	cur -> next = t1;
	t1 -> prev = cur;
}


void  insert_before()
{
	int value;
	cur = (struct node*)malloc(sizeof(struct node));
	printf("enter the data node:\n");
	scanf("%d",&(cur -> data));
	printf("nenter the value before which node we need to perform inesertion\n");
	scanf("%d",&value);	
	t1 = head;
	while(t1 -> data != value && t1 != NULL) 
	{
		t2 = t1;
		t1  = t1 -> next;
	}
	t2 -> next = cur;
	cur -> prev = t2; 
	cur -> next = t1;
	t1 -> prev = cur;
}



void insert_after()
{
	int value;
	cur = (struct node*)malloc(sizeof(struct node));
	printf("enter the data node:\n");
	scanf("%d",&(cur -> data));
	printf("enter the value after which node we need to perform insertion\n");
	scanf("%d",&value);	
	t1 = head;
	while(t1 -> data != value && t1 != NULL) 
	{
		
		t1  = t1 -> next;
	}
	t2 = t1 -> next;
	cur -> next = t2;
	t2 -> prev = cur ;
	t1 -> next =  cur;
	cur -> prev = t1;
}


void del_atbegin()
{
	cur= head;
	head = head -> next;
	head -> prev = NULL;
	cur -> next = NULL;
	printf("del %d", cur -> data);
	free(cur);
}
	
	
void del_atend()
{
	cur = tail;
	tail = tail -> prev;
	tail -> next = NULL;
	cur -> prev = NULL;
	printf("del elem %d " ,cur -> data);
	free(cur);
}


void del_atpos()
{
	int c=1,pos;
	int value;
	t1 = head;
	printf("enter the pos ");
	scanf("%d",&pos);
	while(c < pos && t1 != NULL) 
	{
		t2 = t1;
		t1  = t1 -> next;
		c++;
	}
	t2 -> next =t1 -> next;
	t1 -> next -> prev = t2;
	printf("del data is %d",t1 -> data);
	free(t1);
}



void del_before()
{
	int value;
	printf("\nenter before which node we to del\n");
	scanf("%d",&value);
	t1 = head;
	while(t1 -> next -> data != value && t1 -> next != NULL) 
	{
		t2 =t1;
		t1 = t1 -> next;
	}
	t2 -> next = t1 -> next;
	t1 -> next -> prev = t2;
	printf("del data is %d",t1 -> data);
	free(t1);
}


void del_after()
{
	int value;
	printf("\nenter after which node we to del\n");
	scanf("%d",&value);
	t1 = head;
	while(t1 != NULL && t1 -> data != value )
	{
		t1 = t1 -> next; 
	}
	t2 = t1 -> next;
	t1 -> next = t2 -> next;
	t2 -> next -> prev = t1;
	printf(" del element %d",t2 -> data);
	free(t2);
}




void display()
{
	if (head== NULL) 
		printf("DLL is empty");
		
    else 
    {
    	cur = head;
    	printf("\nthe data elements are :\n");
    	while(cur != NULL ) 
    	{
    		printf("%d <->",cur -> data);
    		cur = cur -> next;
		}
    }
}


void display_reverse()
{
	if (head== NULL) 
		printf("DLL is empty");
		
    else 
    {
    	cur = tail;
    	printf("\nthe data elements are :\n");
    	while (cur != NULL) 
    	{
    		printf("%d<-> ",cur -> data);
    		cur = cur -> prev;
		}
    }
}

void search()
{
	float value,flag = 0,c=1;
	printf("enter value to be searched");
	scanf("%d",&value);
	t1 = head;
	while(t1 != NULL)
	{
		if (t1 -> data == value )
		{
			flag = 1;
			break;
		}
		t1 = t1 -> next;
		c++;
	}
	if (flag == 1)
	printf("elem present in list at %d pos\n",c);
	else
	printf("elem not found \n");
}



void sorting()
{
	struct node*p1,*p2,*last = NULL ;
	int c,t;
	do
	{
		c= 0;
		p1 = head;
		while(p1 -> next != last)
		{
			if(p1 -> data > p1 -> next -> data)
			{
				t = p1 -> data;
				p1 -> data = p1 -> next -> data;
				p1 -> next -> data = t;
				c = 1;
			}
			p1 = p1 -> next;
		}
		last = p1;
	}while(c);
}




int main()
{
	int ch;
	while(1)
	{
		printf("program for double list \n");
		printf("1 create\n2-insert at begin\n3-insert at position\n4-insert at end\n5-insert before");
		printf("\n6-insert after\n7 del at begin\n8-delete at end\n9- delete at pos\n10 - delete before\n");
		printf("11- delete after\n12-display\n13  dispaly in reverse\n14-search\n15-sort\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create();
					break;
			case 2: insert_atbegin();
					break;
			case 3 : insert_atpos();
					break;
			case 4 : insert_atend();
					break;
			case 5 : insert_before();
					break;
			case 6 : insert_after();
					break;
			case 7 : del_atbegin();
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
			case 13 :display_reverse( );
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
