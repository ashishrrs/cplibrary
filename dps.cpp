/*

LIS O(N^2)

*/

in(n)
inarr(arr, n);
int dp[n ];
dp[0] = 1;
loop(i, 1, n)
{
	dp[i] = 1;
	loop(j, 0, i)
	{
		if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
			dp[i] = dp[j] + 1;
	}
}
cout << *max_element(dp, dp + n);


/*

LIS O(nlogn)

*/

in(n)
inarr(arr, n);
vector<int>dp;
dp.pb(arr[0]);
loop(i, 1, n)
{
	if (dp.back() < arr[i])
		dp.pb(arr[i]);
	else
	{
		auto j = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
		dp[j] = arr[i];
	}
}
cout << dp.size() << endl;


/*

 LCS

 */
in(n);
in(m);
instr(a);
instr(b)
int dp[a.size() + 1][b.size() + 1];
loop(i, 0, a.size() + 1)
{
	loop(j, 0, b.size() + 1)
	{
		if (i == 0 || j == 0)
			dp[i][j] = 0;
		else if (a[i - 1] == b[j - 1])
		{
			dp[i][j] = 1 + dp[i - 1][j - 1];
		}
		else
		{
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
}
cout << dp[a.size()][b.size()] << endl;


/*

Printing LCS

*/
int i = n;
int j = m;
int size = dp[a.size()][b.size()];
char res[size];
while (i > 0 && j > 0)
{
	if (a[i - 1] == b[j - 1])
	{
		res[size - 1] = a[i - 1];
		size--;
		i--;
		j--;

	}
	else if (dp[i - 1][j] > dp[i][j - 1])
	{
		i--;
	}
	else
		j--;
}
cout << res << endl;

/*

converting str1 to str2 using insert ,delete and remove

*/

in(n)
in(m)
instr(a);
instr(b)
int dp[a.size() + 1][b.size() + 1];
loop(i, 0, a.size() + 1)
{
	loop(j, 0, b.size() + 1)
	{
		if (i == 0 )
			dp[i][j] = j;
		else if (j == 0)
			dp[i][j] = i;
		else if (a[i - 1] == b[j - 1])
			dp[i][j] = dp[i - 1][j - 1];
		else

			dp[i][j] = 1 + min(dp[i - 1][j - 1], min( dp[i - 1][j], dp[i][j - 1]));
	}
}
cout << dp[n][m] << endl;

/*

minimum sum path in a grid if you can move only in dowm,right and diagonal

*/

in(n)
in(m)
int arr[n][m];
loop(i, 0, n)
{
	loop(j, 0, m)
	cin >> arr[i][j];
}
int dp[n][m];
dp[0][0] = arr[0][0];
loop(i, 1, m)
dp[0][i] = dp[0][i - 1] + arr[0][i];
loop(i, 1, n)
dp[i][0] = dp[i - 1][0] + arr[i][0];

loop(i, 1, n)
{
	loop(j, 1, m)
	{
		dp[i][j] = arr[i][j] + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
	}
}
cout << dp[n - 1][m - 1] << endl;

/*

Coin change max number of ways

*/
in(sum)
in(n)
inarr(arr, n)
int dp[sum + 1];
mem(dp, 0);
dp[0] = 1;
loop(i, 1, n + 1)
{
	loop(j, arr[i - 1], sum + 1)
	{
		dp[j] += dp[j - arr[i - 1]];
	}
}
cout << dp[sum] << endl;



//
// Djikstra fo adjacency matrix
//
int mindistance(int dist[], bool sptSet[], int V)
{
	int mini = INT_MAX, mini_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= mini)
			mini = dist[v], mini_index = v;

	return mini_index;
}

void print(int parent[], int i)
{
	if (parent[i] == -1)
		return;
	print(parent, parent[i]);
	cout << parent[i] + 1 << " ";
}
void Main() {
	in(n)
	in(m)
	int arr[n][n];
	mem(arr, 0);
	loop(i, 0, m)
	{
		in(A)
		in(B)
		in(w)
		arr[A - 1][B - 1] = w;
		arr[B - 1][A - 1] = w;

	}
	int dist[n];
	dist[0] = 0;
	bool splset[n];
	int parent[n];
	parent[0] = -1;
	loop(i, 0, n)
	{
		parent[i] = -1;
		dist[i] = INT_MAX;
		splset[i] = false;
	}
	dist[0] = 0;
	loop(i, 0, n)
	{
		int u =  mindistance(dist, splset, n);
		splset[u] = 1;
		loop(j, 0, n)
		{
			if (!splset[j] && arr[u][j] && (dist[u] != INT_MAX) && (arr[u][j] + dist[u] < dist[j]))
			{

				parent[j] = u;
				dist[j] = arr[u][j] + dist[u];
			}
		}
	}
	print(parent, n - 1);
	if (parent[n - 1] != -1)
		cout << n << endl;
	else
		cout << -1 << endl;
}

//
// Djikstra for adjacency list
//

void print(int parent[], int i)
{
	if (parent[i] == -1)
		return;
	print(parent, parent[i]);
	cout << parent[i] + 1 << " ";
}
void Main()
{
	in(n)
	in(m)
	vector<pair<int, int>>graph[n];
	loop(i, 0, m)
	{
		in(a)
		in(b)in(c)
		graph[a - 1].pb(mp(b - 1, c));
		graph[b - 1].pb(mp(a - 1, c));
	}
	int dis[n];
	fill(dis, dis + n, inf);
	dis[0] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq;
	pq.push({0, 0});
	int parent[n];
	fill(parent, parent + n, -1);
	parent[0] = -1;
	while (!pq.empty())
	{
		pair<int, int>z = pq.top();
		pq.pop();
		for (auto itr : graph[z.first])
		{
			if ( dis[itr.first] > dis[z.first] + itr.second)
			{
				dis[itr.first] = dis[z.first] + itr.second;
				pq.push({itr.first, dis[itr.first]});
				parent[itr.first] = z.first;
			}
		}
	}

	if (parent[n - 1] == -1)
		cout << -1 << endl;
	else
	{
		print(parent, n - 1);
		cout << n << endl;
	}


}


/*
checking bipartite graph and dividing graph
*/
vector<int>adj[100005];
vector<int>res[2];
int color[100005] = {0};
int dfs(int v, int val = 2)
{
	color[v] = val;
	res[val - 1].pb(v);
	for (auto x : adj[v])
	{
		if (!color[x] && !dfs(x, 3 - val))
			return 0;
		else if (color[x] != 3 - val)
			return 0;

	}
	return 1;

}
void Main()
{
	in(n)
	in(m)
	loop(i, 0, m)
	{
		in(a)in(b)
		adj[a].pb(b);
		adj[b].pb(a);
	}
	loop(i, 1, n + 1)
	{
		if (!color[i])
		{
			if (adj[i].empty())
			{
				continue;
			}
			else if (!dfs(i))
			{
				cout << -1 << endl;
				return;
			}
		}
	}
	loop(i, 0, 2)
	{
		cout << res[i].size() << endl;
		for (auto x : res[i])
			cout << x << " ";
		cout << endl;
	}


}


/**


Matrix exponentiaition


**/

//matmax should be one more than array size
void mult(ll a[matmax][matmax], ll b[matmax][matmax], ll c[matmax][matmax], int m, int n, int p)
{
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= p; j++)
		{
			c[i][j] = 0;
			for (int k = 1; k <= n; k++)
			{
				c[i][j] += (a[i][k] * b[k][j]) % mod;
				c[i][j] %= mod;
			}
		}
	}
}

void mat_pow(ll a[matmax][matmax], ll c[matmax][matmax], int n, ll p)
{
	if (p == 0)
	{
		for (int i = 1; i <= n; i++)
			c[i][i] = 1;
	}
	else if (p == 1)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				c[i][j] = a[i][j];
		}
	}
	else
	{
		ll d[matmax][matmax];
		mat_pow(a, d, n, p / 2);
		if (p % 2)
		{
			ll e[matmax][matmax];
			mult(d, d, e, n, n, n);
			mult(e, a, c, n, n, n);
		}
		else
		{
			mult(d, d, c, n, n, n);
		}
	}
}

/*

FENWICK OR BIT

*/
//BIT update adds a value to the previous value
//BIT can only be used to find additions values
//for max and min we need segment tree

int getsum(int arr[], int index)
{
	int sum = 0;
	index = index + 1;
	while (index > 0)
	{
		sum += arr[index];
		index -= index & -index;
	}
	return sum;
}
void update(int arr[], int index, int val, int size)
{
	index++;
	while (index <= size)
	{
		arr[index] += val;
		index += index & - index;
	}
}
void Main()
{
	in(n);
	int arr[n];
	int bit[n + 1] = {0};
	loop(i, 0, n)
	{
		cin >> arr[i];
		update(bit, i, arr[i], n);
	}
	cout << getsum(bit, 4);
}

/*

Playing with common range

*/

void Main()
{
	in(n)in(q)
	inarr(arr, n);
	sort(arr, arr + n);
	int freq[n] = {0};
	loop(i, 0, q)
	{
		in(a)in(b);
		freq[a - 1]++;
		if (b < n)
			freq[b]--;
	}
	int v = 0;
	int b[n];
	loop(i, 0, n)
	{
		v += freq[i];
		b[i] = v;
	}
	sort(b, b + n);
	int sum = 0;
	loop(i, 0, n)
	{
		sum += b[i] * arr[i];
	}

	cout << sum << endl;
}


///
/*

DSU

*/
struct subset {
	int parent;
	int rank;
};
int find(struct subset subsets[], int i)
{
	// find root and make root as parent of i (path
	// compression)
	if (subsets[i].parent != i)
		subsets[i].parent
		    = find(subsets, subsets[i].parent);

	return subsets[i].parent;
}

void Union(struct subset subsets[], int xroot, int yroot)
{

	// Attach smaller rank tree under root of high rank tree
	// (Union by Rank)
	if (subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if (subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;

	// If ranks are same, then make one as root and
	// increment its rank by one
	else {
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}
void Main()
{
	in(n)
	in(m)
	map<int, int>x;
	struct subset* subsets = (struct subset*)malloc(n * sizeof(struct subset));
	for (int v = 0; v < n; ++v) {
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}
	int j = 0;
	loop(i, 0, m)
	{
		in(a)in(b)
		int f  = find(subsets, a - 1);
		int p = find(subsets, b - 1);
		if (f == p)
			continue;

		Union(subsets, f, p);

	}
}



//Diff array in maps

void Main()
{

	in(n)
	in(c)
	int sum = 0;
	map<int, int>x;
	loop(i, 0, n)
	{
		in(a)
		in(b)
		in(f)
		x[a] += f;
		x[b + 1] -= f;
	}
	int val = 0;
	int prev = 0;
	maploop(x)
	{

		sum += min(c, val) * (itr->ff - prev);
		val += itr->sec;
		prev = itr->ff;

	}
	cout << sum << endl;


}
//DFS implementation to travel all paths such that it doesn not go through chosen paths//
vector< int>x[100005];
map<pair<int, int>, int>arr;
int dfs(int src, int parent = -1)
{
	int res = 0;
	for (auto a : x[src])
	{
		if (a == parent)
			continue;
		int temp = dfs(a, src);
		if (temp == 0)
		{
			res += arr[ {src, a}];
		}
		else
			res += temp;
	}
	return res;
}
void Main()
{

	in(n)
	loop(i, 0, n - 1)
	{
		in(a)in(b)
		in(w)
		x[a].pb(b);
		x[b].pb(a);
		if (w == 2)
		{
			arr[ {a, b}] = 1;
			arr[ {b, a}] = 1;
		}
	}
	cout << dfs(1) << endl;

}
//Kosaraju algo for strongly connected components
vector<int>adj[100005];
vector<int>rev[100005];
vector<int>x(100005, -1);
vector<int>x2(100005, -1);
stack<int>steak;
void dfs(int i)
{
	x[i] = 1;
	for (auto f : adj[i] )
	{
		if (x[f] == 1)
			continue;
		dfs(f);

	}
	steak.push(i);
}

void reverse(int n)
{
	loop(i, 1, n + 1)
	{
		loop(j, 0, adj[i].size())
		{
			rev[adj[i][j]].pb(i);
		}
	}
}
void dfs2(int i)
{
	x2[i] = 1;
	cout << i << " ";
	for (auto f : rev[i] )
	{
		if (x2[f] == 1)
			continue;
		dfs2(f);
	}
}
void Main()
{
	in(n)in(m)
	loop(i, 0, m)
	{
		in(a)
		in(b)
		adj[a].pb(b);
	}
	loop(i, 1, n + 1)
	{
		if (x[i] == -1)
		{
			dfs(i);
		}
	}
	reverse(n);
	while (!steak.empty())
	{

		int i = steak.top();
		steak.pop();
		if (x2[i] == -1)
		{
			dfs2(i);
			cout << endl;
		}
	}
}
//tarjan algo for strongly connected components
int getMid(int s, int e)
{
	return s + (e - s) / 2;
}
int MaxUtil(int* st, int ss, int se, int l,
            int r, int node)
{
	// If segment of this node is completely
	// part of given range, then return
	// the max of segment
	if (l <= ss && r >= se)
		return st[node];

	// If segment of this node does not
	// belong to given range
	if (se < l || ss > r)
		return -1;

	// If segment of this node is partially
	// the part of given range
	int mid = getMid(ss, se);

	return max(MaxUtil(st, ss, mid, l, r,
	                   2 * node + 1),
	           MaxUtil(st, mid + 1, se, l,
	                   r, 2 * node + 2));
}
int MinUtil(int* st, int ss, int se, int l,
            int r, int node)
{
	// If segment of this node is completely
	// part of given range, then return
	// the max of segment
	if (l <= ss && r >= se)
		return st[node];

	// If segment of this node does not
	// belong to given range
	if (se < l || ss > r)
		return -1;

	// If segment of this node is partially
	// the part of given range
	int mid = getMid(ss, se);

	return min(MinUtil(st, ss, mid, l, r,
	                   2 * node + 1),
	           MinUtil(st, mid + 1, se, l,
	                   r, 2 * node + 2));
}
int constructSTUtil(int arr[], int ss, int se,
                    int* st, int si)
{
	// If there is one element in array, store
	// it in current node of
	// segment tree and return
	if (ss == se)
	{
		st[si] = arr[ss];
		return arr[ss];
	}

	// If there are more than one elements, then
	// recur for left and right subtrees and
	// store the max of values in this node
	int mid = getMid(ss, se);

	st[si] = max(constructSTUtil(arr, ss, mid, st,
	                             si * 2 + 1),
	             constructSTUtil(arr, mid + 1, se,
	                             st, si * 2 + 2));

	return st[si];
}
int constructSTUtil2(int arr[], int ss, int se,
                     int* st, int si)
{
	// If there is one element in array, store
	// it in current node of
	// segment tree and return
	if (ss == se)
	{
		st[si] = arr[ss];
		return arr[ss];
	}

	// If there are more than one elements, then
	// recur for left and right subtrees and
	// store the max of values in this node
	int mid = getMid(ss, se);

	st[si] = min(constructSTUtil(arr, ss, mid, st,
	                             si * 2 + 1),
	             constructSTUtil(arr, mid + 1, se,
	                             st, si * 2 + 2));

	return st[si];
}
int* constructST(int arr[], int n)
{
	// Height of segment tree
	int x = (int)(ceil(log2(n)));

	// Maximum size of segment tree
	int max_size = 2 * (int)pow(2, x) - 1;

	// Allocate memory
	int* st = new int[max_size];

	// Fill the allocated memory st
	constructSTUtil(arr, 0, n - 1, st, 0);

	// Return the constructed segment tree
	return st;
}
int* constructST2(int arr[], int n)
{
	// Height of segment tree
	int x = (int)(ceil(log2(n)));

	// Maximum size of segment tree
	int max_size = 2 * (int)pow(2, x) - 1;

	// Allocate memory
	int* st = new int[max_size];

	// Fill the allocated memory st
	constructSTUtil2(arr, 0, n - 1, st, 0);

	// Return the constructed segment tree
	return st;
}
int getMax(int* st, int n, int l, int r)
{
	// Check for erroneous input values
	if (l < 0 || r > n - 1 || l > r)
	{
		printf("Invalid Input");
		return -1;
	}

	return MaxUtil(st, 0, n - 1, l, r, 0);
}
int getMin(int* st, int n, int l, int r)
{
	// Check for erroneous input values
	if (l < 0 || r > n - 1 || l > r)
	{
		printf("Invalid Input");
		return -1;
	}

	return MinUtil(st, 0, n - 1, l, r, 0);
}
