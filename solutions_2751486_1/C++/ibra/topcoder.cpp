#include <stdio.h>
#include<vector>
#include<iostream>
#include <math.h>
#include <algorithm>
#include<cstring>
#include<ctime>
#include<set>
#include <queue>
#include<map>
#include<string>
using namespace std;
const double EPS = 1e-9;
typedef long long ll;
typedef unsigned long long ull; 
int nextint(){int a;scanf("%d",&a);return a;}
ll nextll(){ll a;scanf("%lld",&a);return a;}
double nextdouble(){double a;scanf("%lf",&a);return a;}

char s[1<<20];
ll len, n;

bool isVowel(char c)
{
	return 
		c == 'a' ||
		c == 'e' ||
		c == 'i' ||
		c == 'o' ||
		c == 'u';
}

ll getCount(ll start, ll end) // >= n
{
	if(end < start) return 0;
	ll l = end-start+1;
	if(l < n) return 0;
	return (l-n+1)*(l-n+2)/2;
}

ll getCount1(ll start, ll end) // < n
{
	if(end < start) return 0;
	ll l = end-start+1;
	return l*(n-1) - (n-2)*(n-1)/2;
}

ll brute()
{
	ll res = 0;
	for(int i = 0; i < len; i++)
	{
		for(int j = i; j < len; j++)
		{
			int cnt = 0;
			bool ok = false;
			for(int ii = i; ii <= j; ii++)
			{
				if(!isVowel(s[ii]))
					cnt++;
				else
				{
					if(cnt >= n)
						ok = true;
					cnt = 0;
				}
			}
			if(cnt >= n)
				ok = true;
			if(ok) res++;
		}
	}
	return res;
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t = nextint();
	for(int test = 1; test <= t; test++)
	{
		scanf("%s", s);
		len = strlen(s);
		n = nextint();
		int cnt = 0;
		ll res = len*(len+1)/2 - getCount1(0, len-1);
		vector<pair<int, int> > ps;
		for(int i = 0; i < len; i++)
		{
			if(!isVowel(s[i]))
				cnt++;
			else
			{
				if(cnt >= n)
					ps.push_back(make_pair(i-cnt, i-1));
				cnt = 0;
			}
		}
		if(cnt >= n)
			ps.push_back(make_pair(len-cnt, len-1));

		if(ps.size())
			res -= getCount(0, ps.front().first+n-2);
		for(int i = 0; i+1 < ps.size(); i++)
			res -= getCount(ps[i].second-n+2, ps[i+1].first+n-2);
		if(ps.size())
			res -= getCount(ps.back().second-n+2, len-1);

		if(ps.empty())
			res = 0;

		cout << "Case #" << test << ": " << res << endl; 
	}
	


	return 0;
}