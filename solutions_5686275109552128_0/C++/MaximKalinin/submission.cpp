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


class Solution {
public:
    void solve(std::istream& in, std::ostream& out) {
        int T;
        in >> T;
        for (int test = 1; test <= T; ++test) {
            int D;
            in >> D;
            map<int, int> cnt;
            while (D --> 0) {
                int cakes;
                in >> cakes;
                cnt[cakes]++;
            }
            int res = cnt.rbegin()->first;
            int special = 0;
            while (cnt.rbegin()->first > 1) {
                int mx = cnt.rbegin()->first, sz = cnt.rbegin()->second;
                cnt.erase(mx);
                int x1 = mx/2, x2 = mx-x1;
                cnt[x1] += sz;
                cnt[x2] += sz;
                special += sz;
                res = min(res, special + cnt.rbegin()->first);
            }
            out << "Case #" << test << ": " << res << endl;
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
