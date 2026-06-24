#include <iostream>

#define SIZE 3

using namespace std;

template <typename T>

class PriorityQueue
{
private:
    int capacity;
    int index;

    T* container;

public:
    PriorityQueue()
    {
        capacity = 0;
        index = 0;

        container = nullptr;
    }

    void resize(int newSize)
    {
        capacity = newSize;

        T* temporary = new T[capacity];

        for (int i = 0; i < capacity; i++)
        {
            temporary[i] = NULL;
        }

        for (int i = 0; i < index; i++)
        {
            temporary[i] = container[i];
        }

        delete[] container;

        container = temporary;
    }
};

int main()
{
    PriorityQueue<int> pQ;

    pQ.resize(1);
    pQ.resize(2);
    pQ.resize(4);

    return 0;
}