#include <iostream>
#include <cstdio>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

#define mxn 200005
#define LL long long
#define MP make_pair
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)

char s[1005];

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    int t, cas = 0, n;

    scanf("%d", &t);
    while (t--) {
        scanf("%d%s", &n, &s);
        int ans = 0, tot = 0;
        REP(i, 0, n) {
            if (tot < i) ans += i - tot, tot = i;
            tot += s[i] - '0';
        }
        printf("Case #%d: %d\n", ++cas, ans);
    }
    return 0;
}