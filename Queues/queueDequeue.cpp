#include "R:\C++\Project1\lcHeader.h"

class QueueUsingTwoStacks {
private:
    stack<int> stack1, stack2;

public:
    int front() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        if (stack2.empty()) {
            return INT_MIN;
        }

        return stack2.top();
    }

    bool isEmpty() {
        return stack1.empty() && stack2.empty();
    }

    void enqueue(int value) {
        stack1.push(value);
    }

    void dequeue(){
        if(stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if(!stack2.empty()){
            stack2.pop();
        }
    }
    
};

int main(){
        QueueUsingTwoStacks queue;
        cout << "Enqueuing values of 1, 2, and 3 to the queue:\n";
        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);
        cout << "Front result before dequeue: " << queue.front();
        queue.dequeue();
        cout << "Front result after 1st dequeue: " << queue.front();
        queue.dequeue();
        cout << "Front result after 2nd dequeue: " << queue.front();
}
