#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
#include <complex>
using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979
#define x0 ikjnrmthklmnt
#define y0 lkrjhkltr
#define y1 ewrgrg

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<Int, Int> PLL;
typedef pair<double, double> PDD;
typedef complex<double> base;

const int INF = 1000000000;
const int BASE = 1000000007;
const int MAX = 100000;
const int MAX2 = 7777;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 800;

const double eps = 1e-6;

int t, n;
bool used[20];
int num;

void tadd(int val)
{
	while (val)
	{
		//cout << used[val % 10]<<" "<<val % 10 << " " << val << " " << num << endl;
		if (!used[val % 10])
		{
			num++;
			used[val % 10] = 1;
		}
		val /= 10;
	}
}

int main()
{
	freopen("in.in", "r", stdin);
	//freopen("/Users/Taras/Downloads/constellation.in",  "r", stdin);
	//freopen("/Users/Taras/Downloads/constellationANS.txt", "w", stdout);
	freopen("out.txt" , "w" , stdout);

	cin >> t;
	FOR (tst, 0, t)
	{
		cin >> n;
		cerr << tst << endl;
		FILL(used, 0);
		num = 0;
		printf("Case #%d: ", tst + 1);
		int ok = 0;
		FOR(i, 1, 1001)
		{
			tadd(i*n);
			if (num == 10)
			{
				ok = i;
				break;
			}
		}
		if (ok) cout << ok*n << endl;
		else cout <<"INSOMNIA\n";
	}
	return 0;
}