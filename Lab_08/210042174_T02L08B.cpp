#include <iostream>
#include <vector>

using namespace std;

const int N = 100005;

vector<vector<int>> tree(N);
vector<int> cats(N);
int m;
int validRestaurants = 0;

void dfs(int node, int parent, int consecutiveCats)
{
    if (cats[node] == 1)
    {
        consecutiveCats++;
    }
    else
    {
        consecutiveCats = 0;
    }

    if (consecutiveCats > m)
    {
        return;
    }

    if (tree[node].size() == 1 && node != 1)
    {
        validRestaurants++;
        return;
    }

    for (int neighbor : tree[node])
    {
        if (neighbor != parent)
        {
            dfs(neighbor, node, consecutiveCats);
        }
    }
}

int main()
{
    int n;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> cats[i];
    }

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1, 0, cats[1]);

    cout << validRestaurants << endl;

    return 0;
}
