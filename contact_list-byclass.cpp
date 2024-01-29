#include "pch.h"
#include <iostream>
#include <vector>
#include<string>
#include<fstream>
using namespace std;

int main()
{
    vector<list> contacts;
    string f, l, e;
    int c;
    bool ext = false;

    do
    {
        list n;
        cout << "1.add user" << endl;
        cout << "2.disp user" << endl;
        cout << "3.save file" << endl;
        cin >> c;
        switch (c)
        {
        case 1:
            int a;

            do
            {
                cout << "please write ur name and email: " << endl;
                cin >> f >> l >> e;
                n.adduser(f, l, e);
                contacts.push_back(n);
                cout << "Do u want to add anothwe person? if yes please click 1" << endl;
                cin >> a;
            } while (a == 1);
            break;
        case 2:
            for (int i = 0; i < contacts.size(); i++)
            {
                contacts[i].disp();
            }
                break;
        case 3:
            n.save(contacts);
            break;
        case 4:
            n.load();
            break;
        case 5:
            ext = !ext;
            break;
        }

    } while (!ext);

    return 0;
}