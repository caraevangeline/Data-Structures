#include<iostream>
using namespace std;
struct node
{
    int key;
    node *l,*r;
}*root='\0',*head;
node *rightrotate(node *x)
{
    node *y=x->l;
    x->l=y->r;
    y->r=x;
    return y;
}
node *leftrotate(node *x)
{
    node *y=x->r;
    x->r=y->l;
    y->l=x;
    return y;
}
node *splay(node *root,int key)
{
    if(root=='\0'|| root->key==key)
        return root;
    if(root->key>key)
    {
        if(root->l=='\0')
            return root;
        if(root->l->key>key)
        {
            root->l->l=splay(root->l->l,key);
            root=rightrotate(root);
        }
        else if(root->l->key<key)
        {
            root->l->r=splay(root->l->r,key);
            if(root->l->r!='\0')
                root->l=leftrotate(root->l);
        }
            if(root->l=='\0')
                return root;
            else
                return rightrotate(root);
    }
    else
    {
        if(root->r=='\0')
            return root;
        if(root->r->key>key)
        {
            root->r->l=splay(root->r->l,key);
            if(root->r->l!='\0')
                root->r=rightrotate(root->r);
        }
        else if(root->r->key<key)
        {
            root->r->r=splay(root->r->r,key);
            root=leftrotate(root);
        }
        if(root->r=='\0')
            return root;
        else
            leftrotate(root);
    }
}
void form(node *n)
{
    if(n->key > root->key)
    {
        if(root->r=='\0')
            root->r=n;
        else
        {
            root=root->r;
            form(n);
        }
    }
    else if(n->key <= root->key)
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
void preorder(node *root)
{
    cout<<root->key<<" ";
    if(root->l!='\0')
        preorder(root->l);
    if(root->r!='\0')
        preorder(root->r);
}
int main()
{
    int key;
    char ch;
    node *n=new node;
    n->r='\0';
    n->l='\0';
    cout<<"\n enter root:";
    cin>>n->key;
    root=n;
    head=root;
    do
    {
        root=head;
        cout<<"\n continue?";
        cin>>ch;
        if(ch=='y')
        {
            node *n=new node;
            n->r='\0';
            n->l='\0';
            cout<<"\n enter data:";
            cin>>n->key;
            form(n);
        }
    }while(ch!='n');
    root=head;
    cout<<"\n preorder is:";
    preorder(root);
    root=head;
    cout<<"\n enter the key:";
    cin>>key;
    root=splay(root,key);
    cout<<"\n after splaying the preorder is:";
    preorder(root);
}
