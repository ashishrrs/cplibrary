#include<bits/stdc++.h>
#define inf 1e18
#define endl "\n"
#define loop(i,x,y) for(int i = x; i < y ; i++ )
#define in(n)       int n; cin>>n;
#define inarr(arr,n) int arr[n]; for(int i = 0; i < n ; i++){cin>>arr[i];}
#define maploop(x) for(auto itr = x.begin(); itr != x.end();itr++)
#define int long long
using namespace std;
const int N = 500001;
const int mod = 1e9 + 7;
int fac[N];
int mul(int a, int b)
{
	return (a * b) % mod;
}
void pre()
{
	fac[0] = 1;
	loop(i, 1, N)
	{
		fac[i] = mul(fac[i - 1], i);
	}
}
int sub(int a, int b)
{
	int l = a - b;
	if (l < 0)
	{
		l += mod;
	}
	return l;
}
int powe(int a, int b)
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
int div(int a)
{
	int ans;
	return ans = powe(a, mod - 2);
}
int comb(int n, int k)
{
	if (n >= k)
	{
		return mul(fac[n], div(mul(fac[k], fac[n - k])));
	}
	else
		return 0;
}
int add(int a, int b)
{
	a += b;
	if (a > mod)
	{
		a -= mod;
	}
	return a;
}

void Main()
{
	cout << powe(2, 5) << endl;


}

int32_t main()
{
	srand(time(0));
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--)
	{
		Main();
	}
}