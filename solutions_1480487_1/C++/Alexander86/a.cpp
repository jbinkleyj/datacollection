
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)

double inp[500];
int main() {
	int tc;
	cin >> tc;
	FOR(tcc,1,tc+1){
		int N;
		cin >> N;
		FOR(i,0,N)cin >> inp[i];
		double sum = 0;
		FOR(i,0,N)sum+=inp[i];
		cout << "Case #" << tcc <<":";
		FOR(n,0,N){
			double lo = 0, hi = 1.0;
			while(hi - lo > eps){
				double cur = lo + (hi - lo) * 0.5;
				double pts = inp[n] + cur * sum;
				double need = pts - inp[n];
				FOR(i,0,N)if(i!=n){
					if(inp[i] < pts){
						need += pts - inp[i];
					}
				}
				if(need > sum)hi = cur;
				else lo = cur;
			}
			printf(" %.7lf",lo * 100.0);
		}
		cout << endl;
	}
	return 0;
}
