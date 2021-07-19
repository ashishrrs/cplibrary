#include<bits/stdc++.h>
#define inf 2e18
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
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------ - */


const int N = 1e5 + 5;
const int mod = 1e9 + 7;

int n, m, par[N]; vector<pair<int, int>> g[N]; int d[N];

void bfs(int i = 1) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
	d[i] = 0;

	q.push({d[i], i});
	while (!q.empty()) {
		pair<int, int> p = q.top();
		q.pop();

		// if (p.first > d[p.second]) continue;

		for (auto pr : g[p.second]) {
			if (d[pr.first] > d[p.second] + pr.second) {
				d[pr.first] = d[p.second] + pr.second;
				par[pr.first] = p.second;
				q.push({d[pr.first], pr.first});
			}
		}
	}

}

void code() {
	cin >> n >> m;

	fill(d, d + n + 5, inf);
	fill(par, par + n + 5, 0);

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--;
		v--;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}

	bfs(0);
	if (d[n - 1] == inf) {
		cout << "-1\n";
		return;
	}
	//cout << d[n - 1] << endl;
	int to = n - 1;
	vector<int> answer;
	while (to != 0) {
		answer.push_back(to);
		to = par[to];
	}

	reverse(answer.begin(), answer.end());
	for (auto i : answer) cout << i << " "; cout << "\n";
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t = 1;
	// cin>>t;

	while (t-- > 0) {
		code();
	}
}