#include <bits/stdc++.h>
#include "objects/Parkinglot.cpp"
#include "stratergy/parking_stratergy.cpp"
#include "parkinglotservice.cpp"
#include "stratergy/natural.cpp"
#include "objects/slot.cpp"
#include "objects/car.cpp"

using namespace std;

int main()
{

    int capacity = 5;
    ParkingLot *pl = new ParkingLot(capacity);
    // cout << pl << endl;
    ParkingLotService parkingLotService;
    ParkingStrategy *parkingStrategy = new NaturalOrderingParkingStrategy();
    try
    {
        parkingLotService.createParkingLot(pl, parkingStrategy);
    }
    catch (const char *excp)
    {
        cout << excp << endl;
    }
    Car *car_1 = new Car("ciaz", "blue");
    Car *car_2 = new Car("baleno", "black");
    Car *car_3 = new Car("bmw", "blue");
    Car *car_4 = new Car("audi", "black");
    Car *car_5 = new Car("porsche", "black");
    try
    {
        int a = parkingLotService.park(*car_1);
        cout << car_1->getRegistrationNumber() << " parked at slot " << a << endl;
        a = parkingLotService.park(*car_2);
        cout << car_2->getRegistrationNumber() << " parked at slot " << a << endl;
        a = parkingLotService.park(*car_3);
        cout << car_3->getRegistrationNumber() << " parked at slot " << a << endl;
        a = parkingLotService.park(*car_4);
        cout << car_4->getRegistrationNumber() << " parked at slot " << a << endl;
        a = parkingLotService.park(*car_5);
        cout << car_5->getRegistrationNumber() << " parked at slot " << a << endl;
    }

    // Car *car_1 = new Car("ciaz", "blue");
    // Car *car_2 = new Car("baleno", "black");
    // Car *car_3 = new Car("bmw", "blue");
    // Car *car_4 = new Car("audi", "black");
    // Car *car_5 = new Car("porsche", "black");
    // try
    // {
    //     int a = 5;
    //     pl->park(*car_1, 1);
    //     cout << car_1->getRegistrationNumber() << "parked at slot " << a << endl;
    //     pl->park(*car_2, 2);
    //     cout << car_2->getRegistrationNumber() << "parked at slot " << a << endl;
    //     pl->park(*car_3, 3);
    //     cout << car_3->getRegistrationNumber() << "parked at slot " << a << endl;
    //     pl->park(*car_4, 4);
    //     cout << car_4->getRegistrationNumber() << "parked at slot " << a << endl;
    //     pl->park(*car_5, 5);
    //     cout << car_5->getRegistrationNumber() << "parked at slot " << a << endl;
    // }
    catch (const char *excp)
    {
        cout << excp << endl;
    }
    // map<int, Slot> slots = pl->getSlots();
    // for (auto it = slots.begin(); it != slots.end(); it++)
    // {

    //     cout << it->second.getParkedCar().getRegistrationNumber() << endl;
    //     // cout << &slots << endl;
    // }
    parkingLotService.makeSlotFree(3);
    Car *car_6 = new Car("hcity", "black");
    parkingLotService.park(*car_6);
    vector<Slot> sl = parkingLotService.getOccupiedSlots();

    for (int i = 0; i < sl.size(); i++)
    {
        cout << sl[i].getParkedCar().getRegistrationNumber() << " " << sl[i].getParkedCar().getColor() << endl;
    }
}
