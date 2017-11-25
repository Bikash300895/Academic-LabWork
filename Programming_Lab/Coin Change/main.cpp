#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

/*
int count(int arr[], int m, int n)
{
	if (n == 0) return 1;
	else if (n < 0) return	0;
	else if (m < 0) return 0;

	return count(arr, m - 1, n) + count(arr, m, n - arr[m-1]);
}
*/

int count(int S[], int m, int n)
{
	int x, y;

	int table[n+1][m];

	for (int i = 0; i < n + 1; i++)
		table[0][i] = 1;

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 0; j < m; j++)
		{
			x = (i - S[j] >= 0) ? table[i - S[j]][j] : 0;

			// Count of solutions excluding S[j]
			y = (j >= 1) ? table[i][j - 1] : 0;

			// total count
			table[i][j] = x + y;

		}
	}

	return table[n][m - 1];
}



int main()
{
	int i, j;
	int arr[] = { 1, 2, 3 };
	int m = sizeof(arr) / sizeof(arr[0]);
	printf("%d ", count(arr, m, 4));
	getchar();
	return 0;
}
