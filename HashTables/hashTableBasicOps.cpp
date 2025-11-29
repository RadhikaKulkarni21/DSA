#include <iostream>
#include <vector>

using namespace std;

class Node {
    public:
        string key;
        int value;
        Node* next;

        Node(string key,int value) {
            this->key = key;
            this->value = value;
            next = nullptr;
        }
};

class HashTable {
    private:
        static const int SIZE = 7;
        Node* dataMap[SIZE];

        int hash(string key){
            int hash = 0;
            for(int i = 0;i<key.length();i++){
                int asciiValue = int(key[i]);
                //multiplying by a prime numbers makes the result more random
                hash = (hash + asciiValue * 23) % SIZE;
            }
            return hash;
        }

    public:
        HashTable() {
            for(int i = 0; i < SIZE; i++) {
                dataMap[i] = nullptr;
            }
        }
        
        // ---------------------------------------------------
        //  Destructor code is similar to keys() function
        //  Watch that video to help understand how this works
        // ---------------------------------------------------
        ~HashTable() {
            for(int i = 0; i < SIZE; i++) {
                Node* head = dataMap[i];
                Node* temp = head;
                while (head) {
                    head = head->next;
                    delete temp;
                    temp = head;
                }
            }
        }
        
        void printTable() {
            for(int i = 0; i < SIZE; i++) {
                cout << "Index " << i << ": ";
                if(dataMap[i]) {
                    cout << "Contains => ";
                    Node* temp = dataMap[i];
                    while (temp) {
                        cout << "{" << temp->key << ", " << temp->value << "}";
                        temp = temp->next;
                        if (temp) cout << ", ";
                    }
                    cout << endl;
                } else {
                    cout << "Empty" << endl;
                }
            }
        }

        void set(string key, int value){
            int index = hash(key);
            Node* newNode = new Node(key, value);
            if(dataMap[index] == nullptr){
                dataMap[index] = newNode;
            }
            else{
                Node* temp = dataMap[index];
                while(temp->next != nullptr){
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        int get(string key){
            int index = hash(key);
            Node* temp = dataMap[index];
            while(temp != nullptr){
                if(temp->key == key) return temp->value;
                temp = temp->next;
            }
            return 0;
        }
        
        vector<string> keys(){
            vector<string> allKeys;
            for(int i = 0;i<SIZE;i++){
                Node* temp = dataMap[i];
                while(temp != nullptr){
                    allKeys.push_back(temp->key);
                    temp = temp->next;
                }
            }
            return allKeys;
        }
};

int main(){
    HashTable* ht = new HashTable();

    ht->set("nails", 100);
    ht->set("bolts", 1000);
    ht->set("screws", 40);
    ht->set("nuts", 40);
    ht->set("wood", 4000);

    // cout<< "Wood:" <<ht->get("wood") << endl;
    // cout<< "Nuts:" <<ht->get("nuts") << endl;
    // cout<< "Ply:" <<ht->get("ply") << endl;
    vector<string> mkeys = ht->keys();
    for(auto key: mkeys){
        cout<<key<<" ";
    }

    //ht->printTable();
}