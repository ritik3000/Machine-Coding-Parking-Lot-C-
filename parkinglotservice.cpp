#include "objects/Parkinglot.cpp"
#include "stratergy/parking_stratergy.cpp"
#include "objects/slot.cpp"
#include "objects/car.cpp"
#include <bits/stdc++.h>
#ifndef parkinglotservice_cpp
#define parkinglotservice_cpp
using namespace std;

/**
 * Service for enable the functioning of a parking lot. This will have all the business logic of
 * how the parking service will operate.
 */
class ParkingLotService
{
private:
    ParkingStrategy *parkingStrategy = NULL;
    ParkingLot *parkingLot = NULL;

    /**
     * Allots a parking lot into the parking service. Throwns {@link ParkingLotException} if there is
     * already a parking lot alloted to the service previously.
     *
     * @param parkingLot Parking lot to be alloted.
     * @param parkingStrategy Strategy to be used while parking.
     */
public:
    void createParkingLot(ParkingLot *parkingLot, ParkingStrategy *parkingStrategy)
    {
        if (this->parkingLot != NULL)
        {
            throw "Parking lot already exists.";
        }
        this->parkingLot = parkingLot;
        this->parkingStrategy = parkingStrategy;
        for (int i = 1; i <= this->parkingLot->getCapacity(); i++)
        {
            this->parkingStrategy->addSlot(i);
        }
    }

    /**
     * Parks a {@link Car} into the parking lot. {@link ParkingStrategy} is used to decide the slot
     * number and then the car is parked into the {@link ParkingLot} into that slot number.
     *
     * @param car Car to be parked.
     * @return Slot number in which the car is parked.
     */
    int park(Car &car)
    {
        validateParkingLotExists();
        int nextFreeSlot = parkingStrategy->getNextSlot();
        Slot s = parkingLot->park(car, nextFreeSlot);
        // cout << parkingLot << endl;
        parkingStrategy->removeSlot(nextFreeSlot);
        return nextFreeSlot;
    }

    /**
     * Unparks a car from a slot. Freed slot number is given back to the parking strategy so that it
     * becomes available for future parkings.
     *
     * @param slotNumber Slot number to be freed.
     */

    void makeSlotFree(int slotNumber)
    {
        validateParkingLotExists();
        parkingLot->makeSlotFree(slotNumber);
        parkingStrategy->addSlot(slotNumber);
    }

    /**
     * Gets the list of all the slots which are occupied.
     */
public:
    vector<Slot> getOccupiedSlots()
    {
        cout << parkingLot << endl;
        validateParkingLotExists();
        vector<Slot> occupiedSlotsList;
        map<int, Slot> slots = parkingLot->getSlots();

        for (int i = 1; i <= parkingLot->getCapacity(); i++)
        {
            // cout << "a" << endl;
            if (slots.find(i) != slots.end())
            {

                Slot slot = slots[i];
                if (!slot.isSlotFree())
                {
                    occupiedSlotsList.push_back(slot);
                }
            }
        }

        return occupiedSlotsList;
    }

    /**
     * Helper method to validate whether the parking lot exists or not. This is used to validate the
     * existence of parking lot before doing any operation on it.
     */
private:
    void validateParkingLotExists()
    {
        if (parkingLot == NULL)
        {
            throw "Parking lot does not exists to park.";
        }
    }

    /**
     * Gets all the slots in which a car with given color is parked.
     *
     * @param color Color to be searched.
     * @return All matching slots.
     */
public:
    vector<Slot> getSlotsForColor(string color)
    {
        vector<Slot> occupiedSlots = getOccupiedSlots();
        vector<Slot> occupiedSlots_color;
        for (int i = 0; i < occupiedSlots.size(); i++)
        {
            if (occupiedSlots[i].getParkedCar().getColor() == color)
            {
                occupiedSlots_color.push_back(occupiedSlots[i]);
            }
        }
        return occupiedSlots_color;
    }
};

#endif