#include <iostream>

#define SIZE 5

using namespace std;

template <typename T>

class Queue
{
private:
    int m_front;
    int m_rear;

    T container[SIZE];
public:
    Queue()
    {
        m_front = 0;
        m_rear = 0;

        for (int i = 0; i < SIZE; i++)
        {
            container[i] = NULL;
        }
    }

    void push(T data)
    {
        if (m_rear >= SIZE)
        {
            cout << "linear queue overflow" << endl;
            return;
        }

        container[m_rear++] = data;
    }

    void pop()
    {
        if (m_front >= m_rear)
        {
            cout << "linear queue is empty" << endl;
            return;
        }

        container[m_front++] = 0;

        // 프론트가 증가
        // 10의 데이터를 지운다. -> 0으로
        // 프론트의 값을 증가시켰기에 한칸 이동
        // 만약 리어를 30까지만 만들었다고 했을때,
        // 20삭제(0으로 한후 프론트 증가), 30에 프론트
        // pop을 했을 때 30에 있던 프론트가 30과 40사이에 있음.
        // 40에는 리어가 있지만, 프론트가 pop을 한 번 더 실행할 시 
        // "linear queue is empty"라고 출력.
        // 리어가 있는 값(40)전 30에 있던 프론트가 pop을 한 번 더 실행하면
        // 출력하게 됨.
    }

    const bool& empty()
    {
        return m_front >= m_rear;
    }

    const T& front()
    {
        return container[m_front];
    }

    const int& size()
    {
        return m_rear - m_front;
    }
};

int main()
{
    Queue<int> queue;

    queue.push(10);
    queue.push(20);
    queue.push(30);
    queue.push(40);
    queue.push(50);

    while (queue.empty() == false)
    {
        cout << queue.front() << endl;

        queue.pop();
    }

    queue.push(1);

    return 0;
}