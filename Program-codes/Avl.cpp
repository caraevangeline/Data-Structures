#include<iostream>
using namespace std;
struct node
{
    int data;
    node *l,*r;
    int h;
}*root='\0';
int getbal(node *);
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
node *newnode(int data)
{
    node *n=new node;
    n->data=data;
    n->l='\0';
    n->r='\0';
    n->h=1;
    return n;
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
        return (newnode(data));
    if(data<n->data)
        n->l=insertion(n->l,data);
    else
        n->r=insertion(n->r,data);
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
    int n;
    do
    {
        cout<<"\n enter data:";
            cin>>n;
            root=insertion(root,n);
            cout<<"\n continue?";
            cin>>ch;
    }while(ch!='n');
    cout<<"\n preorder is:";
    preorder(root);
    return 0;
}
