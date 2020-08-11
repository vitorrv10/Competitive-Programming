#include <iostream>
#define _ ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long

using namespace std;

ll arr[112345];

ll BinarySearch(int x, int n)
{
    int low = 1, high = n, ret = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x)
        {
            ret = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ret;
}

int main()
{_
    int n; cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int num; cin >> num;
        arr[i] = arr[i - 1] + num;
    }
    int m; cin >> m;
    while (m--)
    {
        int q; cin >> q;
        cout << BinarySearch(q, n) << '\n';
    }
}
