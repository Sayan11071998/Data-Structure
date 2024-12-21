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

// LinkedList Class
class LinkedList
{
public:
	// Constructor
	LinkedList(int value)
	{
		Node* newNode = new Node(value);
		head = newNode;
		tail = newNode;
		length = 1;
	}

	// Destructor
	~LinkedList()
	{
		Node* temp = head;

		while (head)
		{
			head = head->next;
			delete temp;
			temp = head;
		}
	}

	// Print Function
	void printList()
	{
		Node* temp = head;

		while (temp)
		{
			cout << temp->value << endl;
			temp = temp->next;
		}
	}

	// Inserting Element at Begining
	void prepend(int value)
	{
		Node* newNode = new Node(value);

		if (length == 0)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}

		length++;
	}

	// Inserting Element at End
	void append(int value)
	{
		Node* newNode = new Node(value);

		if (length == 0)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}

		length++;
	}

	// Deleting Element at End
	void deleteLast()
	{
		if (length == 0) return;

		Node* temp = head;
		
		if (length == 1)
		{
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			Node* pre = head;

			while (temp->next)
			{
				pre = temp;
				temp = temp->next;
			}

			tail = pre;
			tail->next = nullptr;
		}

		delete temp;
		length--;
	}

	// Getters
	void getHead() { cout << "Head: " << head->value << endl; }
	void getTail() { cout << "Tail: " << tail->value << endl; }
	void getLength() { cout << "Length: " << length << endl; }

private:
	Node* head;
	Node* tail;
	int length;
};

int main()
{
	LinkedList* myLinkedList = new LinkedList(1);
	myLinkedList->append(2);
	myLinkedList->prepend(3);

	cout << "LL before deleteLast(): " << endl;
	myLinkedList->printList();
	cout << endl;

	myLinkedList->deleteLast();
	cout << "LL after first deleteLast()" << endl;
	myLinkedList->printList();
	cout << endl;

	myLinkedList->deleteLast();
	cout << "LL after second deleteLast()" << endl;
	myLinkedList->printList();
	cout << endl;

	myLinkedList->deleteLast();
	cout << "LL after third deleteLast()" << endl;
	myLinkedList->printList();
	cout << endl;

	myLinkedList->deleteLast();
	cout << "LL after fourth deleteLast()" << endl;
	myLinkedList->printList();
	cout << endl;

	return 0;
}
