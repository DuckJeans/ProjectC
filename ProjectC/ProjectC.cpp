#include <iostream>

using namespace std;

template <typename T>

class List
{
private:
    struct Node
    {
        T data;
        Node* previous;
        Node* next;
    };

    int size;
    Node* head;
    Node* tail;

public:
    List()
    {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    void push_front(T data)
    {
        Node* newNode = new Node;

        newNode->data = data;
        newNode->previous = nullptr;
        newNode->head = head;

        if (head == nullptr)
        {
            head == nullptr;
            tail == nullptr;
        }
        else
        {
            head->previous = newNode;
            head = newNode;
        }
        
        size++;
    }
};

int main()
{
    List<int> list;

    list.push_front(5);
    list.push_front(1);

    return 0;
}