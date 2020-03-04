#include<iostream>
#include<fstream>
using namespace std;
#include<cstring>
int const l=100;
class student
{
	public:
		char name[20],rno[10],tfee[2],hfee[2],blog[2],state[10],dob[12],mno[11],branch[5],buffer[l];
		char ncourse[2],sem[2];
		//c1[8],c2[8],c3[8],c4[8],c5[8],c6[8],cn1[20],cn2[20],cn3[20],cn4[20],cn5[20],cn6[20];
		/*char f1[20],f2[20],f3[20],f4[20],f5[20],f6[20],buffer[l];
		void packstu();
		/*void unpackstu();*/
		void packdept(ofstream &);
		/*void unpackdept(ifstream &);
		void packc(ofstream &);
		void unpackc(ifstream &);
		void packfac(ofstream &);
		void unpackfac(ifstream &);*/
};


void register1(student s)
{

	int x,y;
    cout<<"\n Student Name:";
    cin>>s.name;
    cout<<"\n Roll Number";
    cin>>s.rno;
    cout<<"\n Tution fee paid? Y/N";
    cin>>s.tfee;
    cout<<"\n Hostel fee paid? Y/N";
    cin>>s.hfee;
    cout<<"\n Number of Backlogs";
    cin>>s.blog;
    int j=0;
    ofstream a;
    a.open("cse.txt",ios::app);
    a<<"jj";
    /*if((s.tfee=='y'|| s.tfee=='Y')&& (s.hfee=='y' || s.hfee=='Y') && (s.blog=='0'|| s.blog=='1' || s.blog=='2'))
    {*/
    	cout<<"\n State:";
    	cin>>s.state;
    	cout<<"\n Semester (1-4):";
    	cin>>s.sem;
    	cout<<"\n D.O.B:";
    	cin>>s.dob;
    	cout<<"\n MObile Number:";
    	cin>>s.mno;
    	cout<<"\n Branch:\n 1.Computer science Engineering\n 2.Electornics and communication Engineering \n 3.Electrical And Electronics Engineering\n";
    	cin>>x;
    	cout<<"\n Enter number of courses:";
    	cin>>s.ncourse;
    	j=(int)s.ncourse-48;
    	cout<<j;

    	/*switch(x)
		{
			case 1:{*/
				strcpy(s.branch,"cse");

			a<<"hi";
			s.packdept(a);
			a.close();
			/*if(s.sem=='1')
			{
			cout<<"\n 1.Mathematics-1 \n 2.English \n 3.Physics \n 4.Basic Electronics Engineering \n 5.Environmental Studies \n 6.Problem Solving and Computer Programming\n";
			for(int i=0;i<j;++i)
			{
			cin>>y;
			switch(y)
			{
				case 1:{a.open("ma101.txt",ios::app);
				s.packc(a);
				a.close();
		 	break;}
				case 2: {a.open("hs101.txt",ios::app);
				s.packc(a);
				a.close();
				break;}
				case 3: { a.open("ph101.txt",ios::app);
				s.packc(a);
				a.close();
				break;}
				case 4:{a.open("ec101.txt",ios::app);
				s.packc(a);
				a.close();
				break;}
				case 5:{a.open("ce102.txt",ios::app);
				s.packc(a);
				a.close();
				break;}
				case 6:{a.open("cs101.txt",ios::app);
				s.packc(a);
				a.close();
				break;}
			}
			}}/*        	else
			cout<<"\nRegistration failed";*/

}
/*void student :: packc (ofstream &a)
{
	a<<s.rno<<"\n";
}*/

void student::packdept(ofstream & a)
{
 strcpy(buffer,rno);
 strcat(buffer,"|");
 strcat(buffer,name);
 strcat(buffer,"|");
 strcat(buffer,ncourse);
 strcat(buffer,"|");
 while(strlen(buffer)<l-1)
 strcat(buffer," ");
 strcat(buffer,"\n");
  a<<buffer;
 }

/*void student::packstu()
{ofstream out;
out.open("stu.txt",ios::app);
buffer[0]='\0';
strcpy(buffer,rno);
strcat(buffer,"|");
strcat(buffer,name);
strcat(buffer,"|");
strcat(buffer,(char *)tfee);
strcat(buffer,"|");
strcat(buffer,(char *)hfee);
strcat(buffer,"|");
strcat(buffer,(char *)blog);
strcat(buffer,"|");
strcat(buffer,state);
strcat(buffer,"|");
strcat(buffer,(char *)sem);
strcat(buffer,"|");
strcat(buffer,dob);
strcat(buffer,"|");
strcat(buffer,mno);
strcat(buffer,"|");
strcat(buffer,branch);
strcat(buffer,"|");
while(strlen(buffer)<l-1)
strcat(buffer," ");
strcat(buffer,"\n");

out<<buffer;
}
/*void init()
{
    s.name[0]='\0';
    s.rno[0]='\0';
    s.state[0]='\0';
    s.tfee='\0';
    s.hfee='\0';
    s.blog='\0';
    s.state[0]='\0';
    s.dob[0]='\0';
    s.mno[0]='\0';
    s.branch[0]='\0';
    s.ncourse='\0';
    s.sem='\0';
    s.buffer[0]='\0';
}*/
int main()
{
    student s;
    //init(s);
	register1(s);
	return 0;
}

