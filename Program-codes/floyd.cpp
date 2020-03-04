#include<iostream>
using namespace std;
int inf=1111;
int main()
{
    int a[10][10],i,j,k,b[10][10],n;
    cout<<"\n enter no of vertices:";
    cin>>n;
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            cin>>a[i][j];
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=n;++j)
            {
                if(a[i][j]==-1)
                    a[i][j]=inf;
                b[i][j]=a[i][j];

            }
        }
        for(int m=0;m<10;m++)
        {
            for(i=1;i<=n;++i)
        {
            for(j=1;j<=n;++j)
            {[]
                for(k=1;k<=n;++k)
                {
                    if(b[i][k]+b[k][j]<b[i][j])
                        b[i][j]=b[i][k]+b[k][j];
                }
            }
        }
        }
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=n;++j)
                cout<<b[i][j]<<" ";
            cout<<"\n";
        }
}
