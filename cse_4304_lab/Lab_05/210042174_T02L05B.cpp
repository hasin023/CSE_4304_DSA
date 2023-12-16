#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int numOfCookies, targetSweetness;
    cin >> numOfCookies >> targetSweetness;

    priority_queue<int, vector<int>, greater<int>> cookies;

    for (int i = 0; i < numOfCookies; i++)
    {
        int sweetness;
        cin >> sweetness;
        cookies.push(sweetness);
    }

    // while (!cookies.empty())
    // {
    //     cout << cookies.top() << " ";
    //     cookies.pop();
    // }
    // cout << endl;

    int operation_count = 0;

    while (cookies.top() <= targetSweetness)
    {
        if (cookies.size() < 2)
        {
            cout << "-1" << endl;
            return 0;
        }

        int least_sweet = cookies.top();
        cookies.pop();
        int second_least_sweet = cookies.top();
        cookies.pop();

        int new_cookie = 1 * least_sweet + (2 * second_least_sweet);
        cookies.push(new_cookie);
        operation_count++;
    }

    cout << operation_count << endl;

    return 0;
}
