#include<stdio.h> //Header file

struct employee   // Initializing structure
{
	char name[20];
	int id,pno,salary;
}e[5];          // we can call structure employee by e[i]

void main()  // Main fuction of void return type
{
	int i;
	for(i=0;i<=4;i++)     // for-loop for taking input from user 
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
	for(i=0;i<=4;i++)   // for-loop for printing details of employee
	{
		printf("%d.  Name:         %s\n",(i+1),e[i].name);
		printf("    ID No.:       %d\n",e[i].id);
		printf("    Phone Number :%d\n",e[i].pno);
		printf("    Salary :      %d\n",e[i].salary);
	}
}


