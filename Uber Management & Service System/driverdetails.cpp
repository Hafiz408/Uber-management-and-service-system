#include"driverdetails.h"
#include<iostream>
using namespace std;
#include<string.h>
#include<fstream>
#include<string>
ofstream outfile;
#include<stdlib.h>
#include"windows.h"
void Driverdetails::set_licence_no()
{
    cout<<"\n\n\n\t\tLicense Number:";
    cin>>licence_no;

}

void Driverdetails::set_name()
{
    int i,j=0,check;
    for (i=0;i>=0;i++)
    {
        check=0;
        cout<<"\t\tName:";
        cin>>name;
        for(j=0;j<strlen(name);j++)
        {
            if((int(name[j])>=65&&int(name[j])<=92)||(int(name[j])>=97&&int(name[j])<=122))
            {
                continue;
            }
            else
            {
                check=-1;
                break;
            }
        }
        if(check==0)
            break;
        else
        {
            cout<<"\n\t**Enter a valid name**";
            Sleep(200);
            system("CLS");
            cout<<"\n\n\n";
        }
    }
}

void Driverdetails::set_age()
{
    int i,j,check;
    for(i=0;i>=0;i++)
    {
        check=0;
        cout<<"\t\tAge:";
        cin>>age;
        if(age>=20&&age<=60)
        {
            break;
        }

        else
        {
            cout<<"\n\t***Enter a valid age***";
            Sleep(200);
            system("CLS");
            cout<<"\n\n\n";
        }
    }

}

void Driverdetails::set_phone()
{
    int i,j=0,check;
    for (i=0;i>=0;i++)
    {
        check=0;
        cout<<"\t\tPhone:";
        cin>>phone;
        if(strlen(phone)==10)
        {
            for(j=0;j<strlen(name);j++)
            {
                if((int(phone[j])>=48&&int(phone[j])<=57))
                {
                    continue;
                }
                else
                {
                    check=-1;
                    break;
                }
            }
        }
        else
        {
            check=-1;
            cout<<"\n\t**Enter a valid phone number**";
            Sleep(200);
            system("CLS");
        }

        if(check==0)
            break;
        else
        {
            cout<<"\n\t**Enter a valid phone number**";
            Sleep(200);
            system("CLS");
            cout<<"\n\n\n";
        }
    }
}

void Driverdetails::set_rides()
{
    cout<<"\t\tNo. of Rides:";
    cin>>rides;
}


void Driverdetails::set_location()
{
    int i,j=0,check;
    for (i=0;i>=0;i++)
    {
        check=0;
        cout<<"\t\tLocation:";
        cin>>location;
        for(j=0;j<strlen(location);j++)
        {
            if(strcmp(location,"peelamedu")==0||strcmp(location,"gandhipuram")==0||strcmp(location,"chinniyampalayam")==0||strcmp(location,"ukkadam")==0)
            {
                continue;
            }
            else
            {
                check=-1;
                break;
            }
        }
        if(check==0)
            break;
        else
        {
            cout<<"\n\t**Enter a valid Location Name**";
            Sleep(200);
            system("CLS");
            cout<<"\n\n\n";
        }
    }
}

void Driverdetails::set_salary()
{
    if(rides>5)
        salary=30500;
    else if(rides>10)
        salary=31500;
    else
        salary=30000;
}

void Driverdetails::setdata()
{
    set_licence_no();
    set_name();
    set_age();
    set_phone();
    set_rides();
    set_location();
    veh=new vehicle;
    char temp[30];
    strcpy(temp,name);
    veh->set_data(temp);
    strcpy(temp,name);
    outfile.open(strcat(temp,".txt"));
    outfile<<location<<endl;
    outfile<<licence_no<<endl;
    outfile<<name<<endl;
    outfile<<age<<endl;
    outfile<<phone<<endl;
    outfile<<rides<<endl;
    outfile<<salary<<endl;
    outfile.close();
    ofstream outfile;
    outfile.open("driver_list.txt",ios::app);
    outfile<<name<<endl;
}

void Driverdetails::update_vehicle_list(char *type)
{
    char temp[20];
    char temp1[20];
    char in[20];
    ifstream infile;
    ifstream infile1;
    ofstream outfile;
    outfile.open("booking_vehicle.txt",ios::trunc);
    infile.open("driver_list.txt");
    while(infile)
    {
        infile>>temp;
        strcpy(temp1,temp);
        infile1.open(strcat(temp1,"vehicle.txt"));
        infile1>>in;
        infile1.close();
        if(strcmp(type,in)==0)
        {
            outfile<<temp<<endl;
        }
    }
    infile.close();
    outfile.close();
}

void Driverdetails::load_data(char name1[20])
{
    veh=new vehicle;
    char temp[20];
    strcpy(temp,name1);
    ifstream infile;
    infile.open(strcat(temp,".txt"));
    infile>>location;
    infile>>licence_no;
    infile>>name;
    infile>>age;
    infile>>phone;
    infile>>rides;
    infile>>salary;
    infile.close();
    veh->load_data(strcat(name1,"vehicle.txt"));
}

void Driverdetails::display_driver_details()
{
    cout<<"\t\tName:     "<<name<<endl;
    cout<<"\t\tPhone:    "<<phone<<endl;
    cout<<"\t\tLocation: "<<location<<endl;
    cout<<"\t\tAge:      "<<age<<endl;
    cout<<"\t\tVehicle Details:"<<endl;
    char temp[20];
    strcpy(temp,name);
    veh->load_data(strcat(temp,"vehicle.txt"));
    cout<<"\t\tVehicle Number:"<<veh->get_vehicle_no();

}


