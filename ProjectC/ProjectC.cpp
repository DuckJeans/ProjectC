#include <iostream>

using namespace std;

template <typename KEY, typename VALUE>

class HashTable
{
private:
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

    int size;
    int capacity;
    Bucket* bucket;

public:
    

    HashTable()
    {
        size = 0;
        capacity = 0;
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

    template<>
    unsigned int hash_function(const char* key)
    {
        unsigned int sum = 0;

        for (int i = 0; *key != '\0'; i++)
        {
            sum += key[i];

            key = key + 1;
        }

        return sum % capacity;
    }

    void insert(KEY key, VALUE value)
    {
        int hashIndex;

        hashIndex = hash_function(key);

        Node* newNode = new Node;
        newNode->key = key;
        newNode->value = value;
        newNode->next = nullptr;

        if (bucket[hashIndex].head == nullptr)
        {
            bucket[hashIndex].head = newNode;
        }
        else
        {
            newNode->next = bucket[hashIndex].head;

            bucket[hashIndex].head = newNode;
        }

        bucket[hashIndex].count++;
        size++;
    }

    ~HashTable()
    {
        for (int i = 0; i < capacity; i++)
        {
            Node* current = bucket[i].head;

            while (current != nullptr)
            {
                Node* deleteNode = current;
                current = current->next;
                delete deleteNode;
            }
        }

        if (bucket != nullptr)
        {
            delete[] bucket;
        }
    }
};

int main()
{
    HashTable<const char*,int> hT;

    hT.insert("Knight", 3000);
    hT.insert("Mega Knight", 8000);
    hT.insert("Dark Knight", 25000);

    return 0;
}