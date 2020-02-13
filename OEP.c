#include<stdio.h>
#include<malloc.h>

void display();
void add();

int a[50],n=0,i,j;
struct node
{
	int ce,exp;
	struct node *link;
}*header,*ptr,*newnode,*cpt,*ptr1;


void Del(struct node*cpt)
{
	ptr1=header;
	while(ptr1->link!=cpt)
		ptr1=ptr1->link;
	ptr1->link=cpt->link;
	free(cpt);
}

void display()
{
	printf("The Expressions are:\n");
	ptr=header->link;
	for(i=0;i<n;i++)
	{
		for(j=0;j<a[i];j++)
		{
			if(ptr->exp==0)
				printf(" + (%d)",ptr->ce);
			else if(ptr->ce==0)
				break;
			else
				printf(" + (%dX^%d)",ptr->ce,ptr->exp);
			ptr=ptr->link;
		}
		printf("\n");
	}
}

void add()
{
	ptr=header->link;
	while(ptr->link!=NULL)
	{
		cpt=ptr->link;
		while(cpt!=NULL)
		{
			if(cpt->exp==ptr->exp)
			{
				ptr->ce+=cpt->ce;
				Del(cpt);
				cpt=ptr1->link;
			}
			else
				cpt=cpt->link;
		}
		if(ptr->link!=NULL)
			ptr=ptr->link;
	}
	ptr=header->link;
	printf("Addition of Expressions:\n");
	while(ptr!=NULL)
	{
		if(ptr->exp==0)
			printf(" + (%d)",ptr->ce);
		else if(ptr->ce==0)
			break;
		else
			printf(" + (%dX^%d)",ptr->ce,ptr->exp);
		ptr=ptr->link;
	}
}

void main()
{
	ptr=(struct node*)malloc(sizeof(struct node));
	header=ptr;
	header->link=NULL;
	header->ce=header->exp=0;
	int m1,ans;
	do
	{
		printf("Enter number of elements: ");
		scanf("%d",&m1);
		a[n]=m1;
		n++;
		printf("Enter Co efficient and Exponential : ");
		for(i=0;i<m1;i++)
		{
			newnode=(struct node*)malloc(sizeof(struct node));
		    scanf("%d %d",&newnode->ce,&newnode->exp);
		    ptr->link=newnode;
		    ptr=ptr->link;
	    }
	    ptr->link=NULL;
	    printf("Continue adding expression ?(1=Yes): ");
	    scanf("%d",&ans);
	}while(ans==1);
	display();
	add();
}

