#include<iostream>
using namespace std;
struct node
{
    int a;
    node *link;
}*head1='\0',*head2='\0',*temp,*prev,*temp1;
void perform()
{
    int l1,l2,i,i1,i2,lenth,c=0,p1,p2;
    cout<<"\n enter no of data items in list1:";
    cin>>l1;
    cout<<"\n enter the data items:";
    for(i=0;i<l1;++i)
    {
        node *n=new node;
        n->link='\0';
        cin>>n->a;
        temp=head1;
        if(head1=='\0')
        head1=n;
        else
        {
            while(temp->link!='\0')
                temp=temp->link;
            temp->link=n;
        }
    }
    cout<<"\n enter no of data items in list2:";
    cin>>l2;
    cout<<"\n enter the data items:";
    for(i=0;i<l2;++i)
    {
        node *n=new node;
        n->link='\0';
        cin>>n->a;
        temp=head2;
        if(head2=='\0')
        head2=n;
        else
        {
            while(temp->link!='\0')
                temp=temp->link;
            temp->link=n;
        }
    }
    node *p;
    p=new node;
    for(p=head1;p!='\0';p=p->link)
        cout<<p->a<<" ";
        for(p=head2;p!='\0';p=p->link)
        cout<<p->a<<" ";
    cout<<"\n enter the position of list 1 from which elements must be inserted:";
    cin>>i1;
    cout<<"\n enter the position of list 2 from which elements must be taken:";
    cin>>i2;
    cout<<"\n enter no of elements to be taken:";
    cin>>lenth;
    if(i1>l1+1 || i2+lenth-1>l2 || i1<1 ||i2<1)
        cout<<"\n operation not possible:";
    else
    {
        while(c!=lenth)
        {
            p1=1;
            temp=head2;
            node *n=new node;
            for(p=head2;p!='\0';p=p->link)
            cout<<p->a<<" ";
            while(p1!=i2)
            {
                temp=temp->link;
                n=temp;
                cout<<n->a<<" ";
                p1++;
            }
             //cout<<n->a<<" ";
            i2++;
            p2=1;
            temp1=head1;
            while(p2!=i1)
            {
                prev=temp1;
                temp1=temp1->link;
                p2++;
            }
            prev->link=n;
            n->link=temp1;

            i1++;
            ++c;
        }
    }
    //for(p=head1;p!='\0';p=p->link)
      //  cout<<p->a<<" ";
}
int main()
{
    perform();
    return 0;
}
