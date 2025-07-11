#include <iostream>
using namespace std;

class Node { 
    public: 
        int value;
        Node* next;
        Node* prev;
    
        Node(int value) {
            this->value = value;
            next = nullptr;
            prev = nullptr;
        }
};

class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;
        int length;
    
    public:  
    //DoublyLinkedList constructor    
        DoublyLinkedList(int value){
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        ~DoublyLinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }
    
        void printList() {
            Node* temp = head;
            if (temp == nullptr) {
                cout << "empty" << endl;
                return;
            }
            while (temp->next != nullptr) {
                cout << temp->value << " <-> ";
                temp = temp->next;
            }
            cout << temp->value << endl;
        }
    
        Node* getHead() {
            return head;
        }
    
        Node* getTail() {
            return tail;
        }
    
        int getLength() {
            return length;
        }

        // This method will make the DLL empty.
        // It will be used to make sure append works with an empty DLL.
        void makeEmpty() {
            Node* current = head;
            while (current != nullptr) {
                Node* nodeToDelete = current;
                current = current->next;
                delete nodeToDelete;
            }
            head = nullptr;
            tail = nullptr;
            length = 0;
        }

    //Append - adding node at last
    void append(int value){
         Node* newNode = new Node(value);
        if(length == 0){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next= newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }

    //deleting last item
    void deleteLast(){
        Node* temp = tail;
        if(length == 0)return;
        if(length == 1){
            head = nullptr;
            tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        length--;
    }

    void prepend(int value){
        Node* newNode = new Node(value);
        if(length == 0){
            head = newNode;
            tail = newNode;
        }
        else{
            newNode->next = head;
            head->prev= newNode;
            head = newNode;
        }
        length++;
    }

    void deleteFirst(){
        Node* temp = head;
        if(length == 1){
            head = nullptr;
            tail = nullptr;
        }
        else{
            head = head->next;
            head->prev = nullptr;
        }
        delete temp; 
        length--;
    }

    Node* get(int index){
        if(index < 0 || index > length){
            return nullptr;
        }
        Node* temp = head;
        if(index < length/2){
            for(int i = 0; i < index;i++){
                temp = temp->next;
            }
        }
        else{
            temp = tail;
            for(int i = length - 1;i > index;i--){
                temp = temp->prev;
            }
        }
        return temp;
    }

    bool set(int index, int value){
        Node* temp = get(index);
        if(temp){
            temp->value = value;
            return true;
        }
        return false;
    }

    bool insert(int index, int value){
        Node* newNode = new Node(value);
        Node* before = get(index-1);
        Node* after = before->next;
        if(index < 0 || index > length)return false;
        if(index == 0){
            prepend(value);
            return true;
        }
        if(index == length){
            append(value);
            return true;
        }       
        newNode->prev = before;
        newNode->next = after;
        before->next = newNode;
        after->prev = newNode;
        length++;
        return true;
    }

    void deleteNode(int index){
        if(index < 0 || index >= length)return;
        if(index == 0)return deleteFirst();
        if(index == length)return deleteLast();

        Node* temp = get(index);
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete temp;
        length--;
    }
};

int main(){
    DoublyLinkedList* dll = new DoublyLinkedList(7);
    dll->append(8);
    //dll->printList();
   // dll->deleteLast();
    dll->prepend(6);
    //dll->set(2,4);
    dll->insert(1,5);
    dll->printList();
    dll->deleteNode(1);
    dll->printList();
    // cout<<dll->get(0)->value<<endl;
    // cout<<dll->get(1)->value<<endl;
}


