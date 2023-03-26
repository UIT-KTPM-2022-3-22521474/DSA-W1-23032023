#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() 
{
    int n, m; cin >> n >> m;
    vector <vector <int> > a(n + 1, vector <int>(m + 1));
    vector <vector <int> > pref(n + 1, vector <int>(m + 1));

    for (int i = 1; i <= n; ++i) 
    {
        for (int j = 1; j <= m; ++j) 
        {
            cin >> a[i][j];
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i][j];
        }
    }

    int ans = 1e9;

    for (int i = 1; i <= n; ++i) 
    {
        for (int j = 1; j <= m; ++j) 
        {
            if (i + 2 <= n && j + 2 <= m) 
            {
                int u = i + 2;
                int v = j + 2;
                ans = min(ans, pref[u][v] - pref[i - 1][v] - pref[u][j - 1] + pref[i - 1][j - 1]);
            }
        }
    }

    cout << ans << endl;
    return 0;
}