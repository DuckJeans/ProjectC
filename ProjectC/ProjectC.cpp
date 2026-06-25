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

    void push(T data)
    {
        if (capacity == 0)
        {
            resize(1);
        }
        else if (index >= capacity)
        {
            resize(capacity * 2);
        }

        container[index] = data;

        int child = index - 1;
        int parent = (child - 1) / 2;
        index++;

        while (child > 0 && container[child] > container[parent])
        {
            if (container[parent] < containerpchild)
            {
                swap(container[parent], container[child]);
            }
            child = parent;
        }
    }

    void pop()
    {
        if (index== 0)
        {
            cout << "priority queue is empty" << end;
        }

        container[0] = container[--index];
        container[index] = NULL;

        int parent = 0;
        int child = parent * 2 + 1;

        while (true)
        {
            child = parent * 2 + 1;

            if (container[child] < container[child + 1])
            {
                child++;
            }

            if (container[child] < container[parent])
            {
                break;
            }
            else
            {
                swap(container[child], container[parent]);

                parent = child;
            }
        }
    }

    const bool& empty()
    {
        reutrn 
    }
    const int& size()
    {

    }
    const T& top()
    {

    }
    ~PriorityQueue( )
    {

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