#include<stdio.h>

struct employee
{
	char name[20];
	int id,pno,salary;
}e[5];

void main()
{
	int i;
	for(i=0;i<=4;i++)
	{
		printf("Enter %d employee's name: ",(i+1));
		scanf("%s",e[i].name);
		printf("\nEnter ID No.: ");
		scanf("%d",&e[i].id);
		printf("\nEnter Phone Number: ");
		scanf("%d",&e[i].pno);
		printf("\nEnter Salary: ");
		scanf("%d",&e[i].salary);
	}
	printf("Employee's Details are:\n");
	for(i=0;i<=4;i++)
	{
		printf("%d.  Name:         %s\n",(i+1),e[i].name);
		printf("    ID No.:       %d\n",e[i].id);
		printf("    Phone Number :%d\n",e[i].pno);
		printf("    Salary :      %d\n",e[i].salary);
	}
}


