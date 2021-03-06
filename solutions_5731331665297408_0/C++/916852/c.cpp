#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <ctime>
using namespace std;

#define LL long long
#define mod 1000000007
#define eps 1e-8
#define mxn 55
#define mxe 20000

string s[55], ans;
int first[mxn], vv[mxe], nxt[mxe], e = 0, sta[55], top = 0;
int n;
bool vis[mxn], p[mxn], q[mxn];

void add( int u, int v ) {
    vv[e] = v; nxt[e] = first[u]; first[u] = e++;
}

void serach( int u, bool *p ) {
    p[u] = true;
    for( int i = first[u]; i != -1; i = nxt[i] ) {
        int v = vv[i];
        if( !p[v] && !vis[v] ) serach(v, p);
    }
}

bool ok( int v ) {
    //return false;
    //cout << "ok " << v << endl;
    if( vis[v] ) return false;
    memset(q, 0, sizeof(q));
    serach(v, q);
    for( int i = 1; i <= n; ++i )
        if( !vis[i] && p[i] && !q[i] )
            return false;
    return true;
}

void dfs( int u ) {
    sta[top++] = u;
    ans += s[u];
    vis[u] = true;
    if( top == n ) return ;
    string xx = "9999999";
    int id = -1;
    memset(p, 0, sizeof(p));
    for( int k = top - 1; k >= 0; --k ) {
        for( int i = first[sta[k]]; i != -1; i = nxt[i] ) {
            int v = vv[i];
            //cout << k << " " << i <<  endl;
            //cout << "u = " << sta[k] << " v = " << v << endl;
            if( ok(v) && s[v] < xx )
                xx = s[v], id = v;
        }
        serach(sta[k], p);
    }
    dfs(id);
}

int main()
{
    //freopen( "c.in", "r", stdin );
    //freopen( "c.out", "w", stdout );
    int t, cas = 0, m, u, v;
    cin >> t;
    while( t-- ) {
        cin >> n >> m;
        for( int i = 1; i <= n; ++i ) cin >> s[i];
        memset(first, -1, sizeof(first)); e = 0;
        while( m-- ) {
            scanf( "%d%d", &u, &v );
            add(u, v);
            add(v, u);
        }
        memset(vis, 0, sizeof(vis));
        string st = s[1];
        int cur = 1;
        for( int i = 1; i <= n; ++i ) if( s[i] < st ) st = s[i], cur = i;
        ans = "";
        top = 0;
        dfs(cur);
        printf( "Case #%d: %s\n", ++cas, ans.c_str() );
    }
    return 0;
}