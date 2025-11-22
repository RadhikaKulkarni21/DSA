/*Theory in notes*/

#include "R:\C++\Project1\lcHeader.h"

class hashNode{
    public:
    int key;
    int value;

    //constructor
    hashNode(int key, int value): key(key), value(value){};
};

class hashMap {
    hashNode** arr;
    int capacity;
    int size;

    hashNode* dummy;

public:

    // constructor to initialize members
    hashMap() {
        capacity = 20;
        size = 0;
        arr = new hashNode*[capacity];
        for (int i = 0; i < capacity; i++)
            arr[i] = NULL;
        dummy = new hashNode(-1, -1);
    }

    // hash function to calculate index
    //essentially the mathematical equation for it
    int hashCode(int key) {
        return key % capacity;
    }

    /*---------------------------*/
    /*----ONLY IMPORTANT PART----*/
    /* SKIP THE REST OF THE CODE */
    /*---------------------------*/
    // function to insert a key-value pair
    void insertNode(int key, int value) {
        hashNode* temp = new hashNode(key, value);
        int hashIndex = hashCode(key);

        // linear probing to find correct index
        while (arr[hashIndex] != NULL &&
               arr[hashIndex]->key != key &&
               arr[hashIndex]->key != -1) {
            hashIndex++;
            hashIndex %= capacity;
        }

        // insert node and update size if it's a new entry
        if (arr[hashIndex] == NULL || 
                    arr[hashIndex]->key == -1)
            size++;
        arr[hashIndex] = temp;
    }

    // function to delete a node by key
    int deleteNode(int key) {
        int hashIndex = hashCode(key);

        // search for the node with the given key
        while (arr[hashIndex] != NULL) {
            if (arr[hashIndex]->key == key) {
                hashNode* temp = arr[hashIndex];
                arr[hashIndex] = dummy;
                size--;
                return temp->value;
            }
            hashIndex++;
            hashIndex %= capacity;
        }

        // key not found
        return -1;
    }

    // function to get value for a given key
    int get(int key) {
        int hashIndex = hashCode(key);
        int counter = 0;

        // search for the key using linear probing
        while (arr[hashIndex] != NULL) {
            if (counter++ > capacity)
                return -1;

            if (arr[hashIndex]->key == key)
                return arr[hashIndex]->value;
            hashIndex++;
            hashIndex %= capacity;
        }

        // key not found
        return -1;
    }

    // function to return number of elements in map
    int sizeofMap() {
        return size;
    }

    // function to check if map is empty
    bool isEmpty() {
        return size == 0;
    }

    // function to print all key-value pairs
    void display() {
        for (int i = 0; i < capacity; i++) {
            if (arr[i] != NULL && arr[i]->key != -1)
                cout  << arr[i]->key << " "
                         << arr[i]->value << endl;
        }
    }
};

int main() {
    hashMap* h = new hashMap;

    h->insertNode(1, 1);
    h->insertNode(2, 2);
    h->insertNode(2, 3);

    h->display();

    cout << h->sizeofMap() << endl;

    cout << h->deleteNode(2) << endl;

    cout << h->sizeofMap() << endl;

    cout << boolalpha << h->isEmpty() << endl;

    cout << h->get(2);

    return 0;
}