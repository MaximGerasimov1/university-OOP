#ifndef RWFUNC_HPP
#define RWFUNC_HPP

#include <iostream>

struct InfoAboutLand {
    int number;
    std::string cadastralNumber;
    double area;
    std::string categoryLand;
    double cadastralValue;
};

int readFile(InfoAboutLand *land, std::string file);
int writeToFile(InfoAboutLand *land, std::string file, int currentRecord);

#endif // RWFUNC_HPP

