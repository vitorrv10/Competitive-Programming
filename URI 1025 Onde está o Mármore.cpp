#include <iostream>
#include <algorithm>
#define _ ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int arr[11234], caso = 1;

int BinarySearch(int x, int n)
{
    int low = 1, high = n, ret = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            ret = mid;
            high = mid - 1;
        }
        else if (x < arr[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return ret;
}

int main()
{_
    while (true)
    {
        int n, q;
        cin >> n >> q; if (!n && !q) break;
        cout << "CASE# " << caso << ":\n";
        for (int i = 1; i <= n; ++i) cin >> arr[i];
        sort (arr, arr + n + 1);
        while (q--)
        {
            int num; cin >> num;
            int index = BinarySearch(num, n);
            if (index != -1) cout << num << " found at " << index << '\n';
            else cout << num << " not found\n";
        }
        ++caso;
    }
}
