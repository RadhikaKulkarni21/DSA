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

    void sinkDown(int index){
        int maxIndex = index;
        while(true){
            int leftIndex = leftChild(index);//calculate the value bu do not check the proper index
            int rightIndex = rightChild(index);

            if(heap[leftIndex] > heap[maxIndex]){
                maxIndex = leftIndex;
            }
            if(heap[rightIndex] > heap[maxIndex]){
                maxIndex = rightIndex;
            }
            if(maxIndex != index){
                swap(index, maxIndex);
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

    void insert(int value) {
        heap.push_back(value);
        int current = heap.size() - 1;

        //to break out of while => should not be empty and value should always be greater than parent
        while(current > 0 && heap[current] > heap[parent(current)]){
            swap(current, parent(current));//swapping to get bigger value 
            current = parent(current);//change the current pointer for next comparision
        }
    }

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
    newHeap->insert(99);
    newHeap->insert(72);
    newHeap->insert(61);
    newHeap->insert(58);

    newHeap->printHeap();  
    newHeap->insert(100);

     newHeap->printHeap(); 
}