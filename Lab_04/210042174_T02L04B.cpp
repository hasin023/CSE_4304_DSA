#include <iostream>
#include <queue>

using namespace std;

class Deque
{
private:
    queue<int> frontQueue;
    queue<int> rearQueue;

public:
    // Insert an item at the front of the deque
    void pushFront(int item)
    {
        frontQueue.push(item);
    }

    // Insert an item at the rear of the deque
    void pushRear(int item)
    {
        rearQueue.push(item);
    }

    // Remove and return an item from the front of the deque
    int popFront()
    {
        if (isEmpty())
            throw runtime_error("Deque is empty");

        if (frontQueue.empty())
        {
            // Move items from rearQueue to frontQueue in reverse order
            while (!rearQueue.empty())
            {
                frontQueue.push(rearQueue.front());
                rearQueue.pop();
            }
        }

        int frontItem = frontQueue.front();
        frontQueue.pop();
        return frontItem;
    }

    // Remove and return an item from the rear of the deque
    int popRear()
    {
        if (isEmpty())
            throw runtime_error("Deque is empty");

        if (rearQueue.empty())
        {
            // Move items from frontQueue to rearQueue in reverse order
            while (!frontQueue.empty())
            {
                rearQueue.push(frontQueue.front());
                frontQueue.pop();
            }
        }

        int rearItem = rearQueue.front();
        rearQueue.pop();
        return rearItem;
    }

    // Check if the deque is empty
    bool isEmpty()
    {
        return frontQueue.empty() && rearQueue.empty();
    }
};

int main()
{
    Deque dq;

    dq.pushRear(1);
    dq.pushRear(2);
    dq.pushFront(3);

    cout << dq.popRear() << endl;
    cout << dq.popFront() << endl;

    return 0;
}
