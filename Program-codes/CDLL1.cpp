#include<iostream>
#include<stdlib.h>
using namespace std;
int i=0;
struct node
{
    int a;
    node *nextlink;
    node *prevlink;
}*head='\0',*temp,*prev,*next,*head1='\0',*head2='\0',*curr,*l;
void insertbeg(int x)
{
    node *n;
    n=new node;
    n->a=x;
    n->nextlink='\0';
    n->prevlink='\0';
    if(head=='\0')
    {
        head=n;
        n->nextlink=n;
        n->prevlink=n;

    }
    else
    {
        (head->prevlink)->nextlink=n;
        n->prevlink=head->prevlink;
        n->nextlink=head;
        head->prevlink=n;
        head=n;
    }
}
void insertpos(int x, int pos)
{
    int c=1;
    node *n;
    n=new node;
    n->a=x;
    n->nextlink='\0';
    n->prevlink='\0';
    temp=head;
    while(c!=pos)
    {
        prev=temp;
        temp=temp->nextlink;
        ++c;
    }
    prev->nextlink=n;
    n->prevlink=temp->prevlink;
    temp->prevlink=n;
    n->nextlink=temp;
    if(pos==1)
        head=n;
}
void insertitem(int x, int y)
{
    node *n;
    n=new node;
    n->a=x;
    n->nextlink='\0';
    n->prevlink='\0';
    temp=head;
    while(temp->a!=y)
    {
        temp=temp->nextlink;
    }
    (temp->nextlink)->prevlink=n;
    n->nextlink=temp->nextlink;
    temp->nextlink=n;
    n->prevlink=temp;
}
void insertend(int x)
{
    node *n;
    n=new node;
    n->prevlink='\0';
    n->nextlink='\0';
    n->a=x;
    temp=head;
    if(head=='\0')
    {
        n->nextlink=n;
        n->prevlink=n;
        head=n;
    }
    else
    {
        while(temp->nextlink!=head)
            temp=temp->nextlink;
        n->prevlink=temp;
        n->nextlink=head;
        temp->nextlink=n;
        head->prevlink=n;
    }
}
void del(int x)
{

    node *n;
    n=new node;
    n->nextlink='\0';
    n->prevlink='\0';
    n->a=x;
    temp=head;
    l=head;
    while(temp->a!=x && temp->nextlink!=head)
    {
        prev=temp;
        temp=temp->nextlink;
    }
    if(temp->a==x)
    {
        if(temp==head)
        {
            while(l->nextlink!=head)
                l=l->nextlink;
            l->nextlink=temp->nextlink;
            (temp->nextlink)->prevlink=l;
            head=temp->nextlink;
            temp->nextlink='\0';
            temp->prevlink='\0';
            delete temp;
        }
        else{
        (temp->prevlink)->nextlink=temp->nextlink;
        (temp->nextlink)->prevlink=temp->prevlink;
        temp->nextlink='\0';
        temp->prevlink='\0';
        delete temp;}
    }
    else
        cout<<"\n no such element to delete";
    }
    void del1(int pos)
    {
        int c=1;
        temp=head;
        while(c!=pos && temp->nextlink!=head)
        {
            prev=temp;
            temp=temp->nextlink;
            ++c;

        }
        if(c==pos)
        {
             if(temp==head)
        {
            while(l->nextlink!=head)
                l=l->nextlink;
            l->nextlink=temp->nextlink;
            (temp->nextlink)->prevlink=l;
            head=temp->nextlink;
            temp->nextlink='\0';
            temp->prevlink='\0';
            delete temp;
        }
        else{
        (temp->prevlink)->nextlink=temp->nextlink;
        (temp->nextlink)->prevlink=temp->prevlink;
        temp->nextlink='\0';
        temp->prevlink='\0';
        delete temp;}
        }
        else
         cout<<"\n no such position exists";
    }
    int sea(int x)
    {
        int c=1;
        temp=head;
        while(temp->a!=x && temp->nextlink!=head)
        {

            temp=temp->nextlink;
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
        while(temp->nextlink!=head)
        {
            next=temp->nextlink;
            while(next!=head)
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
    void display()
{
    node *p;
    p=new node;
    for(p=head;p->nextlink!=head;p=p->nextlink)
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
    n->nextlink='\0';
    n->prevlink='\0';
    cin>>n->a;
    temp=head1;
    if(head1=='\0')
    {

       // head1=n;
        n->prevlink=n;
        n->nextlink=n;
        head1=n;
    }
    else{
        while(temp->nextlink!=head1)
            temp=temp->nextlink;
        n->prevlink=temp;
        n->nextlink=head1;
        temp->nextlink=n;
        head1->prevlink=n;
    }
    }
    cout<<"\n enter no of data items of list2:";
    cin>>n;
cout<<"\n enter the data items of list2 in sorted order:";
for(i=0;i<n;++i)
{
    node *n=new node;
    n->nextlink='\0';
    n->prevlink='\0';
    cin>>n->a;
    temp=head2;
    if(head2=='\0')
    {

       // head2=n;
        n->nextlink=n;
        n->prevlink=n;
        head2=n;
    }
    else{
         while(temp->nextlink!=head2)
            temp=temp->nextlink;
        n->prevlink=temp;
        n->nextlink=head2;
        temp->nextlink=n;
        head2->prevlink=n;
    }
}
 node *p1,*p2;
p1=new node;
p2=new node;
p1=head1;
p2=head2;

while(p1->nextlink!=head1 && p2->nextlink!=head2)
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
while(p1!=head1)
{
x=p1->a;
insertend(x);
p1=p1->nextlink;
}
while(p2!=head2)
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

    if(t==head)
    {
        return;}
    else
    {

        dispreverse(t->nextlink);
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
                dispreverse(head->nextlink);
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
