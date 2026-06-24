#include <iostream>

#define SIZE 4

using namespace std;

template <typename T>

class Queue
{
private:
    int m_rear;
    int m_front;

    T container[SIZE];
public:
    Queue()
    {
        m_rear = SIZE - 1;
        m_front = SIZE - 1;

        for (int i = 0; i < SIZE; i++)
        {
            container[i] = NULL;
        }
    }

    void push(T data)
    {
        // 리어값이 증가되면서 0번째 인덱스로 이동
        // 0인덱스에 10값을 넣음
        // 또 push하면 1인덱스를 리어가 가르키고
        // 20이라는 값을 넣음
        // 리어가 2번 인덱스에 30을 넣고 더 이상 값을 넣을 수 없음
        // "circle queue overflow"라고 출력
        // 만약 pop으로 프론트가 0인덱스에 있다면, 3인덱스에 값을 넣을 수 있음
        // 리어는 3을 가르키게됨.
        // 리어가 3을 가르킬때는 40을 넣을 수 있게.

        if (m_front == (m_rear + 1) % SIZE)
        {
            cout << "circle queue overflow" << endl;
            return;
        }

        m_rear = (m_rear + 1) % SIZE;
        container[m_rear] = data;
    }

    void pop()
    {
        if (m_front == m_rear)
        {
            cout << "circle queue is empty" << endl;
            return;
        }

        m_front = (m_front + 1) % SIZE;
        container[m_front] = 0;
    }

    const bool& empty()
    {
        return m_rear == m_front;
    }

    const T& front()
    {
        return container[(m_front + 1) % SIZE];
    }
};

int main()
{
    Queue<int> queue;

    queue.push(10);
    queue.push(20);
    queue.push(30);

    queue.pop();
    queue.pop();
    queue.pop();

    while (queue.empty() == false)
    {
        cout << queue.front() << endl;

        queue.pop();
    }

    queue.push(10);
    queue.push(20);
    queue.push(30);

    return 0;
}