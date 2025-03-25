#include "ArrayList.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Creates a new ArrayList with a given capacity.
 * 
 * @param capacity The initial capacity of the ArrayList.
 * @param growth_factor The factor by which the ArrayList's capacity is increased when it is reallocated.
 * @return A pointer to the newly created ArrayList.
 */
ArrayList* createArrayList(int capacity, int growth_factor) {
    ArrayList* list = (ArrayList*)malloc(sizeof(ArrayList));
    list->data = (void**)malloc(capacity * sizeof(void*));
    list->size = 0;
    list->capacity = capacity;
    list->growth_factor = growth_factor;

    list->add = add;
    list->removeElement = removeElement;
    list->get = get;
    list->set = set;
    list->getSize = getSize;
    list->getCapacity = getCapacity;

    return list;
}

/**
 * Creates a new ArrayList with default capacity and growth factor.
 * Default capacity is 10 and default growth factor is 2.
 * 
 * @return A pointer to the newly created ArrayList.
 */
ArrayList* newArrayList() {
    return createArrayList(10, 2);
}

/**
 * Frees the memory used by the ArrayList.
 * 
 * @param self A pointer to the ArrayList to be destroyed.
 */
void destroyArrayList(void* self) {
    ArrayList* list = (ArrayList*)self;
    free(list->data);
    free(list);
}

/**
 * Adds an element to the end of the ArrayList.
 * 
 * @param self A pointer to the ArrayList.
 * @param element A pointer to the element to be added.
 */
void add(void* self, void* element) {
    ArrayList* list = (ArrayList*)self;
    if (list->size == list->capacity) {
        list->capacity *= list->growth_factor;
        list->data = (void**)realloc(list->data, list->capacity * sizeof(void*));
    }
    list->data[list->size++] = element;
}

/**
 * Removes an element from the ArrayList.
 * 
 * @param self A pointer to the ArrayList.
 * @param index The index of the element to be removed.
 */
void removeElement(void* self, int index) {
    ArrayList* list = (ArrayList*)self;
    if (index < 0 || index >= list->size) {
        printf("Error: Index out of bounds\n");
        return;
    }
    for (int i = index; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->size--;
}

/**
 * Gets an element from the ArrayList.
 * 
 * @param self A pointer to the ArrayList.
 * @param index The index of the element to be retrieved.
 * @return A pointer to the element at the specified index.
 */
void* get(void* self, int index) {
    ArrayList* list = (ArrayList*)self;
    if (index < 0 || index >= list->size) {
        printf("Error: Index out of bounds\n");
        return NULL;
    }
    return list->data[index];
}

/**
 * Sets an element in the ArrayList.
 * 
 * @param self A pointer to the ArrayList.
 * @param index The index of the element to be set.
 * @param element A pointer to the new element.
 */
void set(void* self, int index, void* element) {
    ArrayList* list = (ArrayList*)self;
    if (index < 0 || index >= list->size) {
        printf("Error: Index out of bounds\n");
        return;
    }
    list->data[index] = element;
}

/**
 * Returns the number of elements in the ArrayList.
 * 
 * @param self A pointer to the ArrayList.
 * @return The number of elements in the ArrayList.
 */
int getSize(void* self) {
    ArrayList* list = (ArrayList*)self;
    return list->size;
}

/**
 * Returns the capacity of the ArrayList.
 * 
 * @param self A pointer to the ArrayList.
 * @return The capacity of the ArrayList.
 */
int getCapacity(void* self) {
    ArrayList* list = (ArrayList*)self;
    return list->capacity;
}