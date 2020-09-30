#include <iostream>
#include <algorithm>
#include <string>
#define _ ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define INF 11234567
#define MAX 1123456

using namespace std;

int N;
int memo[MAX];

int f(int n){
    if (n == 0) return 0;
    if (memo[n] != -1) return memo[n];
    string s = to_string(n);
    int ans = INF;
    for (int i = 0; i < s.size(); ++i){
        int letra = (int)s[i] - '0';
        if (s[i] != '0')
        ans = min(ans, 1 + f(n - letra));
    }
    return memo[n] = ans;
}

int main(){_
    cin >> N;
    for (int i = 0; i <= N; ++i){
        memo[i] = -1;
    }
    cout << f(N);
}