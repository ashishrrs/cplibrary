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
int32_t main()
{
	srand(time(0));
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--)
	{
		in(n)
		inarr(arr, n);
		vector<int>cache;
		cache.push_back(arr[0]);
		int j = 1;
		loop(i, 1, n)
		{
			if (arr[i] > cache[j - 1])
			{
				cache.push_back(arr[i]);
				j++;
			}
			else
			{
				auto itr = lower_bound(cache.begin(), cache.end(), arr[i]) - cache.begin();
				cache[itr] = arr[i];
			}
		}
		cout << j << endl;
	}
}