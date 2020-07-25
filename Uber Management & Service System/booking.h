#ifndef booking_h
#define booking_h
#include"driverdetails.h"
#include<string>
#include"payment.h"

using namespace std;
class Booking
{
    char date[20];
    char time[20];
    char vehicle_type[20];
    char source[30];
    char full_address[100];
    char destination[30];
    char dfull_address[100];
    float fare;
    char vehicle[20];
    Driverdetails *driver;
    Payment *p;

    public:

        int book_ride(string name);
        int book_rental(string name);
        int history(string name);
        void payment_details();
        void file_write(string name,int n);
        void set_date();
        void set_time();
        void set_source();
        void set_sfull_address();
        void set_destination();
        void set_dfull_address();
        void set_fare();
        void setdriver();
        void display_booking();
        void set_vehicle_type();
};
#endif // booking_h
