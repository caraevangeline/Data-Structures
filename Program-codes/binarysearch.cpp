#include<iostream>
using namespace std;
struct node
{
    int a;
    node *l,*r;
}*root='\0',*temp='\0',*head='\0',*p,*y,*p1;
void form(node *);
void del(int,node*);
void preorder(node*);
int main()
{
    int x;
    char ch;
    node *n;
    n=new node;
    n->r='\0';
    n->l='\0';
    cout<<"\n enter root:";
    cin>>n->a;
    root=n;
    head=root;
    do
    {
        root=head;
        cout<<"\n continue?";
        cin>>ch;
        if(ch=='y')
        {
            node *n;
            n=new node;
            n->r='\0';
            n->l='\0';
            cout<<"\n enter data:";
            cin>>n->a;
            form(n);
        }
    }while(ch!='n');
    cout<<"\n preorder is:";
    root=head;
    preorder(root);
    root=head;
    cout<<"\n enter the node data value to be deleted:";
    cin>>x;
    del(x,root);
    root=head;
    cout<<"\n preorder is:";
    preorder(root);
    return 0;
}
void form(node *n)
{
    if(n->a > root->a)
    {
        if(root->r=='\0')
            root->r=n;
        else
        {
            root=root->r;
            form(n);
        }
    }
    else if(n->a <=root->a)
    {
        if(root->l=='\0')
            root->l=n;
        else
        {
            root=root->l;
            form(n);
        }
    }
}
void del(int x,node *t)
{
    while(t->a!=x)
    {
        p=t;
        if(x<=t->a)
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
        while(y->r!='\0')
        {
            p1=y;
            y=y->r;
        }
        t->a=y->a;
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
}
void preorder(node *root)
{
    cout<<root->a<<" ";
    if(root->l!='\0')
        preorder(root->l);
    if(root->r!='\0')
        preorder(root->r);
}
