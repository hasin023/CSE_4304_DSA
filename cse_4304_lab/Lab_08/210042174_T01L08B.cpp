#include <bits/stdc++.h>
using namespace std;

const int N = 20008;

int type[N];
bool vis[N];

void bfs(vector<vector<int>> &adj, int source)
{
    queue<int> q;
    q.push(source);
    vis[source] = true;
    type[source] = 1;

    int cnt1 = 1, cnt2 = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (!vis[v])
            {
                vis[v] = true;
                q.push(v);
                type[v] = (type[u] == 1) ? 2 : 1;
                (type[v] == 1) ? cnt1++ : cnt2++;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;

    for (int case_number = 1; case_number <= t; case_number++)
    {
        vector<vector<int>> adj(N);
        set<int> s;

        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            s.insert(a);
            s.insert(b);
        }

        long long ans = 0;

        for (int i : s)
        {
            if (!vis[i])
            {
                bfs(adj, i);
                ans += max(count(type + 1, type + N, 1), count(type + 1, type + N, 2));
            }
        }

        cout << "Case " << case_number << ": " << ans << "\n";
    }
}
