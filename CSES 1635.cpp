#include <iostream>
#define _ ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 1123456
#define MOD 1000000007

using namespace std;

int N, n, x, arr[MAX], memo[MAX];

int f(int n){
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (memo[n] != -1) return memo[n];
    int ans = 0;
    for (int i=1; i<=N; ++i){
        ans = (ans+f(n-arr[i]))%MOD;
    }
    return memo[n] = (ans % MOD);
}
int main(){_
    cin >> N >> x;
    for (int i=0; i<=x; ++i){
        memo[i] = -1;
    }
    for (int i=1; i<=N; ++i){
        cin >> arr[i];
    }
    cout << f(x) << endl;
    return 0;
}