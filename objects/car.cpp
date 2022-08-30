#include <iostream>
#ifndef car_cpp
#define car_cpp
using namespace std;

class Car
{
private:
    string registrationNumber;
    string color;

public:
    string getRegistrationNumber()
    {
        return registrationNumber;
    }

    string getColor()
    {
        return color;
    }

    Car(const string registrationNumber, const string color)
    {
        this->registrationNumber = registrationNumber;
        this->color = color;
    }
};
#endif