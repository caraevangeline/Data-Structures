#include<iostream>
using namespace std;
struct node
{
    int a;
    node *l,*r;
}*root='\0',*head;
int preind=0;
int sea(int [],int,int,int);
node *build(int in[20],int post[20],int instrt,int inend,int poststrt,int postend)
{
    node *cnode=new node;
    cnode->a=post[postend];
    cnode->l='\0';
    cnode->r='\0';
    if(preind==0)
        head=cnode;
    preind++;
    if(instrt==inend)
        return cnode;
    else
    {
        int index=sea(in,instrt,inend,post[postend]);
        if(instrt<index)
        cnode->l=build(in,post,instrt,index-1,poststrt,poststrt+index-(instrt+1));
        if(inend>index)
        cnode->r=build(in,post,index+1,inend,poststrt+index-instrt,postend-1);
    }
    return cnode;
}
int sea(int in[20],int first,int last,int val)
{
    for(int i=first;i<=last;++i)
        if(val==in[i])
        return i;
}
void preorder(node *root)
{
     cout<<root->a<<" ";
    if(root->l!='\0')
        preorder(root->l);
    if(root->r!='\0')
        preorder(root->r);
}
int main()
{
    int n,in[20],post[20];
    cout<<"\n enter no of nodes:";
    cin>>n;
    cout<<"\n enter inorder:";
    for(int i=0;i<n;++i)
        cin>>in[i];
    cout<<"\n enter postorder:";
    for(int i=0;i<n;++i)
        cin>>post[i];
    root=build(in,post,0,n-1,0,n-1);
    cout<<"\n preorder:";
    preorder(head);
    return 0;
}

