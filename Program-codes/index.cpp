#include<iostream>
#include<process.h>
#include<ctype.h>

#include<fstream>
#include<cstring>
#define LEN 48
using namespace std;
class Student
{
char name[25],usn[11],age[3];
char buf[LEN];
int n=0;
public:
    void pack();
void unpack();
void Add();
Find (char buf[ ][20], char *key, int n);
void search1();
void del ();
void write_file();
void read_file();
Student();
};
void Student::pack()
{
strcpy(buf,usn);
strcat(buf,"|");
strcat(buf,name);
strcat(buf,"|");
strcat(buf,age);
for(int i=strlen(buf); i<LEN; i++) // LEN is the length of the record fixed
strcat(buf,"#");
}
void Student::unpack()
{
strcpy(usn,strtok(buf,"|"));
strcpy(name,strtok(NULL,"|"));
strcpy(age,strtok(NULL,"#"));
}
void Student::write_file( )
{
    ofstream fout;
cout<<"Enter USN: ";
cin>>usn;
cout<<"Enter name: ";
cin>>name;
cout<<"Enter age: ";
cin>>age;
pack( );
fout.open("student.text",ios::app);
fout<<buf<<endl;
cout<<"Student record added\n";
fout.close( );
}
void Student::read_file( )
{
    ifstream fin;
int rrn;
cout<<"Enter the RRN: ";
cin>>rrn;
fin.open("student");
fin.seekg(rrn*(LEN+1),ios::beg);
fin>>buf;
unpack();
cout<<"\nUSN: "<<usn<<"\nName: "<<name<<"\nAge: "<<age<<endl;
fin.close( );
}
Student::Student ()
{
int i, n = 0;
ifstream fin;
ofstream fout;
fin.open ("index.text");
if (!fin.fail ())
{
for (i = 0; !fin.eof (); i++)
{
fin >> buf[i];
if (fin.fail ())
break;
}
n = i;
fin.close ();
}
fin.open ("student.text");
fout.open ("student.text", ios::app);
}
void Student::Add( )
{
cout<<"Enter USN: ";
cin>>usn;
cout<<"Enter name: ";
cin>>name;
cout<<"Enter age: ";
cin>>age;
pack( );
ofstream fout;
fout.open("student.text",ios::app);
fout<<buf<<endl;
fout.close( );
cout<<"Student record added\n";
}
int Student::Find (char buf[ ][20], char *key, int n)
{
char *usn, temp[50];
for(int i=0;i<n;i++)
{
strcpy (temp, buf[i]);
usn = strtok (temp, "|");
if (strcmp (key, usn) == 0) return i;
}
return -1; //key not found
}//Searching for a record
void Student::search1()
{
    ifstream fin;
    ofstream fout;
char key[4], temp[20], *temp1;int index, RecAddr;
cout << "Enter the key: "; cin >> key;
cout << "Student found!\n";
strcpy (temp, buf);
temp1 = strtok (temp, "|");
RecAddr = int (temp1);
fin.seekg (RecAddr, ios::beg);
unpack ();
cout << "Name: " << name;
cout << "\nUSN: " << usn;
cout << "\nAge: " << age << endl;

}void Student::del ()
{
char key[4];
int index;
cout << "Enter the key: ";
cin >> key;
if (index  == -1)
cout << "Record not found!\n";
else
{
cout << "Record deleted\n";
}
}
//update the index file
/*Student::~Student ()
{
fout.close ();
fout.open ("index");
for (int i = 0; i < n; i++)
if (buf[i][0] != '*')
fout << buf[i] << endl;
fout.close ();
}fin.close ();
}*/
int main()
{
    int ch;
    do
    {
        cout<<"\n 1.Add 2.write 3.read 4.search 5.find 6.delete:";
        cin>>ch;
         Student s;
        switch(ch)
        {
            case 1:s.write_file();
            break;
            case 2:s.read_file();
            break;

            case 3:s.Add();
            break;
            case 4:s.search1();
break;
        }

    }while(ch!=7);
    return 0;
}
