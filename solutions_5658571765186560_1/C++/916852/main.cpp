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

bool solve(int x, int r, int c) {
    if (x >= 7) return true;
    if (r * c % x != 0) return true;
    if (r > c) swap(r, c);
    if (c < x || r < (x + 1) / 2) return true;
    if (x <= 3) return false;
    return r == 2;
}

int main()
{
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);

    int t, cas = 0, x, r, c;

    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &x, &r, &c);
        printf("Case #%d: %s\n", ++cas, solve(x, r, c) ? "RICHARD" : "GABRIEL");
    }
    return 0;
}