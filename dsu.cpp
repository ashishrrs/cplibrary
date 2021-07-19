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


const int N = 10001;
int mod = 998244353;
class dsu {
public:
	vector<int> p;
	int n;
	vector<int> siz;

	dsu(int _n) : n(_n) {
		p.resize(n);
		siz.resize(n);
		loop(i, 0, n)
		{
			siz[i] = 1;
		}
		iota(p.begin(), p.end(), 0);
	}

	inline int get(int x) {
		return (x == p[x] ? x : (p[x] = get(p[x])));
	}
	inline int siza(int x)
	{
		return siz[get(x)];
	}
	inline bool unite(int x, int y) {
		int l = get(x);
		int k = get(y);
		if (l == k)
			return 0;
		if (siz[l] > siz[k])
		{
			swap(l, k);
		}
		siz[k] += siz[l];
		p[l] = k;
		//debug(siz)
		return 1;
	}
};
int mul(int a, int b)
{
	return (a * b) % mod;
}
int pow(int a, int b)
{
	int z = 1;
	while (b  > 0 )
	{
		if (b % 2)
		{
			z = mul(a, z);
		}
		a = mul(a, a);
		b = b / 2;

	}
	return z;
}
void Main()
{
	in(c)
	in(n)
	in(m)

	vector<pair<int, int>>lol;
	loop(i, 0, c)
	{
		in(x)
		//cout << x << endl;
		while (x--)
		{
			in(a)
			in(b)
			//cout << a << " " << b << endl;
			lol.pb({a - 1, i});
			lol.pb({b, ~i});
			//cout << a - 1 << " " << i << " " << b << " " << ~i << endl;
			//cout << 1 << endl;
		}
	}
	sort(lol.begin(), lol.end());
	debug(lol)
	dsu l(c);
	int prev = 0;
	int loners = 0;
	set<int>s;
	loop(i, 0, lol.size())
	{
		if (lol[i].first > prev && s.empty())
		{
			loners += lol[i].first - prev;
		}
		if (lol[i].second >= 0)
		{
			if (!s.empty())
			{
				l.unite(*s.begin(), lol[i].second);
			}
			s.insert(lol[i].second);
		}
		else
		{
			int f = ~lol[i].second;
			s.erase(f);
		}
		prev = lol[i].first;
		//debug(s);
	}
	loners += n - prev;
	//cout << loners << endl;
	loop(i, 0, c)
	{
		if (l.get(i) == i)
			loners++;
	}
	//cout << loners << endl;
	cout << pow(m, loners) << endl;
	// cout << 1 << endl;

}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--)
	{
		Main();
	}
}
