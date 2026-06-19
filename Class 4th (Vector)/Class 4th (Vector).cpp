#include <iostream>

using namespace std;

template <typename T>

class Vector
{
private:
    T* pointer;
    int m_size;
    int capacity;
public:
    Vector()
    {
        m_size = 0;
        capacity = 0;
        pointer = nullptr;
    };

    const int& size()
    {
        return m_size;
    }

    const T& operator[ ](const int& index)
    {
        return pointer[index];
    }

    ~Vector()
    {
        delete[] pointer;
    };

    void resize(int newSize)
    {
        // capacity에 새로운 size값을 저장.
        capacity = newSize;

        // 새로운 포인터 변수를 생성해서 새롭게 만들어진 메모리 공간을 가리키도록.
        T* temporary = new T[capacity];

        // 새로운 메모리 공간의 값을 초기화
        for (int i = 0; i < capacity; i++)
        {
            temporary[i] = NULL;
        }


        // 기존 배열에 있는 값을 복사해서 새로운 배열에 넣음.
        for (int i = 0; i < m_size; i++)
        {
            temporary[i] = pointer[i];
        }

        // 기존 배열의 메모리를 해제
        delete[] pointer;

        // 기존 배열을 가리키던 포인터 변수의 값을 새로운 배열의 시작 주소로 가르킴.
        pointer = temporary;
    }

    void push_back(T data)
    {
        if (capacity <= 0)
        {
            resize(1);
        }
        else if (m_size >= capacity)
        {
            resize(capacity * 2);
        }

        pointer[m_size++] = data;
    }

    void pop_back()
    {
        if (m_size <= 0)
        {
            cout << "Vector is empty" << endl;
        }
        else
        {
            pointer[--m_size] = NULL;
        }
    }
};

int main()
{
    Vector<int> vector;

    vector.push_back(10);
    vector.push_back(20);
    vector.push_back(30);
    vector.push_back(40);

    vector.pop_back();
    vector.pop_back();
    vector.pop_back();
    vector.pop_back();
    vector.pop_back();

    return 0;
}