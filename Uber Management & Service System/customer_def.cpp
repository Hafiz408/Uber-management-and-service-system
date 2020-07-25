#include <iostream>
#include<fstream>
#include<string>
#include"customer.h"

using namespace std;

void Customer::file_write()
{
    ofstream f;
    f.open("Login.txt",ios::app);
    f<<number<<"-"<<password<<"-"<<name<<endl;
    f.close();
}

int Customer::file_check(string n)
{
    ifstream f;
    string s;
    f.open("Login.txt");
    while(!f.eof())
    {
        getline(f,s);
        if(s.find(n)!=string::npos)
        {
            int n1=s.find("-");
            int n2=s.find("-",n1+1);
            number=s.substr(0,10);
            password=s.substr(n1+1,n2-n1-1);
            name=s.substr(n2+1);
            return 1;
        }
    }
    f.close();
    return 0;
}

void Customer::data_copy(string n,string no,string psd)
{
    name=n;
    number=no;
    password=psd;
}

string Customer::get_password()
{
    return password;
}

string Customer::get_name()
{
    return name;
}

int Customer::book_details(int n)
{
    do{
        if(n==1)
            n=b.book_ride(get_name());
        if(n==2)
            n=b.book_rental(get_name());
        if(n==3)
            n=b.history(get_name());
    }while(n==1 || n==2 || n==3);
    return n;
}

