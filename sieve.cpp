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
bool prime[N];
void sieve()
{
	memset(prime, true, sizeof(prime));
	prime[1] = false;
	for (int i = 2; i * i <= N - 1 ; i++)
	{
		if (prime[i])
		{
			for (int j = 2; j * i <= N - 1; j++)
				prime[j * i] = false;
		}
	}
}
int32_t main()
{
	srand(time(0));
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	sieve();
	while (t--)
	{
		in(n)
		cout << prime[n] << endl;
	}
}