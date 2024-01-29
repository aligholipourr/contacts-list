#include <string>
#include <vector>
#include <list>
#include <string>
#include<fstream>

using namespace std;

enum typenum
	{
	  Main=1,Home,Work,Office,Fax
	};
struct phonenum {
string _phonenum;
typenum type;
};
struct contact
{
	string firstname;
	string lastname;
	string email;
	vector <phonenum> _phonenum;

};
void adduser(vector<contact>& contactlist);
void display(vector <contact>& contactlist);
void search(vector<contact>& contactlist);
void delete_user(vector<contact>& contactlist);
void delete_all(vector<contact>& contactlist);
void savefile(vector<contact>& contactlist);
void loadfile(vector<contact>& contactlist);