#include "../../ArrayList.h"
#include <iostream>

using namespace std;

int main() {
    try {
        // Create a new ArrayList with an initial capacity of 10 and a growth factor of 2
        ArrayList<int> list(10, 2);

        // Add elements to the list
        list.add(10);
        list.add(20);
        list.add(30);

        // Print the elements of the list
        cout << "Elements in the list:" << endl;
        for (int i = 0; i < list.getSize(); i++) {
            cout << "Element at index " << i << ": " << list.get(i) << endl;
        }

        // Remove an element from the list
        list.remove(1);

        // Print the elements of the list after removal
        cout << "After removal:" << endl;
        for (int i = 0; i < list.getSize(); i++) {
            cout << "Element at index " << i << ": " << list.get(i) << endl;
        }

        // Set a new value at a specific index
        list.set(1, 50);
        cout << "After setting index 1 to 50:" << endl;
        for (int i = 0; i < list.getSize(); i++) {
            cout << "Element at index " << i << ": " << list.get(i) << endl;
        }

        // Print the current size and capacity of the list
        cout << "Current size: " << list.getSize() << endl;
        cout << "Current capacity: " << list.getCapacity() << endl;

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}