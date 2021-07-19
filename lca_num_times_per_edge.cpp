#include<bits/stdc++.h>
#define inf 1e18
#define endl "\n"
#define mp make_pair
#define pb push_back
#define loop(i,x,y) for(int i = x; i < y ; i++ )
#define all(x) (x).begin(),(x).end()
#define in(n)       int n; cin>>n;
#define inarr(arr,n) vector<int>arr(n); for(int i = 0; i < n ; i++){cin>>arr[i];}
#define maploop(x) for(auto itr = x.begin(); itr != x.end();itr++)
#define int long long
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}


template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


const int N = 1e5 + 5;
int mod = 1000000007;
int n;
vector<pair<int, int>>adj[N];
vector<vector<int>>bin_lift(N, vector<int>(20, -1));
vector<int>mark(N, 0);
vector<int>level(N, 0);
vector<int>diff(N, 0);
vector<int>ans(N, 0);

void dfs(int x, int parent, int height, int idx)
{
	mark[x] = idx;
	level[x] = height;
	bin_lift[x][0] = parent;
	for (auto a  : adj[x])
	{
		if (a.first != parent)
		{
			dfs(a.first, x, height + 1, a.second);
		}
	}

}
int dfs2(int x, int parent)
{
	int curr = 0;
	for (auto k : adj[x])
	{
		if (k.first == parent)
			continue;
		curr += dfs2(k.first, x);
	}
	curr += diff[x];
	ans[mark[x]] = curr;
	return curr;
}
void lift()
{
	dfs(1, -1, 0, 0);
	for (int j = 1; j < 20; ++j)
	{
		for (int i = 1; i <= n; i++)
		{

			if (bin_lift[i][j - 1] != -1)
			{
				bin_lift[i][j] = bin_lift[bin_lift[i][j - 1]][j - 1];
			}
		}
	}
}

int lca(int a, int b)
{
	if (level[a] > level[b])
		swap(a, b);
	int d = level[b] - level[a];
	while (d > 0)
	{
		int l = log2(d);
		b = bin_lift[b][l];
		d -= 1 << l;
	}

	if (a == b)
		return a;
	for (int i = 19; i >= 0; i-- )
	{
		if (bin_lift[a][i] != -1 && bin_lift[a][i] != bin_lift[b][i])
		{
			a = bin_lift[a][i], b = bin_lift[b][i];

		}

	}
	return bin_lift[a][0];
}





void Main()
{
	cin >> n;
	loop(i, 1, n)
	{
		in(a)
		in(b)
		adj[a].pb(mp(b, i));
		adj[b].pb(mp(a, i));
	}


	lift();

	in(q)

	loop(i, 0, q)
	{
		in(a)
		in(b)
		//cout << lca(a, b) << endl;
		int f = lca(a, b);
		diff[a]++;
		diff[b]++;
		//debug(f);
		diff[f] -= 2;
	}

	dfs2(1, -1);
	loop(i, 1, n)
	{
		cout << ans[i] << " ";
	}




}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	//cin >> t;
	while (t--)
	{
		Main();
	}
}