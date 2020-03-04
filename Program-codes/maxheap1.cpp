#include<iostream>
#include<cstdlib>
using namespace std;
int i=1,k=0,h[50],p=1;
void insertheap(int x)
{
    int t;
    k++;
    h[k]=x;
    i=k;
    while(i!=0)
    {
        if(i/2==0)
            break;
        if(h[i]<h[i/2])
        {
            t=h[i];
            h[i]=h[i/2];
            h[i/2]=t;
            i=i/2;
        }
        else
            break;
    }
}
int del()
{
    int x,t;
    x=h[1];
    h[1]=h[k];
    p=1;
    while(p!=k)
    {
        if((2*p)+1>k)
        break;
        if(h[p]>h[2*p] || h[p]>h[(2*p)+1])
        {
            if(h[2*p]<h[(2*p)+1])
            {
                t=h[p];
                h[p]=h[2*p];
                h[2*p]=t;
                p=2*p;
            }
            else
            {
                t=h[p];
                h[p]=h[(2*p)+1];
                h[(2*p)+1]=t;
                p=(2*p)+1;
            }
            }
            else
                break;
        }
            --k;
        return x;

}
void display()
{
    int j;
    for(j=1;j<=k;++j)
        cout<<h[j]<<" ";
}
int main()
{
    int ch,x;
    do
    {
        cout<<"\n1.insert \n2.delete \n3.display \n4.exit:";
        cin>>ch;
        switch(ch)
        {
        case 1:cout<<"\n enter data:";
        cin>>x;
                insertheap(x);
            break;
            case 2:x=del();
            cout<<x<<" ";
            break;
            case 3:display();
            break;
            case 4:exit(0);
        }
    }while(ch!=4);
    return 0;
}
