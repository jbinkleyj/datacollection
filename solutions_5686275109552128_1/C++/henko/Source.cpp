#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <utility>
#include <string.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cctype>

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef long lint;

#define MP make_pair
#define PB push_back
#define EPS 0.0000001
#define ALL(a) a.begin(), a.end()

const int INF = 1000 * 1000 * 1000;
const int MOD = 1000 * 1000 * 1000 + 7;
const lint INF_L = 1000 * 1000 * 1000;
const ll INF_LL = 1LL * INF_L * INF_L;
const ll MOD_LL = 1000000000007LL;


ll gcd(ll a, ll b) 
{
	while (b) 
	{
		a %= b;
		swap(a, b);
	}
	return a;
}

ll lcm(ll a, ll b) 
{
	return (a / gcd(a, b)) * b;
}


//#define ONLINE_JUDGE
int main() 
{
#ifndef ONLINE_JUDGE
	freopen("B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		int d, pi, maxp = 1;
		cin >> d;
		map <int, int> p;
		for (int j = 0; j < d; ++j)
		{
			cin >> pi;
			++p[pi];
			maxp = max(maxp, pi);
		}
		int ans = maxp;
		for (int pp = 1; pp <= maxp; ++pp)
		{
			int curOps = 0;
			for (auto j : p)
			{
				if (j.first > pp)
				{
					curOps += j.second * ((j.first) / pp - 1 * (j.first % pp == 0));
				}
			}
			ans = min(ans, pp + curOps);
		}
		printf("Case #%d: %d\n", i, ans);
	}

	return 0;
}