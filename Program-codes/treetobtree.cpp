#include<iostream>
using namespace std;
struct tree
{
    int a;
    tree *l1,*l2,*l3;
}*r='\0',*h='\0',*p;
struct btree
{
    int a;
    btree *l,*r;
}*r1='\0',*h1='\0';
void create(tree *);
void convert(tree *);
void preorder(btree *);
int main()
{
    tree *n=new tree;
    n->l1='\0';
    n->l2='\0';
    n->l3='\0';
    cout<<"\n enter data:";
    cin>>n->a;
    r=n;
    create(r);
    return 0;
}
void create(tree *r)
{
    char ch;
    cout<<"\n First child?";
    cin>>ch;
    if(ch=='y')
    {
        tree *n=new tree;
        n->l1='\0';
        n->l2='\0';
        n->l3='\0';
        cout<<"\n enter data:";
        cin>>n->a;
        r->l1=n;
    }
    cout<<"\n Second child?";
    cin>>ch;
    if(ch=='y')
    {
        tree *n=new tree;
        n->l1='\0';
        n->l2='\0';
        n->l3='\0';
        cout<<"\n enter data:";
        cin>>n->a;
        r->l2=n;
    }
    cout<<"\n Third child?";
    cin>>ch;
    if(ch=='y')
    {
        tree *n=new tree;
        n->l1='\0';
        n->l2='\0';
        n->l3='\0';
        cout<<"\n enter data:";
        cin>>n->a;
        r->l3=n;
    }
        if(r->l1!='\0')
        create(r->l1);
        if(r->l2!='\0')
        create(r->l2);
        if(r->l3!='\0')
        create(r->l3);
}
void convert(tree *r)
{
    if(h1=='\0')
    {
        h1=r;
    }
    if(r->l1!='\0')
    {
        r1=r;
        r1->l=r->l1;
        p=r;
        convert(r->l1);
    }
    r=p;
    if(r->l2!='\0')
    {
        r1=r1->l;
        r1->rt=r->l2;
        p=r;
        convert(r->l2);
    }
    r=p;
    if(r->l3!='\0')
    {
        r=r->l;
        while(r1->rt!='\0')
            r1=r1->rt;
        r1->rt=r->l3;
    }
}
