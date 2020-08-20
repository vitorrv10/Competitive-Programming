#include <iostream>
#include <vector>
#define _ ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 51234

using namespace std;

vector<vector <int>> adj(MAX);
vector <int> vis(MAX, -1);

int n, m, ans;

void dfs(int u)
{
    vis[u] = 1;
    for (int i = 0; i < adj[u].size(); ++i)
    {
        if (vis[adj[u][i]] == -1)
        {
            dfs(adj[u][i]);
        }
    }
}

int main()
{_
    cin >> n >> m;
    for (int i = 1; i <= m;++i)
    {
        int a, b; cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i] == -1) ++ans;
        dfs(i);
    }
    cout << ans;
}