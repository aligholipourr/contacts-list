#include "pch.h"
#include <iostream>
#include <vector>
#include<string>
#include<fstream>

using namespace std;

void list::adduser(string f, string l, string e)
{
	firstname = f;
	lastname = l;
	email = e;
}

void list::disp()
{
	cout << "ur first name is: "<<firstname << endl<<"ur last name is: " << lastname << endl<<"ur email is: " << email << endl;
}
void list::save(vector<list>& contacts)
{
	ofstream _file;
	
	
	_file.open("file.dat", ios::binary);
	for (const auto& item : contacts)
	{
		_file.write((char*)&item, sizeof(list));
	}
	_file.close();
}

vector<list> list::load()
{
	ifstream _file;
	list p;
	vector<list> contact;
	_file.open("file.dat", ios::binary);
	list obj;
	while (_file.read((char*)&p, sizeof(list)))
	{
		contact.push_back(p);
	}
		_file.close();
		for (auto m : contact)
		{
			cout << m.firstname << endl << m.lastname << endl << m.email << endl;

		}
		return contact;
}
