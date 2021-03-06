/*
Author :: MD. Musfiqur Rahman Sanim
Aust cse 28th Batch
ID:11.02.04.097
*/


//{ Template
using namespace std;
//{ C-headers
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cfloat>
#include <cctype>
#include <cassert>
#include <ctime>
//}
//{ C++-headers
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <utility>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
//}
//{ Loops
#define forab(i,a,b) for (__typeof(b) i = (a); i <= (b); ++i)
#define rep(i,n) forab (i, 0, (n) - 1)
#define For(i,n) forab (i, 1, n)
#define rofba(i,a,b) for (__typeof(b) i = (b); i >= (a); --i)
#define per(i,n) rofba (i, 0, (n) - 1)
#define rof(i,n) rofba (i, 1, n)
#define forstl(i,s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
//}
//{ Floating-points
#define EPS 1e-7
#define abs(x) (((x) < 0) ? - (x) : (x))
#define zero(x) (abs (x) < EPS)
#define equal(a,b) (zero ((a) - (b)))
#define PI 2*acos (0.0)
//}
typedef long long int64;
typedef unsigned long long int64u;
#define memo(a,v) memset(a,v,sizeof(a))
#define all(a) a.begin(),a.end()
#define db double
#define pb push_back
#define pii pair<int ,int >
#define NL puts("")
//{
//Intput_Output
#define II ({ int a; scanf("%d",&a); a;})
#define IL ({ int64 a; scanf("%lld",&a);  a;})
#define ID ({ db a; scanf("%lf",&a);  a;})
#define IC ({ char a; scanf("%c",&a);  a;})
#define IS ({ string a; cin >> a;  a;})
#define ICA(n) ({ char a[n]; scanf("%s",&a);  a;})
#define OC printf("Case #%d:",cs);
//}
//}
template <class T, class U> inline T max (T &a, U &b)
{
    return a > b ? a : b;
}
template <class T, class U> inline T min (T &a, U &b)
{
    return a < b ? a : b;
}
template <class T, class U> inline T swap (T &a, U &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

const int64 INF = (1ll)<<50;
const int mx = 1e5 + 7;
const int mod = 1000000007 ;
const db pi = PI;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}
bool vis[10];
vector<int >e[10];
vector<int >v;
int n,m;
string ans,zip[10];
bool cmp(int a,int b){
    return zip[a] < zip[b];
}

void call(int now,int take){
    if(take == n) return;
    vis[now] = true;
    bool flag = true;
    int len = e[now].size();
    rep(i,len){
        if(vis[e[now][i]]) continue;
        flag = false;
        ans += zip[e[now][i]];
        while(i<len-1) {
            v.pb(e[now][i+1]);
            i++;
        }
        call(e[now][i],take+1);
    }
    if(flag){
        int len = v.size();
        for(int i = len - 1;i >= 0;i--){
                if(vis[v[i]]) {
                    v.pop_back();
                    continue;
                }
                ans += zip[v[i]];
                call(v[i],take+1);
        }
    }


}

int main() {
#ifdef Sanim
    freopen ("in.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    int t = II;
    For(cs,t){
        n = II,m = II;
        For(i,n) cin >> zip[i];
        rep(i,m){
            int u = II,v = II;
            e[u].pb(v);
            e[v].pb(u);
        }
        For(i,n) sort(all(e[i]),cmp);
        int id = 1;
        string s = zip[1];
        For(i,n) if(s > zip[i]){
            s = zip[i];
            id = i;
        }
        ans = s;
        call(id,1);
        OC;
        cout << " " << ans << endl;
        For(i,n) e[i].clear();
        v.clear();
    }

}
