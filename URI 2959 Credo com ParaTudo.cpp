#include <iostream>
#include <algorithm>
#define _ ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 1234
#define INF 1123456

using namespace std;

int n, m, p;
int adj[MAX][MAX];

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
    cin >> n >> m >> p;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            if (i != j) adj[i][j] = INF;
            else adj[i][j] = 1;
        }
    }
    while (m--)
    {
        int a, b; cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    floydWarshall();
    while (p--)
    {
        int k, l; cin >> k >> l;
        if (adj[k][l] == INF) cout << "Deu ruim\n";
        else cout << "Lets que lets\n";
    }
}
