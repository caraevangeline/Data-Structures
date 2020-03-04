#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
int a[10][10],i,j,k,n,qu[10],front,rear,v,visit[10],visited[10],max1,x,y,b[10][10],d[10][10],h;
int bfs();
void maximum()
{
    int i,j;

    for(i=1;i<=n;++i)
    {
        for(j=1;j<=n;++j)
        {
            if(d[i][j]>=max1)
            {

            max1=d[i][j];
                x=i;
                y=j;
            }
        }
    }
    d[x][y]=0;
    d[y][x]=0;
    //h=max1;
cout<<"&"<<max1<<x<<y<<"&";
}
int main()
{
int m,c=0,t;
cout <<"enterno of vertices";
cin >> n;
cout <<"ente no of edges";
cin >> m;
cout <<"\nEDGES \n";
for(k=1;k<=m;k++)
{
cin >>i>>j;
cin>>t;
a[i][j]=t;
a[j][i]=t;
max1=t;
}
for(int s=1;s<=n;++s)
{
    for(int r=1;r<=n;++r)
        d[s][r]=a[s][r];
}
while(c!=m)
{

maximum();
max1=0;
for(int p=0;p<10;++p)
{
    visited[p]=0;
    visit[p]=0;
}
rear=0;
front=0;
for(int s=1;s<=n;++s)
{
    for(int r=1;r<=n;++r)
        b[s][r]=a[s][r];
}
b[x][y]=0;
b[y][x]=0;
t=bfs();
cout<<t;
if(t==1)
{
    a[x][y]=0;
    a[y][x]=0;
}
++c;
}
for(int i=1;i<=n;++i)
{
    for(int j=1;j<=n;++j)
    {
       cout<<a[i][j]<<" ";
    }
    cout<<"\n";
}
return 0;
}
int bfs()
{
v=x;
visited[v]=1;
k=1;
while(k<n)
{
for(j=1;j<=n;j++)
{
if(b[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
{
visit[j]=1;
qu[rear++]=j;
}}
v=qu[front++];
k++;
visit[v]=0; visited[v]=1;
}
int c=0;
for(int o=1;o<=n;++o)
{

    if(visited[o]==1)
        ++c;
}
if(c==n)
    return 1;
else
    return 0;
}
