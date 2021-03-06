/*****************************************************************************************/
/*																		     			 */
/*  					Adarsh Pugalia 										 			 */
/*																			 			 */
/*****************************************************************************************/
 
#include <bits/stdc++.h>

/* Data types and structures. */
#define ll long long int
#define llu long long int unsigned
#define vi vector <int>
#define vl vector <ll> 
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector <pii >
#define vpll vector <pll >
 
/* Data structure helpers. */ 
#define f first
#define s second
#define pb push_back
#define pob pop_back
#define mp make_pair
#define sz(n) (int)n.size()-1
#define all(n) n.begin(), n.end()
#define has(it,s) if(it!=s.end())
 
/* Input output defines. */
#define sd(n) scanf("%d", &n)
#define sl(n) scanf("%lld", &n)
#define slf(n) scanf("%lf", &n) 
#define pd(n) printf("%d", n);
#define pl(n) printf("%lld", n);
#define plf(n) printf("%0.9lf", n);
#define ps printf(" ")
#define pe printf("\n")

/* loops */
#define rep(i,j,k) for(int i=j; i<=k; i++)
#define repd(i,j,k) for(int i=j; i>=k; i--)
#define iter(it, s) for(auto it=s.begin(); it!=s.end(); it++)

/* constraints. */ 
#define max_size 100005
#define max_sieve_size 1000005
#define max_matrix_size 100
#define max_log 17
#define INF 1000000000000000000
#define MOD 1000000007
#define EPS 0.0000000001
#define GCD_EPS 0.0001
#define PI 3.14159265358979323846
#define mod(a) ((a)%MOD)

#define bcnt __builtin_popcount 

ll ciel(double a) { ll ret = a; if(a-ret>EPS) ret++; return ret; }
ll gcd(ll a, ll b) { if(a<b)return gcd(b, a); if(a%b==0)return b; return gcd(b, a%b); }
ll pow(ll n, ll p) {if(p==0)return 1; if(n<=1)return n;ll res = 1;while(p){if(p&1) res = mod(res*n);n = mod(n*n);p /= 2;} return res;}

double fgcd(double a, double b) { if(fabs(a)<fabs(b)) return fgcd(b, a); if(fabs(b)<GCD_EPS) return a; return fgcd(b, fmod(a,b)); }

bool db_db_cmp(double a, double b) { return (a+EPS>b && a-EPS<b); }
 
using namespace std;

void preprocess() {
}

void init() {
}

pair<string, string> topics[20];
set<string> first;
set<string> second;
vector<int> to_check;

void solve(int test_case) {
	init();
	cout<<"Case #"<<test_case<<": ";

	int n;
	sd(n);


	rep(i,0,n-1) {
		cin>>topics[i].f>>topics[i].s;
	}

	int ans = 0;
	for(int mask = 0; mask<(1<<n); mask++) {
		int temp = mask;

		first.clear();
		second.clear();
		to_check.clear();

		int temp2 = 0;
		for(int i=0; i<n; i++) {
			int cur = temp%2;
			if(cur==1) {
				first.insert(topics[i].f);
				second.insert(topics[i].s);
			}
			else {
				to_check.pb(i);
				temp2++;
			}

			temp /= 2;
		}

		int flag2 = 1;
		for(int i=0; i<temp2; i++) {
			int flag = 0;
			rep(j,0,sz(to_check)) {
				if(to_check[j]>=0) {
					if(first.find(topics[to_check[j]].f)!=first.end() && second.find(topics[to_check[j]].s)!=second.end()) {
						flag = 1;
						to_check[j] = -1;
						break;
					}
				}
			}

			if(!flag) {
				flag2 = 0;
				break;
			}
		}

		if(flag2 && temp2>ans)
			ans = temp2;
	}

	cout<<ans<<endl;
}

int main() {
	preprocess();
	int t = 1;
	sd(t);

	// cout<<check(1, "1?")<<endl;
	// return 0;
 
	rep(i,1,t) {
		solve(i);
	}
	return 0;
}
