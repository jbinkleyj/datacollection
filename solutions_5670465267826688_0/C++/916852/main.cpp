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

char ss[10005];
char c[128][128];
int f[128][128];

void init() {
    string s = "1ijk";
    FOR(i, 0, 4) c['1'][s[i]] = c[s[i]]['1'] = s[i], c[s[i]][s[i]] = '1';
    c['i']['j'] = c['j']['i'] = 'k';
    c['i']['k'] = c['k']['i'] = 'j';
    c['k']['j'] = c['j']['k'] = 'i';
    f['i']['i'] = f['j']['j'] = f['k']['k'] = 1;
    f['i']['k'] = f['j']['i'] = f['k']['j'] = 1;
}

bool solve(string& s) {
    int flag = 1, pos = 0, n = s.size();
    char i = '1', j = '1', k = '1', l = '1';
    while (pos < n && i != 'i') flag ^= f[i][s[pos]], i = c[i][s[pos]], ++pos;
    if (i != 'i') return false;
    while (pos < n && j != 'j') flag ^= f[j][s[pos]], j = c[j][s[pos]], ++pos;
    if (j != 'j') return false;
    while (pos < n && k != 'k') flag ^= f[k][s[pos]], k = c[k][s[pos]], ++pos;
    if (k != 'k') return false;
    while (pos < n) flag ^= f[l][s[pos]], l = c[l][s[pos]], ++pos;
    if (l != '1') return false;
    return flag == 1;
}

int main()
{
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);

    int t, cas = 0, n, m;

    init();
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%s", &n, &m, ss);
        string s = "";
        if (m > 6) m = 6 + (m - 6) % 4;
        REP(i, 1, m) s += ss;
        printf("Case #%d: %s\n", ++cas, solve(s) ? "YES" : "NO");
    }
    return 0;
}