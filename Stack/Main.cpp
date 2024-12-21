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

// Stack Class
class Stack
{
public:
	// Constructor
	Stack(int value)
	{
		Node* newNode = new Node(value);
		top = newNode;
		height = 1;
	}

	// Destructor
	~Stack()
	{
		Node* temp = top;

		while (top)
		{
			top = top->next;
			delete temp;
			temp = top;
		}
	}

	// Print Function
	void printStack()
	{
		Node* temp = top;

		while (temp)
		{
			cout << temp->value << endl;
			temp = temp->next;
		}
	}

	// Adding Element from TOP
	void push(int value)
	{
		Node* newNode = new Node(value);
		newNode->next = top;
		top = newNode;
		height++;
	}

	// Removing Element from TOP
	int pop()
	{
		if (height == 0) return INT_MIN;

		Node* temp = top;
		int poppedValue = top->value;
		top = top->next;
		delete temp;
		height--;

		return poppedValue;
	}

	// Checking for Empty Stack
	bool isEmpty()
	{
		if (height == 0) return true;
		return false;
	}

	// Getting TOP value
	int topValue()
	{
		if (top) return top->value;

		return INT_MIN;
	}

	// Getters
	void getTop()
	{
		if (top == nullptr)
			cout << "Top: nullptr" << endl;
		else
			cout << "Top: " << top->value << endl;
	}

	void getHeight() { cout << "Height: " << height << endl; }

private:
	Node* top;
	int height;
};

int main()
{
	// Initialize the stack with a value
	Stack stack(50);

	// Use push to add more elements
	stack.push(100);
	stack.push(150);
	stack.push(200);

	// Print the current stack
	cout << "Stack after pushing elements:" << endl;
	stack.printStack();

	// Get the top value
	cout << "Top value using topValue(): " << stack.topValue() << endl;

	// Check if the stack is empty
	cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

	// Print the top element using getTop()
	stack.getTop();

	// Print the height of the stack
	stack.getHeight();

	// Pop an element and print the stack
	cout << "Popped value: " << stack.pop() << endl;
	cout << "Stack after popping an element:" << endl;
	stack.printStack();

	// Pop all elements to empty the stack
	cout << "Popping all elements:" << endl;
	while (!stack.isEmpty())
	{
		cout << "Popped: " << stack.pop() << endl;
	}

	// Check the stack after emptying
	cout << "Is stack empty now? " << (stack.isEmpty() ? "Yes" : "No") << endl;

	// Try to pop from an empty stack
	cout << "Attempt to pop from an empty stack: " << stack.pop() << endl;

	// Check the top value of an empty stack
	cout << "Top value of an empty stack: " << stack.topValue() << endl;

	// Check the height of an empty stack
	stack.getHeight();

	return 0;
}