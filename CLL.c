#include<stdio.h>
#include<malloc.h>

void create();
void insert();
void delete();
void display();

struct node *ptr,*cpt,*newnode;
int ans;

struct node
{
	struct node * llink,* rlink;
	int data;
}*header;

void main()
{
	int op,c;
	header=(struct node*)malloc(sizeof(struct node));
	header->data=0;
	header->llink=NULL;
	header->rlink=NULL;
	do
	{
	printf("Choose Operation:\n1: Create\n2: Insert\n3: Delete\n4: Display\n");
	scanf("%d",&op);
	switch(op)
	{
		case 1: create();
				break;
		case 2: insert();
				break;
		case 3: delete();
				break;
		case 4:	display();
				break;
		default: printf("Enter valid input !!\n");
	}
	printf("Do you want to Continue ?(1=Yes): ");
	scanf("%d",&c);
	}while(c==1);
}

void create()
{	
	ptr=header;
	do
	{
		cpt=(struct node*)malloc(sizeof(struct node));
		printf("Enter Data\n");
		scanf("%d",&cpt->data);
		ptr->rlink=cpt;
		cpt->llink=ptr;
		ptr=cpt;
		printf("Continue adding nodes ?(1-Yes)\n");
		scanf("%d",&ans);
	}while(ans==1);
	ptr->rlink=header;
	header->llink=ptr;
}

void insert()
{
	int an,c,p;
	ptr=header;
	if(ptr->rlink==NULL)
		printf("First Create a List !!\n");
	else
	{
		printf("Choose your preference:\n1: Insert at End\n2: Insert Before Specified Position\n");
		scanf("%d",&an);
		switch(an)
		{
			case 1: while(ptr->rlink!=header)
						ptr=ptr->rlink;
					newnode=(struct node*)malloc(sizeof(struct node));
					printf("Enter the data: ");
					scanf("%d",&newnode->data);
					newnode->rlink=header;
					newnode->llink=ptr;
					ptr->rlink=newnode;
					break;
			case 2: printf("Enter Position (Node will be inserted at Previous Position):\n");
				scanf("%d",&p);
				c=0;
				if(p<1)
					printf("Invalid input !!");
				else
				{
					while(ptr->rlink!=header && c!=p)
					{
						ptr=ptr->rlink;
						c++;
					}
					if(ptr->rlink==header && c!=p)
						printf("Position Not Found !!");
					else
					{
						newnode=(struct node*)malloc(sizeof(struct node));
						printf("Enter the data: ");
						scanf("%d",&newnode->data); 
						newnode->rlink=ptr;
						ptr=ptr->llink;
						ptr->rlink=newnode;
						newnode->llink=ptr;
						ptr=newnode->rlink;
						ptr->llink=newnode;
					}
				}
				break;
			default: printf("Enter valid input !!");
		}
	}
}	

void delete()
{
	int an,c,p;
	ptr=header;
	if(ptr->rlink==NULL)
		printf("Empty List !! Deletion Not Possible !!\n");
	else
	{
		printf("Choose your preference:\n1: Delete First Node\n2: Delete after Specified Position\n");
		scanf("%d",&an);
		switch(an)
		{
			case 1: ptr=ptr->rlink;
				if(ptr->rlink==NULL)
				{
					header->rlink=NULL;
					free(ptr);
				}
				else
				{
					ptr=ptr->rlink;
					ptr->llink=header;
					ptr=header->rlink;
					header->rlink=ptr->rlink;
					free(ptr);
				}
				break;
			case 2: printf("Enter Position (Next node will be deleted):\n");
				scanf("%d",&p);
				c=0;
				while(ptr->rlink!=header && c!=p)
				{
					ptr=ptr->rlink;
					c++;
				}
				if(ptr->rlink==header && c!=p)
					printf("Position Not Found !!");
				else if(ptr->rlink==header)
					printf("No next node to be deleted !!\n");
				else
				{
					cpt=ptr->rlink;
					ptr->rlink=cpt->rlink;
					free(cpt);
				}
				break;
			default: printf("Enter valid input !!\n");
		}
	}
}

void display()
{
	int an;
	ptr=header->rlink;
	if(ptr==NULL)
		printf("List is Empty !!\n");
	else
	{
		printf("Enter your preference:\n1: Traverse front to end\n2: Traverse end to first\n3: Print both traversal\n");
		scanf("%d",&an);
		switch(an)
		{
			case 1:	printf("Data :\n");
					while(ptr->rlink!=header)
					{
						printf("%d ",ptr->data);
						ptr=ptr->rlink;
					}
					if(ptr->rlink==header)
						printf("%d\n",ptr->data);
					break;
			case 2:	ptr=header->llink;
					printf("Data :\n");
					while(ptr->llink!=header)
					{
						printf("%d ",ptr->data);
						ptr=ptr->llink;
					}
					if(ptr->llink==header)
						printf("%d\n",ptr->data);
					break;
			case 3:	printf("Data :\n");
					while(ptr->rlink!=header)
					{
						printf("%d ",ptr->data);
						ptr=ptr->rlink;
					}
					if(ptr->rlink==header)
						printf("%d || ",ptr->data);
					while(ptr->llink!=header)
					{
						printf("%d ",ptr->data);
						ptr=ptr->llink;
					}
					if(ptr->llink==header)
						printf("%d\n",ptr->data);
					break;
			default:printf("Enter valid input !!");
		}
	}
}

