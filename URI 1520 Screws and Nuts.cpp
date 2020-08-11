#include <iostream>
#include <vector>
#include <algorithm>
#define _ ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int BinarySearch (vector <int> arr,int x, int n, bool version)
{
    int low = 0, high = n - 1, ret = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            if (version) high = mid - 1;
            else low = mid + 1;
            ret = mid;
        }
        else if (x < arr[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return ret;
}

int main()
{_
    int n;
    while (cin >> n)
    {
        vector <int> arr;
        while (n--)
        {
            int x, y; cin >> x >> y;
            for (int i = x; i <= y; ++i) arr.push_back(i);
        }
        sort (arr.begin(), arr.end());
        int num; cin >> num;
        int indexX = BinarySearch(arr,num, arr.size(), true), indexY = BinarySearch(arr,num, arr.size(), false);
        if (indexX != -1 && indexY != -1) cout << num << " found from " << indexX << " to " << indexY << '\n';
        else cout << num << " not found\n";
    }
}
