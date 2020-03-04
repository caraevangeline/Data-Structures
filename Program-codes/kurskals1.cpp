#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
int a[10][10],i,j,k,n,qu[10],front,rear,v,visit[10],visited[10],min1,x,y,b[10][10];
int bfs();
void minimum()
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
min1=t;
}
int h;
while(c!=m)
{
minimum();
h=min1;
min1=1000;
for(int p=0;p<10;++p)
{
    visited[p]=0;
    visit[p]=0;
}
rear=0;
front=0;
t=bfs();
if(t==1)
{
    b[x][y]=h;
    b[y][x]=h;
}
++c;
}
for(int i=1;i<=n;++i)
{
    for(int j=1;j<=n;++j)
    {
       cout<<b[i][j]<<" ";
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
    if(visited[y]==1)
        return 0;
    else
        return 1;
}
