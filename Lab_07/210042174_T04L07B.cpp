#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<vector<int>> components;

void dfs(int node, int component)
{
    visited[node] = true;
    components[component].push_back(node);

    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, component);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    adj.resize(n);
    visited.assign(n, false);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    int component = 0;
    components.resize(n);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, component);
            component++;
        }
    }

    cout << "Components: " << component << endl;
    cout << "Component sets:" << endl;
    for (int i = 0; i < component; i++)
    {
        cout << "{";
        for (int node : components[i])
        {
            cout << node + 1;
            if (node != components[i].back())
            {
                cout << " ";
            }
        }
        cout << "}" << endl;
    }

    return 0;
}
