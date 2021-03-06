#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <set>
#include <algorithm>
#include <utility>
#include <functional>
#include <numeric>
#include <cmath>
#include <string>
#include <cctype>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef istringstream ISS;

#define ALL(x) ((x).begin()),((x).end())
#if __cplusplus >= 201103L
#define FOR(i,c) for(auto i=c.begin(); i!=c.end(); ++i)
#define REP(i,n) for(decltype(n) i=0; i<(n); ++i)
#else
#define FOR(i,c) for(typeof(c.begin()) i=c.begin(); i!=c.end(); ++i)
#define REP(i,n) for(typeof(n) i=0; i<(n); ++i)
#endif

const int infty = 999999999;

template<class T> void minimize(T &a, T b) { a = min(a,b); }
template<class T> void maximize(T &a, T b) { a = max(a,b); }

#define DEBUGGING 1

#if defined(DEBUGGING)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#else
#define debug(...)
#endif

int R,N,M,K;
VI prod, facts, nums;

const int primes[4] = {2,3,5,7};

int main()
{
	srand(1);

	int nruns;
	cin >> nruns; // == 1;
	cout << "Case #1:\n";

	cin >> R >> N >> M >> K;

	REP(i,R) {
		nums = VI();
		prod = VI(K);
		facts = VI(4,0);
		REP(j,K) {
			VI currfacts(4,0);
			int p;
			cin >> p;
			prod[j] = p;

			REP(k,4) while ( p%primes[k]==0 ) { currfacts[k]++; p /= primes[k]; }
			REP(k,4) maximize(facts[k],currfacts[k]);
	    }

		REP(k,facts[1]) {
			if ( rand()%2 && M>=6 ) {
				nums.push_back(6);
				facts[0]--;
			} else {
				nums.push_back(3);
			}
		}

		for(int k=2; k<4; k++) {
			while ( facts[k]>0 ) { nums.push_back(primes[k]); facts[k]--; }
		}

		if ( nums.size()+facts[0]<N ) facts[0] += N-nums.size();
		if ( nums.size()<N ) facts[0] += rand()%(N-nums.size());

		while ( nums.size()<N ) {
			int pmax = facts[0]-(N-nums.size()-1);
			if ( pmax<1 ) pmax = 1+rand()%3;
			int p = 1 + rand()%pmax;
			if ( nums.size()+1==N ) p = pmax;
			debug("p = %d / %d\n",p,pmax);
			nums.push_back(1<<p);
			facts[0] -= p;
		}

		if ( nums.size()!=N ) {
			debug("error: #nums = %d != %d\n",nums.size(),N);
			return 0;
		}

		REP(j,N) {
			if ( nums[j]<2 || nums[j]>M ) nums[j] = 2;
			cout << nums[j];
		}
		cout << endl;
	}

	return 0;
}
