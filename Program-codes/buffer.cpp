	#include <iostream>
	#include <iomanip>
	#include "account.h"
	#include "Lentext.h"
	#include<cstring>

	using namespace std;
	int main()
	{
	    int result;
	    account a;
	    LengthTextBuffer b;

	    strcpy(a.account_Number,"1111111111");
	    strcpy(a.name, "Name");
	    strcpy(a.address, "Address");
	    strcpy(a.city, "City");
	    strcpy(a.state, "IL");
	    strcpy(a.zip_Code, "60192");
	    cout<<"person object's data\n";
	    a.Print(cout);
	    result=a.Pack(b);
	    cout<<"result after pack is"<<result;
	    b.Print(cout);
	    result=b.Write(cout);
	    cout<<"result after write is"<<result;
	    return 0;
	}
