#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef unsigned int uint;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mii;

// Input macros
#define RI                          ({int a; scanf("%d", &a); a;})
#define RL                          ({long long a; cin >> a; a;})
#define RS                          ({string a; cin >> a; move(a)})
#define RD                          ({double a; scanf("%lf", &a); a;})
#define RC                          ({char a; cin >> a; a;})

// Useful constants
const int INF =                     numeric_limits<int>::max();
const int HINF =                    (INF/2-1);
const double EPS =                     1e-9;
const int dy [] =                   {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx [] =                   {0, 1, 1, 1, 0, -1, -1, -1};
const double pi =                      3.1415926535897932384626;

// Useful hardware instructions
#define bitcount                    __builtin_popcount
#define gcd                         __gcd
#define bitfirst                    __builtin_ctz // count trailing zeros
#define bitlast                     __builtin_clz // count leading zeros

// Useful comparation
#define bet(x,a,b) (a<x&&x<b)
#define beti(x,a,b) (a<=x&&x<=b)
#define remax(a,b) (a)=max((a),(b)) // set a to the maximum of a and b
#define remin(a,b) (a)=min((a),(b));

// Useful container manipulation / traversal macros
#define rep(i,a,b)               for(int i=a;i<b;i++)
#define repi(i,a,b)              for(int i=a;i<=b;i++)
#define rrep(i,a,b)              for(int i=a;i>b;i--)
#define rrepi(i,a,b)             for(int i=a;i>=b;i--)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define ms(a,v)                     memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))
#define mp                          make_pair

// Bit ops
#define bit(x,i) ((x>>i)&1ull)  //select the bit of position i of x
#define bitset(x, i) (x|(1ull<<i))
#define bittog(x, i) (x^(1ull<<i))
#define bitclear(x,i) (x&(0ull<<i))
#define lowbit(x) ((x)&((x)^((x)-1))) //get the lowest bit of x


// Global Variables and Constants
long long mk[100001];
long long n, b;
//

long long compute(long long x){
	long long cnt = 0;
	for(long long i = 1; i <= b; i++){
		cnt += x / mk[i] + 1;
	}
	return cnt;
}

bool ok(long long x){
	return compute(x) >= n;
}
void solve(int tn){
	scanf("%lld%lld", &b, &n);
	long long max_mk = 0;
	for(int i = 1; i <= b; i++) scanf("%lld", mk+i), max_mk = max(max_mk, mk[i]);
	
	long long ans = 0;
	if(n <= b)
		ans = n;
	else{
		long long l = 0, r = max_mk*n;
		while(l < r){
			long long m = (l+r)/2;
			if(ok(m))
				r = m;
			else l = m+1;
		}
		
		long long delta = compute(l)-n+1;
		for(long long i = b, j = 0; i >= 1; i--){
			if(l % mk[i] == 0) j++;
			if(j == delta){
				ans = i;
				break;
			}
		}
	}
	
	printf("Case #%d: %lld\n", tn, ans);
}

int main(){
	int tt; scanf("%d", &tt);
	for(int t = 1; t <= tt; t++)
		solve(t);
}
