#include<iostream>
using namespace std;
struct node
{
    int data;
    node *l,*r;
}*root='\0',*temp='\0';
int f=-1,r=-1,q[20];
int siz=20;
void create(node *);
void levelorder(node *);
void postorder(node *root)
{
    if(root->l!='\0')
        postorder(root->l);
    if(root->r!='\0')
        postorder(root->r);
    cout<<root->a<<" ";
}
void ins(int x)
{
    if((r+1==f)||(f==0 && r==n-1))
        cout<<"\n overflow";
    else
    {
        if(r==-1 && f==-1)
        {
            r=0;
            f=0;
        }
        else if(r==n-1)
            r=0;
        else
            r=r+1;
        q[r]=x;
    }
}
int del()
{
    int x;
    if(f==-1)
        cout<<"\n underflow";
    else
    {
        x=q[f];
        if(f==r)
            {
                f=-1;
                r=-1;
            }
        else if(f==siz-1)
            f=0;
        else
            f=f+1;
    }
    return x;
}
int main()
{
    node *n=new node;
    n->l='\0';
    n->r='\0';
    cout<<"\n enter data:";
    cin>>n->data;
    root=n;
    temp=root;
    create(root);
    root=temp;
    levelorder(root);
    return 0;
}
void create(node *root)
{
    char ch;
    cout<<"\n leftchild?";
    cin>>ch;
    if(ch=='y')
    {
      node *n=new node;
      n->r='\0';
      n->l='\0';
      cout<<"\n enter data:";
      cin>>n->data;
      root->l=n;
    }
    cout<<"\n rightchild?";
    cin>>ch;
    if(ch=='y')
    {
        node *n=new node;
        n->l='\0';
        n->r='\0';
        cout<<"\n enter data:";
        cin>>n->data;
        root->r=n;

    }
    if(root->l!='\0')
        create(root->l);
    if(root->r!='\0')
        create(root->r);
}
void levelorder(node *root)
{
    node *t;
    t=root;
    cout<<t->data;
    while(t!='\0')
    {
        if(t->l!='\0');
        ins((t->l)->data);
        if(t->r!='\0')
        ins((t->r)->data);
        x=del();

    }
}
