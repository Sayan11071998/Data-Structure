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

		while (temp != nullptr)
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

	// Inster Element at a Given Index
	bool insert(int index, int value)
	{
		if (index < 0 || index > length) return false;
		
		if (index == 0)
		{
			prepend(value);
			return true;
		}
		
		if (index == length)
		{
			append(value);
			return true;
		}
		
		Node* newNode = new Node(value);
		Node* temp = get(index - 1);
		newNode->next = temp->next;
		temp->next = newNode;
		length++;
		return true;
	}

	// Deleting Element at Begining
	void deleteFirst()
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
			head = head->next;
		}
		
		delete temp;
		length--;
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

	// Delete Element At a Given Index
	void deleteNode(int index)
	{
		if (index < 0 || index >= length) return;
		if (index == 0) return deleteFirst();
		if (index == length - 1) return deleteLast();

		Node* prev = get(index - 1);
		Node* temp = prev->next;

		prev->next = temp->next;
		delete temp;
		length--;
	}

	// Reversing Linked List
	void reverse()
	{
		Node* temp = head;
		head = tail;
		tail = temp;
		Node* after = temp->next;
		Node* before = nullptr;
		
		for (int i = 0; i < length; ++i)
		{
			after = temp->next;
			temp->next = before;
			before = temp;
			temp = after;
		}
	}

	// Getters
	void getHead()
	{
		if (head == nullptr)
			cout << "Head: nullptr" << endl;
		else
			cout << "Head: " << head->value << endl;
	}

	void getTail()
	{
		if (tail == nullptr)
			cout << "Tail: nullptr" << endl;
		else
			cout << "Tail: " << tail->value << endl;
	}

	void getLength() { cout << "Length: " << length << endl; }

	Node* get(int index)
	{
		if (index < 0 || index >= length) return nullptr;

		Node* temp = head;
		
		for (int i = 0; i < index; ++i)
			temp = temp->next;

		return temp;
	}

	bool set(int index, int value)
	{
		Node* temp = get(index);
		
		if (temp)
		{
			temp->value = value;
			return true;
		}
		
		return false;
	}

private:
	Node* head;
	Node* tail;
	int length;
};

int main()
{

	// Create a LinkedList with an initial value
	LinkedList list(10);
	cout << "The Linked List is: " << endl;
	list.printList();

	// Test append method
	cout << "\nAppending values 20 and 30:" << endl;
	list.append(20);
	list.append(30);
	list.printList();

	// Test prepend method
	cout << "\nPrepending value 5:" << endl;
	list.prepend(5);
	list.printList();

	// Test insert method
	cout << "\nInserting value 15 at index 2:" << endl;
	list.insert(2, 15);
	list.printList();

	// Test deleteFirst method
	cout << "\nDeleting the first node:" << endl;
	list.deleteFirst();
	list.printList();

	// Test deleteLast method
	cout << "\nDeleting the last node:" << endl;
	list.deleteLast();
	list.printList();

	// Test deleteNode method
	cout << "\nDeleting the node at index 1:" << endl;
	list.deleteNode(1);
	list.printList();

	// Test reverse method
	cout << "\nReversing the LinkedList:" << endl;
	list.reverse();
	list.printList();

	// Test get method
	cout << "\nGetting the value at index 1:" << endl;
	Node* node = list.get(1);
	if (node)
		cout << "Value at index 1: " << node->value << endl;
	else
		cout << "Invalid index!" << endl;

	// Test set method
	cout << "\nSetting the value at index 1 to 25:" << endl;
	if (list.set(1, 25))
		cout << "Value set successfully." << endl;
	else
		cout << "Failed to set value at index 1." << endl;
	list.printList();

	// Test getters for head, tail, and length
	cout << "\nGetting head, tail, and length:" << endl;
	list.getHead();
	list.getTail();
	list.getLength();

	return 0;
}
