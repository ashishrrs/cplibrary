#include<bits/stdc++.h>
#define inf 1e18
#define endl "\n"
int mod = 1000000007;
#define loop(i,x,y) for(int i = x; i < y ; i++ )
#define in(n)       int n; cin>>n;
#define inarr(arr,n) int arr[n]; for(int i = 0; i < n ; i++){cin>>arr[i];}
#define maploop(x) for(auto itr = x.begin(); itr != x.end();itr++)
#define int long long
using namespace std;
const int N = 100005;
int cache[N];
int dp(int arr[], int n, int i)
{
	cache[i] = 1;
	loop(j, i + 1, n)
	{
		if (arr[i] < arr[j] && cache[i] < cache[j] + 1)
			cache[i] = cache[j] + 1;
	}
	return cache[i];

}
int32_t main()
{
	srand(time(0));
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--)
	{
		in(n)
		inarr(arr, n)
		memset(cache, 0, sizeof(cache));
		int maxi = INT_MIN;
		for (int i = n - 1; i >= 0; i--)
		{
			maxi = max(maxi, dp(arr, n, i));
		}
		cout << maxi << endl;
	}
}