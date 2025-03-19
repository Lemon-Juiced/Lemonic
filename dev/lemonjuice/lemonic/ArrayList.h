#pragma once
#include <stdio.h>
#include <stdlib.h>

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
 * - createArrayList: Creates a new ArrayList with a given capacity.
 * - newArrayList: Creates a new ArrayList with default capacity and growth factor.
 * - destroyArrayList: Frees the memory used by the ArrayList.
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
typedef struct {
    // Data Members
    void** data;
    int size;
    int capacity;
    int growth_factor;

    // Member Functions
    void (*add)(void* self, void* element);
    void (*removeElement)(void* self, int index);
    void* (*get)(void* self, int index);
    void (*set)(void* self, int index, void* element);
    int (*getSize)(void* self);
    int (*getCapacity)(void* self);
} ArrayList;

// Function Prototypes
ArrayList* createArrayList(int capacity, int growth_factor);
ArrayList* newArrayList();
void destroyArrayList(void* self);
void add(void* self, void* element);
void removeElement(void* self, int index);
void* get(void* self, int index);
void set(void* self, int index, void* element);
int getSize(void* self);
int getCapacity(void* self);