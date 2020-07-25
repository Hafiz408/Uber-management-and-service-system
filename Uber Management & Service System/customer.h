#include<string>
#include"booking.h"

using namespace std;

class Customer
{
    string name;
    string password;
    string number;
    Booking b;

public:

    void data_copy(string n,string no,string psd);
    int file_check(string n);
    void file_write();
    string get_password();
    string get_name();
    int book_details(int n);
};

