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

    ~List();

    void push_front(T data)
    {
        Node* newNode = new Node;

        newNode->data = data;
        newNode->previous = nullptr;
        newNode->next = head;

        if (head == nullptr)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head->previous = newNode;
            newNode->next = head;
            head = newNode;
        }
        
        size++;
    }

    void pop_front()
    {
        if (head == nullptr)
        {
            printf("Linked list is empty");
            return;
        }

        Node* deleteNode = head;

        if (head == tail)
        {
            head = nullptr; 
            tail = nullptr;
        }
        else
        {
            deleteNode->next->previous = nullptr;
            head = head->next;
        }

        delete deleteNode;
        size--;
    }

    void push_back(T data)
    {
        Node* newNode = new Node;

        newNode->data = data;
        newNode->next = nullptr;
        newNode->previous = nullptr;

        if (head == nullptr)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
        size++;
    }

    void pop_back()
    {
        if (tail == nullptr)
        {
            printf("Linked list is empty");
            return;
        }

        Node* deleteNode = tail;

        if (head == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            deleteNode->previous->next = nullptr;
            tail = tail->next;
        }

        delete deleteNode;
        size--;
    }
};

int main()
{
    List<int> list;

    list.push_front(5);
    list.push_front(1);

    list.push_back(20);
    list.push_back(30);

    list.pop_front();
    list.pop_front();
    list.pop_front();

    return 0;
}