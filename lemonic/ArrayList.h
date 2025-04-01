#pragma once
#include <memory>
#include <stdexcept>

using namespace std;

/**
 * The ArrayList "class" is a dynamic array that can store any type of data.
 * The class is implemented as a struct that contains a few fields:
 * - data: A pointer to the array of void pointers that store the data. 
 *         void* is a generic pointer type. It can point to any type of data.
 * - size: The number of elements currently stored in the array.
 * - capacity: The maximum number of elements that the array can store.
 * - growth_factor: The factor by which the array's capacity is increased when it is reallocated.
 * 
 * The class also contains a few functions to manipulate the array:
 * - Constructor & Destructor
 * - addElement: Adds an element to the end of the ArrayList.
 * - removeElement: Removes an element from the ArrayList.
 * - get: Gets an element from the ArrayList.
 * - set: Sets an element in the ArrayList.
 * - getSize: Returns the number of elements in the ArrayList.
 * - getCapacity: Returns the capacity of the ArrayList.
 * 
 * When the capacity of the ArrayList is reached, the array is reallocated with a larger capacity.
 * The new capacity is calculated as the old capacity multiplied by a growth factor (e.g., 2).
 */
template <typename T>
class ArrayList {
private:
    unique_ptr<T[]> data; // Smart pointer for automatic memory management
    int size;
    int capacity;
    int growthFactor;

    void resize();

public:
    ArrayList(int initialCapacity = 10, int growthFactor = 2);
    ~ArrayList();

    void add(const T& element);
    void remove(int index);
    T get(int index) const;
    void set(int index, const T& element);
    int getSize() const;
    int getCapacity() const;
};