#include <iostream>
#include <algorithm>
#define _ ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 112
#define MAXM 1123

using namespace std;

int N, W, V, w[MAX], v[MAX], memo[MAX][MAXM];

int f(int idx, int cap){
    if (idx < 1) return 0;
    if (cap == 0) return 0;
    if (memo[idx][cap] != -1) return memo[idx][cap];
    int ans = 0;
    if (w[idx] <= cap) {
        ans = max(f(idx - 1, cap-w[idx]) + v[idx], f(idx - 1, cap));
    } else {
        ans = f(idx - 1, cap);
    }
    return memo[idx][cap] = ans;
}

int main() {_
    int t; cin >> t;
    while (t--){
        cin >> N; 
        for (int i = 1; i <= N; ++i) {
            cin >> v[i] >> w[i];      
        }
        cin >> W;
        cin >> V;
        for (int i = 0; i <= N; ++i) {
            for (int j = 0; j <= W; ++j) {
                memo[i][j] = -1;
            }
        }
        int dano = f(N, W);
        if (dano >= V) cout << "Missao completada com sucesso\n";
        else cout << "Falha na missao\n";
    }
}
