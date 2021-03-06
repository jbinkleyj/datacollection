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
#define ALL(c) (c).begin(), (c).end()

ll area(const pll& p0, const pll& p1, const pll& p2) {
    pll v1{p1.first-p0.first, p1.second-p0.second};
    pll v2{p2.first-p0.first, p2.second-p0.second};
    ll a = v1.first * v2.second - v2.first * v1.second;
    return a;
}

ll dot(const pll& p1, const pll& p2) {
    return p1.first * p2.first + p1.second * p2.second;
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
            pll org{0LL, 0LL};
            for (int i = 0; i < N; ++i) {
                int res = N-1;
                vector<pll> r;
                for (int j = 0; j < N; ++j) if (j != i)
                    r.emplace_back(p[j].first - p[i].first, p[j].second-p[i].second);

                bool sameLine = true;
                for (int i = 1; i < N-1; ++i) {
                    if (area(org, r[0], r[i]) != 0) {
                        sameLine = false;
                        break;
                    }
                }
                if (sameLine) {
                    out << 0 << endl;
                    continue;
                }

                sort(ALL(r), [&](const pll& p1, const pll& p2) {
                    if (p1.second >= 0 && p2.second < 0)
                        return true;
                    if (p1.second < 0 && p2.second >= 0)
                        return false;
                    ll a = area(org, p1, p2);
                    return a > 0 || 
                        (a == 0 && dot(p1, p2) < 0 && p1.first > 0) ||
                        (a == 0 && dot(p1, p2) > 0 && dot(p1, p1) < dot(p2, p2));
                });
                int j = 1;
                for (int start = 0; start < N-1; ++start) {
                    while (area(org, r[start], r[j]) >= 0) {
                        j = (j + 1) % (N-1);
                        if (j == start)
                            break;
                    }

                    res = min(res, ((start-j) % (N-1) + N-1) % (N-1));
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
