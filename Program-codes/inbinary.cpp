#include<iostream>
using namespace std;
struct node
{
    node *l,*r;
    int a;
}*head='\0',*root,*temp,*req,*p,*pa;
void create(node *root);
int i;
node *sea(node *root,int data);
int height(node *root)
{
    if(root=='\0')
        return 0;
    else
    {
        int lheight=(height(root->l));
        int rheight=(height(root->r));
        if(lheight>rheight)
            return lheight+1;
        else
            return rheight+1;
    }
}
node *printgivenlevel(node *root,int level)
{
    if(root=='\0')
        return '\0';
    if(level==1)
        cout<<root->a<<" ";
    else if(level>1)
    {
        printgivenlevel(root->l,level-1);
        printgivenlevel(root->r,level-1);

    }
}
void levelorder(node *root)
{
    int h=height(root);
    for(int i=1;i<=h;++i)
        printgivenlevel(root,i);
}
int main()
{
    int x;
    node *n=new node;
    n->l='\0';
    n->r='\0';
    cout<<"\n enter data:";
    cin>>n->a;
    root=n;
    head=n;
    create(root);
    root=head;
    cout<<"\n levelorder:";
    levelorder(root);
    cout<<"\n enter the data to be searched:";
    cin>>x;
    root=head;
    p=sea(root,x);
    if(req!=head)
    {
        cout<<"\n parent is:";
        cout<<pa->a;
        cout<<"\n sibling is:" ;
        if(i=1 && pa->r!='\0' && pa->r->a!=req->a)
            cout<<pa->r->a;
        else if(i=2 &&pa->l!='\0' && pa->l->a!=req->a)
            cout<<pa->l->a;
        else
            cout<<"\n no sibling";
            cout<<"\n children:";
            if(req->l!='\0')
            {
                cout<<"\n leftchild:";
                cout<<req->l->a;
            }
            if(req->r!='\0')
            {
                cout<<"\n rightchild:";
                cout<<req->r->a;
            }}
else
    {
        cout<<"\n no parent :";

            cout<<"\n no sibling";
            cout<<"\n children:";
            if(req->l!='\0')
            {
                cout<<"\n leftchild:";
                cout<<req->l->a;
            }
            if(req->r!='\0')
            {
                cout<<"\n rightchild:";
                cout<<req->r->a;
            }
    }


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
        n->l='\0';
        n->r='\0';
        cout<<"\n enter data:";
        cin>>n->a;
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
        cin>>n->a;
        root->r=n;
    }
    if(root->l!='\0')
        create(root->l);
    if(root->r!='\0')
        create(root->r);

}
node *sea(node *root,int data)
{
    p=root;
    if(head->a==data)
        req=head;
    if(root->l!='\0'&& root->a!=data)
    {
        temp=sea(root->l,data);
        if(temp!='\0')
           {
               i=1;
               req=temp;
               pa=root;
           }
    }
    if(root->r!='\0'&& root->a!=data)
    {
        temp=sea(root->r,data);
        if(temp!='\0')
        {
            i=2;
           req=temp;
           pa=root;
        }
    }
    if(root->a==data)
        return root;
    else
        return '\0';
}
