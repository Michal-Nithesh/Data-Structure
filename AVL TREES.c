#include<stdio.h>
typedef struct node
{
int data;
struct node *left,*right;
int ht;
}node;
node *insert(node *,int);
node *Delete(node *,int);
void preorder(node *);
void inorder(node *);
int height( node *);
node *rotateright(node *);
node *rotateleft(node *);
node *RR(node *);
node *LL(node *);
node *LR(node *);
node *RL(node *);
int BF(node *);
int main()
{
node *root=NULL;
int x,n,i,op;
do
{
printf(&quot;\n1)Create:&quot;);
printf(&quot;\n2)Insert:&quot;);
printf(&quot;\n3)Delete:&quot;);
printf(&quot;\n4)Print:&quot;);
printf(&quot;\n5)Quit:&quot;);
printf(&quot;\n\nEnter Your Choice:&quot;);
scanf(&quot;%d&quot;,&amp;op);
switch(op)

{
case 1: printf(&quot;\nEnter no. of elements:&quot;);
scanf(&quot;%d&quot;,&amp;n);
printf(&quot;\nEnter tree data:&quot;);
root=NULL;
for(i=0;i&lt;n;i++)
{
scanf(&quot;%d&quot;,&amp;x);
root=insert(root,x);
}
break;
case 2: printf(&quot;\nEnter a data:&quot;);
scanf(&quot;%d&quot;,&amp;x);
root=insert(root,x);
break;
case 3: printf(&quot;\nEnter a data:&quot;);
scanf(&quot;%d&quot;,&amp;x);
root=Delete(root,x);
break;
case 4: printf(&quot;\nPreorder sequence:\n&quot;);
preorder(root);
printf(&quot;\n\nInorder sequence:\n&quot;);
inorder(root);
printf(&quot;\n&quot;);
break;
}
}while(op!=5);
return 0;
}
node * insert(node *T,int x)
{
if(T==NULL)
{
T=(node*)malloc(sizeof(node));
T-&gt;data=x;
T-&gt;left=NULL;
T-&gt;right=NULL;
}
else
if(x &gt; T-&gt;data) // insert in right subtree
{
T-&gt;right=insert(T-&gt;right,x);
if(BF(T)==-2)
if(x&gt;T-&gt;right-&gt;data)
T=RR(T);
else
T=RL(T);
}
else
if(x&lt;T-&gt;data)

{
T-&gt;left=insert(T-&gt;left,x);
if(BF(T)==2)
if(x &lt; T-&gt;left-&gt;data)
T=LL(T);
else
T=LR(T);
}
T-&gt;ht=height(T);
return(T);
}
node * Delete(node *T,int x)
{
node *p;
if(T==NULL)
{
return NULL;
}
else
if(x &gt; T-&gt;data) // insert in right subtree
{
T-&gt;right=Delete(T-&gt;right,x);
if(BF(T)==2)
if(BF(T-&gt;left)&gt;=0)
T=LL(T);
else
T=LR(T);
}
else
if(x&lt;T-&gt;data)
{
T-&gt;left=Delete(T-&gt;left,x);
if(BF(T)==-2) //Rebalance during windup
if(BF(T-&gt;right)&lt;=0)
T=RR(T);
else
T=RL(T);
}
else
{
//data to be deleted is found
if(T-&gt;right!=NULL)
{ //delete its inorder succesor
p=T-&gt;right;
while(p-&gt;left!= NULL)
p=p-&gt;left;
T-&gt;data=p-&gt;data;
T-&gt;right=Delete(T-&gt;right,p-&gt;data);
if(BF(T)==2)//Rebalance during windup
if(BF(T-&gt;left)&gt;=0)

T=LL(T);
else
T=LR(T);\
}
else
return(T-&gt;left);
}
T-&gt;ht=height(T);
return(T);
}
int height(node *T)
{
int lh,rh;
if(T==NULL)
return(0);
if(T-&gt;left==NULL)
lh=0;
else
lh=1+T-&gt;left-&gt;ht;
if(T-&gt;right==NULL)
rh=0;
else
rh=1+T-&gt;right-&gt;ht;
if(lh&gt;rh)
return(lh);
return(rh);
}
node * rotateright(node *x)
{
node *y;
y=x-&gt;left;
x-&gt;left=y-&gt;right;
y-&gt;right=x;
x-&gt;ht=height(x);
y-&gt;ht=height(y);
return(y);
}
node * rotateleft(node *x)
{
node *y;
y=x-&gt;right;
x-&gt;right=y-&gt;left;
y-&gt;left=x;
x-&gt;ht=height(x);
y-&gt;ht=height(y);
return(y);
}
node * RR(node *T)
{
T=rotateleft(T);

return(T);
}
node * LL(node *T)
{
T=rotateright(T);
return(T);
}
node * LR(node *T)
{
T-&gt;left=rotateleft(T-&gt;left);
T=rotateright(T);
return(T);
}
node * RL(node *T)
{
T-&gt;right=rotateright(T-&gt;right);
T=rotateleft(T);
return(T);
}
int BF(node *T)
{
int lh,rh;
if(T==NULL)
return(0);
if(T-&gt;left==NULL)
lh=0;
else
lh=1+T-&gt;left-&gt;ht;
if(T-&gt;right==NULL)
rh=0;
else
rh=1+T-&gt;right-&gt;ht;
return(lh-rh);
}
void preorder(node *T)
{
if(T!=NULL)
{
printf(&quot;%d(Bf=%d)&quot;,T-&gt;data,BF(T));
preorder(T-&gt;left);
preorder(T-&gt;right);
}
}
void inorder(node *T)
{
if(T!=NULL)
{
inorder(T-&gt;left);
printf(&quot;%d(Bf=%d)&quot;,T-&gt;data,BF(T));
inorder(T-&gt;right);

}
}
