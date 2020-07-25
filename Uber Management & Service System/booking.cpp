#include<iostream>
#include"booking.h"
using namespace std;
#include<string.h>
#include<fstream>
#include<stdlib.h>
#include<windows.h>


void Booking::set_date()
{
    cout<<"\t\tDate:";
    cin>>date;
}

void Booking::set_time()
{
    cout<<"\t\tTime:";
    cin>>time;
}

void Booking::set_destination()
{
    int i,j=0,check;
        for(j=0;j>=0;j++)
        {
            cout<<"\t\tDestination:";
            cin>>destination;
            if(strcmp(destination,"peelamedu")==0||strcmp(destination,"gandhipuram")==0||strcmp(destination,"chinniyampalayam")==0||strcmp(destination,"ukkadam")==0)
            {
                break;
            }
            else
            {
                cout<<"\n\t**Enter a valid Location Name**";
                Sleep(200);
                system("CLS");
                cout<<"\n\n\n\n";
            }
        }
}

void Booking::set_dfull_address()
{
    cout<<"\t\tDestination Full Address:";
    cin>>dfull_address;
}

void Booking::set_source()
{
    int i,j=0,check;
    for(j=0;j>=0;j++)
    {
        cout<<"\t\tSource:";
        cin>>source;
            if(strcmp(source,"peelamedu")==0||strcmp(source,"gandhipuram")==0||strcmp(source,"chinniyampalayam")==0||strcmp(source,"ukkadam")==0)
            {
                break;
            }
            else
            {
                cout<<"\n\t**Enter a valid Location Name**";
                Sleep(200);
                system("CLS");
                cout<<"\n\n\n\n";
            }
    }
}

void Booking::set_sfull_address()
{
    cout<<"\t\tSource Full Address:";
    cin>>full_address;
}

void Booking::set_fare()
{
    ifstream infile;
    infile.open("fare.txt");
    char s[20];
    char d[20];
    int i=0;
    int temp;
    for(i=0;i>=0;i++)
    {
        infile>>s;
        infile>>d;
        if((strcmp(source,s)==1||strcmp(source,d)==1)&&(strcmp(destination,s)==1||strcmp(destination,d)==1))
        {
            infile>>fare;
            infile.close();
            break;
        }
        else
        {
            infile>>temp;
            continue;
        }
    }
    cout<<"\t\tFare:"<<fare<<endl;
}

void Booking::setdriver()
{
    int i,k;
    k=0;
    ifstream infile1;
    ifstream infile2;
    ifstream infile3;
    char location1[20];
    char driver1[20];
    char temp[20];
    char near1[20];
    strcpy(temp,source);
    infile1.open(strcat(temp,".txt"));
    for(i=0;i<5;i++)
    {
        infile1>>near1;
        infile2.open("booking_vehicle.txt");
        while(infile2>>driver1)
        {
            strcpy(temp,driver1);
            infile3.open(strcat(temp,".txt"));
            infile3>>location1;
            if(strcmp(near1,location1)==0)
            {
                strcpy(temp,driver1);
                driver->load_data(driver1);
                infile3.close();
                infile2.close();
                k=-1;
                break;
            }
            else
            {
                infile3.close();
                continue;
            }
        }
        infile2.close();
        if(k==-1)
        break;
    }
    infile1.close();
    cout<<"\t\tNearest Driver:"<<temp<<endl;
}

void Booking::set_vehicle_type()
{
    int i,j=0,check;
    for(j=0;j>=0;j++)
    {
        cout<<"\t\tVehicle Type('car','bike',auto):";
        cin>>vehicle_type;
            if(strcmp(vehicle_type,"car")==0||strcmp(vehicle_type,"bike")==0||strcmp(vehicle_type,"auto")==0)
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
    driver=new Driverdetails;
    driver->update_vehicle_list(vehicle_type);
}

void Booking::display_booking()
{
    system("CLS");
    cout<<"\n\n\t\t\tBooking Details:\n\t\t-------------------------\n\n\n";
    cout<<"\t\tDate:  "<<date<<endl;
    cout<<"\t\tTime:  "<<time<<endl;
    cout<<"\t\tSource:"<<source<<endl;
    cout<<"\t\tDestination:"<<destination<<endl;
    cout<<"\n\t\tDriver Details:\n";
    driver->display_driver_details();
}

int Booking::book_ride(string name)
{
    system("CLS");
    cout<<"\n\t\t\tBOOK RIDE\n\t\t---------------------\n\n\n\n";
    set_date();
    set_time();
    set_source();
    set_sfull_address();
    set_destination();
    set_dfull_address();
    set_vehicle_type();
    set_fare();
    setdriver();
    char ch;
    cout<<"\n\t\tProceed to payment ?(y/n) ";
    cin>>ch;
    if(ch=='y')
    {
        file_write(name,1);
        cout<<"\n\t\tPAYMENT PORTAL\n\t\t----------------\n";
        cout<<"\n\tAmount : "<<fare<<endl;
        cout<<"\n\t\tTypes:\n\n\t1.Cash\t2.Card\t3.UPI\n\n\t\tChoice ? ";
        int n;
        cin>>n;
        if(n==1)
        {
            p=new Cash;
            p->pay(fare);
        }
        if(n==2)
        {
            p=new Card;
            p->pay(fare);
        }
        if(n==3)
        {
            p=new UPI;
            p->pay(fare);
        }
        cout<<"\n\t>> Ride booked <<";
        Sleep(2000);
        display_booking();
        return 0;
    }
    else
    {
        return -1;
    }
}


int Booking::book_rental(string name)
{
    int i=1;
    int time1;
    char model[30];
    char vehicle_no[20];
    char registration[20];
    char in[20];
    char ch;
    char temp[20];
    system("CLS");
    cin.ignore();
    cout<<"\n\t\tRENTAl BOOKING\n\t\t----------------\n\n\n";
    set_date();
    cout<<"\t\tEnter Time Required:(Hours)";
    cin>>time1;
    cout<<"\n\t\tAvailable Vehicles\n";
    ifstream infile;
    infile.open("rental.txt");
    while(infile>>model)
    {
        cout<<"\n\t\tVehicle "<<i;
        cout<<"\n\t\tModel:"<<model<<endl;
        infile>>vehicle_no;
        cout<<"\t\tVehicle No:"<<vehicle_no<<endl;
        infile>>registration;
        cout<<"\t\tRegistration:"<<registration<<endl;
        infile>>fare;
        cout<<"\t\tFare per hour:"<<fare<<endl;
        i++;
    }
    infile.close();
    cout<<"\n\t\tEnter the Model required:";
    cin>>temp;
    infile.open("rental.txt");
    while(!infile.eof())
    {
        infile>>in;
        if(strcmp(temp,in)==0)
        {
            strcpy(model,in);
            infile>>vehicle_no;
            infile>>registration;
            infile>>fare;
            fare=fare*time1;
            infile.close();
            break;
        }
        infile>>in;
        infile>>in;
        infile>>in;
    }
    infile.close();
    cout<<"\n\t\tProceed to payment ?(y/n) ";
    cin>>ch;
    if(ch=='y')
    {
        system("CLS");
        cout<<"\n\n\n\t\tPAYMENT PORTAL\n\t\t----------------\n";
        cout<<"\n\tAmount : "<<fare<<endl;
        cout<<"\n\t\tTypes:\n\n\t1.Cash\t2.Card\t3.UPI\n\n\t\tChoice ? ";
        int n;
        cin>>n;
        if(n==1)
        {
            p=new Cash;
            p->pay(fare);
        }
        if(n==2)
        {
            p=new Card;
            p->pay(fare);
        }
        if(n==3)
        {
            p=new UPI;
            p->pay(fare);
        }
        cout<<"\n\t>> Ride booked <<";
        Sleep(2000);
        system("CLS");
        cout<<"\n\n\t\tBooked Vehicle Details\n\t-------------------------------------\n\n\n";
        cout<<"\n\t\tVehicle Model:"<<model<<endl;
        cout<<"\t\tVehicle Number:"<<vehicle_no<<endl;
        cout<<"\t\tRegistration:"<<registration<<endl;
        cout<<"\t\tFare:"<<fare<<endl;
        ofstream f;
        string path =  name + "history.txt";
        f.open(path.c_str(),ios::app);
        f<<"(rental)-"<<date<<"-"<<model<<"-"<<vehicle_no<<endl;
        f.close();
        return 0;
    }
    else
    {
        return -1;
    }
}

int Booking::history(string name)
{
    char ch;
    system("CLS");
    cin.ignore();
    cout<<"\n\t\t\tHISTORY\n\t\t\t------------\n\n";
    char line[20];
    int cnt=1;
    ifstream f;
    string path =  name + "history.txt";
    f.open(path.c_str());
    if(!f)
    {
        cout<<"\t\t NO Travel History";
    }
    else{
    while(!f.eof())
    {
        f>>line;
        if(f.eof())
            break;
        cout<<"\t\t"<<cnt<<"."<<line<<endl;
        cnt++;
    }}
    f.close();
    cout<<endl;
    system("PAUSE");
    return -1;
}

void Booking::file_write(string name,int n)
{
    ofstream f;
    string path =  name + "history.txt";
    f.open(path.c_str(),ios::app);
    if(n==1)
        f<<source<<"-"<<destination<<"-"<<time<<endl;
    f.close();
}
