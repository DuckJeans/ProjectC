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

    const int& operator[ ]();

    ~Vector()
    {

    };
};

int main()
{
    Vector<int> vector;

    return 0;
}