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
#define mxn 32000

LL dp[65][3][3];

int F( int pre, int cur, int lmt ) {
    if( cur < lmt ) return 0;
    if( cur > lmt ) return 2;
    return pre;
}

void upd( int cur, int pre, int k, int a, int b ) {
    if( k == 1 ) {
        for( int i = 0; i < 3; ++i )
            for( int j = 0; j < 3; ++j )
                dp[cur][F(i,1,a)][F(j,1,b)] += dp[pre][i][j];
    }
    else {
        for( int i = 0; i < 3; ++i ) {
            for( int j = 0; j < 3; ++j ) {
                dp[cur][F(i,1,a)][F(j,0,b)] += dp[pre][i][j];
                dp[cur][F(i,0,a)][F(j,1,b)] += dp[pre][i][j];
                dp[cur][F(i,0,a)][F(j,0,b)] += dp[pre][i][j];
            }
        }
    }
}

LL cal( LL a, LL b, int i, LL k, int zero ) {
    LL A = a >> i;
    LL B = b >> i;
    memset(dp, 0, sizeof(dp));
    if( A & 1 ) {
        if( B & 1 ) dp[0][1][0] = 1;
        else dp[0][1][1] = 1;
    }
    else {
        if( B & 1 ) dp[0][2][0] = 1;
        else dp[0][2][1] = 1;
    }
    if( zero ) {
        memset(dp[0], 0, sizeof(dp[0]));
        if( A & 1 ) {
            if( B & 1 ) dp[0][0][0] = 1;
            else dp[0][0][1] = 1;
        }
        else {
            if( B & 1 ) dp[0][1][0] = 1;
            else dp[0][1][1] = 1;
        }
    }
    int cur = 0;
    while( true ) {
        A >>= 1; B >>= 1; k >>= 1;
        if( !k && !A && !B ) break;
        ++cur;
        int pre = cur - 1;
        upd(cur, pre, k & 1, A & 1, B & 1);
    }
    LL ret = 0;
    a &= (1 << i) - 1;
    b &= (1 << i) - 1;
    ret += dp[cur][0][0] * (1 << i) * (1 << i);
    ret += dp[cur][0][1] * (1 << i) * (b + 1);
    ret += dp[cur][1][0] * (a + 1) * (1 << i);
    ret += dp[cur][1][1] * (a + 1) * (b + 1);
    return ret;
}

LL solve( LL a, LL b, LL k ) {
    int i = 0;
    LL ret = 0;
    while( k ) {
        int j = k & 1;
        if( j ) ret += cal(a, b, i, k, 0) + cal(b, a, i, k, 0) + cal(a, b, i, k, 1);
        k >>= 1;
        ++i;
    }
    return ret;
}

int main()
{
    //freopen( "B.in", "r", stdin );
    //freopen( "B.out", "w", stdout );
    int t, cas = 0, a, b, c;
    cin >> t;
    while( t-- ) {
        cin >> a >> b >> c;
        LL ans = solve(a - 1, b - 1, c);
        printf( "Case #%d: %lld\n", ++cas, ans );
    }
    return 0;
}