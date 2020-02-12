#include<stdio.h>

#define n 4

void insert();
void delete();
void display();

int cq[n],f=-1,r=-1,op,ans,i;

void main()
{
	do
	{
		printf("Select the operation:\n1.Insert\n2.Delete\n3.Display\n>");
		scanf("%d",&op);
		switch(op)
		{
			case 1 : insert();
					 break;
			case 2 : delete();
					 break;
			case 3 : display();
					 break;
			default: printf("Enter Valid input !!");
		}
	printf("\nDo you want to continue ?('1' for yes/else no): ");
	scanf("%d",&ans);
	}while(ans==1);
}

void insert()
{
	if(f==0 && r==n || f==(r+1))
	{
		printf("CQueue Overflow !!");
		return;
	}
	else if(r==-1 && f==-1)
		r=f=0;
	else if(r==n)
		r=0;
	else
		r++; 
	printf("Enter element to insert: ");
	scanf("%d",&cq[r]);
	display();
}

void delete()
{
	if(r==-1 && f==-1)
	{
		printf("Queue Underflow !!");
		return;
	}
	else
		cq[f]=0;
	if(f==r)
		f=r=-1;
	else if(f==n)
		f=0;
	else
		f++;
	display();
}

void display()
{
	if(r==-1 && f==-1)
		printf("Queue Is Empty !!");
	else if(f<=r)
	{
		printf("The Elements are:\n");
		for(i=f;i<=r;i++)
		{
			if(i==f && i==r)
				printf("%d__FRONT__REAR\n",cq[i]);
			else if(i==f)
				printf("%d__FRONT\n",cq[i]);
			else if(i==r)
				printf("%d__REAR\n",cq[i]);
			else
				printf("%d\n",cq[i]);
		}
	}
	else
	{
		printf("The elements are:\n");
		for(i=f;i<=n;i++)
		{
			if(i==f)
				printf("%d__FRONT\n",cq[i]);
			else
				printf("%d\n",cq[i]);
		}
		for(i=0;i<=r;i++)
		{
			if(i==r)
				printf("%d__REAR\n",cq[i]);
			else
				printf("%d\n",cq[i]);
		}
	}
}


