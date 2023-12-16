#include <iostream>
using namespace std;

class LinkedList
{
private:
    struct LinkedNode
    {
        int val;
        LinkedNode *next;
        LinkedNode() : val(0), next(nullptr) {}
        LinkedNode(int x) : val(x), next(nullptr) {}
    };

    LinkedNode *HEAD;

public:
    LinkedList()
    {
        HEAD = nullptr;
    }

    // void Insert_front()
    // {
    // }

    // void Insert_back()
    // {
    // }

    // void Insert_after_node(int key, int v)
    // {
    // }

    // void Update_node(int key, int v)
    // {
    // }

    // void Remove_head()
    // {
    // }

    // void Remove_element(int key)
    // {
    // }

    // void Remove_end()
    // {
    // }

    void print()
    {
        // print the full list;
        if (HEAD == nullptr)
        {
            cout << "Empty List" << endl;
            return;
        }
    }
};

int main()
{
    LinkedList mLinkedList;

    return 0;
}