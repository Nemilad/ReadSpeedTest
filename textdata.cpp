#include "textdata.h"

Textdata::Textdata()
{

}

bool Textdata::loadtext_file(std::string filename)
{
    std::ifstream file;
    file.open(filename);
    if(!file.is_open()) return false;
    else
    {
        file.close();
        return true;
    }
}
