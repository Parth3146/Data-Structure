#include<stdio.h>
#include<malloc.h>

void create();
void insert();
void delete();
void display();

struct node *ptr,*cpt,*newnode;
int ans,key;

struct node
{
	struct node * llink;
	int data;
	struct node * rlink;
};
struct node *header;

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
		default: printf("Enter valid input !!");
	}
	printf("Do you want to Continue ?(1-Yes): ");
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
	int an;
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
		case 2: printf("Enter the value of the node after the position of the node to be inserted :\n");
			scanf("%d",&key);
			while(ptr->rlink!=header && ptr->data!=key)
				ptr=ptr->rlink;
			if(ptr->rlink==header && ptr->data!=key)
				printf("Key Not Found !!");
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
			break;
		default: printf("Enter valid input !!");
	}
}	

void delete()
{
	int an;
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
				header->rlink=ptr->rlink;
				free(ptr);
				break;
			case 2: printf("Enter the value of the node before the node to be deleted :\n");
				scanf("%d",&key);
				while(ptr->rlink!=NULL && ptr->data!=key)
					ptr=ptr->rlink;
				if(ptr->rlink==NULL && ptr->data!=key)
					printf("Key Not Found !!");
				else if(ptr->rlink==header)
					printf("No next node to be deleted !!\n");
				else
				{
					cpt=ptr->rlink;
					ptr->rlink=header;
					header->llink=ptr;
					free(cpt);
				}
				break;
			default: printf("Enter valid input !!");
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
		printf("LLink | Data | RLink :\n");
		while(ptr->rlink!=header)
		{
			printf("%p | %d | %p\n",ptr->llink,ptr->data,ptr->rlink);
			ptr=ptr->rlink;
		}
		if(ptr->rlink==header)
			printf("%p | %d | %p\n",ptr->llink,ptr->data,ptr->rlink);
	}
}


