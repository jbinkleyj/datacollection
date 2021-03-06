#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <queue>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

map<int, vector<int>> ma;
map<int, vector<int>>::iterator iter;
int a[100];
int n;

bool check(int i, int j)
{
	for (int k = 0; k < n; k++)
	{
		if ((i & (1 << k)) != 0 && (j & (1 << k)) != 0)
			return false;
	}
	return true;
}

int main()
{
	//freopen("input.txt","r",stdin);
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
	int t, cas = 1;
	int i, j, k, sum, len;
	bool flag;
	vector<int> temp;
	scanf ("%d", &t);
	while (t--)
	{
		scanf ("%d", &n);
		ma.clear();
		for (i = 0; i < n; i++)
			scanf ("%d", &a[i]);
		len = 1 << n;
		flag = false;
		for (i = 1; i < len; i++)
		{
			for (j = sum = 0; j < n; j++)
			{
				if ((i & (1 << j)) != 0)
					sum += a[j];
			}
			temp = ma[sum];
			int siz = temp.size();
			for (j = 0; j < siz; j++)
			{
				if (check(i, temp[j]))
				{
					flag = true;
					break;
				}
			}
			if (flag)
				break;
			ma[sum].push_back(i);
		}
		printf ("Case #%d:\n", cas++);
		if (!flag)
			printf ("Impossible\n");
		else
		{
			j = temp[j];
			flag = false;
			for (k = 0; k < n; k++)
			{
				if ((i & (1 << k)) != 0)
				{
					if (flag)
						printf (" ");
					flag = true;
					printf ("%d", a[k]);
				}
			}
			printf ("\n");
			flag = false;
			for (k = 0; k < n; k++)
			{
				if ((j & (1 << k)) != 0)
				{
					if (flag)
						printf (" ");
					flag = true;
					printf ("%d", a[k]);
				}
			}
			printf ("\n");
		}
    }
    return 0;
}