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

bool v[1005][2];
PII a[1005];

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("output.out","w",stdout);
	int n, m, t;
	int i, j, k;
	int cas = 1;
	bool flag;
	scanf ("%d", &t);
	while (t--)
	{
		scanf ("%d", &n);
		for (i = 0; i < n; i++)
			scanf ("%d %d", &a[i].first, &a[i].second);
		int ans, now = 0;
		int maxneed1, maxneed2, maxneed3;
		flag = true;
		memset(v, false, sizeof(v));
		for (ans = 0; ; ans++)
		{
			maxneed1 = maxneed2 = maxneed3 = -1;
			for (i = 0; i < n; i++)
			{
				if (!v[i][0] && a[i].first <= now)
				{
					if (maxneed1 == -1)
						maxneed1 = i;
					if (a[i].second > a[maxneed1].second)
						maxneed1 = i;
				}
				if (!v[i][0] && !v[i][1] && a[i].second <= now)
				{
					if (maxneed2 == -1)
						maxneed2 = i;
					if (a[i].second > a[maxneed2].second)
						maxneed2 = i;
				}
				if (v[i][0] && !v[i][1] && a[i].second <= now)
				{
					if (maxneed3 == -1)
						maxneed3 = i;
					if (a[i].second > a[maxneed3].second)
						maxneed3 = i;
				}
			}
			if (maxneed1 == -1 && maxneed2 == -1 && maxneed3 == -1)
				break;
			if (maxneed2 != -1)
			{
				now += 2;
				v[maxneed2][0] = v[maxneed2][1] = true;
			}
			else if (maxneed3 != -1)
			{
				now += 1;
				v[maxneed3][1] = true;
			}
			else if (maxneed1 != -1)
			{
				now += 1;
				v[maxneed1][0] = true;
			}
		}
		printf ("Case #%d: ", cas++);
		if (now == n * 2)
			printf ("%d\n", ans);
		else
			printf ("Too Bad\n");
	}
	return 0;
}