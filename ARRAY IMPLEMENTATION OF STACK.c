#include<stdio.h>
void main()
{
int a[10]={0},i,top=-1,max=10,n,x;
printf("\n\tMENU\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
do
{
printf("\nEnter your choice\n");
scanf("%d",&n);
switch(n)
{
case 1:
if(top==max-1)
printf("Stack is FULL\n");
else
{
printf("Enter the element\n");
scanf("%d",&x);
a[++top]=x;
}
break;
case 2:
if(top<0)
printf("Stack is Empty\n");
else
printf("The deleted item =%d",a[top--]); break;
case 3:
if(top<0)
printf("The stack is empty\n");
else
{
printf("The elements of the stack are :");
for(i=0;i<=top;i++)
printf("%d\n",a[i]);
}
break;
case 4:
break;
default:
printf("Invalid choice\n");
break;
}
}
while(n!=4);
}
