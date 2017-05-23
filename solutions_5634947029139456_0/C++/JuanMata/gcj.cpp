#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <complex>
#include <utility>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>

using namespace std;


typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef pair<int,int> PII;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define REV(i,a,b) for(int i=a-1;i>=b;i--)
#define rev(i,n) REV(i,n,0)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define GI ({ int x; scanf("%d",&x); x; })
#define GLL ({ LL x; scanf("%lld",&x); x; })
#define ALL(v) v.begin(),v.end()
#define PB push_back
#define MP make_pair
#define PQ priority_queue
#define inf (int)(1e9)
#define linf (LL)(1e18)
#define eps (double)(1e-9)
#define leps (LD)(1e-18)
#define PI (double)(3.141592653589793238)


int n,l;
string o[155],d[155];

char flip(char c)
{
	return (c=='0'?'1':'0');
}

bool check(int mask)
{
	string t[155];
	rep(i,n)
		rep(j,l)
		{
			if(mask&(1<<j))
				t[i].PB(flip(o[i][j]));
			else
				t[i].PB(o[i][j]);
		}
	map<string,int> cnt;
	rep(i,n)
		cnt[t[i]]++,cnt[d[i]]--;
	TR(it,cnt)
		if(it->second)
			return 0;
	return 1;
}

void solve(int t)
{
	cin>>n>>l;
	rep(i,n)
		cin>>o[i];
	rep(i,n)
		cin>>d[i];
	int ans=55;
	rep(i,(1<<l))
		if(check(i))
			ans=min(ans,__builtin_popcount(i));
	if(ans==55)
		cout<<"Case #"<<t<<": NOT POSSIBLE\n";
	else
		cout<<"Case #"<<t<<": "<<ans<<'\n';
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	REP(i,1,t+1)
		solve(i);
	return 0;
}