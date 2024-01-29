#include"file.h"
#include<fstream>
#include <iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
    
    vector<contact> contactlist;
    int c,f;
    bool ext = true;
    do
    {
        cout << "1.add user" << endl;cout << "2.display" << endl;
        cout << "3.search person" << endl;
        cout << "4.delete user" << endl;        cout << "5.delete all users" << endl;
        cout << "6.save file" << endl; cout << "7.loadfile" << endl;   cout << "8.exit" << endl;
        cin >> c;
        switch (c)
        {
        case 1:
            do
            {
                adduser(contactlist);
                cout << "if do want to add anoter person pls click 0" << endl;
                cin >> f;
            } while (f == 0);
            break;

        case 2:
            display(contactlist);
            break;
        case 3:
            search(contactlist);
            break;
        case 4:
            delete_user(contactlist);
            break;
        case 5:
            delete_all(contactlist);
            break;
        case 6:
            savefile(contactlist);
            break;
        case 7:
            loadfile(contactlist);
            break;
        case 8:
            ext = !ext;
            break;
        }
    } while (ext);
    return 0;
}
