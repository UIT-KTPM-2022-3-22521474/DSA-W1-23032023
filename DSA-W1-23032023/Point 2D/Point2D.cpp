#include <iostream>
#include <algorithm>
using namespace std;

struct point
{
	int x;
	int y;
};
typedef struct point POINT;

void Input(POINT[], int&);
void PointQuickSort(POINT[], int, int);
void Output(POINT[], int);

int main()
{
	ios::sync_with_stdio(false);
	static POINT AP[1000000];
	int n;
	Input(AP, n);
    PointQuickSort(AP, 0, n - 1);
	Output(AP, n);
	return 0;
}

void Input(POINT AP[], int& n)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> AP[i].x >> AP[i].y;
}
void PointQuickSort(POINT AP[], int left, int right)
{
    int i = left, j = right;
    POINT pivot = AP[(left + right) / 2];
    while (i <= j) 
    {
        while (AP[i].x < pivot.x || (AP[i].x == pivot.x && AP[i].y > pivot.y))
            i++;
        while (AP[j].x > pivot.x || (AP[j].x == pivot.x && AP[j].y < pivot.y))
            j--;
        if (i <= j) 
        {
            swap(AP[i], AP[j]);
            i++;
            j--;
        }
    };
    if (left < j)
        PointQuickSort(AP, left, j);
    if (i < right)
        PointQuickSort(AP, i, right);
}
void Output(POINT AP[], int n)
{
	for (int i = 0; i < n; i++)
		cout << AP[i].x << " " << AP[i].y << endl;
}
