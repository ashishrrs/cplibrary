#include<bits/stdc++.h>
#define inf 1e18
#define endl "\n"
int mod = 1000000007;
#define loop(i,x,y) for(int i = x; i < y ; i++ )
#define in(n)       int n; cin>>n;
#define inarr(arr,n) int arr[n]; for(int i = 0; i < n ; i++){cin>>arr[i];}
#define maploop(x) for(auto itr = x.begin(); itr != x.end();itr++)
#define instr(str) string str; cin>>str;
#define int long long
using namespace std;
const int N = 10000;
int cache[N][N];
int dp(string a, string b, int m, int n)
{
	if (m == 0)
		return cache[m][n] = n;
	if (n == 0)
		return cache[m][n] = m;
	if (cache[m][n] != 0)
		return cache[m][n];
	if (a[m - 1] == b[n - 1])
		return  cache[m][n] = dp(a, b, m - 1, n - 1);
	else
		return cache[m][n] = 1 + min(dp(a, b, m - 1, n - 1), min(dp(a, b, m - 1, n), dp(a, b, m, n - 1)));
	//m-1,n-1 ==>> replace ; m-1,n ==>> remove ; m,n-1 ==>>insert
}
int32_t main()
{
	srand(time(0));
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--)
	{
		instr(a)
		instr(b)
		memset(cache, 0, sizeof(cache));
		cout << dp(a, b, a.size(), b.size()) << endl;
	}
}