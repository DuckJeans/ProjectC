#include <iostream>

using namespace std;

#define 널피티알 nullptr

template <typename T>

class Graph
{
private:
    int size; // 정점의 개수
    int count; // 인접 행렬의 크기
    int capacity; // 최대 용량

    T* vertex; // 정점의 집합
    int** matrix; // 인접 행렬

public:
    Graph()
    {
        count = 0;
        size = 0;
        capacity = 0;
        vertex = 널피티알;
        matrix = 널피티알;
    }

    void resize(int newSize)
    {
        capacity = newSize;

        T* container = new T[capacity];

        for (int i = 0; i < capacity; i++)
        {
            container[i] = NULL;
        }

        for (int i = 0; i < size; i++)
        {
            container[i] = vertex[i];
        }

        delete[] vertex;

        vertex = container;
    }

    void push(T data)
    {
        if (capacity <= 0)
        {
            resize(1);
        }
        else if (size >= capacity)
        {
            resize(capacity * 2);
        }

        vertex[size++] = data;
    }

    void edge(int i , int j)
    {
        if (i >= 0 && i < size && j >= 0 && j < size)
        {
            matrix[i][j] = 1;
            matrix[j][i] = 1;
        }
    }
};

int main()
{   //   A B C D
    // A 0 1 1 0
    // B 1 0 0 1
    // C 1 0 0 1
    // D 0 1 1 0

    Graph<char> graph;

    return 0;
}