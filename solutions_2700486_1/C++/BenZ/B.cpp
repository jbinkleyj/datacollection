#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define rep(x, n) for (int x = 1; x <= n; ++x)
#define zrp(x, n) for (int x = n; x; --x)
#define FOR(x, l, r) for (int x = l; x <= r; ++x)
#define foredge(i, x) for (int i = start[x]; i; i = e[i].l)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define abs(a) ((a) > 0 ? (a) : (-(a)))
typedef long long int64;
int x, y, n;

void work()
{
	int p = (x + y) / 2;
	p = (2 * p + 1) * (p + 1);
	if (n >= p)
	{
		puts("1.0");
		return;
	}
	else
	{
		int tp = (x + y) / 2 - 1;
		tp = (2 * tp + 1) * (tp + 1);
		if (n <= tp)
		{
			puts("0.0");
			return;
		}
		n -= tp;
	}
	if (x == 0)
	{
		puts("0.0");
		return;
	}
	long double u, v, c = 1;
	u = 0; v = 0;
	FOR(i, 0, min(n, x + y))
	{
		int j = n - i;
		if (j <= x + y)
		{
			u += c;
			if (i >= y + 1) v += c;
		}
		c = c / (i + 1) * (n - i);
	}
	if (u <= 1e-9) u = 1;
	v /= u;
	double ans = double(v);
	printf("%.8lf\n", ans);
}

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int ca;
	scanf("%d", &ca);
	rep(t, ca)
	{
		scanf("%d%d%d", &n, &x, &y);
		x = abs(x); y = abs(y);
		printf("Case #%d: ", t);
		work();
	}
	return 0;
}
