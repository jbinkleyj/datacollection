#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
#include <list>
#include <iomanip>

#if __cplusplus >= 201103L
#include <array>
#include <tuple>
#include <initializer_list>
#include <unordered_set>
#include <unordered_map>
#include <forward_list>

#define cauto const auto&
#endif

using namespace std;


namespace{

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

#define VV(T) vector<vector< T > >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
	v.assign(a, vector<T>(b, t));
}

template <class F, class T>
void convert(const F &f, T &t){
	stringstream ss;
	ss << f;
	ss >> t;
}


#define REP(i,n) for(int i=0;i<int(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define PB push_back


#define MOD 1000000009LL
#define EPS 1e-8


void prepare(){
	
}


pll solve(){
	int n;
	cin >> n;
	vll m(n);
	for(int i = 0; i < n; ++i){
		cin >> m[i];
	}
	LL y = 0, z = 0;
	LL r = 0;
	for(int i = 1; i < n; ++i){
		r = max(r, m[i - 1] - m[i]);
	}
	for(int i = 1; i < n; ++i){
		y += max(m[i - 1] - m[i], 0LL);
		z += min(m[i - 1], r);
	}
	return pll(y, z);
}


}
int main(){
	cout << fixed << setprecision(15);
	cerr << fixed << setprecision(6);
	prepare();

	int T = 0;
	cin >> T;
	for(int cnum = 1; cnum <= T; ++cnum){
		fprintf(stderr, "%4d / %d\n", cnum, T);
		cout << "Case #" << cnum << ": " << flush;
		auto ans = solve();
//		cout << ans << endl;
		cout << ans.first << ' ' << ans.second << endl;
	}
}
