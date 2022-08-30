#include <iostream>
#ifndef slot_cpp
#define slot_cpp
#include "car.cpp"
using namespace std;
class Slot
{
private:
    Car *parkedCar = NULL;
    int *slotNumber = NULL;

public:
    Slot()
    {
    }
    Slot(int &slotNumber)
    {
        this->slotNumber = &slotNumber;
    }

    int getSlotNumber()
    {
        return *slotNumber;
    }

    Car getParkedCar()
    {
        return *parkedCar;
    }

    bool isSlotFree()
    {
        return parkedCar == NULL;
    }

    void assignCar(Car &car)
    {
        // cout << car.getRegistrationNumber() << endl;
        this->parkedCar = &car;
        // cout << parkedCar->getRegistrationNumber() << endl;
    }

    void unassignCar()
    {
        this->parkedCar = NULL;
    }
};
#endif