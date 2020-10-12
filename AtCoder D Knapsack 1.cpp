#include <iostream>
#include <algorithm>
#define _ ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 112
#define MAXM 112345
#define ll long long

using namespace std;

ll N, W, w[MAX], v[MAX], memo[MAX][MAXM];

ll f(ll idx, ll cap){
    if (idx < 1) return 0;
    if (cap == 0) return 0;
    if (memo[idx][cap] != -1) return memo[idx][cap];
    ll ans = 0;
    if (w[idx] <= cap) {
        ans = max(f(idx - 1, cap-w[idx]) + v[idx], f(idx - 1, cap));
    } else {
        ans = f(idx - 1, cap);
    }
    return memo[idx][cap] = ans;
}

int main() {_
    cin >> N >> W;
    for (int i = 1; i <= N; ++i) {
        cin >> w[i] >> v[i];      
    }
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= W; ++j) {
            memo[i][j] = -1;
        }
    }
    cout << f(N, W);
}