#include <iostream>

using namespace std;

template <typename KEY, typename VALUE>

class HashTable
{
public:
    struct Node
    {
        Node* next;
        KEY key;
        VALUE value;
    };

    struct Bucket
    {
        Node* head;
        int count;
    };

    HashTable()
    {
        size = 0;
        capacity = 7;
        bucket = new Bucket[capacity];

        for (int i = 0; i < capacity; i++)
        {
            bucket[i].head = nullptr;
            bucket[i].count = 0;
        }
    }

    template <typename KEY>
    unsigned int hash_function(KEY key)
    {
        return (unsigned int)key % capacity;
    }

    template<typename KEY>
    unsigned int hash_function(const char* key)
    {
        return hash
    }

private:
    int size;
    int capacity;
    Bucket* bucket;
};

int main()
{
    HashTable<float,int> hT;

    cout << hT.hash_function(3129) << endl;
    cout << hT.hash_function(-362) << endl;

    return 0;
}