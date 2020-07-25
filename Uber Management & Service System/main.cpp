#include <iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<windows.h>
#include"customer.h"
#include"administrator.h"
using namespace std;

Administrator a;
Customer c;
int menu(int choice)
{
    string name,password,number;
    if(choice==1)
    {
                system("CLS");
                cout<<"\n\t\tREGISTRATION\n\t\t------------\n"<<endl;
                cout<<"\tName : ";
                cin>>name;
                cout<<"\tMobile no. : ";
                cin>>number;
                cout<<"\tPassword : ";
                cin>>password;
                if(c.file_check(number))
                {
                    char ch;
                    cout<<endl<<"\t\t>> This number already registered <<\n\n\tTry to Login ?(y/n) ";
                    cin>>ch;
                    if(ch=='y')
                    {
                        choice=2;
                    }
                    else
                    {
                        return 1;
                    }
                }
                else
                {
                    c.data_copy(name,number,password);
                    c.file_write();
                    cout<<"\n\t\t>> Successfully registered <<\n";
                    Sleep(3000);
                }
        }
        if(choice==2)
        {
            system("CLS");
            cout<<"\n\t\tLOGIN\n\t\t------\n\n"<<endl;
            cout<<"\tMobile no. : ";
            cin>>number;
            cout<<"\tPassword : ";
            cin>>password;
            if(c.file_check(number))
            {
                if(password==c.get_password())
                {
                    cout<<"\n\t\t>> Login successful <<";
                    Sleep(2000);
                    return 0;
                }
                else
                {
                    char ch;
                    cout<<"\n\t\t>> Password wrong <<\n\n\tTry again ?(y/n) ";
                    cin>>ch;
                    if(ch=='y')
                    {
                        menu(2);
                    }
                    else
                    {
                        return 1;
                    }
                }
            }
            else
            {
                char ch;
                cout<<"\n\t\t>> Number not registered <<\n\n\tTry again ?(y/n) ";
                cin>>ch;
                if(ch=='y')
                {
                    menu(2);
                }
                else
                {
                    return 1;
                }
            }
            return 0;

        }
        if(choice!=1 && choice!=2)
        {
            printf("\n\t\t>> Enter a valid input <<\n");
            return 1;
        }
}
int main()
{

    int choice,control,opt=0,i;
    do{
        system("CLS");
        cout <<"\n\t\tOLA CABS AND SERVICES\n\t\t--------------------" << endl;
        cout<<"\n\t1.Administrator\t\t2.Customer\n\n\t\tChoice ?";
        cin>>opt;
        if (opt==1)
        {
            ifstream infile;
            char user[20],pass[20],in[20];
            do
            {
                infile.open("administrator.txt");
                system("CLS");
                cout<<"\n\t\t\tLOGIN\n\t\t--------------------";
                cout<<"\n\n\n\t\tUser Name:";
                cin>>user;
                infile>>in;
                if(strcmp(user,in)==0)
                {
                    cout<<"\t\tPassword:";
                    cin>>pass;
                    infile>>in;
                    cout<<"\n\t\t>> Login successful <<";
                    Sleep(200);
                    system("CLS");
                    if(strcmp(pass,in)==0)
                    {
                        cout<<"\n\t\t\tWelcome "<<endl;
                        cout<<"\n\n\n\t1.Add new driver record\n\t2.Add new rental vehcile\n\t3.Update driver info"<<endl;
                        cout<<"\n\n\t\tChoice ?";
                        cin>>choice;
                        if(choice==1)
                            a.new_record();
                        if(choice==2)
                            a.new_rental();
                        if(choice==3)
                            a.update();
                        cout<<"\n\n\n\t\t\tEnter -1 to log out";
                        cin>>i;
                        if(i==-1)
                        {
                            opt=0;
                            break;
                        }
                    }
                }
            }while(1);
        }
        else if (opt==2)
        {

            Customer c;
            do{
                system("CLS");
                cout <<"\n\t\tWELCOME\n\t\t--------" << endl;
                cout<<"\n\t1.Register\t2.Login\n\n\t\tchoice ? ";
                cin>>choice;
                control=menu(choice);
            }while(control==1);
            do{
                system("CLS");
                cout<<"\n\t\t\tWelcome "<<c.get_name()<<endl;
                cout<<"\n\t1.Book a ride\t2.Book a rental\t  3.Travel history\n\n\t\tchoice ? ";
                cin>>choice;
                choice=::c.book_details(choice);
                cout<<"\n\t\t\t\tEnter -1 to log out:";
                cin>>i;
                if(i==-1)
                {
                    opt=0;
                    break;
                }
                }while(choice==-1);
        }
        else
        {
            opt=0;
            cout<<"\nEnter a valid choice:";
            Sleep(2000);
        }
    }while(opt==0);

}
