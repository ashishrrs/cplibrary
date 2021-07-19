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
	if (m == 0 || n == 0)
		return cache[m][n] = 0;
	if (cache[m][n] != 0)
		return cache[m][n];
	if (a[m - 1] == b[n - 1])
		return  cache[m][n] = 1 + dp(a, b, m - 1, n - 1);
	else
		return cache[m][n] = max(dp(a, b, m - 1, n), dp(a, b, m, n - 1));
}
vector<char>lcs;
void print(string a, string b, int m, int n)
{
	while (m > 0 && n > 0)
	{
		if (a[m - 1] == b[n - 1])
		{
			lcs.push_back(a[m - 1]);
			m--;
			n--;
		}
		else
		{
			if (cache[m - 1][n] > cache[m][n - 1])
				m--;

			else
				n--;
		}
	}
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
		int x = dp(a, b, a.size(), b.size());
		if (x == 0)
			cout << -1 << endl;
		else
		{
			print(a, b, a.size(), b.size());
			reverse(lcs.begin(), lcs.end());
			loop(i, 0, lcs.size())
			cout << lcs[i];
			cout << endl;
		}
	}
}