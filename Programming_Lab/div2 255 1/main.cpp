#include <iostream>
using namespace std;

int min(int a, int b)
{
	if (a<b)
		return a;
	return b;
}

int main()
{
	int n, a;
	cin >> n >> a;
	a--;
	int arr[n];
	for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
	int i = a, j = a;
	int ans = 0;
	if (arr[a] == 1)
		ans++;
	while (i > 0 &&  j < n-1)
	{
		i--;
		j++;
		if (arr[i] == 1 && arr[j]==1)
			ans+=2;
	}
	while (i > 0)
	{
	    i--;
		if (arr[i] == 1)
			ans++;
	}
	while (j < n-1)
	{
	    j++;
		if (arr[j] == 1)
			ans++;
	}
	cout << ans << endl;
}
