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
	int data;
	struct node * link;
}*header;

void main()
{
	int op,c;
	header=(struct node*)malloc(sizeof(struct node));
	header->data=0;
	header->link=NULL;
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
			default:printf("Enter valid input !!");
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
		ptr->link=cpt;
		ptr=cpt;
		printf("Continue adding nodes ?(1=Yes)\n");
		scanf("%d",&ans);
	}while(ans==1);
	ptr->link=NULL;
}

void insert()
{
	int an,val;
	ptr=header;
	printf("Choose your preference:\n1: Insert at Front\n2: Insert at End\n3: Insert in Ascending order\n");
	scanf("%d",&an);
	switch(an)
	{
		isrt_f:
		case 1: newnode=(struct node*)malloc(sizeof(struct node));
				printf("Enter the data: ");
				scanf("%d",&newnode->data);
				newnode->link=header->link;
				header->link=newnode;
				break;
		isrt_e:
		case 2:	while(ptr->link!=NULL)
					ptr=ptr->link;
				newnode=(struct node*)malloc(sizeof(struct node));
				printf("Enter the data: ");
				scanf("%d",&newnode->data);
				ptr->link=newnode;
				newnode->link=NULL;
				break;
		case 3: printf("Enter the value to be inserted: ");
				scanf("%d",&val);
				ptr=ptr->link;
				if(ptr==NULL)
					goto isrt_f;
				else
				{
					while(val>=ptr->data && ptr->link!=NULL)
					{
						cpt=ptr;
						ptr=ptr->link;
					}	
					if(ptr->link==NULL && ptr->data<val)
						goto isrt_e;
					else
					{
						newnode=(struct node*)malloc(sizeof(struct node));
						newnode->data=val;
						cpt->link=newnode;
						newnode->link=ptr;
					}
				}
				break;
		default:printf("Enter valid input !!");
	}
}	

void delete()
{
	int an,p,c=0;
	ptr=header;
	if(ptr->link==NULL)
		printf("Empty List !! Deletion Not Possible !!\n");
	else
	{
		printf("Choose your preference:\n1: Delete First Node\n2: Delete a node before specified position\n3: Delete a node after specified position\n");
		scanf("%d",&an);
		switch(an)
		{
			dlt_f:
			case 1: ptr=ptr->link;
	        		header->link=ptr->link;
					free(ptr);
					break;
			case 2: printf("Enter Position (Previous Node will be deleted): ");
					scanf("%d",&p);
					if(p<2)
						printf("No Node to delete !!\n");
					else if(p==2)
						goto dlt_f;
					else
					{
						while(c!=(p-2) && ptr->link!=NULL)
						{
							ptr=ptr->link;
							c++;
						}
						if(ptr->link==NULL)
							printf("Position not found !!\n");
						else
						{
							cpt=ptr->link;
							if(cpt==NULL)
								printf("No node to delete !!\n");
							else
							{
								ptr->link=cpt->link;
								free(cpt);	
							}		
						}
					}
					break;
			case 3: printf("Enter Position (Next Node will be deleted): ");
					scanf("%d",&p);
					while(c!=p && ptr->link!=NULL)
					{
						ptr=ptr->link;
						c++;
					}
					if(ptr->link==NULL && c!=p)
						printf("Position not found !!\n");
					else
					{
						cpt=ptr->link;
						if(cpt==NULL)
								printf("No node to delete !!\n");
						else
						{
							ptr->link=cpt->link;
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
	ptr=header->link;
	if(ptr==NULL)
		printf("List is Empty !!\n");
	else
	{
		printf("Data :\n");
		while(ptr != NULL)
		{
			printf("%d\n",ptr->data);
			ptr=ptr->link;
		}
	}
}


