#include <iostream>
#include <fstream>
#include<stdlib.h>
#include<cstring>
using namespace std;

class Train
{
	int trainNo,IstClassSeats,IstClassFare,IIndClassSeats,IIndClassFare;
	char trainName[200],source[200],destination[200];
	bool runningDays[7];
public:
	void accept()
	{
		cin.ignore();
		cout<<"Enter the details as follows\n";
		cout<<"Train no:\t";
		cin>>trainNo;
		cout<<"Train Name:\t";
		cin>>trainName;
		cout<<"Source station:\n ";
		cin>>source;
		cout<<"Destination station\t";
		cin>>destination;
		cout<<"First class \n";
		cout<<"Seats:";
		cin>>IstClassSeats;
		cout<<"Fare";
		cin>>IstClassFare;
		cout<<"Second Class\n";
		cout<<"Seats:";
		cin>>IIndClassSeats;
		cout<<"Fare:";
		cin>>IIndClassFare;
		cout<<"Running Days\n";
		cout<<"Monday";
		cin>>runningDays[0];
		cout<<"Tuesday";
		cin>>runningDays[1];
		cout<<"Wednesday";
		cin>>runningDays[2];
		cout<<"Thursday";
		cin>>runningDays[3];
		cout<<"Friday";
		cin>>runningDays[4];
		cout<<"Saturday";
		cin>>runningDays[5];
		cout<<"Sunday";
		cin>>runningDays[6];
		try
		{
			if(IstClassFare<0 && IIndClassFare<0)
				throw 0;
		}
		catch(int x)
		{
			throw x;
		}
	}

	void display()
	{


cout<<trainNo<<"\t\t"<<trainName<<"\t\t"<<source<<"\t\t"<<destination<<"\t\t"<<IstClassSeats<<"\t\t"<<IstClassFare<<"\t\t"<<IIndClassSeats<<"\t\t"<<IIndClassFare<<"\t\t";
		for(int i=0;i<7;i++)
				{
					if(runningDays[i]==0)
						cout<<"N\t";
					else
						cout<<"Y\t";
				}
				cout<<"\n\n";
	}
int getTrainNo()
{
	return trainNo;
}
string getsource()
{
	return source;
}
string getdest()
{
	return destination;
}
};
void addTrain()
{


	Train obj;
	try{obj.accept();}
	catch(int x)
	{
		cout<<"Fare cannot be negative";return;
	}

	ofstream out("trainDetails.txt",ios::app|ios::binary);
	out.write((char*)&obj,sizeof(obj));

	out.close();

}
void displayTrains()
{
	cout<<"Train No\tTrain Name\tSource\tDestination\t1st Class seats\t1st Class fare\t2nd Class seats\t2nd Class fare\tM\tT\tW\tTh\tF\tS\tS\n";
	Train obj;
	ifstream in("trainDetails.txt", ios::in|ios::binary);
	while(in)
	{

		in.read((char*)&obj,sizeof(obj));

		if(in.eof())
			break;

		obj.display();

	}
	in.close();
}

void updateTrain()
{
	int trainNo;
		cout<<"Enter the train no:";
		cin>>trainNo;
		Train obj;
			fstream in("trainDetails.txt",ios::in | ios::out|ios::binary );
			while(in)
			{
			in.read((char*)&obj,sizeof(obj));
			if(in.eof())
				break;
			if(obj.getTrainNo()==trainNo)
			{
				cout<<"Enter the new details:";
					obj.accept();

				in.seekp((-1)*sizeof(obj),ios::cur);

				in.write((char*)&obj,sizeof(obj));
			break;
			}
			}
			if(in.eof())
			{
					cout<<"Not Found";
			}
			in.close();
}

class Ticket
{
int pnrno;
	int noOfSeats;
	char name[20];
	int age;
	char category[20];
	char trainName[20];
	int trainNo;
	char source[20],destination[20];
	char date[20];
	int Class;
public:
static int pnr;
	void accept()
	{
		pnr++;
		pnrno=pnr;
		cout<<"Enter train No";
		cin>>trainNo;
		Train obj;
			fstream in("trainDetails.txt",ios::in | ios::out|ios::binary );
			while(in)
			{
			in.read((char*)&obj,sizeof(obj));
			if(in.eof())
				break;
			if(obj.getTrainNo()==trainNo)
			{
				cout<<"Train No\tTrain Name\tSource\tDestination\t1st Class seats\t1st Class fare\t2nd Class seats\t2nd Class fare\tM\tT\tW\tTh\tF\tS\tS\n";
				obj.display();
			}
			}
		cout<<"Enter the train Name ";
		cin>>trainName;
		cout<<"Enter Your Source";
		cin>>source;
		cout<<"Enter Your Destination";
		cin>>destination;
		cout<<"Enter no. of seats";
		cin>>noOfSeats;
	
			cout<<"Enter passenger Name";
			cin>>name;
			cout<<"Enter age";
			cin>>age;
			if(age<=15)
				strcpy(category,"child");
			else if(age>=60)
				strcpy(category,"Senior");
			else
				strcpy(category,"adult");

		cout<<"Enter date of journey";
		cin>>date;
		cout<<"Enter class";
		cin>>Class;
try
		{
	if(age<0 )
	throw (age);
		}
catch(int x){
	throw x;
	}
}
	void display()
	{

		if(pnrno==0)
	cout<<"CANCELLED";
		else
	cout<<"\nPNR no:"<<pnrno<<endl;
		cout<<"Train No."<<trainNo<<"\n"<<"Train Name"<<trainName<<"\n"<<"Class"<<Class<<endl;
		cout<<"Journey:"<<source <<" to "<<destination<<" on "<<date<<endl;


			cout<<"Name:"<<name<<" \n"<<"Age:"<<age<<"\n "<<"Category:"<<category<<"\n\n"<<endl;


	}
	int getpnr()
	{
	    return pnrno;
	}
	void setpnr()
	{
	    pnrno=0;
	}
};
int Ticket::pnr=0;
void displayPassengers()
{
		Ticket obj;
		ifstream in("ticketDetails.txt",ios::binary);
		while(in)
		{

			in.read((char*)&obj,sizeof(obj));

			if(in.eof())
				break;

			obj.display();

		}
		in.close();
}

void reserve()
{


	Ticket obj;
	try{
		obj.accept();
	}
	catch(int x)
	{
		cout<<"age cannot be negative";return;
	}
obj.display();
	ofstream out("ticketDetails.txt",ios::app|ios::binary);
	out.write((char*)&obj,sizeof(obj));

	out.close();
}
void cancel()
{
cout<<"Enter your PNR no";
int PNR;
cin>>PNR;

	Ticket obj;
			fstream in("ticketDetails.txt",ios::in | ios::out|ios::binary);
			while(in)
			{
			in.read((char*)&obj,sizeof(obj));
			if(in.eof())
				break;
			if(obj.getpnr()==PNR)
			{
				obj.setpnr();
				in.seekp((-1)*sizeof(obj),ios::cur);

				in.write((char*)&obj,sizeof(obj));
				cout<<"Successfully Cancelled your ticket";
				obj.display();	
			break;
			}
			}
			if(in.eof())
			{
					cout<<"Not Found";
			}
			in.close();


}
void enquiry()
{
    cout<<"Enter Source:";
    string SOURCE;
    cin>>SOURCE;
    cout<<"Enter Destination";
    string DESTINATION;
    cin>>DESTINATION;
	Train obj;
			fstream in("trainDetails.txt",ios::in | ios::out|ios::binary );
			while(in)
			{
			in.read((char*)&obj,sizeof(obj));
			if(in.eof())
				break;
			if(obj.getsource()==SOURCE && obj.getdest()==DESTINATION)
			{
			    obj.display();

			}

			}

			in.close();

}
void UserMenu()
{
	int ch;
		cout<<"....***WELCOME TO THE USER MENU***....\n";
		do
		{
		cout<<"1.Reserve\n";
		cout<<"2.Cancel\n";
		cout<<"3.Enquiry \n";
		cout<<"4.Return to the previous menu\n";
		cout<<"Enter your choice:";
		cin>>ch;
		cout<<endl;
		switch(ch)
		{
		case 1:reserve();break;
		case 2:cancel();break;
		case 3:enquiry();break;
		}
		}while(ch<=3);

}
class user
{
	char id[20],password[20];
public:
	void accept()
	{
		cout<<"id:";
		cin>>id;
		cout<<"password:";
		cin>>password;
	}
	void display()
	{
		cout<<"Id:"<<id<<endl;
		cout<<"Password:"<<password<<endl;
	}
	string getid()
	{
		return id;

	}
	string getpass()
	{
		return password;
	}
};
void createUser()
{
	char ch;
	user obj;
	ofstream out("loginDetails",ios::app |ios::out);
	do{
		obj.accept();
		out.write((char*)&obj,sizeof(obj));
		cout<<"continue?\n y for yes \n n for no";
		cin>>ch;
	}while(ch=='y');
		out.close();

}
void addUser()
{
	user obj;
		obj.accept();

		ofstream out("loginDetails",ios::app);
		out.write((char*)&obj,sizeof(obj));

		out.close();

}
void displayUser()
{
	user obj;
		ifstream in("loginDetails", ios:: in);
		while(in)
		{

			in.read((char*)&obj,sizeof(obj));

			if(in.eof())
				break;

			obj.display();

		}
		in.close();
}
void UserManagementMenu()
{
	int ch;
	cout<<"....***WELCOME TO THE USER MANAGEMENT MENU***....\n";
	do
	{
	cout<<"1.Create id data base\n";
	cout<<"2.Add details\n";
	cout<<"3.Display details\n";
	cout<<"4.Return to the previous menu\n";
	cout<<"Enter your choice:";
	cin>>ch;
	cout<<endl;
	switch(ch)
	{
	case 1:createUser();break;
	case 2:addUser();break;
	case 3:displayUser();break;
	}
	}while(ch<=3);

}
void admin_menu()
{
	int choice;
	do{
		cout<<"*******Administrator menu************"<<endl;

		cout<<"1.Add train details"<<endl;
		cout<<"2.Display train details"<<endl;
		cout<<"3.Update train details"<<endl;
		cout<<"4.User management"<<endl;
		cout<<"5.Display passenger details"<<endl;
		cout<<"6.Return to previous menu"<<endl;
		cout<<"Enter your choice";
		cin>>choice;
		switch(choice)
		{

		case 1:addTrain();break;
		case 2:displayTrains();break;
		case 3:updateTrain();break;
		case 4:UserManagementMenu();break;
		case 5:displayPassengers();break;
		}
	}while(choice>0 && choice<6);
}

bool validate()
{
	string id,password;
	cout<<"Enter id:";
	cin>>id;
	cout<<"Enter password:";
	cin>>password;

			user obj;
				fstream in("loginDetails",ios::in );
				while(in)
				{
				in.read((char*)&obj,sizeof(obj));
				if(in.eof())
					break;
				if(obj.getid()==id)
				{
					if(obj.getpass()==password)
					{
						return 1;
					}
					else
						cout<<"Wrong password";
					break;
				}

				}
				if(in.eof())
				{
						cout<<"Not Found";
				}
				in.close();
				return 0;
}
void MainMenu()
{

	    int ch;
	    	do{
	    	cout<<"***********MAIN MENU**************"<<endl;
			cout<<"1.Admin Mode"<<endl;
			cout<<"2.User Mode"<<endl;
			cout<<"3.EXIT"<<endl;
			cout<<"Enter your choice:";
			cin>>ch;
			switch(ch)
			{
			case 1:
				{cout<<"Enter id:";
				string id,pass;
			cin>>id;
			cout<<"Enter Password:";
			cin>>pass;
			if(id=="Admin@123" && pass=="PASSword")
				admin_menu();
			else
				cout<<"!!!!!!!!!!!!!!!!ACCESS DENIED!!!!!!!!!!!\n";
				}
			break;
			case 2:if(validate()){UserMenu();}break;
			case 3:cout<<"Thank you for visiting\nHappy to see you again";break;
			default:cout<<"Please enter a valid choice";
			}
		}while(ch>0 &&ch<4);

}
int main() {
	cout<<"-----------------------------------------------"<<endl;
	cout<<"******RAILWAY RESERVATION SYSTEM********"<<endl;
	cout<<"-----------------------------------------------\n"<<endl;
	MainMenu();


	cout<<"Thank you";
	return 0;
}
