#include<stdio.h>
struct complex
{
	int real,imag; 
};
void add(struct complex c1,struct complex c2)
{
	printf("%d+i%d\n",c1.real+c2.real,c1.imag+c2.imag);
}
int main()
{
	struct complex c1,c2;
	scanf("%d",&c1.real);
	scanf("%d",&c1.imag);
	scanf("%d",&c2.real);
	scanf("%d",&c2.imag);
	add(c1,c2);
}
