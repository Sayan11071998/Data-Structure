#include <iostream>
using namespace std;

class Singleton
{
private:
    static Singleton* singletonInstance;

    Singleton() {}

public:
    static Singleton* getSingletonInstance()
    {
        if (singletonInstance == nullptr) { singletonInstance = new Singleton(); }
        return singletonInstance;
    }

    void print() { cout << "This is a Singleton Pattern"; }
};

Singleton* Singleton::singletonInstance = nullptr;

int main()
{
    Singleton* singleton = Singleton::getSingletonInstance();
    singleton->print();

    return 0;
}
