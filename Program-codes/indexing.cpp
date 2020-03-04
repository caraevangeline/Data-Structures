#include<iostream>
using namespace std;
#include<cstdio>
#include<fstream>
#include<cstdlib>
#include<cstring>
class Person
{
int add[10],count;
char usnl[10][10];
char usn[30];
char name[30];
char address[30];
char branch[30];
char college[30];
char buffer[100];
public:
void input();
void creatind();
void search();
void remove();
void pack();
void sort();
int searchusn(char[20]);
void Write();
};
void Person :: input()
{
cout<<"Enter Usn"<<endl;
cin>>usn;
cout<<"Enter Name"<<endl;
cin>>name;
cout<<"Enter Address"<<endl;
cin>>address;
cout<<"Enter Branch"<<endl;
cin>>branch;
cout<<"Enter College"<<endl;
cin>>college;
}
void Person::pack()
{
strcpy(buffer,usn); strcat(buffer,"|");
strcat(buffer,name); strcat(buffer,"|");
strcat(buffer,address); strcat(buffer,"|");
strcat(buffer,branch); strcat(buffer,"|");
strcat(buffer,college); strcat(buffer,"|");
strcat(buffer,"#");
}
void Person:: Write()
{
fstream os("pt.txt",ios::out|ios::app);
os.write(buffer,strlen(buffer));
os<<endl;
os.close();
}
void Person::creatind()
{
int pos;
count=-1;
fstream file;
file.open("pt.txt",ios::in);
while(file)
{
pos=file.tellg();
file.getline(buffer,'#');
if(*buffer=='$')
continue;
if(file.eof())
break;
char *ptr=buffer;
while(*ptr!='|')
ptr++;
*ptr='\0';
strcpy(usnl[++count],buffer);
add[count]=pos;
}
file.close();
sort();
}
void Person::sort()
{
int i,j,addlist;
char temp[20];
for(i=0;i<=count;i++)
{
for(j=i+1;j<=count;j++)
{
if(strcmp(usnl[i],usnl[j])>0)
{
strcpy(temp,usnl[i]);
strcpy(usnl[i],usnl[j]);
strcpy(usnl[j],temp);
addlist=add[i];
add[i]=add[j];
add[j]=addlist;
}
}
}
}
int Person :: searchusn(char key[20])
{
int low=0,high=count,mid=0,flag=0,pos;
while(low<=high)
{
mid=(low+high)/2;
if(strcmp(usnl[mid],key)==0)
{
flag=1;
break;
}
if(strcmp(usnl[mid],key)>0)
high=mid-1;
else
low=mid+1;
}
if(flag)
return mid;
else
return -1;
}
void Person ::remove()
{
char key[30];
char del='$';
fstream is;
cout<<"ENTER THE USN :: "<<endl;
cin>>key;
int pos=searchusn(key);
if(pos>=0)
{
is.open("pt.txt",ios::in|ios::out);
int addl=add[pos];
is.seekp(addl,ios::beg);
is<<del;
cout<<"Record DELETED !!! "<<endl;
is.close();
count--;
}
else
cout<<"Record Not Found!!! "<<endl;
}
void Person::search()
{
int pos=0;
char key[20];
fstream file;
cout<<"\n ENTER THE KEY TO BE SEARCH : " ;
cin>>key;
pos=searchusn(key);
if(pos>=0)
{
file.open("pt.txt",ios::in);
int addl=add[pos];
file.seekp(addl,ios::beg);
file.getline(buffer,'#');
cout<<"\n RECORD FOUND !!! "<<buffer;
file.close();
}
else
cout<<"Record Not Found!!! "<<endl;
}
int main()
{
int choice = 1;
Person ob;
while(choice < 4)
{
ostream&flush();
cout<<"1> Insert A Record "<<endl;
cout<<"2> Search For A Record "<<endl;
cout<<"3> Delete A Record "<<endl;
cout<<"4> Exit "<<endl;
cin>> choice;
switch(choice)
{
case 1: ob.input();
ob.pack();
ob.Write();
break;
case 2: ob.creatind();
ob.search();
break;
case 3: ob.creatind();
ob.remove();
break;
}
}
return 0;
}
