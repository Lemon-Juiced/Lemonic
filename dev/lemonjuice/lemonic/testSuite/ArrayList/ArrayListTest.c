#include <stdio.h>
#include "../../ArrayList.h"

int main() {
    // Create a new ArrayList with default capacity and growth factor
    ArrayList *list = createArrayList(10, 2.0); // Example arguments: initial capacity of 10 and growth factor of 2.0
    // Add elements to the list
    int elem1 = 10, elem2 = 20, elem3 = 30;
    list->add(list, &elem1);
    list->add(list, &elem2);
    list->add(list, &elem3);

    // Print the elements of the list
    for (int i = 0; i < list->getSize(list); i++) {
        printf("Element at index %d: %d\n", i, *(int*)list->get(list, i));
    }

    // Remove an element from the list
    list->removeElement(list, 1);

    // Print the elements of the list after removal
    printf("After removal:\n");
    for (int i = 0; i < list->getSize(list); i++) {
        printf("Element at index %d: %d\n", i, *(int*)list->get(list, i));
    }
    
    // Clean up
    destroyArrayList(list);

    return 0;
}