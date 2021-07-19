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

bool prime_check(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 0;
	if (n <= 3)
		return  1;
	if (n % 2 == 0 || n % 3 == 0)
		return 0;
	for (int i = 5; i * i <= n ; i = i + 6)
	{
		if (n % i == 0 || n % (i + 2) == 0)
			return 0;
	}
	return 1;
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
		cout << prime_check(n) << endl;
	}
}