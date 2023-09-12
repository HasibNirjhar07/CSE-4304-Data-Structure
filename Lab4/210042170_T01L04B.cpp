// Implementing the basic operations of Queue.
// Implement the following operations with a circular queue.
// void Enqueue (int x)
// int Dequeue()
// int size
// void front
// Void rear
// Bool isEmpty()
// Bool isFull() 

// Test the functions by your self made test-cases.

#include <iostream>
using namespace std;

#define MAX_SIZE 100

int* queue = new int[MAX_SIZE]; // Dynamically allocate memory for the queue.
int* front = nullptr;
int* rear = nullptr;

bool isEmpty() {
    return front == nullptr;
}

bool isFull() {
    return (front == queue && rear == queue + MAX_SIZE - 1) || (front == rear + 1); // Check if the queue is full.
}

void Enqueue(int x) {
    if (isFull()) {
        cout << "Queue is full. Cannot enqueue." << endl;
        return;
    }

    if (isEmpty()) {
        front = rear = queue; // If the queue is empty, set front and rear to the first element of the queue.
    } else if (rear == queue + MAX_SIZE - 1) { // If rear is at the end of the queue, set rear to the first element of the queue.
        rear = queue; 
    } else {
        rear++; // Rear is not at the end of the queue. Increment rear.
    }

    *rear = x; // Set the value of the rear to x.
}

int Dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return -1;
    }

    int item = *front;

    if (front == rear) { // If the queue has only one element, set front and rear to nullptr.
        front = rear = nullptr; 
    } else if (front == queue + MAX_SIZE - 1) { // If front is at the end of the queue, set front to the first element of the queue.
        front = queue;
    } else {
        front++;
    }

    return item;
}

int size() {
    if (isEmpty()) {
        return 0;
    }

    if (front <= rear) { 
        return rear - front + 1; 
    } else { 
        return (MAX_SIZE - (front - queue)) + (rear - queue + 1); 
    } 
}

int Front() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return -1;
    }

    return *front;
}

int Rear() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return -1;
    }

    return *rear;
}

int main() {
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Enqueue(5);

    cout << "Queue size: " << size() << endl;
    cout << "Front element: " << Front() << endl;
    cout << "Rear element: " << Rear() << endl;

    Dequeue();
    Dequeue();

    Enqueue(6);
    Enqueue(7);
    cout<<queue[0]<<endl;
    cout<<queue[2]<<endl;
     cout<<queue[1]<<endl;

    cout << "Queue size after dequeuing 2 elements: " << size() << endl;
    cout << "Front element: " << Front() << endl;
    cout << "Rear element: " << Rear() << endl;

    delete[] queue; // Don't forget to release memory.
    return 0;
}