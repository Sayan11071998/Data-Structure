#include <iostream>
using namespace std;

// Node Class
class Node
{
public:
    int value;
    Node* next;

    Node(int value)
    {
        this->value = value;
        this->next = nullptr;
    }
};

// Queue Class using LinkedList
class Queue
{
public:
    // Constructor
    Queue(int value)
    {
        Node* newNode = new Node(value);
        first = newNode;
        last = newNode;
        length = 1;
    }

    // Destructor
    ~Queue()
    {
        Node* current = first;

        while (current != nullptr)
        {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }

        first = nullptr;
        last = nullptr;
        length = 0;
    }

    // Print Method
    void printQueue()
    {
        Node* temp = first;

        while (temp)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    // For Inserting Element from Last
    void enqueue(int value)
    {
        Node* newNode = new Node(value);

        if (length == 0)
        {
            first = newNode;
            last = newNode;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }

        length++;
    }

    // For Deleting Element from First
    int dequeue()
    {
        if (length == 0) return INT_MIN;

        Node* temp = first;
        int dequeuedValue = first->value;

        if (length == 1)
        {
            first = nullptr;
            last = nullptr;
        }
        else
        {
            first = first->next;
        }

        delete temp;
        length--;

        return dequeuedValue;
    }

    // Checking for Emepty Queue
    bool isEmpty()
    {
        if (length == 0) return true;
        return false;
    }

    // Getting First Element
    int firstValue()
    {
        if (first) return first->value;
        return INT_MIN;
    }

    // Getters
    void getFirst()
    {
        if (first == nullptr)
            cout << "First: nullptr" << endl;
        else
            cout << "First: " << first->value << endl;
    }

    void getLast()
    {
        if (last == nullptr)
            cout << "Last: nullptr" << endl;
        else
            cout << "Last: " << last->value << endl;
    }

    void getLength() { cout << "Length: " << length << endl; }

private:
    Node* first;
    Node* last;
    int length;
};

int main()
{
    // Initialize the queue with one element
    cout << "Initializing the queue with value 10..." << endl;
    Queue myQueue(10);

    // Print the initial state of the queue
    cout << "\nInitial queue:" << endl;
    myQueue.printQueue();
    myQueue.getFirst();
    myQueue.getLast();
    myQueue.getLength();

    // Enqueue elements
    cout << "\nEnqueueing values 20 and 30..." << endl;
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    // Print the queue after enqueueing
    cout << "\nQueue after enqueueing elements:" << endl;
    myQueue.printQueue();
    myQueue.getFirst();
    myQueue.getLast();
    myQueue.getLength();

    // Dequeue an element
    cout << "\nDequeuing an element..." << endl;
    int dequeuedValue = myQueue.dequeue();
    cout << "Dequeued value: " << dequeuedValue << endl;

    // Print the queue after dequeueing
    cout << "\nQueue after dequeueing an element:" << endl;
    myQueue.printQueue();
    myQueue.getFirst();
    myQueue.getLast();
    myQueue.getLength();

    // Check if the queue is empty
    cout << "\nChecking if the queue is empty..." << endl;
    if (myQueue.isEmpty())
        cout << "The queue is empty." << endl;
    else
        cout << "The queue is not empty." << endl;

    // Enqueue more elements
    cout << "\nEnqueueing values 40 and 50..." << endl;
    myQueue.enqueue(40);
    myQueue.enqueue(50);

    // Print the queue after enqueueing
    cout << "\nQueue after enqueueing more elements:" << endl;
    myQueue.printQueue();
    myQueue.getFirst();
    myQueue.getLast();
    myQueue.getLength();

    // Dequeue all elements to empty the queue
    cout << "\nDequeuing all elements to empty the queue..." << endl;
    while (!myQueue.isEmpty())
    {
        int value = myQueue.dequeue();
        cout << "Dequeued: " << value << endl;
    }

    // Print the queue state after emptying
    cout << "\nQueue after emptying:" << endl;
    myQueue.printQueue();
    myQueue.getFirst();
    myQueue.getLast();
    myQueue.getLength();

    // Final check if the queue is empty
    cout << "\nFinal check if the queue is empty..." << endl;
    if (myQueue.isEmpty())
        cout << "The queue is now empty." << endl;
    else
        cout << "The queue is not empty." << endl;

    return 0;
}