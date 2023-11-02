#include <iostream>
#include <vector>

using namespace std;

vector<int> parentNode;

int find(int node)
{
    if (parentNode[node] == -1)
        return node;
    return parentNode[node] = find(parentNode[node]);
}

void dsu_setNode(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
        parentNode[a] = b;
}

int main()
{
    int n, m;
    cin >> n >> m;

    parentNode.resize(n, -1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        dsu_setNode(u - 1, v - 1);
    }

    int q;
    cin >> q;

    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (find(x - 1) == find(y - 1))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
