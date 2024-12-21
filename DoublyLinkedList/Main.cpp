#include <iostream>
using namespace std;

// Node Class
class Node
{
public:
    int value;
    Node* next;
    Node* prev;

    Node(int value)
    {
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

// DoublyLinkedList Class
class DoublyLinkedList
{
public:
    // Constructor
    DoublyLinkedList(int value)
    {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    // Destructor
    ~DoublyLinkedList()
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
            head->prev = newNode;
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
            newNode->prev = tail;
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
        Node* before = get(index - 1);
        Node* after = before->next;

        newNode->prev = before;
        newNode->next = after;
        before->next = newNode;
        after->prev = newNode;

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
            head->prev = nullptr;
        }

        delete temp;
        length--;
    }

    // Deleting Element at End
    void deleteLast()
    {
        if (length == 0) return;

        Node* temp = tail;
        
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            tail = tail->prev;
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

        Node* temp = get(index);

        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        
        delete temp;
        length--;
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
        
        if (index < length / 2)
        {
            for (int i = 0; i < index; ++i) { temp = temp->next; }
        }
        else
        {
            temp = tail;
            for (int i = length - 1; i > index; --i) { temp = temp->prev; }
        }

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
    // Create a new DoublyLinkedList with an initial value
    DoublyLinkedList list(10);
    cout << "Initial list:" << endl;
    list.printList();

    // Append elements
    cout << "\nAppending values 20 and 30:" << endl;
    list.append(20);
    list.append(30);
    list.printList();

    // Prepend elements
    cout << "\nPrepending value 5:" << endl;
    list.prepend(5);
    list.printList();

    // Insert elements
    cout << "\nInserting value 15 at index 2:" << endl;
    list.insert(2, 15);
    list.printList();

    // Delete the first node
    cout << "\nDeleting the first node:" << endl;
    list.deleteFirst();
    list.printList();

    // Delete the last node
    cout << "\nDeleting the last node:" << endl;
    list.deleteLast();
    list.printList();

    // Delete a node at a specific index
    cout << "\nDeleting the node at index 1:" << endl;
    list.deleteNode(1);
    list.printList();

    // Get and set a node
    cout << "\nGetting the value at index 1:" << endl;
    Node* node = list.get(1);
    if (node)
        cout << "Value at index 1: " << node->value << endl;
    else
        cout << "Invalid index!" << endl;

    cout << "\nSetting the value at index 0 to 25:" << endl;
    if (list.set(0, 25))
        cout << "Value set successfully." << endl;
    else
        cout << "Failed to set value at index 0." << endl;
    list.printList();

    // Get head, tail, and length
    cout << "\nGetting head, tail, and length:" << endl;
    list.getHead();
    list.getTail();
    list.getLength();

    return 0;
}