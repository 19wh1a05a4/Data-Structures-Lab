#include<stdio.h>
int binary_search(int first,int last,int a[50],int key)
{
	int pos = -1;
	while(first<= last)
	{
		int mid =(first+last)/2;
		if(a[mid] == key)
		{
			pos =mid;
			break;
		}	
		else if(a[mid] < key)
		{
		first = mid + 1;
		}	
		else
		{
			last = mid -1;
		}
	}
	return pos;	
	
}
int main()
{
	int i,n,pos,target,a[50];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	scanf("%d",&target);
	pos = binary_search(0,n-1,a,target);
	if (pos == -1)
	printf("element not found");
	else
	printf("element found at position",pos + 1);
}
