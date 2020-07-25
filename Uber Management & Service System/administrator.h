#ifndef administrator_h
#define administrator_h
#include"driverdetails.h"
#include"vehicle.h"
class Administrator
{
    Driverdetails *driver;
    vehicle *v;

    public:

        void new_record();
        void update();
        void incentive();
        void new_rental();
};
#endif // administrator_h
