#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <complex>
#include <queue>
#include <functional>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)
#define next NEXTHUI
#define prev PREVHUI
#define y1 Y1HUI

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

int n, m;
int a[200][200];
int mx[200], my[200];

void solve() {
	cin >> n >> m;
	forn(i, n)
		forn(j, m)
			scanf("%d", &a[i][j]);
	forn(i, n) {
		mx[i] = 0;
		forn(j, m)
			mx[i] = max(mx[i], a[i][j]);
	}
	forn(j, m) {
		my[j] = 0;
		forn(i, n)
			my[j] = max(my[j], a[i][j]);
	}
	bool ok = 1;
	forn(i, n)
		forn(j, m)
			if (a[i][j] < mx[i] && a[i][j] < my[j])
				ok = 0;
	if (ok)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	int tt;
	cin >> tt;
	forn(ii, tt) {
		printf("Case #%d: ", ii + 1);
		solve();
	}	
	return 0;
}
