#include<iostream>
#include<stdlib.h>
using namespace std;
int r=-1,f=-1,size=10,q[10];
void insertion(char ch,int x)
{
if(ch=='f')
{
if(f==0)
cout<<"\n insertion at front not possible";
else if(f==-1 && r==-1)
{
    f=0;
    r=0;
    q[f]=x;
}
else
{
f=f-1;
q[f]=x;
}
}
else
{
if(r==size-1)
cout<<"\n insertion at rear not possible";
else if(f==-1 && r==-1)
{
    f=0;
    r=0;
    q[f]=x;
}
else
{
r=r+1;
q[r]=x;
}
}
}
void del(char ch)
{
if(ch=='f')
{
if(f<r)
f=f+1;
else if(f==r)
{
    if(f==-1 && r==-1)
cout<<"\n empty";
f=-1;
r=-1;
}
}
else
{
if(f<r)
r=r-1;
else if(f==r)
{
    if(f==-1 && r==-1)
cout<<"\n empty";
r=-1;
f=-1;
}
}
}
void display()
{
for(int i=f;i<=r;++i)
cout<<q[i]<<" ";
}
int main()
{
    int a,x;
    char ch;
do
{
cout<<"\n1.insert \n2.delete \n3.display \n4.exit:";
cin>>a;
switch(a)
{
    case 1:cout<<"\n front=f \n rear=r:";
    cin>>ch;
    cout<<"\n enter a number:";
    cin>>x;
    insertion(ch,x);
    break;
    case 2:cout<<"\n front=f \n rear=r:";
    cin>>ch;
    del(ch);
    break;
    case 3:display();
    break;
    case 4:exit(0);

}
}while(a!=4);
return 0;
}
