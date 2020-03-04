#include<iostream>
using namespace std;
#include<stdlib.h>
int i=0;
struct node
{
int a;
node *link;
}*head='\0',*temp,*prev,*next,*head1='\0',*head2='\0',*curr,*l;
void insertbeg(int x)
{

    node *n;
    n=new node;
    n->a=x;
    n->link='\0';
    temp=head;
    if(head=='\0')
    {
        head=n;
        n->link=n;
    }
    else
    {
        n->link=head;
        while(temp->link!=head)
        {

            temp=temp->link;
        }
        temp->link=n;
        head=n;
    }
}
void insertpos(int x, int pos)
{

    int c=1;
    node *n;
    n=new node;
    n->a=x;
    n->link='\0';
    temp=head;
    while(c!=pos)
    {

        prev=temp;
        temp=temp->link;
        c++;
    }
    prev->link=n;
    n->link=temp;
}
void insertitem(int x, int y)
{

    temp=head;
    node *n;
    n=new node;
    n->a=x;
    n->link='\0';
    while(temp->a!=y)
    {
        prev=temp;
        temp=temp->link;
    }
    prev->link=n;
    n->link=temp;
}
void insertend(int x)
{

    node *n;
    n=new node;
    n->a=x;
    n->link='\0';
    temp=head;
    if(head!='\0')
    {

        while(temp->link!=head)
        {

            temp=temp->link;
        }
        n->link=temp->link;
        temp->link=n;
    }
    else
        {

            head=n;
            n->link=n;
        }
}
void display()
{

    node *p;
    p=new node;
    for(p=head;p!='\0'&& p->link!=head;p=p->link)
        cout<<p->a<<" ";
        cout<<p->a;
}
void del(int x)
{
    l=head;
    temp=head;
    while(temp->a!=x && temp->link!=head)
    {
        prev=temp;
        temp=temp->link;
    }
    if(temp->a==x)
    {

    if(temp==head)
    {
        while(l->link!=head)
        l=l->link;
        l->link=temp->link;
            head=temp->link;
        temp->link='\0';
        delete temp;
    }
    else if(temp->link==head)
    {

        prev->link=head;
        temp->link='\0';
        delete temp;
    }
    else
    {

        prev->link=temp->link;
        temp->link='\0';
        delete temp;
    }

    }
}
void del1(int pos)
{
    int c=1;
 l=head;
    temp=head;
    while(c!=pos && temp->link!=head)
    {
        prev=temp;
        temp=temp->link;
        ++c;
    }
    if(c==pos)
    {

    if(temp==head)
    {
        while(l->link!=head)
        l=l->link;
        l->link=temp->link;
            head=temp->link;
        temp->link='\0';
        delete temp;
    }
    else if(temp->link==head)
    {

        prev->link=head;
        temp->link='\0';
        delete temp;
    }
    else
    {

        prev->link=temp->link;
        temp->link='\0';
        delete temp;
    }

    }

}/*
int sea(int x)
{

    int c=1,j=0;
    temp=head;
    while(temp->a!=x)
    {

        ++c;
        temp=temp->nextlink;
        ++j;
        if(j==i)
        break;
    }
    if(j==i)
        return 0;
    else
        return c;
}
void sorting()
{

    temp=head;
    while(temp!='\0')
    {

        next=temp->nextlink;
        while(next!='\0')
        {

            if(temp->a > next->a)
            {

                int t;
                t=temp->a;
                temp->a=next->a;
                next->a=t;
            }
            next=next->nextlink;
        }
        temp=temp->nextlink;
    }
}
void merging()
{
    int x,i=0,m,n;
cout<<"\n enter no of data items of list1:";
cin>>m;
cout<<"\n enter the data items of list1 in sorted order:";
for(i=0;i<m;++i)
{
     node *n=new node;
    n->nextlink='\0';
    n->prevlink='\0';
    cin>>n->a;
    if(head1=='\0')
    {

        head1=n;
        curr=head1;
    }
    else{
        curr->nextlink=n;
        curr=n;
    }
    }
    cout<<"\n enter no of data items of list2:";
    cin>>n;
cout<<"\n enter the data items of list2 in sorted order:";
for(i=0;i<n;++i)
{
    node *n=new node;
    n->nextlink='\0';
    cin>>n->a;
    if(head2=='\0')
    {

        head2=n;
        curr=head2;
    }
    else{
        curr->nextlink=n;
        curr=n;
    }
}
 node *p1,*p2;
p1=new node;
p2=new node;
p1=head1;
p2=head2;

while(p1!='\0' && p2!='\0')
{

if((p1->a) < (p2->a))
{
x=p1->a;
insertend(x);
p1=p1->nextlink;
}
else
{
x=p2->a;
insertend(x);
p2=p2->nextlink;
}
}
while(p1!='\0')
{
x=p1->a;
insertend(x);
p1=p1->nextlink;
}
while(p2!='\0')
{
x=p2->a;
insertend(x);
p2=p2->nextlink;
}
cout<<"\n the merged list is:";
display();
}
void dispreverse(node *t)
{

    if(t=='\0')
        return;
    else
    {

        dispreverse(t->nextlink);
        cout<<t->a<<" ";
    }
}*/
int main()
{

    int x,pos,y,b;
    do
    {

        cout<<"\n 1.insertion at beg \n 2.insertion at given position \n 3.insertion after a given data item";
        cout<<"\n 4.insertion at end \n 5.delete a data item \n 6.delete at a particular position \n 7.search \n 8.sorting\n 9.merging \n 10.reverse display \n 11.display \n 12.exit:";
        cin>>b;
        switch(b)
        {

            case 1: cout<<"\n enter a number:";
            cin>>x;
            insertbeg(x);
            ++i;
            break;
            case 2: cout<<"\n enter a number:";
            cin>>x;
            cout<<"\n enter the position:";
            cin>>pos;
            insertpos(x,pos);
            ++i;
            break;
            case 3: cout<<"\n enter a number:";
            cin>>x;
            cout<<"\n enter the data item after which it should be placed:";
            cin>>y;
            insertitem(x,y);
            ++i;
            break;
            case 4:cout<<"\n enter a number:";
            cin>>x;
            insertend(x);
            ++i;
            break;
            case 5:cout<<"\n enter the element to be deleted:";
            cin>>x;
            del(x);
            --i;
            break;
            case 6: cout<<"\n enter the position at which the data item should be deleted:";
            cin>>pos;
            del1(pos);
            --i;
            break;
            /*case 7: cout<<"\n enter the data item to be searched:";
            cin>>x;
            y=sea(x);
            if(y==0)
                cout<<"\n element not found";
            else
                cout<<"\n element found in position "<<y;
            break;
            case 8:sorting();
            break;
            case 9:merging();
            break;
            case 10:
                dispreverse(head);
            break;*/
            case 11:cout<<"\n the data items are:";
            display();
            break;
            case 12:exit (0);
        }
    }while(b!=12);
    return 0;
}
