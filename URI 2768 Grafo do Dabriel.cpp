#include <iostream>
#include <algorithm>
#define _ ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 0x3f3f3f3f
#define MAX (int)1e2+5
using namespace std;

int n, m, u, v, w, q, k;
int adj [MAX][MAX][MAX];

void floydWarshall()
{
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                adj[k][i][j] = min(adj[k - 1][i][j], adj[k - 1][i][k] + adj[k - 1][k][j]);
            }
        }
    }
}

int main()
{_
    while (cin >> n >> m)
    {
        for (int i = 0; i <= n; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                if (i != j) adj[0][i][j] = INF;
                else adj[0][i][j] = 0; 
            }
        }
        while (m--)
        {
            cin >> u >> v >> w;
            adj[0][u][v] = w;
            adj[0][v][u] = w;
        }
        floydWarshall();
        cin >> q;
        while (q--)
        {
            cin >> u >> v >> k;
            if (adj[k][u][v] != INF) cout << adj[k][u][v] << '\n';
            else cout << -1 << '\n';
        }
    }
}