#include <iostream>
#define _ ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll unsigned long long

using namespace std;

ll t, n, maximo = 10000000000;

ll BinarySearch(ll low, ll high)
{
    ll ret = 1;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        ll atual = (mid * (mid + 1)) / 2;
        if (atual <= n)
        {
            ret = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return ret;
}

int main()
{_
    cin >> t;
    while (t--)
    {
        cin >> n;
        ll ans = BinarySearch(1, maximo);
        cout << ans << '\n';
    }
    return 0;
}
