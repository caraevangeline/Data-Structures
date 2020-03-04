#include<iostream>
#include<cstdlib>
using namespace std;
struct student
{
    int rno;
    char name[20];
    student *link;
}*head,*temp,*temp1,*p;
struct node
{
    int key;
    student *slink;
}*t,*prev;
node *hash[20];
int n=7;
void del1(student *n)
{
    temp=head;
    while(temp->rno!=n->rno)
    {
        p=temp;
        temp=temp->link;
    }
    if(temp==head)
        head=head->link;
    else if(temp->link=='\0')
        p->link='\0';
    else
    {
        p->link=temp->link;
        temp->link='\0';
    }
}
void del()
{
    int no,flag=0;
    cout<<"\n enter roll no to be deleted:";
    cin>>no;
    student *n=new student;
    for(int i=0;i<7;++i)
    {
        if(hash[i]->key==no)
        {
            flag=1;
            cout<<"\n student deleted:";
            n=hash[i]->slink;
            hash[i]='\0';
            del1(n);
            break;
        }
    }
    if(flag==0)
        cout<<"\n student not found";
}
void insert()
{
    cout<<"\n enter student details:";
    student *s=new student;
    s->link='\0';
    cout<<"\n enter rno:";
    cin>>s->rno;
    cout<<"\n enter name:";
    cin>>s->name;
    int k;
    k=(s->rno)%7;
    node *n=new node;
    n->key=s->rno;
    n->slink=s;
    int y;
    if(hash[k]=='\0')
       {
         hash[k]=n;
         if(head=='\0')
    {
        head=s;
        temp1=s;
    }
    else
    {
        temp1->link=s;
        temp1=s;
    }
    cout<<"\n inserted into the list:";
    cout<<"\n inserted into hash table:";
       }
    else
    {
        y=k;
        for(int i=0;i<7;++i)
    {
        k=y;
        k=(k+(i*i))%7;
        if(hash[k]=='\0')
        {
            hash[k]=n;
            if(head=='\0')
    {
        head=s;
        temp1=s;
    }
    else
    {
        temp1->link=s;
        temp1=s;
    }
    cout<<"\n inserted into the list:";
    cout<<"\n inserted into hash table:";
            break;
        }


    }}

}
void displayhash()
{
    for(int i=0;i<7;++i)
    {
        cout<<i<<"->";
        if(hash[i]!='\0')
            cout<<hash[i]->key;
        cout<<"\n";
    }
}
void displaylist()
{
    temp=head;
    while(temp!='\0')
    {
        cout<<temp->rno<<" "<<temp->name;
        temp=temp->link;
        cout<<"\n";
    }
}
void search()
{
    int key,flag=0;
    cout<<"\n enter the rno to be searched:";
    cin>>key;
    student *n=new student;
    for(int i=0;i<7;++i)
    {
        if(hash[i]->key==key)
        {
            flag=1;
            n=hash[i]->slink;
            break;
        }
    }
    if(flag==0)
        cout<<"\n student not found";
    else
    {
        cout<<"\n Roll no:"<<n->rno;
        cout<<"\n Name:"<<n->name;
    }
}
int main()
{
    int ch,x;
    do
    {
        cout<<"\n1.insert \n2.delete \n3.display list \n4.display hash table \n5.search \n6.exit:";
        cin>>ch;
        switch(ch)
        {
            case 1:x=0;
                for(int i=0;i<7;++i)
        {
            if(hash[i]!='\0')
        ++x;}
        if(x==7)
            {cout<<"\n no more insertions";
            break;
            }
insert();
            break;
            case 2:del();
            break;
            case 3:displaylist();
            break;
            case 4:displayhash();
            break;
            case 5:search();
            break;
            case 6:exit(0);
        }
    }while(ch!=6);
    return 0;
}
