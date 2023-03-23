#include <iostream>
#include <algorithm>
using namespace std;

void InputA(int[], int);
int BinarySearch(int[], int, int);
void QuickSort(int[], int, int);

int main()
{
	ios::sync_with_stdio(false);
	static int a1[100000], a2[100000], n, q;
	cin >> n >> q;
	InputA(a1, n);
	InputA(a2, q);
	QuickSort(a1, 0, n - 1);
	for (int i = 0; i < q; i++)
		if (BinarySearch(a1, n, a2[i]) != -1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	return 0;
}

void QuickSort(int a[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		int pivot = a[mid];
		int i = low, j = high;
		while (i <= j)
		{
			while (a[i] < pivot) i++;
			while (a[j] > pivot) j--;
			if (i <= j)
			{
				swap(a[i], a[j]);
				i++; j--;
			}
		}
		if (low < j) 
			QuickSort(a, low, j);
		if (i < high) 
			QuickSort(a, i, high);
	}
}
void InputA(int a[], int sz)
{
	for (int i = 0; i < sz; i++)
		cin >> a[i];
}
int BinarySearch(int a[], int sz, int x)
{
	int l = 0, r = sz - 1;
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (x == a[m])
			return m;
		if (x < a[m])
			r = m - 1;
		else
			l = m + 1;
	}
	return -1;
}