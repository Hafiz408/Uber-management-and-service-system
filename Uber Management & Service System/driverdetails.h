#ifndef Driverdetails_h
#define Driverdetails_h
#include"vehicle.h"
class Driverdetails
{
    char licence_no[10];
    char name[30];
    int age;
    char phone[10];
    int rides;
    vehicle *veh;
    char location[20];
    int salary;

    public:
        void set_licence_no();
        void set_name();
        void set_age();
        void set_phone();
        void set_rides();
        void set_location();
        void set_salary();
        void setdata();
        void load_data(char name1[20]);
        void display_driver_details();
        void update_vehicle_list(char *type);
};
#endif // Driverdetails
