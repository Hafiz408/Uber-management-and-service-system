#include<string>
#ifndef payment_h
#define payment_h


using namespace std;

class Payment
{
    Payment *m;
    double amount;

public:

    virtual void pay(float fare)=0;
};

class Card:public Payment
{
    string bank;
    string card_no;
    string cvv;

public:
    void pay(float fare);
};

class UPI:public Payment
{
    string upi_id;

public:
    void pay(float fare);
};

class Cash:public Payment
{
public:
    void pay(float fare);
};

#endif // payment_h
