#include <iostream>
using namespace std;

struct Queue {
   private:
    int front;
    int rear;
    int front_data;
    int rear_data;
    int len;
    int *arr;
    bool full;

   public:
    Queue(int l) {
        arr = new int[l];
        front = 0;
        rear = 0;
        len = l;
        full = false;
        front_data = rear_data = 0;
    }
    
    void enque(int data) {
        if (full) {
            cout << "Queue is full\n";
            return;
        }
        arr[rear] = data;  // Insert at rear
        rear_data = data;  // Update rear data
        rear = (rear + 1) % len;  // Circular increment
        
        if (rear == front) {
            full = true;
        }
        front_data = arr[front];  // Update front data
    }

    int deque() {
        if (front == rear && !full) {  // Queue is empty
            cout << "Queue is empty\n";
            return -1;
        }

        full = false;
        int temp = arr[front];
        front = (front + 1) % len;  // Circular increment
        front_data = arr[front];    // Update front data
        return temp;
    }

    int start() { return arr[front]; }  // Start (front element)
    int end() { return arr[(rear - 1 + len) % len]; }  // End (rear element)
    
    void show() {
        if (front == rear && !full) {  // Queue is empty
            cout << "Nothing to show\n";
            return;
        }
        
        int f = front;
        while (f != rear || full) {
            cout << arr[f] << " ";
            f = (f + 1) % len;
            if (f == rear) break;
        }
        cout << endl;
    }
};

int main() {
    Queue queue(5);  // Queue of size 5
    
    queue.enque(1);
    queue.enque(2);
    queue.enque(4);
    queue.enque(5);
    queue.enque(6);
    
    // Full queue, this will not insert
    queue.enque(7);
    
    queue.deque();
    queue.deque();
    
    queue.enque(8);  // Add after dequeue
    
    cout << "Start (front): " << queue.start() << endl;
    cout << "End (rear): " << queue.end() << endl;
    
    queue.show();  // Show the queue content
    
    return 0;
}
