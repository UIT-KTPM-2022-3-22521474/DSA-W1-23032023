#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

void input(int a[], int n) 
{
    for (int i = 0; i < n; i++) 
        cin >> a[i];
}

void rotate(int a[], int n, int k) 
{
    k %= n;
    reverse(a, a + n);
    reverse(a, a + k);
    reverse(a + k, a + n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    const int MAXN = 1e6;
    int a[MAXN];
    int n, k;
    cin >> n >> k;
    input(a, n);
    rotate(a, n, k);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}