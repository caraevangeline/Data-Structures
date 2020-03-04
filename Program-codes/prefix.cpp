#include<iostream>
using namespace std;
#include<string.h>
const int size=100;
int top=-1;
char st[100];
struct weight
{
    char b;
    int a;
}w[5]={{'^',100},{'*',99},{'/',99},{'+',98},{'-',98}};
void push(char ch)
{
    if(top==size-1)
        cout<<"\n overflow";
    else
    {
        top=top+1;
        st[top]=ch;
    }
}
char pop()
{int g;
    if(top==-1)
        cout<<"\n underflow";
    else
    {    g=top;
    top=top-1;
        return st[g];
        }
}
int main()
{

    char ch1[100],s,o[50],ch[100];
    int l,j=0,i,a,x,b=0,y,t,z;
    cout<<"\n enter the infix expression:";
    cin>>ch1;
    l=strlen(ch1);
    for(i=l-1;i>=0;--i)
    {
        ch[j]=ch1[i];
        ++j;
    }
    for(i=0;i<l;++i)
    {

        if(ch[i]=='(')
            ch[i]=')';
       else if(ch[i]==')')
            ch[i]='(';
    }
    for(i=0;i<l;++i)
    {
        if(ch[i]=='+' || ch[i]=='-'|| ch[i]=='^'|| ch[i]=='*' || ch[i]=='/')
        {
            for(j=top;j>=0 && st[j]!='(';--j)
            {
                if(st[j]=='+' || st[j]=='-'|| st[j]=='^'|| st[j]=='*' || st[j]=='/')
                {
                    for(a=0;a<5;++a)
                {
                    if(w[a].b==ch[i])
                        x=w[a].a;
                    if(w[a].b==st[j])
                    y=w[a].a;
                }
                if(y>=x)
                {
                    s=pop();
                    o[b]=s;
                    ++b;
                   // push(ch[i]);
                }
               // else
                    //push(ch[i]);
                }
                //else
                   // push(ch[i]);
            }

            push(ch[i]);
        }
        else if(ch[i]=='(')
                    push(ch[i]);
        else if(ch[i]==')')
        {
            z=top;
            while(st[z]!='(')
            {
                s=pop();
                o[b]=s;
                ++b;
                --z;
            }
            s=pop();
            //cout<<"\n "<<s;
        }
        else{
            o[b]=ch[i];
            ++b;
        }}
        for(t=b-1;t>=0;--t)
        cout<<o[t];
        return 0;

}
