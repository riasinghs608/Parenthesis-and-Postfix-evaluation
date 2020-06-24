#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define max 100
#define size 100
int stack[max];
int top=-1;

void push(int item)
{
	if(top==max-1)
	{
		printf("\nOverflow");
	}
	else
	{
		top++;
		stack[top]=item;
	}
}
int pop()
{
	int item;
	
	if(top==-1)
	{
		printf("\nUnderflow");
	}
	else
	{
		item=stack[top];
		top--;
		return item;
	}
}
void posteval(char arr[])
{
	int i,val,A,B;
	char ch;
	
	for(i=0;arr[i]!='.';i++)
	{
		ch=arr[i];
		
		if(isdigit(ch))
		{
			push(ch-'0');
		}
		else if(ch=='+'||ch=='-'||ch=='/'||ch=='*')
		{
			A=pop();
			B=pop();
			
			switch(ch)
			{
				case '+' : val=B+A;
				           break;
				           
				case '*' : val=B*A;
				           break;
				           
				case '/' : val=B/A;
				           break;
				           
				case '-' : val=B-A;
				           break;
			}
			push(val);
		}
	}
	
	printf("\nResult is : %d",pop());
}
main()
{
	char arr[size];
	
	printf("\nEnter expression : ");
	int i;
	for(i=0;i<=size-1;i++)
	{
		scanf("%c",&arr[i]);
		
		if(arr[i]=='.')
		  {
		    break;
		}
	}
	posteval(arr);
}
