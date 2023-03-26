#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

long long n, x, ans = -99999999, l, r;
int main()
{
    //   freopen("task.INP", "r", stdin);
    //   freopen("task.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    vector < long long  > a(n);
    for (auto& i : a) cin >> i;
    sort(a.begin(), a.end());
    for (int i = n - 1; i >= 1; i--)
    {
        l = 0; r = i - 1;
        int k = x - a[i];
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (a[m] <= k) l = m + 1;
            else r = m - 1;
        }
        if (r == -1) continue;
        ans = max(ans, a[r] + a[i]);
    }
    cout << ans;
}