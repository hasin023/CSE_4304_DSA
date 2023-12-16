#include <iostream>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    int arr[n];
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    int op, x, y, idx;
    for (int i = 1; i <= q; i++)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> x >> y;
            for (int j = 1; j <= n; j++)
            {
                if (arr[j] == x)
                    arr[j] = y;
            }
        }
        else
        {
            cin >> idx;
            cout << arr[idx] << endl;
        }
    }
    return 0;
}