#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
int cost[10][10],i,j,k,n,qu[10],front,rare,v,visit[10],visited[10];

main()
{
int m;
cout <<"enterno of vertices";
cin >> n;
cout <<"ente no of edges";
cin >> m;
cout <<"\nEDGES \n";
for(k=1;k<=m;k++)
{
cin >>i>>j;
cost[i][j]=1;
cost[j][i]=1;
}
for(i=1;i<=n;++i)
{
    for(j=1;j<=n;++j)
        cout<<cost[i][j]<<" ";
    cout<<"\n";
}
cout <<"enter initial vertex";
cin >>v;
cout <<"Visitied vertices\n";
cout << v<<" ";
visited[v]=1;
k=1;
while(k<n)
{
for(j=1;j<=n;j++)
{
if(cost[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
{
visit[j]=1;
qu[rare++]=j;
}}
v=qu[front++];
if(v!=0)
cout<<v << " ";
k++;
visit[v]=0; visited[v]=1;
}
for(int x=1;x<=n;++x)
    cout<<visited[x];
int c=0;
for(int x=1;x<=n;++x)
{

    if(visited[x]==1)
        ++c;
}
if(c==n)
    cout<<"\n Connected";
else
    cout<<"\n Not Connected";
}
