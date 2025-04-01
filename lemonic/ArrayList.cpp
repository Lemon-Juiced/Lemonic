#include "ArrayList.h"
#include <utility>
#include <string>

using namespace std;

/**
 * Constructor for the ArrayList class.
 * Initializes the list with a given initial capacity and growth factor.
 * 
 * @param initialCapacity The initial capacity of the list.
 * @param growthFactor The factor by which the list's capacity will grow when it is full.
 * @return The newly created ArrayList object.
 */
template <typename T>
ArrayList<T>::ArrayList(int initialCapacity, int growthFactor)
    : size(0), capacity(initialCapacity), growthFactor(growthFactor) {
    if (initialCapacity <= 0 || growthFactor <= 1) {
        throw std::invalid_argument("Invalid capacity or growth factor");
    }
    data = std::make_unique<T[]>(capacity);
}

/**
 * Destructor for the ArrayList class.
 */
template <typename T>
ArrayList<T>::~ArrayList() = default;

/**
 * Resizes the list to a new capacity.
 * The new capacity is calculated as the old capacity multiplied by the growth factor.
 */
template <typename T>
void ArrayList<T>::resize() {
    capacity *= growthFactor;
    std::unique_ptr<T[]> newData = std::make_unique<T[]>(capacity);
    for (int i = 0; i < size; ++i) {
        newData[i] = std::move(data[i]);
    }
    data = std::move(newData);
}

/**
 * Adds an element to the end of the list.
 * If the list is full, it resizes the list to accommodate the new element.
 * 
 * @param element The element to be added to the list.
 */
template <typename T>
void ArrayList<T>::add(const T& element) {
    if (size == capacity) {
        resize();
    }
    data[size++] = element;
}

/**
 * Removes an element from the list at a specified index.
 * 
 * @param index The index of the element to be removed.
 */
template <typename T>
void ArrayList<T>::remove(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    for (int i = index; i < size - 1; ++i) {
        data[i] = std::move(data[i + 1]);
    }
    --size;
}

/**
 * Gets an element from the list at a specified index.
 * 
 * @param index The index of the element to be retrieved.
 * @return The element at the specified index.
 */
template <typename T>
T ArrayList<T>::get(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

/**
 * Sets an element in the list at a specified index.
 * 
 * @param index The index of the element to be set.
 * @param element The new element to be set at the specified index.
 */
template <typename T>
void ArrayList<T>::set(int index, const T& element) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    data[index] = element;
}

/**
 * Gets the current size of the list.
 * 
 * @return The number of elements in the list.
 */
template <typename T>
int ArrayList<T>::getSize() const {
    return size;
}

/**
 * Gets the current capacity of the list.
 * 
 * @return The maximum number of elements that the list can hold.
 */
template <typename T>
int ArrayList<T>::getCapacity() const {
    return capacity;
}

// Explicit instantiation of the template class
template class ArrayList<int>;
template class ArrayList<float>;
template class ArrayList<string>;