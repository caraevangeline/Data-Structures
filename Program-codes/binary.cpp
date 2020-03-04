#include<iostream>
using namespace std;
int top=-1;
int size=50,s[50];
int push(int x)
{
if(top==size-1)
cout<<"\n overflow";
else
{
top=top+1;
if(x==0 || x==1)
s[top]=x;
else
{
push(x/2);
push(x%2);
}
}
}
void pop()
{
    int i;
if(top==-1)
cout<<"\n underflow";
else
{
for(i=0;i<=top;++i)
cout<<s[i];
}
}
int main()
{
    int n;
cout<<"\n enter a decimal number:";
cin>>n;
push(n);
pop();
}
