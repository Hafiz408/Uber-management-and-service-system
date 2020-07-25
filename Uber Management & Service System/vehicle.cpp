#include"vehicle.h"
#include<iostream>
using namespace std;
#include<string.h>
#include<fstream>
#include<stdlib.h>
#include<windows.h>

void vehicle::set_vehicle_no()
{
    cout<<"\t\tVehicle No:";
    cin>>vehicle_no;
}

void vehicle::set_engine_no()
{
    cout<<"\t\tEngine Number:";
    cin>>engine_no;
}

void vehicle::set_insurance()
{
    cout<<"\t\tInsurance Number:";
    cin>>insurance;
}

void vehicle::set_rc_no()
{
    cout<<"\t\tRC Number:";
    cin>>rc_no;
}

void vehicle::set_registration()
{
    cout<<"\t\tRegistration:";
    cin>>registration;
}

void vehicle::set_vehicle_type()
{
    int i,j=0,check;
    for(j=0;j>=0;j++)
    {
        cout<<"\n\n\n\t\tVehicle Type('car','bike',auto):";
        cin>>vehicle_type;
            if(strcmp(vehicle_type,"car")==0||strcmp(vehicle_type,"bike")==0||strcmp(vehicle_type,"auto")==0)
            {
                break;
            }
            else
            {
                cout<<"\n\t**Enter a valid Type**";
                Sleep(200);
                system("CLS");
                cout<<"\n\n\n";
            }
    }

}


void vehicle::set_data(char *name1)
{
    set_vehicle_type();
    set_vehicle_no();
    set_engine_no();
    set_insurance();
    set_rc_no();
    set_registration();
    ofstream outfile;
    outfile.open(strcat(name1,"vehicle.txt"));
    outfile<<vehicle_type<<endl;
    outfile<<vehicle_no<<endl;
    outfile<<engine_no<<endl;
    outfile<<insurance<<endl;
    outfile<<rc_no<<endl;
    outfile<<registration<<endl;
}

void vehicle::set_vehicle_model()
{
   int i,j=0,check;
    for(j=0;j>=0;j++)
    {
        cout<<"\t\tVehicle Model:";
        cin>>model;
            if(strcmp(model,"Hyundai,i10")==0||strcmp(model,"Alto,k10")==0||strcmp(model,"Toyota,Innova")==0||strcmp(model,"Honda,Amaze")==0)
            {
                break;
            }
            else
            {
                cout<<"\n\t**Enter a valid Model**";
                Sleep(200);
                system("CLS");
                cout<<"\n\n\n";
            }
    }
}

void vehicle::set_fare()
{
    if(strcmp(model,"Hyundai,i10"))
        fare=500;
    if(strcmp(model,"Alto,k10"))
        fare=300;
    if(strcmp(model,"Toyota,Innova"))
        fare=700;
    if(strcmp(model,"Honda,Amaze"))
        fare=500;
}

void vehicle::set_rental()
{
    set_vehicle_model();
    set_fare();
    set_vehicle_no();
    set_engine_no();
    set_insurance();
    set_rc_no();
    set_registration();
    ofstream outfile;
    outfile.open("rental.txt",ios::app);
    outfile<<model<<endl;
    outfile<<vehicle_no<<endl;
    outfile<<registration<<endl;
    outfile<<fare<<endl;
    outfile.close();
}


void vehicle::load_data(char name1[20])
{
    ifstream infile;
    infile.open(name1);
    infile>>vehicle_type;
    infile>>vehicle_no;
    infile>>engine_no;
    infile>>insurance;
    infile>>rc_no;
    infile>>registration;
    infile.close();
}



float vehicle::get_fare()
{
    return fare;
}

char* vehicle::get_vehicle_no()
{
    return vehicle_no;
}
