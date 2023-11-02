#include <iostream>
#include <vector>

using namespace std;

const int MAX_SIZE = 105;
const char OBSTACLE = '*';
const char START_SYMBOL = '@';

vector<vector<char>> grid(MAX_SIZE, vector<char>(MAX_SIZE));
vector<vector<bool>> visited(MAX_SIZE, vector<bool>(MAX_SIZE, false));

int dx[] = {1, 0, -1, 0, -1, 1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int m, n;

bool in_reach(int x, int y)
{
    return (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == START_SYMBOL && !visited[x][y]);
}

void dfs(int x, int y)
{
    visited[x][y] = true;

    for (int i = 0; i < 8; i++)
    {
        int mx = x + dx[i];
        int ny = y + dy[i];
        if (in_reach(mx, ny))
        {
            dfs(mx, ny);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> m >> n && m != 0 && n != 0)
    {
        grid.assign(MAX_SIZE, vector<char>(MAX_SIZE, 0));
        visited.assign(MAX_SIZE, vector<bool>(MAX_SIZE, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == START_SYMBOL && !visited[i][j])
                {
                    dfs(i, j);
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
