#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
int a[10][10],i,j,k,n,qu[10],front,rear,v,visit[10],visited[10];
void bfs(int  );
int main()
{
int m,t=1;
cout <<"enterno of vertices";
cin >> n;
cout <<"ente no of edges";
cin >> m;
cout <<"\nEDGES \n";
for(k=1;k<=m;k++)
{
cin >>i>>j;
a[i][j]=1;
a[j][i]=1;
}
for(int i=1;i<=n;++i)
{
if(visited[i]==0)
{
cout<<"\n";
for(int p=0;p<10;++p)
{   qu[p]=0;
    visit[p]=0;
}
rear=0;
front=0;
cout<<"\n connected component "<<t<<":";
++t;
bfs(i);
}
}
return 0;
}
void bfs(int x)
{
v=x;
cout<<v<<" ";
visited[v]=1;
k=1;
while(k<n)
{
for(j=1;j<=n;j++)
{
if(a[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
{
visit[j]=1;
qu[rear++]=j;
}}
v=qu[front++];
if(v!=0)
cout<<v<<" ";
k++;
visit[v]=0; visited[v]=1;
}
}
