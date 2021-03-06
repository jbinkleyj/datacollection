#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <ctime>
#include <functional>

using namespace std;

#define CLR(a,x) memset(a,x,sizeof a)
#define LL long long
#define ALL(v) v.begin(),v.end()
#define FR(i,n) for(LL i=0;i<(LL)n;i++)
#define FAB(i,a,b) for(LL i=(LL)a;i<(LL)b;i++)
#define FBA(i,b,a) for(LL i=(LL)b;i>=(LL)a;i--)
#define IIN(x) scanf("%d",&x)
#define IIN2(x,y) scanf("%d%d",&x,&y)
#define LIN(x) scanf("%I64d",&x)
#define LIN2(x,y) scanf("%I64d%I64d",&x,&y)
#define EXIT(n) {cout<<n<<endl;return 0;}
#define PII pair<int,int>
#define PPI pair<PII,int>
#define PLL pair<LL,LL>
#define PDD pair<double,double>
#define PDI pair<double,int>
#define PIS pair<int,string>
#define PSI pair<string,int>
#define PI 3.141592653589793238
#define VI vector<int>
#define VLL vector<long>
#define VS vector<string>
#define SI set<int>
#define SLL set<LL>
#define SIP set<PIP>
#define SS set<string>
#define MII map<int,int>
#define MLL map<LL,LL>
#define MSI map<string,int>
#define MSL map<string,LL>
#define MIS map<int,string>
#define INF 100000000000000000
#define MOD 1000000007
#define MAX 1000+1

int tc;
int n,mn,ch[MAX],par[MAX];
VI adj[MAX];
SI s;

void input()
{
	IIN(n);
	FR(i,n) adj[i].clear();
	FR(i,n-1)
	{
		int x,y; IIN2(x,y);
		x--; y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}

void DFS(int v)
{
	s.insert(v);
	FR(i,adj[v].size())
	{
		int u=adj[v][i];
		if(u!=par[v]) 
		{
			par[u]=v;
			DFS(u);
		}
	}
}

void dfs(int v)
{
	FR(i,adj[v].size())
	{
		int u=adj[v][i];
		if(u!=par[v]) 
		{
			par[u]=v;
			dfs(u);
			ch[v]++;
		}
	}
	if(ch[v]==1)
	{
		if(adj[v][0]!=par[v]) DFS(adj[v][0]);
		else DFS(adj[v][1]);
	}
	if(ch[v]>2)
	{
		ch[v]=0;
		vector<PII> p;
		FR(i,adj[v].size())
		{
			int u=adj[v][i];
			if(u==par[v]) continue;
			ch[v]+=(ch[u]+1);
			p.push_back(PII(ch[u],u));
		}
		sort(ALL(p));
		FR(i,p.size()-2)
		{
			DFS(p[i].second);
		}
	}
}

void solve()
{
	mn=MAX+10;
	FR(i,n)
	{
		CLR(par,-1);
		CLR(ch,0);
		s.clear();
		dfs(i);
		mn=min(mn,(int)s.size());
	}
}

void output(int q)
{
	cout<<"Case #"<<q+1<<": "<<mn<<endl;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	cin>>tc;
	FR(q,tc)
	{
		input();
		solve();
		output(q);
	}

	return 0;
}