#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <stack>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

double d[100005];
double dp[100005];
double p[100005];

int main()
{
	freopen("input.txt","r",stdin);
	//freopen("output.out","w",stdout);
	int n, m, t;
	int i, j, k;
	int cas = 1;
	scanf ("%d", &t);
	while (t--)
	{
		scanf ("%d %d", &n, &m);
		for (i = 0; i < n; i++)
			scanf ("%lf", &p[i]);
		d[0] = 1;
		for (i = 1; i <= n; i++)
			d[i] = d[i-1] * p[i-1];
		double ans = m + 2;
		for (i = 0; i <= n; i++)
		{
			double press1 = i + m - (n - i) + 1;
			double press2 = i + m - (n - i) + 1 + m + 1;
			ans = min(ans, press1 * d[n-i] + press2 * (1 - d[n-i]));
		}
		printf ("Case #%d: %.6lf\n", cas++, ans + 1e-9);
	}
	return 0;
}