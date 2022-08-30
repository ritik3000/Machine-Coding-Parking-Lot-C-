#include <iostream>
#include <map>
#ifndef Parkinglot_cpp
#define Parkinglot_cpp
#include "slot.cpp"
#include "car.cpp"
using namespace std;
class ParkingLot
{
private:
    const int MAX_CAPACITY = 100000;
    int capacity;
    map<int, Slot> slots;

public:
    int getCapacity()
    {
        return capacity;
    }

    ParkingLot(int capacity)
    {
        this->capacity = capacity;
    }

    map<int, Slot> getSlots()
    {

        return slots;
    }

    /**
     * Helper method to get a {@link Slot} object for a given slot number. If slot does not exists,
     * then new slot will be created before giving it back.
     *
     * @param slotNumber Slot number.
     * @return Slot.
     */
private:
    Slot getSlot(int slotNumber)
    {
        if (slotNumber > getCapacity() || slotNumber <= 0)
        {
            throw "InValid Slot";
        }

        // slots.insert({slotNumber, new_slot});
        return slots[slotNumber];
    }

    /**
     * Parks a car into a given slot number.
     *
     * @param car Car to be parked.
     * @param slotNumber Slot number in which it has to be parked.
     * @return {@link Slot} if the parking succeeds. If the slot is already occupied then {@link
     *     SlotAlreadyOccupiedException} is thrown.
     */
public:
    Slot park(Car &car, int slotNumber)
    {
        if (slots.find(slotNumber) == slots.end())
        {
            // cout << 2 << endl;
            Slot new_slot(slotNumber);
            new_slot.assignCar(car);
            slots.insert({slotNumber, new_slot});
            // cout << slots[slotNumber].getSlotNumber() << endl;
            // cout << slots[slotNumber].getParkedCar().getRegistrationNumber() << endl;
            // cout << slots[slotNumber].getParkedCar().getColor() << endl;
        }

        else if (!slots[slotNumber].isSlotFree())
        {
            throw "Slot Already Occupied";
        }
        else
        {
            // cout << 1 << endl;
            slots[slotNumber].assignCar(car);
        }
        // new_slot.assignCar(car);
        // for (auto it = slots.begin(); it != slots.end(); it++)
        // {
        //     cout << "```" << endl;
        //     cout << it->first << endl;
        //     cout << (it->second).getParkedCar().getRegistrationNumber() << endl;
        // }

        // cout << slots[slotNumber].getParkedCar().getColor() << endl;
        return slots[slotNumber];
    }

    /**
     * Makes the slot free from the current parked car.
     *
     * @param slotNumber Slot number to be freed.
     * @return Freed slot.
     */
    Slot makeSlotFree(const int slotNumber)
    {
        Slot slot = getSlot(slotNumber);
        slot.unassignCar();
        slots[slotNumber].unassignCar();
        return slot;
    }
};
#endif