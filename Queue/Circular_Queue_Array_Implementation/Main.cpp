#include <iostream>
using namespace std;

// Circular Queue Class using Array
class CircularQueue
{
public:
	// Constructor
	CircularQueue(int queueSize)
	{
		this->queueSize = queueSize;
		queue = new int[queueSize];
		front = -1;
		rear = -1;
		currentSize = 0;
	}

	// Destructor
	~CircularQueue() { delete[] queue; }

	// Push (Enqueue)
	void enqueue(int value)
	{
		if (isFull())
		{
			cout << "Queue is Full!" << endl;
			return;
		}

		if (isEmpty())
			front = rear = 0;
		else
			rear = (rear + 1) % queueSize;

		queue[rear] = value;
		currentSize++;
	}

	// Pop (Dequeue)
	int dequeue()
	{
		if (isEmpty())
		{
			cout << "Queue is Empty!" << endl;
			return -1;
		}

		int poppedValue = queue[front];

		if (front == rear)
			front = rear = -1;
		else
			front = (front + 1) % queueSize;

		currentSize--;
		return poppedValue;
	}

	// Front element
	int frontValue()
	{
		if (isEmpty())
		{
			cout << "Queue is empty!" << endl;
			return -1;
		}

		return queue[front];
	}

	// Size
	int size() { return currentSize; }

	// Empty
	bool empty() { return currentSize == 0; }

private:
	int* queue;
	int front;
	int rear;
	int currentSize;
	int queueSize;

	bool isFull() { return currentSize == queueSize; }

	bool isEmpty() { return currentSize == 0; }
};

int main()
{
	// Initialize a circular queue with capacity 5
	CircularQueue myQueue(5);

	// Push elements
	cout << "Pushing values 10, 20, 30, 40, 50..." << endl;
	myQueue.enqueue(20);
	myQueue.enqueue(30);
	myQueue.enqueue(40);
	myQueue.enqueue(50);

	// Attempt to push into a full queue
	cout << "Attempting to push 60 into a full queue..." << endl;
	myQueue.enqueue(60);

	// Print front and size
	cout << "Front element: " << myQueue.frontValue() << endl;
	cout << "Queue size: " << myQueue.size() << endl;

	// Pop an element
	cout << "Popping an element..." << endl;
	cout << "Popped: " << myQueue.dequeue() << endl;

	// Print front and size after popping
	cout << "Front element after pop: " << myQueue.frontValue() << endl;
	cout << "Queue size after pop: " << myQueue.size() << endl;

	// Push another element
	cout << "Pushing value 60..." << endl;
	myQueue.enqueue(60);

	// Print front and size after pushing
	cout << "Front element: " << myQueue.frontValue() << endl;
	cout << "Queue size: " << myQueue.size() << endl;

	// Pop all elements to empty the queue
	cout << "Popping all elements..." << endl;
	while (!myQueue.empty()) {
		cout << "Popped: " << myQueue.dequeue() << endl;
	}

	// Final check if the queue is empty
	cout << "Final check if the queue is empty: " << (myQueue.empty() ? "Yes" : "No") << endl;

	return 0;
}