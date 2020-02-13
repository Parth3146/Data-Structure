#include<stdio.h>
#include<stdlib.h>
#define p printf
#define s scanf

int ar[100],max,flag=0,f=1,l;

void search(int f,int x,int l)
{
	if((l-f)/2==0)
	{
		p("\n Element not found\n");
		return;
	}
	else if(x==ar[f+((l-f)/2)])
	{
		flag=1;
		p("\nElement found\n");
		return;
	}
	else if(x>ar[f+((l-f)/2)])
	{
		f=f+((l-f)/2);
		search(f,x,l);
	}
	else if(x>ar[f+((l-f)/2)])
	{
		l=l-((l-f)/2);
		search(f,x,l);
	}
	else
	{
		p("Enter Proper Input !!");
	}
}

void main()
{
	int i,x;
	p("Enter Number of Elements: ");
	s("%d",&max);
	p("\nEnter Elements in Ascending Order\n");
	for(i=1;i<=max;i++)
		s("%d",&ar[i]);
	p("Value to Search: ");
	s("%d",&x);
	f=1;
	l=max;
	search(f,x,l);
}
		
