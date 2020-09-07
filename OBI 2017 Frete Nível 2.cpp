#include <iostream>
#include <algorithm>
#define _ ios::sync_with_stdio(false); cout.tie(0); cin.tie(0);
#define MAX 11234
#define INF 9999999
#define ll long long

using namespace std;

ll adj[MAX][MAX];
ll n, m, a, b, c;

void floydWarshall()
{
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
}

int main()
{_
    cin >> n >> m;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            if (i != j) adj[i][j] = INF;
            else adj[i][j] = 0;
        }
    }
    while (m--)
    {
        cin >> a >> b >> c;
        adj[a][b] = c;
        adj[b][a] = c;
    }
    floydWarshall();
    cout << adj[1][n];
}