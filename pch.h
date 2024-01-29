#ifndef PCH_H
#define PCH_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class list
{
private:
	/*enum typenum
	{
		Main = 1, Home, Work, Office, Fax
	};
	struct phonenum {
		string _phonenum;
		typenum type;
	};*/
		string firstname;
		string lastname;
		string email;
		//vector <phonenum> _phonenum;

	
public:
	void adduser(string f, string l, string e);
	void disp();
	void save(vector<list>& contacts);
	vector<list> load();
	~list() {
		cout<<"the progom is finished"<<endl;
	}
};
#endif //PCH_H
