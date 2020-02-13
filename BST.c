#include<stdio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *llink,*rlink;
}*root=NULL,*new,*ptr;
int val,ans,a,n=0,x=0;

void createBST(struct node*,int val);
void inorder(struct node*);
void postorder(struct node*);
void preorder(struct node*);

void main()
{
	ptr=root;
	do
	{
		printf("Choose Option:\n1:CreateBST\n2:Preorder\n3:Postorder\n4:Inorder\n");
		scanf("%d",&ans);
		switch(ans)
		{
			case 1: printf("Enter number of nodes: ");
					scanf("%d",&x);
					while(n!=x)
					{
						printf("Enter Value: ");
						scanf("%d",&val);
						createBST(root,val);
						n++;
					}
					break;
			case 2: preorder(root);
					break;
			case 3: postorder(root);
					break;
			case 4: inorder(root);
					break;
			default:printf("Enter Valid input !!"); 
		}
		printf("Continue to menue ?(1=Yes)");
		scanf("%d",&a);
	}while(a==1);
}

void createBST(struct node*ptr,int val)
{
	if(root==NULL)
	{
		new=(struct node*)malloc(sizeof(struct node));
		new->llink=new->rlink=NULL;
		new->data=val;
		root=new;
		printf("Root=%d\n",root->data);
	}
	else if(val<ptr->data)
	{
		if(ptr->llink==NULL)
		{
			new=(struct node*)malloc(sizeof(struct node));
			new->llink=new->rlink=NULL;
			new->data=val;
			ptr->llink=new;
			printf("%d is left child of %d\n",val,ptr->data);
		}	
		else
			createBST(ptr->llink,val);
	}
	else if(val>=ptr->data)
	{
		if(ptr->rlink==NULL)
		{
			new=(struct node*)malloc(sizeof(struct node));
			new->llink=new->rlink=NULL;
			new->data=val;
			ptr->rlink=new;
			printf("%d is right child of %d\n",val,ptr->data);
		}	
		else
			createBST(ptr->rlink,val);
	}
}

void inorder(struct node*ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->llink);
		printf("%d ",ptr->data);
		inorder(ptr->rlink);
	}
}

void preorder(struct node*ptr)
{
	if(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		preorder(ptr->llink);
		preorder(ptr->rlink);
	}
}

void postorder(struct node*ptr)
{
	if(ptr!=NULL)
	{
		postorder(ptr->llink);
		postorder(ptr->rlink);
		printf("%d ",ptr->data);
	}
}

