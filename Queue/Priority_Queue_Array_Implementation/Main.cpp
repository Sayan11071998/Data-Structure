#include <iostream>
using namespace std;

class PriorityQueue
{
public:
    PriorityQueue(int capacity)
    {
        this->capacity = capacity;
        elements = new int[capacity];
        priorities = new int[capacity];
        size = 0;
    }

    ~PriorityQueue()
    {
        delete[] elements;
        delete[] priorities;
    }

    void enqueue(int element, int priority)
    {
        if (size == capacity)
        {
            cout << "Queue is Full!" << endl;
            return;
        }

        elements[size] = element;
        priorities[size] = priority;
        size++;

        for (int i = size - 1; i > 0; i--)
        {
            if (priorities[i] > priorities[i - 1])
            {
                swap(elements[i], elements[i - 1]);
                swap(priorities[i], priorities[i - 1]);
            }
            else
            {
                break;
            }
        }
    }

    int dequeue()
    {
        if (size == 0)
        {
            cout << "Queue is Empty!" << endl;
            return -1;
        }

        int dequeuedValue = elements[0];

        for (int i = 0; i < size - 1; i++)
        {
            elements[i] = elements[i + 1];
            priorities[i] = priorities[i + 1];
        }

        size--;
        return dequeuedValue;
    }

    int front()
    {
        if (size == 0)
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        return elements[0];
    }

    bool isEmpty() { return size == 0; }

    void printQueue()
    {
        if (size == 0)
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue Elements (Element: Priority):" << endl;
        for (int i = 0; i < size; i++)
            cout << elements[i] << ": " << priorities[i] << endl;
    }

private:
    int* elements;
    int* priorities;
    int size;
    int capacity;
};

int main()
{
    PriorityQueue pq(5);

    pq.enqueue(10, 2);
    pq.enqueue(20, 1);
    pq.enqueue(30, 3);
    pq.enqueue(40, 5);

    cout << "Queue after enqueue operations:" << endl;
    pq.printQueue();
    cout << endl;

    cout << "Front element: " << pq.front() << endl;
    cout << "Dequeued element: " << pq.dequeue() << endl;

    cout << "Queue after dequeue operation:" << endl;
    pq.printQueue();
    cout << endl;

    pq.enqueue(50, 4);

    cout << "Queue after enqueue operation:" << endl;
    pq.printQueue();
    cout << endl;

    return 0;
}
