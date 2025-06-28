#include <iostream>
#include <vector>
#include <climits> 

using namespace std;


class Heap {
    public:
    vector<int> heap;

    int leftChild(int index){
        return 2 * index + 1;
    }

    int rightChild(int index){
        return 2 * index + 2;
    }

    int parent(int index){
        return (index - 1)/2;
    }

    void swap(int index1, int index2){
        int temp = heap[index1];
        heap[index1] =  heap[index2];
        heap[index2] = temp;
    }

    //This code block is to make sure that when we remove an item the complete tree structure is maintained so as to have max value at the top
    //MinHeap sinkDown
    void sinkDown(int index){
        int maxIndex = index;
        while(true){
            int leftIndex = leftChild(index);//calculate the value bu do not check the proper index
            int rightIndex = rightChild(index);

            //for minimum value we need to check if the leftIndex is not lesser than the heap size      
            if(leftIndex < heap.size() && heap[leftIndex] > heap[maxIndex]){
                maxIndex = leftIndex;
            }
            if(rightIndex < heap.size() && heap[rightIndex] > heap[maxIndex]){
                maxIndex = rightIndex;
            }
        // If either child was smaller than the current node,
        // swap the current node with this smaller child. This
        // is essential for moving larger elements down the heap
        // to restore the min heap property.
            if(maxIndex != index){
                swap(index, maxIndex);
                // Update 'index' to the position of the child to
                // continue sinking down the heap if necessary.
                index = maxIndex;
            }
            else return;
        }
    }
    
    void printHeap() {
        cout << "\n[";
        for (size_t i = 0; i < heap.size(); i++) {
            cout << heap[i];
            if (i < heap.size() - 1) { 
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    //MinHeap Insert
    void insert(int value) {
        heap.push_back(value);
        int current = heap.size() - 1;

        //to break out of while => should not be empty and value should always be greater than parent
        while(current > 0 && heap[current] > heap[parent(current)]){
            swap(current, parent(current));//swapping to get bigger value 
            current = parent(current);//change the current pointer for next comparision
        }
    }

    //MinHeap remove
    int remove(){
        if(heap.empty()){
            return INT_MIN;
        }
        int maxValue = heap.front();
        if(heap.size() == 1){
            heap.pop_back();
        }
        else{
            heap[0] = heap.back();
            heap.pop_back();
            sinkDown(0);
        }
        return maxValue;
    }
};

int main(){
    Heap* newHeap = new Heap();
    newHeap->insert(100);
    newHeap->insert(99);
    newHeap->insert(72);
    newHeap->insert(61);
    newHeap->insert(58);

    newHeap->printHeap();  

    newHeap->remove();
    newHeap->printHeap(); 
}