#include <iostream>

using namespace std;

template <typename T>

class Tree
{
private:
    struct Node 
    {
        T data;
        Node* left;
        Node* right;

        Node(T data)
        {
            this->data = data;

            left = nullptr;
            right = nullptr;
        }
    };

    Node* root;
public:
    Tree()
    {
        root = nullptr;
    }

    void insert(T data)
    {
        if (root == nullptr)
        {
            root = new Node(data);
        }
        else
        {
            Node* currentNode = root;

            while (currentNode != nullptr)
            {                
                if (data < currentNode->data)
                {
                    if (currentNode->left == nullptr)
                    {
                        currentNode->left = new Node(data);

                        break;
                    }
                    else
                    {
                        currentNode = currentNode->left;
                    }
                }
                else if (data > currentNode->data)
                {
                    if (currentNode->right == nullptr)
                    {
                        currentNode->right = new Node(data);

                        break;
                    }
                    else
                    {
                        currentNode = currentNode->right;
                    }
                }
                else
                {
                    breakl
                }
            }
        }
    }

};

int main()
{


    return 0;
}