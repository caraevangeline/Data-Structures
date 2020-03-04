#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<fstream>
#include<iostream>
using namespace std;
class node
{
public:
char name[15],usn[15];
node *link;
};
node *h[29]; //Array of record pointers
//equal to size of hash keys--29
class student
{
char sname[15],susn[15],buffer[25];
int count ;
public:
void insert();
void hash_insert();
void retrive();
};
void student::insert()
{
fstream out;
out.open("student.txt",ios::out|ios::app);
cout<<"\nEnter the name = ";
cin>>sname;
cout<<"\nEnter the usn = ";
cin>>susn;
strcpy(buffer,sname);
strcat(buffer,"|");
strcat(buffer,susn);
strcat(buffer,"\n");
out<<buffer;
out.close();
}
//Insert record into the hash table
void student::hash_insert()
{
node *p,*prev,*curr;
p=new node;
strcpy(p->name,sname);
strcpy(p->usn,susn);
p->link=NULL;
prev=NULL;
curr=h[count]; //getting the hash pointer location
if(h[count]==NULL) // Case: No collision
{
h[count]=p;
return;
}
while(h[count]!=NULL) // Case : On collision -- Insert at rear end
{
prev=curr;
curr=curr->link;
}
prev->link=p;
}
void student::retrive()
{
fstream in;
int j;
node *curr;
in.open("student.txt",ios::in);
while(!in.eof())
{
in.getline(sname,15,'|');
in.getline(susn,15,'\n');
count=0;
for(j=0;j<strlen(susn);j++)
{
count=(count*10)+(int)susn[j];
}
count=count%29; // Hash Key = ASCII count% 29
hash_insert();
}
char key[20];
cout<<"\nEnter the usn = ";
cin>>key;
count=0;
for(j=0;j<strlen(key);j++) // Calculating Hash Key
count=(count*10)+(int)key[j];
count=count%29;
curr=h[count];
while(curr!=NULL && strcmp(curr->usn,key)!=0)
{
curr=curr->link;
}
if(strcmp(curr->usn,key)==0)
{
cout<<"\n\nRecord found : "<<curr->usn<<" "<<curr->name;
getch();
return;
}
if(curr==NULL) //End of list reached with no record found
{
cout<<"\nRecord not found";
getch();
return;
}
}
int main()
{
int choice,p=1;
student s;
while(p)
{
cout<<"\n1:insert";
cout<<"\n2:retrive";
cout<<"\n3:exit";
cout<<"\n\nEnter the choice = ";
cin>>choice;
switch(choice)
{
case 1:s.insert();
break;
case 2:s.retrive();
break;
case 3:cout<<"\n@@@@@....THANKING U....@@@@@@\n";
p=0;
break;
default:cout<<"\n SORRY INVALID CHOICE.....!!!!!";
break;
}
}
return 0;
}
