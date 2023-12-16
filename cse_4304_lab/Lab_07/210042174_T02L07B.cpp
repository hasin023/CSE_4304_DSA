#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjacency_matrix(n, vector<int>(n, 0));

    vector<vector<int>> adjacency_list(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adjacency_matrix[u - 1][v - 1] = 1;
        adjacency_matrix[v - 1][u - 1] = 1;

        adjacency_list[u - 1].push_back(v);
        adjacency_list[v - 1].push_back(u);
    }

    cout << "List view:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " -> ";
        for (int neighbor : adjacency_list[i])
        {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    cout << "Matrix view:" << endl;
    cout << "  ";
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " ";
        for (int j = 0; j < n; j++)
        {
            cout << (adjacency_matrix[i][j] ? "x " : "  ");
        }
        cout << endl;
    }

    return 0;
}
