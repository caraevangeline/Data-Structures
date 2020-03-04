#include<iostream>
using namespace std;
int edge=0,min1,x,y;
struct node
{
int a,w;
node *link;
}*m[10],*t;
int a[10][10];
void minimum(int n);
int v[10];
int checkcycle(int b,int j)
{
    int flag=0;
    for(int i=0;i<j;++i)
    {
        if(v[i]==b)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
        v[j]=b;
        if(m[b]=='\0')
            return 1;
        else
        {
            t=m[b];
            while(t!='\0')
            {
                ++j;
                checkcycle(t->a,j);
                t=t->link;
            }
        }
}
void spanning(int v)
{
    int c=0,b,o;
    while(c!=edge)
    {
        minimum(v);
        min1=1000;
        o=checkcycle(x,c);
        for(i=0;i<c;++i)
        {
            if(v[i]==x)
            {
                flag=1;
                break;
            }
        }
        for(i=0;i<c;++i)
        {
            if(v[i]==y)
            {
                flag1=1;
                break;
            }
        }
        if(o==1)
        {
            node *n=new node;
            n->a=x;
            n->w=b;
            n->link='\0';
            if(m[y]=='\0')
                m[y]=n;
            else
            {
                t=m[y];
                while(t->link!='\0')
                    t=t->link;
                t->link=n;
            }
            node *n1=new node;
            n1->a=y;
            n1->w=b;
            n1->link='\0';
            if(m[x]=='\0')
                m[x]=n1;
            else
            {
                t=m[x];
                while(t->link!='\0')
                    t=t->link;
                t->link=n1;
            }
        }
        ++c;
    }
}
int main()
{
    int i=1,j=1,x,n;
    char ch;
    cout<<"\n enter the no of vertices:";
    cin>>n;
    for(i=1;i<=n;++i)
    {
        for(j=i;j<=n;++j)
        {
            cout<<i<<"-"<<j<<"?\n";
            cin>>ch;
            if(ch=='y')
            {
                ++edge;
                cout<<"\n enter the cost of the edge:";
                cin>>x;
                a[i][j]=x;
                a[j][i]=x;
                min1=a[i][j];
            }
            else
            {
                a[i][j]=0;
                a[j][i]=0;
            }
        }
    }
    spanning(n);
    /*for(i=1;i<=n;++i)
    {
        t=m[i];
        cout<<i<<"->";
        while(t->link!='\0')
        {
            cout<<t->a<<" ";
            t=t->link;
        }
        cout<<"\n";
    }*/
    return 0;
}
void minimum(int n)
{
    int i,j;
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=n;++j)
        {
            if(a[i][j]<min1 && a[i][j]!=0)
            {
                min1=a[i][j];
                x=i;
                y=j;
            }
        }
    }
    a[x][y]=0;
                a[y][x]=0;
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=n;++j)
        cout<<a[i][j]<<" ";
        cout<<"\n";
    }
    cout<<min1<<" ";
}
