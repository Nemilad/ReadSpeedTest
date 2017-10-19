#ifndef USERDATA_H
#define USERDATA_H
#include <iostream>
#include <mainwindow.h>
class UserData
{
public:
    UserData();
    UserData(const UserData &copy);
    bool save_data(std::string filename);
    bool load_data(std::string filename);
    void plot();
private:

};

#endif // USERDATA_H
