#include <iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<windows.h>
#include"payment.h"

using namespace std;

void Payment::pay(float fare)
{
    amount=fare;
    char ch;
    system("CLS");
    cin.ignore();

}

void Cash::pay(float fare)
{
    cout<<"\n\t\tCash received\n\t\t>> Payment Successful <<\n";
}

void Card::pay(float fare)
{
    cout<<"\n\t\tCard Transaction";
    cout<<"\n\tBank : ";
    getline(cin,bank);
    cout<<"\n\tCard Number : ";
    cin>>card_no;
    cout<<"\n\tCVV Number : ";
    cin>>cvv;
    char ch;
    cout<<"\n\n\t\tCONFIRM ? (y/n) ";
    cin>>ch;
    if(ch=='y')
        cout<<"\n\n\t\t>> Payment Successful <<\n";
    else
        cout<<"\n\n\t\t>> Transaction canceled <<\n";
}

void UPI::pay(float fare)
{
    cout<<"\n\t\tUPI Transaction";
    cout<<"\n\tUPI ID : ";
    getline(cin,upi_id);
    char ch;
    cout<<"\n\n\t\tCONFIRM ? (y/n) ";
    cin>>ch;
    if(ch=='y')
        cout<<"\n\n\t\t>> Payment Successful <<\n";
    else
        cout<<"\n\n\t\t>> Transaction canceled <<\n";
}

