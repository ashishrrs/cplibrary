int getsum(int x)
{
	int res = 0;
	for (int i = x ; i > 0; i -= (i & -i))
		res += arr[i];
	return res;
}
void update(int x, int val)
{
	for (int i = x ; i <= n; i += (i & -i))
	{
		arr[i] += val;

	}
}