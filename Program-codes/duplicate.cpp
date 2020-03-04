#include<fstream>
#include<iostream>
using namespace std;
#include<conio.h>
#include<string.h>
struct det
{
char s[30];
int a;
}d[20],t;
int main()
{
//clrscr();
int i=0,j=0,n,b=0,k;
char str[20][30],ch;
ifstream a;
a.open("details.txt");
while(!a.eof())
{
ch=a.get();
if(ch=='\n' || ch==' ' || ch=='.')
{
j=0;
++i;
}
else
{
str[i][j]=ch;
++j;
}
}
n=i;
a.close();
for(i=0;i<n;++i)
{     b=0;
strcpy(d[i].s,str[i]);
for(j=0;j<n;++j)
{
if(strcmp(str[i],str[j])==0)
{
++b;
strcpy(d[i].s,str[i]);
d[i].a=b;
}
}                 }
for(i=0;i<n-1;++i)
{
for(j=1;j<n-i;++j)
{
if(strcmp(d[j-1].s, d[j].s)>0)
{
t=d[j-1];
d[j-1]=d[j];
d[j]=t;
}
}
}
for(i=0;i<n;++i)
{
for(j=i+1;j<n;++j)
{
if(strcmp(d[i].s,d[j].s)==0)
{
for(k=i;k<n-2;++k)
{
d[k+1]=d[k+2];
}
n=n-1;
j=j-1;
}
}
}
cout<<"\n the string and it's count:";
for(i=0;i<n;++i)
{
cout<<d[i].s<<" - "<<d[i].a;
cout<<"\n";
}
//getch();
return 0;
}
