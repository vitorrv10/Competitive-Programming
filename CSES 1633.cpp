#include <iostream>
#define _ ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 1123456
#define ll long long
#define MOD 1000000007

using namespace std;

ll N;
ll memo[MAX];

ll f(ll n){
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (memo[n] != -1) return memo[n];
    ll ans = 0;
    for (int i = 1; i <= 6; ++i){
        ans += f(n - i) % MOD;
    }
    return memo[n] = ans % MOD;
}

int main(){_
    cin >> N;
    for (int i = 0; i <= N; ++i){
        memo[i] = -1;
    }
    cout << f(N);
}