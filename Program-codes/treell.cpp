#include<iostream>
using namespace std;
void leftchild();
void rightchild();
void insertion();
struct btree
{
    btree *lchild;
    int a;
    btree *rchild;
}*root='\0',*head='\0',*ptr;
void insertion()
{
int x;
char ch;

if(root=='\0')
{
    cout<<"\n enter data:";
cin>>x;
    btree *n;
    n=new btree;
    n->lchild='\0';
    n->rchild='\0';
    n->a=x;
    root=n;
    head=n;
}
cout<<"\n leftchild?";
cin>>ch;
if(ch=='y')
    leftchild();
cout<<"\n rightchild?";
cin>>ch;
if(ch=='y')
    rightchild();
}
void leftchild()
{
    char ch;
    int x;
    cout<<"\n enter data:";
    cin>>x;
    btree *n=new btree;
    n->lchild='\0';
    n->rchild='\0';
    n->a=x;
    root->lchild=n;
    root=n;
    cout<<"\n continue to next level?";
    cin>>ch;
    if(ch=='y')
        insertion();
}
void rightchild()
{
    char ch;
    int x;
    cout<<"\n enter data:";
    cin>>x;
    btree *n=new btree;
    n->lchild='\0';
    n->rchild='\0';
    n->a=x;
    root->rchild=n;
    root=n;
    cout<<"\n continue to next level?";
    cin>>ch;
    if(ch=='y')
        insertion();
}
void inorder(btree *ptr)
{
    if(ptr!='\0')
    {
        inorder(ptr->lchild);
        cout<<ptr->a;
        inorder(ptr->rchild);
    }
}
int main()
{

    insertion();
    ptr=head;
    inorder(ptr);
    return 0;
}
