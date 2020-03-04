#include<iostream>
using namespace std;
struct node
{
    int data;
    node *l,*r,*pr;
    int h;
}*root='\0',*prev,*p,*p1,*temp,*y,*a,*x,*s;
int getbal(node *);
void preorder(node *);
int height(node *n)
{
    if(n=='\0')
        return 0;
    else
        return n->h;
}
int maximum(int a,int b)
{
    return (a>b)?a:b;
}
node *assign1(node *,int );
node *newnode(int data)
{
    node *n=new node;
    n->data=data;
    n->l='\0';
    n->r='\0';
    n->h=1;
 n->pr=assign1(n,data);
    if(n->pr!='\0')
    cout<<n->data<<" "<<n->pr->data;
    return n;
}
node *assign1(node *n,int data)
{

   if(root=='\0')
        n->pr='\0';
    else if(n->data > x->data)
    {cout<<"\n hi:";
        if(x->r=='\0')
            n->pr=x;
        else
        {
            x=x->r;
            return assign1(x,data);
        }
    }
    else if(n->data < x->data)
    {
        if(x->l=='\0')
            n->pr=x;
        else
        {
            x=x->l;
           return assign1(x,data);
        }
    }
    return n->pr;

}
node *rightrotate(node *y)
{
    node *x=y->l;
    node *t=x->r;
    x->r=y;
    y->l=t;
    y->h=maximum(height(y->l),height(y->r))+1;
    x->h=maximum(height(x->l),height(x->r))+1;
    return x;
}
node *leftrotate(node *x)
{
    node *y=x->r;
    node *t=y->l;
    y->l=x;
    x->r=t;
    x->h=maximum(height(x->l),height(x->r))+1;
    y->h=maximum(height(y->l),height(y->r))+1;
    return y;
}
node *insertion(node *n,int data)
{
    if(n=='\0')
        {
            //assign1(n,data);
                        return (newnode(data));
        }
    if(data<n->data)
    {
        n->l=insertion(n->l,data);
        //assign1(n->l,data);
    }
    else
     {
         n->r=insertion(n->r,data);
         //assign1(n->r,data);
     }
    n->h=maximum(height(n->l),height(n->r))+1;
    int bal;
    bal=getbal(n);
    if(bal>1 && data<(n->l->data))
        return rightrotate(n);
    if(bal<-1 && data>(n->r->data))
        return leftrotate(n);
    if(bal>1 && data>(n->l->data))
    {
        n->l=leftrotate(n->l);
        return rightrotate(n);
    }
    if(bal<-1 && data<(n->r->data))
    {
        n->r=rightrotate(n->r);
        return leftrotate(n);
    }
    return n;
}
 void del(int x,node *t)
{
    while(t->data!=x)
    {
        p=t;
        if(x<=t->data)
            t=t->l;
        else
            t=t->r;
    }
    if(t->l=='\0'&& t->r=='\0')
    {
        if(p->l==t)
            p->l='\0';
        else
            p->r='\0';
    }
    if((t->l=='\0'&& t->r!='\0') || (t->r=='\0'&& t->l!='\0'))
    {
        if(p->l==t && t->l=='\0')
            p->l=t->r;
        else if(p->r==t && t->l=='\0')
            p->r=t->r;
        else if(p->l==t && t->r=='\0')
            p->l=t->l;
        else
            p->r=t->l;
    }
    if(t->l!='\0'&& t->r!='\0')
    {
        y=t->l;
        if(y->r=='\0')
            p1=t;
        while(y->r!='\0')
        {
            p1=y;
            y=y->r;
        }
        t->data=y->data;
        if(y->l=='\0'&& y->r=='\0')
    {
        if(p1->l==y)
            p1->l='\0';
        else
            p1->r='\0';
    }
    if((y->l=='\0'&& y->r!='\0') || (y->r=='\0'&& y->l!='\0'))
    {
        if(p1->l==y && y->l=='\0')
            p1->l=y->r;
        else if(p1->r==y && y->l=='\0')
            p1->r=y->r;
        else if(p1->l==y && y->r=='\0')
            p1->l=y->l;
        else
            p1->r=y->l;
    }
    }
    if((t->l=='\0'&& t->r=='\0')||(t->l=='\0'&& t->r!='\0') || (t->r=='\0'&& t->l!='\0'))
        a=p;
    else
        a=p1;
//cout<<a->data;
    while(a!='\0')
    {
    /*if(getbal(a)<-1 && getbal(a->r)==1)
         {
          a->r=rightrotate(a->r);
          a->pr->r=leftrotate(a);
         }
         if(getbal(a)<-1 && getbal(a->r)==-1)
         {
         a->pr->r=leftrotate(a->r);
         }
         if(getbal(a)>1 && getbal(a->r)==1)
         {
          a->l=leftrotate(a->l);
          a->pr->l=rightrotate(a);
         }*/
//cout<<getbal(a)<<" "<<getbal(a->l)<<" "<<a->pr->data;
    if(getbal(a)>1 && getbal(a->l)==1)
         {
         a->pr->l=rightrotate(a);
         }
         cout<<a->pr->l->data;
    a=a->pr;
    }
}
void preorder(node *root)
{
    cout<<root->data<<" ";
    if(root->l!='\0')
    preorder(root->l);
    if(root->r!='\0')
    preorder(root->r);
}
int getbal(node *n)
{
    if(n=='\0')
        return 0;
    else
        return height(n->l)-height(n->r);
}
int main()
{
    char ch;
    int n,x;
    do
    {
        cout<<"\n enter data:";
            cin>>n;
            root=insertion(root,n);
            cout<<"\n continue?";
            cin>>ch;
    }while(ch!='n');
    cout<<"\n preorder is:";
    temp=root;
    preorder(root);
    root=temp;
    cout<<"\n enter the data to be deleted:";
    cin>>x;
    del(x,root);
    temp=root;
  //  preorder(root);
    return 0;
}
