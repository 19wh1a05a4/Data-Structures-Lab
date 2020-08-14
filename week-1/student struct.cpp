#include<stdio.h>
struct student
{
	char rollno[20];
	char name[30];
	int m[5];
};
int main()
{
	struct student a[20];
	int n,i,j;
	float avg,sum=0;
	char grade;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",a[i].rollno);
		scanf("%s",a[i].name);
		for(j=0;j<5;j++)
		{
			scanf("%d",&a[i].m[j]);
			sum +=a[i].m[j];
		}
		avg = sum/5.0;
		if(avg>=50.0)
		grade = 'A';
		else
		grade= 'B';
		printf("rollno=%s\tname=%s\tgrade=%c\n",a[i].rollno,a[i].name,grade);
	}	
}
