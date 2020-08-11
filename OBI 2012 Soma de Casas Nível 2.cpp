#include <iostream>
#define _ ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int arr[112345];

int BinarySearch(int x, int n)
{
    int low = 1, high = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) return mid;
        else if (x < arr[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int main()
{_
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    int soma; cin >> soma;
    for (int i = 1; i <= n; ++i)
    {
        int atual = BinarySearch(soma - arr[i], n);
        if (atual != -1)
        {
            cout << arr[i] << ' ' << arr[atual];
            return 0;
        }
    }
}
