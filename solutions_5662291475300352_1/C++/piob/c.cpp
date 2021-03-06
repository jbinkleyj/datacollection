#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define SIZE(a) ((int)(a).size())
#define VAR(x) #x ": " << x << " "
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define gcd __gcd
#define x first
#define y second
#define st first
#define nd second
#define pb push_back

using namespace std;

template<typename T> ostream& operator<<(ostream &out, const vector<T> &v){ out << "{"; for(const T &a : v) out << a << ", "; out << "}"; return out; }
template<typename S, typename T> ostream& operator<<(ostream &out, const pair<S,T> &p){ out << "(" << p.st << ", " << p.nd << ")"; return out; }

typedef long long LL;
typedef pair<int, int> PII;
typedef long double K;
typedef vector<int> VI;

const int dx[] = {0,0,-1,1}; //1,1,-1,1};
const int dy[] = {-1,1,0,0}; //1,-1,1,-1};

int n, k;
int D[500010];
LL M[500010];

LL calc(LL t){
	LL r = 0;
	FWD(i,0,k){
		LL f = (360 - D[i]) * (M[i] / 360);
		if(f >= t){
			r += 1;
		}else{
			r += (t - f) / M[i];
		}
	}
	return r;
}

vector<LL> T;

int solve(){
	T.clear();
	k = 0;
	scanf("%d", &n);
	FWD(r,0,n){
		int d, h, m;
		scanf("%d %d %d", &d, &h, &m);
		FWD(i,0,h){
			D[k+i] = d;
			M[k+i] = m + i;
		}
		k += h;
	}
	FWD(i,0,k){
		M[i] *= 720;
		T.push_back((360 - D[i]) * (M[i] / 360) + 1);
	}
	int res = k;
	for(LL t : T){
		LL c = calc(t);
		if(c < res)
			res = (int)c;
	}
	return res;
}

int main(){
	int z;
	scanf("%d", &z);
	FWD(cas,1,z+1) printf("Case #%d: %d\n", cas, solve());
	return 0;
}
