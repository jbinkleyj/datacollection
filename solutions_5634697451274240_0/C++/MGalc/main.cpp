#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <string>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>

using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz size()
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define rep2(i,n,m) for(int i=n;i<(int)(m);i++)
#define For(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define dot(a,b) ((conj(a)*(b)).X)
#define X real()
#define Y imag()
#define vect(a,b) ((b)-(a))
#define cross(a,b) ((conj(a)*(b)).imag())
#define normalize(v) ((v)/length(v))
#define rotate(p,about,theta) ((p-about)*exp(point(0,theta))+about)
#define pointEqu(a,b) (comp(a.X,b.X)==0 && comp(a.Y,b.Y)==0)

typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vii;
typedef long long ll;
typedef long double ld;
typedef complex<double> point;
typedef pair<point, point> segment;
typedef pair<double, point> circle;
typedef vector<point> polygon;

const int oo = (int) 1e9;
const double PI = 2 * acos(0);
const double eps = 1e-9;

inline int comp(const double &a, const double &b) {
    if (fabs(a - b) < eps)
        return 0;
    return a > b ? 1 : -1;
}

int di[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dj[] = { 0, 0, 1, -1, 1, -1, -1, 1 };
int diK[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
int djK[] = { -1, 1, 2, 2, 1, -1, -2, -2 };

int I, J;

inline bool val(const int &i, const int &j) {
    if (i < 0 || j < 0 || i >= I || j >= J)
        return false;
    return true;
}

inline void flip(string& str, int val)
{
    string tmp = str;
    for (int i = 0; i <= val; i++)
    {
        if (tmp[i] == '-')
            str[val - i] = '+';
        else
            str[val - i] = '-';
    }
}

int N;
int main(int argc, char *args[]) {
    if (argc == 2 && strcmp(args[1], "small") == 0) {
        freopen("small.in", "rt", stdin);
        freopen("small.out", "wt", stdout);
    }
    else if (argc == 2 && strcmp(args[1], "large") == 0) {
        freopen("large.in", "rt", stdin);
        freopen("large.out", "wt", stdout);
    }
    else {
        freopen("a.txt", "rt", stdin);
    }

    cin >> N;
    rep2(nn, 1, N + 1) {
        printf("Case #%d: ", nn);

        ///////////////////////////////////////////////////////////////

        string input;
        cin >> input;
        string temp;
        getline(cin, temp);

        int flips = 0;

        bool done = false;
        int index = 0;
        char prev = input[0];
        for (int i = 1; i < input.length(); i++)
        {
            if (input[i] != prev)
            {
                flips++;
                prev = input[i];
            }
        }

        if (input[input.length() - 1] == '-')
            flips++;
        /*while (!done)
        {
            if (input[index] == '+')
            {
                size_t locneg = input.find_first_of('-');
                if (locneg == string::npos)
                {
                    done = true;
                }
                else 
                {
                    flip(input, locneg - 1);
                    index = locneg;
                    flips++;
                }
            }
            else
            {
                size_t locpos = input.find_first_of('+');
                if (locpos == string::npos)
                {
                    flip(input, input.size() - 1);
                    flips++;
                    done = true;
                }
                else 
                {
                    flip(input, locpos - 1);
                    index = locpos;
                    flips++;
                }
            }
            cout << input << endl;
        }
        */
        cout << flips;

        end:
        ///////////////////////////////////////////////////////////////
        cout << endl;
    }

    return 0;
}