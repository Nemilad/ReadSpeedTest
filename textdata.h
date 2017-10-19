#ifndef TEXTDATA_H
#define TEXTDATA_H
#include <iostream>
#include <mainwindow.h>
#include <ui_mainwindow.h>
class textdata
{
public:
    textdata();
    textdata(const textdata &copy);
    void loadtext(int textnumber);
    bool loadtext_file(std::string filename);
private:

};

#endif // TEXTDATA_H
