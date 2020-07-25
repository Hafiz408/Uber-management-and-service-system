#include"administrator.h"
#include<iostream>
using namespace std;
#include<fstream>
#include<string.h>
#include<stdlib.h>
void Administrator::new_record()
{
    system("CLS");
    cout<<"\n\n\t\tNEW DRIVER RECORD\n\t\t-----------------------";
    driver=new Driverdetails;
    driver->setdata();
}

void Administrator::update()
{
    system("CLS");
    int n;
    char temp[30];
    cout<<"\n\n\t\tUPDATE DRIVER LIST\n\t------------------------";
    cout<<"\n\n\n\t\tEnter the name of the driver's details to be modified:";
    cin>>temp;
    ifstream infile;
    infile.open(strcat(temp,".txt"));
    char licence_no[10];
    char name[30];
    int age;
    char phone[10];
    int rides;
    char location[20];
    infile>>location;
    infile>>licence_no;
    infile>>name;
    infile>>age;
    infile>>phone;
    infile>>rides;
    infile.close();
    cout<<"\n\t\tEnter\n\t\t1.To modify License Number\n\t\t2.To Modify Age\n\t\t3.To modify Phone\n\n\t\tChoice?";
    cin>>n;
    switch(n)
    {
        case 1:cout<<"\n\t\tEnter License Number:";
                cin>>licence_no;
                break;
        case 2:cout<<"\n\t\tEnter the Age:";
                cin>>age;
                break;
        case 3:cout<<"\n\t\tEnter the Phone Number:";
                cin>>phone;
                break;
        default:cout<<"\n\t\tEnter a valid option";
    }
    ofstream outfile;
    outfile.open(temp);
    outfile<<location<<endl;
    outfile<<licence_no<<endl;
    outfile<<name<<endl;
    outfile<<age<<endl;
    outfile<<phone<<endl;
    outfile<<rides<<endl;
    outfile.close();

}

void Administrator::new_rental()
{
    system("CLS");
    cout<<"\n\t\tADD RENTAL VEHICLE\n\t\t---------------------\n\n\n";
    v=new vehicle;
    v->set_rental();
}
