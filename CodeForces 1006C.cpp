#include <iostream>
#define _ ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

ll arr[212345];
bool check [212345];
ll ans;

int main()
{_
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    int l = 0, r = n - 1;
    ll soma1 = 0, soma2 = 0;
    while (l <= r)
    {
        if (!check[l])
        {
            soma1 += arr[l];
            check[l] = true;
        }
        if (!check[r])
        {
            soma2 += arr[r];
            check[r] = true;
        }
        if (soma1 < soma2) ++l;
        else if (soma1 > soma2) --r;
        else
        {
            ans = soma1;
            ++l;
            --r;
        }
    }
    cout << ans;
}
