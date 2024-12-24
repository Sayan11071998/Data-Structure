#include <iostream>
using namespace std;

// Queue Class using Array
class Queue
{
public:
    // Constructor
    Queue(int queueSize)
    {
        this->queueSize = queueSize;
        queue = new int[queueSize];
        front = 0;
        rear = -1;
        currentSize = 0;
    }

    // Destructor
    ~Queue() { delete[] queue; }

    // Print Queue
    void printQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
        cout << endl;
    }

    // Push (Enqueue)
    void enqueue(int value)
    {
        if (currentSize == queueSize)
        {
            cout << "Queue is Full. Can not push!" << endl;
            return;
        }

        // Check if rear exceeds the queue size
        if (rear + 1 >= queueSize)
        {
            cout << "Error: Queue overflow detected!" << endl;
            return;
        }

        rear++;
        queue[rear] = value;
        currentSize++;
    }

    // Pop (Dequeue)
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        front++;
        currentSize--;

        // Reset front and rear if the queue becomes empty
        if (currentSize == 0)
        {
            front = 0;
            rear = -1;
        }
    }

    // Front
    int frontValue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return -1; // Return a sentinel value
        }

        return queue[front];
    }

    // Size
    int size() { return currentSize; }

    // Empty
    bool isEmpty() { return currentSize == 0; }

private:
    int* queue;
    int front;
    int rear;
    int currentSize;
    int queueSize;
};

int main()
{
    // Initialize a queue with capacity 5
    Queue myQueue(5);

    // Push elements
    cout << "Pushing values 10, 20, 30..." << endl;
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    // Print the queue
    cout << "Current Queue: ";
    myQueue.printQueue();

    // Print front and size
    cout << "Front element: " << myQueue.frontValue() << endl;
    cout << "Queue size: " << myQueue.size() << endl;

    // Pop an element
    cout << "Popping an element..." << endl;
    myQueue.dequeue();

    // Print the queue after popping
    cout << "Queue after pop: ";
    myQueue.printQueue();
    cout << "Front element after pop: " << myQueue.frontValue() << endl;
    cout << "Queue size after pop: " << myQueue.size() << endl;

    // Push more elements
    cout << "Pushing values 40 and 50..." << endl;
    myQueue.enqueue(40);
    myQueue.enqueue(50);

    // Attempt to push into a full queue
    cout << "Attempting to push 60 into a full queue..." << endl;
    myQueue.enqueue(60);

    // Print the queue
    cout << "Queue after pushing more elements: ";
    myQueue.printQueue();

    // Pop all elements to empty the queue
    cout << "Popping all elements..." << endl;
    while (!myQueue.isEmpty())
    {
        cout << "Popped: " << myQueue.frontValue() << endl;
        myQueue.dequeue();
    }

    // Print the queue state after emptying
    cout << "Queue after emptying: ";
    myQueue.printQueue();

    // Final check if the queue is empty
    cout << "Final check if the queue is empty: " << (myQueue.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
