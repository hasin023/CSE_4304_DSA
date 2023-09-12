#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

// Print the Stack
void print_s()
{
    queue<int> q1 = q;
    while (!q1.empty())
    {
        cout << q1.front() << " ";
        q1.pop();
    }
    cout << endl;
}

// Push into the Stack
void push_s(int x)
{
    q.push(x);
    int size = q.size();
    while (size > 1)
    {
        q.push(q.front());
        q.pop();
        size--;
    }
}

// Removes the element on top of the stack.
void pop_s()
{
    q.pop();
}

// // Get the top element.
int top_s()
{
    return q.front();
}

// // Return whether the stack is empty.
bool empty_s()
{
    return q.empty();
}

int main()
{
    push_s(10);
    cout << top_s() << endl;
    push_s(20);
    cout << top_s() << endl;
    pop_s();
    cout << top_s() << endl;
    push_s(100);
    cout << top_s() << endl;
    cout << empty_s() << endl;
    pop_s();
    pop_s();
    cout << empty_s() << endl;

    // print_s();
}

// Expected Output 10 20 10 100