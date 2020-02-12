#include<stdio.h>
#include<string.h>

char stack[30];
int top=-1;
void in_to_post(char *);
void push(char);
char pop();

void main()
{
	char infix[30];
	printf("Enter expression: ");
	scanf("%s",infix);
	in_to_post(infix);
}

void push(char sym)
{
	if(top>=29)
		printf("Stack Overflow\n");
	else
	{
		top+=1;
		stack[top]=sym;
	}
}

char pop()
{
	char i;
	if(top==-1)
		printf("Stack Underflow\n");
	else
	{
		i=stack[top];
		top-=1;
	}
	return i;
}

int prec(char ch)
{
	if(ch=='^' || ch=='$' || ch=='#')
		return 5;
	else if(ch=='*' || ch=='/' || ch=='%')
		return 4;
	else if(ch=='+' || ch=='-')
		return 2;
	else
		return 0;
}

void in_to_post(char infix[])
{
	int length;
	static int index=0,pos=0;
	char symbol,temp;
	char postfix[50];
	length=strlen(infix);
	while(index<length)
	{
		symbol=infix[index];
		switch(symbol)
		{
			case '(': push(symbol);
					  break;
			case ')': temp=pop();
				  	  while(temp!='(')
				  	  {
						postfix[pos]=temp;
						pos++;
						temp=pop();
				  	  }
				  	  break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			case '^':
			case '$':
			case '#': while(prec(stack[top])>=prec(symbol))
				  	  {
						temp=pop();
						postfix[pos]=temp;
						pos++;
				  	  }
				  	  push(symbol);
				  	  break;
			default:  postfix[pos++]=symbol;
				  	  break;
		}
		index++;
	}
	while(top>=0)
	{
		temp=pop();
		postfix[pos++]=temp;
	}
	postfix[pos++]='\0';
	printf("Postfix expression is:\n");
	puts(postfix);
	return;
}
