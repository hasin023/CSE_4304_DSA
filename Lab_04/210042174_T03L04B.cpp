#include <iostream>
#include <queue>

using namespace std;

int ping(int t)
{
    static queue<int> requests;

    while (!requests.empty() && requests.front() < t - 3000)
    {
        requests.pop();
    }

    requests.push(t);

    return requests.size();
}

int main()
{
    cout << ping(1) << "\n";
    cout << ping(2) << "\n";
    cout << ping(3) << "\n";
    cout << ping(4) << "\n";
    cout << ping(3001) << "\n";
    cout << ping(3002) << "\n";
    cout << ping(3003) << "\n";
    cout << ping(6003) << "\n";
    cout << ping(10003) << "\n";

    return 0;
}

// Expected output: 1 2 3 4 5 5 5 2 1