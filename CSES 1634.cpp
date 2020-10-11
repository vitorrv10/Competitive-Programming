#include <iostream>
#include <algorithm>
#define _ ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 1123456
#define INF 11234567

using namespace std;

int n, x, arr[MAX], memo[MAX];

int f(int x){
    if (x < 0) return INF;
    if (x == 0) return 0;
    if (memo[x] != -1) return memo[x];
    int ans = INF;
    for (int i = 0; i < n; ++i){
        ans = min(ans, 1 + f(x - arr[i]));
    }
    return memo[x] = ans;
}

int main(){_
    cin >> n >> x;
    for (int i = 0; i <= x; ++i){
        memo[i] = -1;
    }
    for (int i = 0; i < n; ++i) cin >> arr[i];
    if (f(x) != INF){
        cout << f(x);
    }
    else cout << -1;
}