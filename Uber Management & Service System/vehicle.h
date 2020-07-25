#ifndef vehicle_h
#define vehicle_h
#include<string>

class vehicle
{
    char model[30];
    char vehicle_type[20];
    char vehicle_no[15];
    char engine_no[10];
    char insurance[10];
    char rc_no[10];
    char registration[20];
    float fare;
    int time;

    public:

    void set_vehicle_model();
    void set_vehicle_type();
    void set_vehicle_no();
    void set_engine_no();
    void set_insurance();
    void set_rc_no();
    void set_registration();
    void set_data(char* name1);
    char* get_vehicle_no();
    void set_fare();
    void set_rental();
    void load_data(char name1[20]);


    float get_fare();

};
#endif // vehicle_h
