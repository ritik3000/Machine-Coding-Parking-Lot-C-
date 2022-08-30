#include "parking_stratergy.cpp"
#include <bits/stdc++.h>

#ifndef natural_cpp
#define natural_cpp

using namespace std;

/**
 * Parking strategy in which the natural ordering numbers are used for deciding the slot numbers.
 * For example, 1st car will be parked in slot 1, then next in slot 2, then in slot 3, and so on.
 */
class NaturalOrderingParkingStrategy : public ParkingStrategy
{
    set<int> slotSet;

public:
    void addSlot(int slotNumber)
    {
        slotSet.insert(slotNumber);
    }

    /**
     * {@inheritDoc}
     */

    void removeSlot(int slotNumber)
    {
        slotSet.erase(slotNumber);
    }

    /**
     * {@inheritDoc}
     */
    int getNextSlot()
    {
        if (slotSet.empty())
        {
            throw "NoFreeSlotAvailableException";
        }
        return *(slotSet.begin());
    }
};

#endif