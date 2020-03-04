#include<iostream>
using namespace std;
int f=-1,r=-1,q[50],size=50;
void insert(int x)
{
    if(r==size-1)
        cout<<"\n overflow";
    else
    {
        if(f==-1 && r==-1)
        {
            f=0;
            r=0;
        }
        else
            r=r+1;
        q[r]=x;
    }
}
int del()
{
    int x=q[f];
    if(r==-1)
       {

       }
    else
    {
        if(f==r)
        {
            f=-1;
            r=-1;
        }
        else if(f<r)
            f=f+1;

                }
    return x;
}
void bfs(int m[10][10],int u,int n)
{
    int k=0,j=1,i,c,flag=0;
    for(i=1;i<=n;++i)
    {
        if(i==u)
        {
            c=i;
            break;
        }
    }
    int v[10];
    v[0]=c;
    while(j<=n)
    {
        for(i=1;i<=n;++i)
        {
            flag=0;
            if(m[c][i]==1)
            {
                m[c][i]=2;
                m[i][c]=2;
                for(int a=0;a<j;++a)
                {
                    if(v[a]==i)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                    {
                        insert(i);
                        v[j]=i;
                    }
            }
        }
        c=del();
                ++j;
    }
    for(i=0;i<j;++i)
        cout<<v[i]<<" ";
    flag=0;
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=n;++j)
            cout<<m[i][j]<<" ";
        cout<<"\n";
    }
    for(i=1;i<=n;++i)
    {
        int count=0;
        for(j=1;j<=n;++j)
        {
            if(m[i][j]==0)
            ++count;
            if(m[i][j]==1)
            {
                flag=1;
                break;
            }
        }
        if(count==n)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
        cout<<"\n connected";
        else
            cout<<"\n not connected";
}
int main()
{
    int i,j,n,m[10][10],u;
    char ch;
    cout<<"\n enter the no of vertices:";
    cin>>n;
    for(i=1;i<=n;++i)
    {
        for(j=i;j<=n;++j)
        {
            cout<<i<<"-"<<j<<"?"<<"\n";
            cin>>ch;
            if(ch=='y')
            {
                m[i][j]=1;
                m[j][i]=1;
            }
            else
            {
                m[j][i]=0;
                m[i][j]=0;
            }
        }
    }
    cout<<"\n enter the vertex number:";
    cin>>u;
    bfs(m,u,n);
    return 0;
}
