#include<iostream>
#include<stdlib.h>
using namespace std;
int i=0;
struct node
{

    int a;
    node *link;
}*head='\0',*temp,*next,*l,*head1='\0',*head2='\0',*prev,*t;
void insertbeg(int x)
{
    node *n;
    n=new node;
    n->link='\0';
    n->a=x;
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
            temp=temp->link;
        temp->link=n;
        head=n;
    }
}
void insertpos(int x, int pos)
{

    int c=1;
    node *n;
    n=new node;
    n->link='\0';
    n->a=x;
    temp=head;
    if(pos==1)
    {
        n->link=head;
        while(temp->link!=head)
            temp=temp->link;
        temp->link=n;
        head=n;
    }
    else
    {
        while(c!=pos)
        {

            prev=temp;
            temp=temp->link;
            ++c;
        }
        prev->link=n;
        n->link=temp;
    }
}
void insertitem(int x, int y)
{
    node *n;
    n=new node;
    n->link='\0';
    n->a=x;
    temp=head;
    while(temp->a!=y)
    {
        temp=temp->link;
    }
    n->link=temp->link;
    temp->link=n;
}
void insertend(int x)
{

    node *n;
    n=new node;
    n->link='\0';
    n->a=x;
    temp=head;
    if(head=='\0')
    {

        head=n;
        n->link=n;
    }
    else
    {
        while(temp->link!=head)
            temp=temp->link;
        n->link=temp->link;
        temp->link=n;
    }
}
void del(int x)
{
    l=head;
    temp=head;
    while(temp->a!=x && temp->link!=head)
    {
        prev=temp;
        temp=temp->link;;
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
    else
        cout<<"\n no such element to delete";
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
    else
        cout<<"\n no such position to delete";
}
int sea(int x)
{
    int c=1;
    temp=head;
    while(temp->a!=x && temp->link!=head)
    {
        temp=temp->link;
        ++c;
    }
    if(temp->a==x)
        return c;
    else
        return 0;
}
void sorting()
{
    temp=head;
    while(temp->link!=head)
    {
        next=temp->link;
        while(next!=head)
        {
            if(temp->a >next->a)
            {
                int t;
                t=temp->a;
                temp->a=next->a;
                next->a=t;
            }
            next=next->link;
        }
        temp=temp->link;
    }
}
void display()
{
    node *p;
    p=new node;
    for(p=head;p->link!=head;p=p->link)
        cout<<p->a<<" ";
        cout<<p->a;

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
    n->link='\0';
    cin>>n->a;
    temp=head1;
    if(head1=='\0')
    {

        head1=n;
        n->link=n;
    }
    else{
        while(temp->link!=head1)
            temp=temp->link;
        n->link=temp->link;
        temp->link=n;
    }
    }
    cout<<"\n enter no of data items of list2:";
    cin>>n;
cout<<"\n enter the data items of list2 in sorted order:";
for(i=0;i<n;++i)
{
    node *n=new node;
    n->link='\0';
    cin>>n->a;
    temp=head2;
    if(head2=='\0')
    {

        head2=n;
        n->link=n;
    }
    else{
        while(temp->link!=head2)
            temp=temp->link;
        n->link=temp->link;
        temp->link=n;
    }
}
 node *p1,*p2;
p1=new node;
p2=new node;
p1=head1;
p2=head2;

while(p1->link!=head1 && p2->link!=head2)
{

if((p1->a) < (p2->a))
{
x=p1->a;
insertend(x);
p1=p1->link;
}
else
{
x=p2->a;
insertend(x);
p2=p2->link;
}
}
while(p1!=head1)
{
x=p1->a;
insertend(x);
p1=p1->link;
}
while(p2!=head2)
{
x=p2->a;
insertend(x);
p2=p2->link;
}
cout<<"\n the merged list is:";
display();
}
void dispreverse(node *t)
{

    if(t==head)
    {
        return;}
    else
    {

        dispreverse(t->link);
        cout<<t->a<<" ";
    }

}
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
            case 7: cout<<"\n enter the data item to be searched:";
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
                dispreverse(head->link);
                cout<<head->a;
            break;
            case 11:cout<<"\n the data items are:";
            display();
            break;
            case 12:exit (0);
        }
    }while(b!=12);
    return 0;
}
