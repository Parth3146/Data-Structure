#include<stdio.h>

int a[10],top=-1,i,n,op;

void push();
void pop();
void peep();
void change();
void display();

void main()
{
	do
	{
		printf("Select Operation:\n1.Push (Input)\n2.Pop (Delete)\n3.Peep\n4.Change\n5.Display\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1: push();
					break;
			case 2: pop();
					break;
			case 3: peep();
					break;
			case 4: change();
					break;
			case 5: display();
					break;
			default: printf("Enter valid input !!\n");
		}
		printf("Do You Want To Continue ?('1' for Yes / else for No): ");
		scanf("%d",&n);
	}while(n==1);
}

void push()
{
	if(top<=8)
	{
		top++;
		printf("Enter element to push: ");
		scanf("%d",&a[top]);
		display();
	}
	else
		printf("Stack is Full !! Can't push the element !\n");
}

void pop()
{
	if(top==-1)
		printf("Stack is Empty !!\n");
	else
	{
		a[top]=0;
		top--;
		display();
	}
}

void peep()
{	
	if(top==-1)
		printf("Stack is Empty !!\n");
	else
	{
		printf("%d",a[top]);
		display();
	}
}

void change()
{
	if(top==-1)
		printf("Stack is Empty !!\n");
	else
	{
		printf("Enter New Element: ");
		scanf("%d",&a[top]);
		display();
	}
}
	
void display()
{
	if(top==-1)
		printf("Stack is Empty !!\n");
	else
	{
		for(i=top;i>=0;i--)
		{
			printf("%d\n",a[i]);
		}
	}
}
