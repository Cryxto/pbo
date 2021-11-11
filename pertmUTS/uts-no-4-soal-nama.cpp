#include <iostream>
#include <string>
using namespace std;

class name
{
private:
    string firstName;
    string middleName;
    string lastName;

public:
    void setFirstName()
    {
        cout << "Masukan First Name : ";
        getline(cin, firstName);
    }
    void setMiddleName()
    {
        cout << "Masukan Middle Name : ";
        getline(cin, middleName);
    }
    void setLastName()
    {
        cout << "Masukan Last Name : ";
        getline(cin, lastName);
    }
    void print()
    {
        cout << "FULL NAME : " << firstName << " " << middleName << " " << lastName << endl;
    }
};
int main()
{
    name user;
    int menu = 2;
    char confirm = 'y';
    bool switcher = false;
    bool switcher2 = true;
    while (switcher == false)
    {
            cout<<endl;
            cout<<"MENU \n"
                <<"0. Keluar\n"
                <<"1. Input\n";
            cout << "PILIH : ";
            cin >> menu;
 
            switch (menu)
            {
            case 0:
                switcher = true;
                break;
            case 1:
                    cin.ignore();
                    user.setFirstName();
                    user.setMiddleName();
                    user.setLastName();
                    user.print();
                    cout<<"Ingin memilih menu lain (y/t)?  ";
                    cin >> confirm;
                    while (switcher2=true){
                        if (confirm == 't'||confirm=='T'||confirm == 'y' || confirm == 'Y'){
                            switcher2 = false;
                            break;
                        }
                        else {
                            cout<<"pilih y/t";
                            cout<<"Ingin memilih menu lain (y/t)? ";
                            cin >> confirm;
                        }
                    }
                    if (confirm == 't'||confirm=='T'){
                        switcher = true;
                    }
                
                break;
            default:
               cout << "Menu tidak ada! Silahkan pilih menu yang ada!" << endl;
            break;
            }
        
         
    }
    cout<<"Thanks"<<endl;
    return 0;
}
