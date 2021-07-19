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


const int N = 3e5 + 5;
int mod = 1000000007;
int n;
vector<pair<int, int>>adj[N];
vector<vector<int>>bin_lift(N, vector<int>(20, -1));
vector<vector<int>>mini(N, vector<int>(20, -1));
vector<int>level(N, 0);

void dfs(int x, int parent, int height, int weight)
{
	level[x] = height;
	bin_lift[x][0] = parent;
	mini[x][0] = weight;
	for (auto a  : adj[x])
	{
		if (a.first != parent)
		{
			dfs(a.first, x, height + 1, a.second);
		}
	}

}
void lift()
{
	dfs(1, -1, 0, -1);
	for (int j = 1; j < 20; ++j)
	{
		for (int i = 1; i <= n; i++)
		{

			if (bin_lift[i][j - 1] != -1)
			{
				bin_lift[i][j] = bin_lift[bin_lift[i][j - 1]][j - 1];
				mini[i][j] = min(mini[i][j - 1], mini[bin_lift[i][j - 1]][j - 1]);
			}
		}
	}
}
int kth_parent(int x, int k)
{
	for (int i = 0; i < 20 ; i++ )
	{
		if (k & 1 << i)
		{
			if (bin_lift[x][i] != -1)
			{
				x = bin_lift[x][i];
			}
			else
				return -1;
		}
	}
	return x;
}

int lca(int a, int b)
{
	int mili = INT_MAX;
	if (level[a] > level[b])
		swap(a, b);
	int d = level[b] - level[a];
	while (d > 0)
	{
		int l = log2(d);
		mili = min(mini[b][l], mili);
		b = bin_lift[b][l];
		d -= 1 << l;
	}

	if (a == b)
		return mili;
	for (int i = 19; i >= 0; i-- )
	{
		if (bin_lift[a][i] != -1 && bin_lift[a][i] != bin_lift[b][i])
		{
			mili = min(mini[a][i], min(mini[b][i], mili));
			a = bin_lift[a][i], b = bin_lift[b][i];
		}

	}
	return min(mini[a][0], min(mini[b][0], mili));
}





void Main()
{
	cin >> n;
	in(m)
	loop(i, 0, m)
	{
		in(a)
		in(b)
		in(c)
		adj[a].pb(mp(b, c));
		adj[b].pb(mp(a, c));
	}


	lift();

	in(q)
	loop(i, 0, q)
	{
		in(a)
		in(b)
		//cout << lca(a, b) << endl;
		int m = lca(a, b);
		cout << m << endl;

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