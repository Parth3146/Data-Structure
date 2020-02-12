#include<stdio.h>

int f=0,n,a[10],i,e,op,ad,ans;

void input();
void insert(int,int);
void delete(int);
int search();
void display();

void main()
{	
	do
	{
		printf("Select your operation:\n1.Input\n2.Insert Element\n3.Delete Element\n4.Search Element\n5.Display Array\n");
		scanf("%d",&op);
		switch(op)
			{
				case 1: input();
					display();
					break;
				case 2: if(n==10)
						printf("Array is full !!\n");
					else if(n<=0)
						printf("Array is empty !!\n");
					else
					{	
						printf("Enter element to insert and its position: ");
						scanf("%d %d",&e,&ad);
						if(ad>n)
							printf("Address is not found !!\n");
						else
						{
							insert(e,ad);
							display();
						}
					}
					break;
				case 3: if(n<=0)
						printf("Array is Empty !!\n");
					else
					{
						printf("Enter position of element to delete: ");
						scanf("%d",&ad);
						if(ad>n)
							printf("Address is not found !!\n");
						else
						{						
							delete(ad);
							display();
						}
					}
					break;
				case 4: if(n<=0)
						printf("Array is Empty !!\n");
					else
					{
						search();
						if(f!=0)
							printf("Position of the element %d is at %d\n: ",e,(i+1));
						else
							printf("Element not found !!\n");
						display();
					}
					break;
				case 5: if(n<=0)
						printf("Array is Empty !!\n");
					else
					{
						display();
					}
					break;
				default: printf("Enter valid input !\n"); 
			}
		printf("Do you want to continue ?('1' for yes / else for no): ");
		scanf("%d",&ans);							
	}while(ans==1);
}

void input()
{
	printf("Enter the number of elements(<=10): \n");
	scanf("%d",&n);
	if(n<=10 && n>=0)
	{
		printf("Enter the elements: \n");
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
	}
	else
		printf("Enter integer between 0 to 10 !!");
}

void insert(int e,int ad)
{
	for(i=n-1;i>=ad-1;i--)
	{
		a[i+1]=a[i];
	}
	a[ad-1]=e;
	n+=1;
}			

void delete(int ad)
{
	for(i=ad-1;i<=n-2;i++)
	{
		a[i]=a[i+1];
	}
	n-=1;					
}

int search()
{
	printf("Enter element to search: ");
	scanf("%d",&e);
	for(i=0;i<n;i++)
	{
		if(a[i]==e)
		{
			f++;
			goto retrn;
		}	
	}
	retrn:return(f);
}

void display()
{
	printf("The Elements are: \n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}

