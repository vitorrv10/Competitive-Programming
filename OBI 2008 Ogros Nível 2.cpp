#include <iostream>
#define _ ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX 112345

using namespace std;

int arr[MAX];
int f[MAX];

int BinarySearch(int x, int n)
{
    int low = 0, high = n - 1, ret = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (x >= arr[mid])
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
    int n, m; cin >> n >> m;
    for (int i = 1; i < n; ++i) cin >> arr[i];
    for (int i = 0; i < n; ++i) cin >> f[i];
    while (m--)
    {
        int num; cin >> num;
        cout << f[BinarySearch(num, n)] << ' ';
    }
}
