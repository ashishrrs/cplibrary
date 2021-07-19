#include<bits/stdc++.h>
#define inf 1e18
#define endl "\n"
#define loop(i,x,y) for(int i = x; i < y ; i++ )
#define all(x) (x).begin(),(x).end()
#define in(n)       int n; cin>>n;
#define mp make_pair
#define pb push_back
static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
#define inarr(arr,n) int arr[n]; for(int i = 0; i < n ; i++){cin>>arr[i];}
#define maploop(x) for(auto itr = x.begin(); itr != x.end();itr++)
#define int long long
using namespace std;
const int N = 200002;
int mod = 998244353;
int sum = 0;
vector<int> adj[N], rev[N];
int arr[N];
int vis[N] = {0};
int comp[N] = {0};
vector<int>grps[N];
vector<int>s;

void dfs(int i)
{
	vis[i] = 1;
	for (auto x : adj[i])
	{
		if (vis[x] == 1)
			continue;
		else
		{
			//	cout << x << endl;
			dfs(x);
		}
	}
	//cout << i << endl;
	s.pb(i);
}

void dfs2(int x, int value)
{
	comp[x] = value;
	for (auto y : rev[x])
	{
		if (comp[y] == -1)
			dfs2(y, value);
	}
	//cout << value << endl;
	grps[value].pb(x);
}
void Main()
{
	int n;
	cin >> n;
	sum = 0;
	loop(i, 1, n + 1)
	{
		cin >> arr[i];
	}
	loop(i, 1, n + 1)
	{
		adj[i].clear();
	}
	loop(i, 1, n + 1)
	{
		in(a)
		if (i != a)
		{
			adj[i].pb(a);
			rev[a].pb(i);
		}

	}
	//s.clear();
	memset(vis, -1, sizeof(vis));
	memset(comp, -1, sizeof(comp));
	loop(i, 1, n + 1)
	{
		if (vis[i] == -1)
			dfs(i);
	}
	// loop(i, 0, s.size())
	// {
	// 	cout << s[i] << " ";
	// }
	// cout << endl;
	int grp = 0;
	reverse(s.begin(), s.end());
	for (auto it : s)
	{
		if (comp[it] == -1)
		{
			grp++;
			dfs2(it, grp);
		}
	}
	//cout << grp << endl;
	map<int, int>outdeg;
	loop(i, 1, n + 1)
	{
		for (auto k : adj[i])
		{
			if (comp[i] != comp[k])
			{
				outdeg[comp[i]]++;
			}
		}
	}
	loop(i, 1, grp + 1)
	{
		if (outdeg[i] == 0)
		{
			// cout << i << endl;
			int maxi = LLONG_MAX;
			for (auto j : grps[i])
			{
				//cout << j << endl;
				maxi = min(maxi, arr[j]);
			}
			sum += maxi;
			//cout << sum << endl;
			//cout << endl;
		}
	}
	cout << sum << endl;

}

int32_t main()
{
	srand(time(0));
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	//cin >> t;
	while (t--)
	{
		Main();
	}
}