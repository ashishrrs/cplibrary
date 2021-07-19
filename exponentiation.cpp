#include<bits/stdc++.h>
#define inf 1e18
#define endl "\n"
#define loop(i,x,y) for(int i = x; i < y ; i++ )
#define in(n)       int n; cin>>n;
#define inarr(arr,n) int arr[n]; for(int i = 0; i < n ; i++){cin>>arr[i];}
#define maploop(x) for(auto itr = x.begin(); itr != x.end();itr++)
#define int long long
using namespace std;
const int N = 100005;
int mod = 1000000007;

long long power( long long x,
                 int y, int p)
{
	long long res = 1;
	x = x % p;

	while (y > 0) {
		if (y & 1)
			res = (res * x) % p;

		y = y / 2;
		x = (x * x) % p;
	}
	return res;
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
		cout << power(n, n, mod) << endl;
	}
}