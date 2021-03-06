#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<ctime>	// srand( time(NULL) )
#include<iostream>
#include<iomanip>
#include<sstream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<utility>
#include<algorithm>
#include<map>
#include<set>
#include<bitset>
#include<climits>

using namespace std;

// Typedefs
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair< int, pair<int, int> > iii;
typedef vector<iii> viii;
typedef vector< vector<int> > vvi;
typedef vector< vector<ii> > vvii;
typedef vector< vector<iii> > vviii;

// Macros
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define FORR(i, a) for(int i = 0; i < a; ++i)
#define FORE(i, a, b) for(int i = a; i >= b; --i)
#define all(v) v.begin(), v.end()
#define sz(A) int((A).size())
#define pb push_back
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define LSOne(S) (S & (-S)) // bit menos significativo
#define first(x) x.first	// lidam com triplas
#define second(x) x.second.first
#define third(x) x.second.second
#define CLR(x, a) memset(x, a, sizeof(x))

// Constantes
const double PI = 2*asin(1.0);
const int INF = 1000000000;	// 9 zeros
const double EPS = 1e-10;

// Matematica basica
inline int cmp(double x, double y = 0, double tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1; }
inline ll gcd(ll n1, ll n2) {return n2==0? abs(n1) : gcd(n2,n1%n2);}	// MUDAR PARA O PKU!
inline ll lcm(ll n1, ll n2) {return n1==0||n2==0? 0 : abs(n1*(n2/gcd(n1,n2)));}	// MUDAR PARA O PKU!

int r, n, m, k, qtd;
vi res[10000];

void go(int idx, vi cur) {
	if(idx >= n) {
		res[qtd++] = cur;
		return;
	}
	FOR(i, 2, m+1) {
		vi aux = cur;
		aux.pb(i);
		go(idx+1, aux);
	}
}

void guess(const vi &prod) {
	double prob = 0.0;
	int idx = 0;
	FORR(i, qtd) {
		vi sub;
		sub.pb(1);
		sub.pb(res[i][0]);
		sub.pb(res[i][1]);
		sub.pb(res[i][2]);
		sub.pb(res[i][0] * res[i][1]);
		sub.pb(res[i][0] * res[i][2]);
		sub.pb(res[i][1] * res[i][2]);
		sub.pb(res[i][0] * res[i][1] * res[i][2]);
		
		double myprob = 1.0;
		FORR(j, sz(prod)) {
			int count = 0;
			FORR(k, sz(sub)) if(sub[k] == prod[j]) count++;
			myprob *= double(count) / double(sz(sub));
		}
		
		if(myprob > prob) {
			prob = myprob;
			idx = i;
		}
	}
	
	FORR(i, sz(res[idx])) cout << res[idx][i];
	cout << endl;
}

int main() {
	int tests = 0;
	scanf("%d ", &tests);
	
	FORR(caseNum, tests) {
		printf("Case #%d:\n", caseNum+1);
		
		cin >> r >> n >> m >> k;
		qtd = 0;
		vi a;
		go(0, a);
		
		FORR(i, r) {
			vi prod(k);
			FORR(j, k) cin >> prod[j];
			guess(prod);
		}
	}

	return 0;
}
