/*
Some famous quotes about the greatest batsman on earth =>  <--------------SACHIN TENDULKAR------------------->
"I want my son to become Sachin Tendulkar."-Brian Lara(WI)
"We did not lose to a team called India, we lost to a man called Sachin."-Mark Taylor(AUS)
"There are 2 kinds of batsmen in this world. 1)Sachin Tendulkar 2)All of the others."-Andy Flower(ZIM)
"I have seen God. He bats at no.4 for India in tests."-Matthew Hayden(AUS)
"I see myself when i see Sachin batting."-Don Bradman(AUS)
"Commit you sins while Sachin is batting, for even the lord is watching"-(AUS fan)
"Sachin is a genius , i am a mere mortal!"-Brian Lara(WI)
"I would go to bed having nightemares of sachin dancing down the ground and hitting me for sixes."-Shane Warne(AUS)
"Don't bowl him bad balls, he hits the good ones for fours."-Michael Kasprowicz(AUS)
"Nothing bad can happen to us if we're on a plane in India with Sachin Tendulkar on it.(After terror attacks)"-Hashim Amla(RSA)
"I never get tired during umpiring whenever sachin is on crease"-Rudi Kortzen(umpire)
"Sachin Tendulkar! If he isn't the best player in the world, I want to see the best player in the world".-David Shepard(umpire)
"If cricket is religion, Sachin is god"-(all fans)
*/

// <-------TEMPLATE--------->
// Author: suh_ash2008
#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cassert>
#include <string.h>
using namespace std;
#define GI ({int t;scanf("%d",&t);t;})
#define GL ({LL t;scanf("%lld",&t);t;})
#define GD ({double t;scanf("%lf",&t);t;})
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define ROF(i,a,b) for(int i=a;i>b;i--)
#define SET(x,a) memset(x,a,sizeof(x))
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define tr(i,a) for(__typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define pb push_back
#define sz(a) (int)(a.size())
#define INF (int)1e9
#define EPS (double)1e-9
#define is istringstream
#define os ostringstream
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
typedef long long LL;
typedef unsigned long long ULL;
typedef pair< int,int > ii;
typedef pair< int,ii > pii;
typedef vector< ii > vii;
typedef vector < vii > vvii;
typedef vector< int > vi;
typedef vector< vi > vvi;
/*
// <----------------------FAST I/O---------------------->
#define MAXX 10000000
char *ipos,*opos,InpFile[MAXX],OutFile[MAXX],DIP[30];
inline int input_int(int flag=0){while(*ipos<=32)++ipos;if(flag)return(*ipos++-'0');int x=0,neg=0;char c;while(true){c=*ipos++;if(c=='-')neg=1;else{if(c<=32)return neg?-x:x;x=(x<<1)+(x<<3)+c-'0';}}}
inline LL input_LL(int flag=0){while(*ipos<=32)++ipos;if(flag)return(*ipos++-'0');LL x=0,neg=0;char c;while(true){c=*ipos++;if(c=='-')neg=1;else{if(c<=32)return neg?-x:x;x=(x<<1)+(x<<3)+c-'0';}}}
inline void input_st(char *s){while(*ipos<=32)++ipos;int pos=0;char c;while(true){c=*ipos++;if(c<=32){s[pos]='\0';break;}else s[pos++]=c;}}
inline char input_ch(){while(*ipos<=32)++ipos;char c=*ipos++;return c;}
inline void output(int x){int y;int dig=0;while(x||!dig){y=x/10;DIP[dig++]=x-((y<<3)+(y<<1))+'0';x=y;}while(dig--)*opos++=DIP[dig];}
inline void InitFASTIO(){ipos=InpFile;opos=OutFile;fread_unlocked(InpFile,MAXX,1,stdin);}
inline void FlushFASTIO(){fwrite_unlocked(OutFile,opos-OutFile,1,stdout);}
// <----------------------END OF FAST I/O---------------------->
*/
// <----------------------END OF TEMPLATE---------------------->

// <---------------------MAIN CODE STARTS HERE--------------------->

int n;
vvi G;

int main(){
	ifstream fin("Ain.txt");
	ofstream fout("Aout.txt");
	int t, kase = 0;
	fin >> t;
	while(t--){
		fin >> n;
		kase++;
		G.clear();
		G.resize(n);
		REP(i, n){
			int m, u;
			fin >> m;
			REP(j, m){
				fin >> u;
				u--;
				G[i].pb(u);
			}
		}
		
		bool ok = false;
		REP(src, n){
			queue <int> q;
			vi d(n, 0);
			q.push(src);
			d[src]++;
			while(!q.empty()){
				int u = q.front();
				q.pop();
				REP(j, sz(G[u])){
					d[ G[u][j] ]++;
					if(d[ G[u][j] ] == 1)	q.push(G[u][j]);
				}
			}
			REP(i, n)	if(d[i] > 1)	{ok = true; break;}
			if(ok)	break;
		}
		fout << "Case #" << kase << ": ";
		if(ok)	fout << "Yes\n";
		else fout << "No\n";
	}
	fin.close();
	fout.close();
    return 0;
}
