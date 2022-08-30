#include <iostream>
#ifndef parking_stratergy_cpp
#define parking_stratergy_cpp
#include "../objects/Parkinglot.cpp"
#include "../objects/slot.cpp"
#include "../objects/car.cpp"

using namespace std;

class ParkingStrategy
{
public:
    /**
     * Add a new slot to parking strategy. After adding, this new slot will become available for
     * future parkings.
     *
     * @param slotNumber Slot number to be added.
     */
    virtual void addSlot(int slotNumber) = 0;

    /**
     * Removes a slot from the parking strategy. After removing, this slot will not be used for future
     * parkings.
     *
     * @param slotNumber Slot number to be removed.
     */
    virtual void removeSlot(int slotNumber) = 0;

    /**
     * Get the next free slot as per the parking strategy.
     *
     * @return Next free slot number.
     */
    virtual int getNextSlot() = 0;
};
#endif