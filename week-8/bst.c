#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct BST
{
	int data;
	struct BST *left,*right;
}node;
struct BST* root=NULL,*temp,*cur;
void create()
{
	temp = root;
	cur = (struct BST*)malloc(sizeof(struct BST));
	printf("\n enter data:\n");
	scanf("%d",&cur->data);
	cur->left = NULL;
	cur->right = NULL;
	if(temp == NULL)
		root = cur;
	else
	{
		while(temp!=NULL)
		{
			if((cur->data) < (temp -> data))
			{
				if(temp -> left == NULL)
				{
					temp->left = cur;
					return;
				}
				else
					temp = temp -> left;
			}
			else
			{
				if(temp -> right ==NULL)
				{
					temp->right = cur;
					return;
				}
				else
					temp = temp ->right;
			}//else
		}//while
	}//else
}
void postorder(struct BST *temp)
{
	if(temp!= NULL)
	{
		postorder(temp -> left);
		postorder(temp -> right);
		printf("\t%d",temp -> data);
	}
}
void inorder(struct BST *temp)
{
	if(temp!=NULL)
	{
		inorder(temp->left);
		printf("\t%d",temp -> data);
		inorder(temp->right);
	}
}
int main()
{
	int ch;
	printf("\nmenu options\n");
	printf("1.create\n2.postorder\n3.exist\n");
	while(1)
	{
		printf("\nenter ur choice ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :create();// 2-preorder 3-inorder 4-postorder 5- exit
					break;
			case 2 :printf("postorder Traversal\n");
					postorder(root);
					break;
			case 3 : exit(0);
			default:printf("invalid choice\n");
		}//switch
	}//while
}
