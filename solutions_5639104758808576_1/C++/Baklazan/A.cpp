#include<cstdio>
#include<iostream>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;

#define inf 1023456789
#define linf 1023456789123456789ll
#define pii pair<int,int>
#define pipii pair<int, pii >
#define pll pair<long long,long long>
#define vint vector<int>
#define vvint vector<vint >
#define ll long long
#define pdd pair<double, double>

#define DEBUG
#ifdef DEBUG
#define db(x) cerr << #x << " = " << x << endl
#else
#define db(x)
#endif

int main()
{
	int t;
	scanf("%d",&t);
	for(int testcase = 0; testcase < t; testcase++)
	{
		int s;
		scanf("%d",&s);
		int res = 0;
		int mam = 0;
		for(int i=0; i<=s; i++)
		{
			char c;
			scanf(" %c",&c);
			int x = c - '0';
			if(mam < i)
			{
				res += i-mam;
				mam = i;
			}
			mam += x;
		}
		printf("Case #%d: %d\n",testcase+1,res);
	}
	
	return 0;
}