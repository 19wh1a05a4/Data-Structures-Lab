#include<stdio.h>
int linear_search(int n,int a[50],int key)
{
	static int i;
	if(i<n)
	{
	if(a[i]== key)
			return i;
	else 
	{
		i++;
		linear_search(n,a,key);
	}
	}
	else
	return -1;
}
int main()
{
	int i,n,pos,key,a[50];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	scanf("%d",&key);
	pos = linear_search(n,a,key);
	if (pos == -1)
	printf("elementy not found");
	else
	printf("element found at position %d location",pos + 1);
}
