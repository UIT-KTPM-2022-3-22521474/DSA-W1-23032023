#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point
{
    int x;
    int y;
};
typedef struct point POINT;

bool PointCompare(const POINT& p1, const POINT& p2)
{
    return (p1.x != p2.x) ? p1.x < p2.x : p1.y > p2.y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector <POINT> points(n);
    for (auto& ap : points)
        cin >> ap.x >> ap.y;
    sort(points.begin(), points.end(), PointCompare);
    for (const auto& ap : points)
        cout << ap.x << " " << ap.y << "\n";
    return 0;
}