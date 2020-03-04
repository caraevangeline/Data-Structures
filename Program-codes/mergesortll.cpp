#include<iostream>
using namespace std;
void mergesort(int,int);
void merge(int,int,int);
struct node
{
    int data;
    node *link;
}*head='\0',*head1='\0',*temp;
void insert(int x)
{
    temp=head1;
    node *n=new node;
    n->data=x;
    n->link='\0';
    if(head1=='\0')
        head1=n;
    else
        {
        while(temp->link!='\0')
        temp=temp->link;
    temp->link=n;
    }
}
int getn(int k,node *h)
{
    cout<<"\n hello:";
    int c=1;
    temp=h;
    while(c!=k)
    {
        temp=temp->link;
        ++c;
    }
    int x=temp->data;
    return x;
}
void copy1(int a,int k)
{
    cout<<"j";
    int c=1;
    temp=head;
    while(c!=k)
    {
        temp=temp->link;
        ++c;
    }
    temp->data=a;
}
int main()
{
    int n;
    cout<<"\n enter no of elements:";
    cin>>n;
    temp=head;
    for(int i=0;i<n;++i)
    {
        cout<<"\nEnter data:";
        node *x=new node;
        cin>>x->data;
        x->link='\0';
        if(head=='\0')
            head=x;
        else
        {
            temp=head;
            while(temp->link!='\0')
                temp=temp->link;
            temp->link=x;
        }
    }
    mergesort(1,n);
    cout<<"\n after sorting";
    temp=head;
    while(temp!='\0')
        cout<<temp->data<<" ";
    return 0;
}
void mergesort(int i,int j)
{
    int mid;
    if(i<j)
    {
        cout<<"hI\n";
        mid=(i+j)/2;
        mergesort(i,mid);
        mergesort(mid+1,j);
        merge(i,mid,j);
    }
}
void merge(int low,int mid ,int high)
{
   int h,i,j,k;
   h=low;
   i=low;
    j=mid+1;
 int a,b;

   while(h<=mid && j<=high)
   {
       cout<<"\n ok";
       a=getn(h,head);
       b=getn(j,head);
       //cout<<a<<" "<<b;
      if(a<=b)
      {
          insert(a);
          ++h;
      }
      else
      {
          insert(b);
          ++j;
      }
   }

   if( h > mid)
   {
       for(k=j;k<=high;++k)
       {
           a=getn(k,head);
           insert(a);
           ++i;
       }
   }
   else
   {
       for(k=h;k<=mid;++k)
       {
           a=getn(k,head);
           insert(a);
           ++i;
       }
   }

   cout <<"\n";
   for(k=low;k<=high;k++)
   {
       a=getn(k,head1);
       copy1(a,k);
      // cout<<a;
   }

}
