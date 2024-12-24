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

// Circular Queue Class using LinkedList
class CircularQueue
{
public:
    // Constructor
    CircularQueue()
    {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    // Destructor
    ~CircularQueue()
    {
        while (!empty()) { dequeue(); }
    }

    // Push (Enqueue)
    void enqueue(int x)
    {
        Node* newNode = new Node(x);

        if (empty())
        {
            head = newNode;
            tail = newNode;
            tail->next = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }

        length++;
    }

    // Pop (Dequeue)
    void dequeue()
    {
        if (empty())
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        Node* temp = head;

        if (head == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = head->next;
            tail->next = head;
        }

        delete temp;
        length--;
    }

    // Front (Get front element)
    int front()
    {
        if (empty())
        {
            cout << "Queue is empty. No front element." << endl;
            return -1;
        }

        return head->value;
    }

    // Size
    int size() { return length; }

    // Empty
    bool empty() { return length == 0; }

    // Print Queue
    void printQueue()
    {
        if (empty())
        {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* temp = head;

        do
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        while (temp != head);

        cout << endl;
    }

private:
    Node* head;
    Node* tail;
    int length;
};

int main()
{
    CircularQueue cq;

    cout << "Pushing elements into the circular queue: 10, 20, 30" << endl;
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);

    cout << "\nCurrent queue: ";
    cq.printQueue();

    cout << "\nFront element: " << cq.front() << endl;
    cout << "Queue size: " << cq.size() << endl;

    cout << "\nPopping an element..." << endl;
    cq.dequeue();

    cout << "\nQueue after popping: ";
    cq.printQueue();

    cout << "\nFront element: " << cq.front() << endl;
    cout << "Queue size: " << cq.size() << endl;

    cout << "\nPushing more elements: 40, 50" << endl;
    cq.enqueue(40);
    cq.enqueue(50);

    cout << "\nCurrent queue: ";
    cq.printQueue();

    cout << "\nEmptying the queue..." << endl;
    while (!cq.empty())
    {
        cout << "Popping: " << cq.front() << endl;
        cq.dequeue();
    }

    cout << "\nQueue after emptying: ";
    cq.printQueue();
    cout << "Queue size: " << cq.size() << endl;

    return 0;
}