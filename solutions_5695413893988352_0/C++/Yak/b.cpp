// Cygwin clang++ 3.7.1 with -std=c++1z

#include <iostream>
#include <sstream>
#include <iomanip>

#include <iterator>

#include <algorithm>
#include <numeric>
#include <utility>
#include <limits>

#include <string>

#include <vector>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>

#include <tuple>
#include <initializer_list>

#include <cmath>

// Boost library can be retrieved from http://www.boost.org/
// 1.58 is used

#pragma GCC diagnostic ignored "-Wconversion"
#include <boost/range/irange.hpp>
#include <boost/range/iterator_range.hpp>
#pragma GCC diagnostic warning "-Wconversion"

typedef unsigned long long ULL;
typedef long long LL;
typedef unsigned long UL;
typedef unsigned int UI;
typedef unsigned short US;
typedef unsigned char UC;

#define RNG(v) (v).begin(), (v).end()
#define REP(v, e) for(UI v = 0U; v < e; ++v)
#define REP_(v, s, e) for(UI v = s; v < e; ++v)
#define REPV(v, e) for(v = 0; v < e; ++v)
#define REPV_(v, s, e) for(v = s; v < e; ++v)

using namespace std;

template<class Integer>
inline boost::iterator_range< boost::range_detail::integer_iterator<Integer> >
IR(Integer first, Integer  last)
{ return boost::irange(first, last); }

bool match(UI n, string s)
{
	REP(i, s.size()) {
		if(s[s.size()-i-1] != '?' && n%10 != s[s.size()-i-1]-'0') return false;
		n /= 10;
	}
	return true;
}

UI absd(UI n1, UI n2) { return n1 > n2 ? n1 - n2 : n2 - n1; }

int main(void)
{
	ios_base::sync_with_stdio(false);

	UI cases; cin >> cases;
	REP(casenum, cases) {
		string c,j; cin >> c >> j;
		const UI m = pow(10, c.size());
		UI rc = m, rj = m, rd = 2*m;
		REP(cc, m)  {
			if(!match(cc, c)) continue;
			REP(jj, m) {
				if(!match(jj, j)) continue;
				if(rd > absd(cc, jj) ||
				   (rd == absd(cc, jj) && rc > cc) ||
				   (rd == absd(cc, jj) && rc == cc && rj > jj)) {
					rd = absd(cc, jj); rc = cc; rj = jj;
				}
			}
		}
		cout << "Case #" << casenum+1 << ": " << setw(c.size()) << setfill('0') << rc << ' '
		                                      << setw(c.size()) << setfill('0') << rj << endl;
	}

	return 0;
}
