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
	header->llink=header->rlink=NULL;
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
		default:printf("Enter valid input !!\n");
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
		printf("Continue adding nodes ?(1=Yes)\n");
		scanf("%d",&ans);
	}while(ans==1);
	ptr->rlink=NULL;
}

void insert()
{
	int an;
	ptr=header;
	if(ptr->rlink==NULL)
		printf("First Create a List !!\n");
	else
	{	
		printf("Choose your preference:\n1: Insert at Front\n2: Insert at End\n");
		scanf("%d",&an);
		switch(an)
		{
			case 1: newnode=(struct node*)malloc(sizeof(struct node));
					printf("Enter the data: ");
					scanf("%d",&newnode->data);
					ptr=header->rlink; 
					newnode->rlink=header->rlink;
					newnode->llink=header;
					header->rlink=newnode;
					ptr->llink=newnode;
					break;
			case 2: while(ptr->rlink!=NULL)
						ptr=ptr->rlink;
					newnode=(struct node*)malloc(sizeof(struct node));
					printf("Enter the data: ");
					scanf("%d",&newnode->data);
					ptr->rlink=newnode;
					newnode->llink=ptr;
					newnode->rlink=NULL;
					break;
			default:printf("Enter valid input !!");
		}
	}
}	

void delete()
{
	int an,p,c;
	ptr=header->rlink;
	if(ptr==NULL)
		printf("Empty List !! Deletion Not Possible !!\n");
	else
	{
		printf("Choose your preference:\n1: Delete Last Node\n2: Delete Before Specified Position\n");
		scanf("%d",&an);
		switch(an)
		{
			case 1: while(ptr->rlink!=NULL)
						ptr=ptr->rlink;
					cpt=ptr->llink;
					cpt->rlink=NULL;
					free(ptr);
					break;
			case 2: printf("Enter Position (Previous Node will be deleted): ");
					scanf("%d",&p);
					c=1;
					if(p<2)
						printf("No Node to delete !!\n");
					else if(p==2)
					{
						ptr=ptr->rlink;
						if(ptr==NULL)
						{
							ptr=header->rlink;
							header->rlink=NULL;
							free(ptr);
						}
						else
						{
							ptr->llink=header;
							ptr=header->rlink;
		        			header->rlink=ptr->rlink;
							free(ptr);
						}
					}
					else
					{
						while(c!=p && ptr->rlink!=NULL)
						{
							ptr=ptr->rlink;
							c++;
						}
						if(ptr->rlink==NULL && c!=p)
							printf("Position not found !!\n");
						else
						{
							cpt=ptr->llink;
							ptr->llink=cpt->llink;
							ptr=cpt->llink;
							ptr->rlink=cpt->rlink;
							free(cpt);			
						}
					}
					break;
			default:printf("Enter valid input !!");
		}
	}
}

void display()
{
	ptr=header->rlink;
	if(ptr==NULL)
		printf("List is Empty !!\n");
	else
	{
		printf("Data :\n");
		while(ptr->rlink!=NULL)
		{
			printf("%d ",ptr->data);
			ptr=ptr->rlink;
		}
		if(ptr->rlink==NULL)
			printf("%d \n",ptr->data);
	}
}


