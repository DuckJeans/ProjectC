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
            Node* deleteNode = bucket[i].head;

            if (bucket[i].head == nullptr)
            {
                continue;
            }
            else
            {
                while (current != nullptr)
                {
                    current = deleteNode->next;

                    delete deleteNode;

                    deleteNode = current;
                }
            }
        }

        delete[] bucket;
    }

    void erase(KEY key)
    {
        int hashIndex = hash_function(key);
        Node* currentNode = bucket[hashIndex].head;
        Node* previousNode = nullptr;

        if (currentNode == nullptr)
        {
            cout << "not key found..." << endl;
        }
        else
        {
            while (currentNode != nullptr)
            {
                if (currentNode->key == key)
                {
                    if (currentNode == bucket[hashIndex].head)
                    {
                        bucket[hashIndex].head = currentNode->next;
                    }
                    else
                    {
                        previousNode->next = currentNode->next;
                    }

                    size--;

                    bucket[hashIndex].count--;

                    delete currentNode;

                    return;
                }
                else
                {
                    previousNode = currentNode;

                    currentNode = currentNode->next;
                }
            }
        }
        cout << "not key found..." << endl;
    }

    const int& bucket_count()
    {
        return capacity;
    }

    const float& load_factor()
    {
        return (float)size / capacity;
    }
};

int main()
{
    HashTable<const char*, int> hT;

    hT.insert("Knight", 3000);
    hT.insert("Mega Knight", 8000);
    hT.insert("Dark Knight", 25000);

    hT.erase("Knight");
    hT.erase("King Knight");

    cout << "Load Factor : " << hT.load_factor() << endl;
    cout << "Bucket Count : " << hT.bucket_count() << endl;

    return 0;
}