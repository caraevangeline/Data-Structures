#include<iostream>
using namespace std;
int const max2=1000;
int a[10][10],dist[10],shortest[10];
int min1(int n)
{
    int index,i;
    int min2=max2;
    for(i=0;i<n;i++)
    {
        if(shortest[i]==0&&dist[i]<=min2)
        {
            min2=dist[i];
            index=i;
        }
    }
    return index;
}
void dij(int n,int v)
{
    int i,j,x;
    for(i=0;i<n;i++)
    {
        dist[i]=max2;
        shortest[i]=0;
    }
    dist[v]=0;
    for(i=0;i<n-1;i++)
    {
        x=min1(n);
        shortest[x]=1;
        for(j=0;j<n;j++)
        {
            if(shortest[j]==0&&a[x][j]&&(dist[x]+a[x][j])<dist[j])
            dist[j]=dist[x]+a[x][j];
        }
    }
    cout<<"\ndistance from source\n";
    for(i=0;i<n;i++)
    cout<<i<<"  "<<dist[i]<<"\n";
    }
int main()
{
    int i,j,n;
    cout<<"n:\t";
    cin>>n;
    for(i=0;i<n;i++)
    {for(j=0;j<n;j++)
        {
            cin>>a[i][j];
    if(a[i][j]==-1)
        a[i][j]=max2;
        }
    }
    dij(n,0);
return 0;
}
