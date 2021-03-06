#include <algorithm>
#include <iomanip>
#include <istream>
#include <map>
#include <ostream>
#include <set>
#include <sstream>
#include <utility>
#include <vector>
using namespace std;
// Solution template generated by caide

typedef long long ll;
typedef pair<ll, ll> pll;

ll area(const pll& p0, const pll& p1, const pll& p2) {
    pll v1{p1.first-p0.first, p1.second-p0.second};
    pll v2{p2.first-p0.first, p2.second-p0.second};
    ll a = v1.first * v2.second - v2.first * v1.second;
    return a;
}


class Solution {
public:
    void solve(std::istream& in, std::ostream& out) {
        int T;
        in >> T;
        for (int test = 1; test <= T; ++test) {
            int N;
            in >> N;
            vector<pll> p(N);
            for (pll& pt : p)
                in >> pt.first >> pt.second;
            out << "Case #" << test << ":" << endl;
            if (N == 1) {
                out << 0 << endl;
                continue;
            }
            for (int i = 0; i < N; ++i) {
                int res = N-1;
                for (int j = 0; j < N; ++j) if (j != i) {
                    int pos = 0, neg = 0;
                    for (int k = 0; k < N; ++k) if (k != i && k != j) {
                        ll a = area(p[i], p[j], p[k]);
                        if (a > 0)
                            ++pos;
                        else if (a < 0)
                            ++neg;
                    }
                    int cur = min(pos, neg);
                    res = min(res, cur);
                }
                out << res << endl;
            }
        }
    }
};

void solve(std::istream& in, std::ostream& out)
{
    out << std::setprecision(12);
    Solution solution;
    solution.solve(in, out);
}
#include <fstream>
#include <iostream>

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    istream& in = cin;

    ostream& out = cout;
    solve(in, out);
    return 0;
}
