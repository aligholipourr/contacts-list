#include "file.h"
#include <iostream>
#include <string>
#include<list>
#include<ostream>
#include<vector>
#include<fstream>
using namespace std;
std::ostream& red_on(std::ostream& os) {
	return os << "\033[36m";
}

std::ostream& red_off(std::ostream& os) {
	return os << "\033[6m";
}

std::ostream& bold_on(std::ostream& os) {
	return os << "\033[5m";
}

std::ostream& bold_off(std::ostream& os) {
	return os << "\033[2m";
}

void adduser(vector<contact>& contactlist)
{
	contact contact;
	cout << "please write your first name:";
	cin >> contact.firstname;
	cout << "please enter your last name:";
	cin >> contact.lastname;
	cout << "please enter your Email:";
	cin >> contact.email;
	int c;
	do
	{
phonenum _phonenum;
	cout << "please enter ur nums: ";
	cin >> _phonenum._phonenum;
	int count;
	cout << "plase enter the type of ur nums:";
	cin >> count;
	while (count > 5 || count < 1)
	{
		cout << "Invalid Input!!!";
		cout << "Enter type of your number:(1:fax,2:home,3:office,4:work,5:main)";
		cin >> count;
	}
    _phonenum.type =static_cast<typenum> (count);
	contact._phonenum.push_back(_phonenum);
	cout << "do u want to add another num? clik 1 " << endl;
	cin >> c;
	} while (c==1);
	
	contactlist.push_back(contact);

}
void display( vector <contact>& contactlist)
{
	for ( auto &list : contactlist)
	{
		cout << list.firstname<<endl;
		cout << list.lastname << endl;
		cout << list.email << endl;
		for (auto& phonelist : list._phonenum)
		{
			switch (phonelist.type)
			{ case Main:
            cout << "Main:  "<<phonelist._phonenum << endl;
			break;
			case Home:
				cout << "Home: " << phonelist._phonenum << endl;
			default:
				break;
			}
			
		}
	}
}
void search(vector<contact>& contactlist)
{
	string name;
	int input;
	cout << "How do u want to serach? (1.by firstname 2.by lastname 3.by numbers)" << endl;
	cin >> input;
	switch (input)
	{
	case 1:
		cout << "please enter the first name of contact|:" << endl;
		cin >> name;
		for (auto& list : contactlist)
		{
			if (name == list.firstname)
			{
				cout << list.firstname << endl;
				cout << list.lastname << endl;
				cout << list.email << endl;
			}
		}break;
	}
}
void delete_user(vector<contact>& contactlist)
{
	cout << "choose how do u want to delete the user(1.by first name 2.by last name 3.by phone number)" << endl;
	int ch;
	string name;
	cin >> ch;
	switch (ch)
	{
	case 1:
		int count = 0;
		cout << "pls enter the name of the person: " << endl;
		cin >> name;
		for (auto& list : contactlist)
		{
			if (name == list.firstname)
			{
				count++;
			}
		}
		for (int i = 0; i < count; i++)
		{
			for (auto& list : contactlist) {
				if (name == list.firstname)
				{
					cout << i + 1 << ": " << list.firstname << " " << list.lastname << endl;
					i++;
				}
			}
			break;
		}
	}
}
void delete_all(vector<contact>& contactlist)
{
	int ch;
	cout << red_on << bold_on << "N O T I C E" << red_off << bold_off <<endl <<"Are u sure to delete all users?!(click 1)" << endl;
	cin >> ch;
	if (ch==1)
	{
		contactlist.clear();
	}
}
void savefile(vector<contact>& contactlist)
{
	std::ofstream  outfile("contact.txt");
	for  ( auto &list: contactlist)
	{
		outfile << "First name; " << list.firstname << endl << "Last name: " << list.lastname << endl;
	}
	outfile.close();
}

void loadfile(vector<contact>& contactlist)
{
	string line;
	ifstream contacts("contact.txt");
	if (contacts.is_open())
	{
		while (getline(contacts, line))
		{
			cout << line << endl;
		}
	}
	contacts.close();
}
