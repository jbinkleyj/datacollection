#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <string>
#include <utility>

#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>

#include <stdio.h>
#include <cstring>

#include <stdlib.h>
#include <time.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int UI;
typedef unsigned char UC;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<UI> VUI;

#define DEBUG 1
#define F(i,n) for(int i=0;i<n;i++)
#define FOR(i,s,n) for(int i=s;i<n;i++)
#define FORE(i,s,n) for(int i=s;i<=n;i++)
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? (-1*(a)) : (a))
#define INSET(s, e) ((s).find(e) != (s).end())
#define INMAP(s, e) ((s).find(e) != (s).end())
#define TRACE(v) (cout << "TRACE(" << #v << "): " << v << endl)
#define TRACE1D(v,s) { cout << "TRACE1D(" << #v << ", " << (s) << "): "; F(i,s) cout << (v)[i] << " "; cout << endl; }
#define TRACE2D(v,s1,s2) { cout << "TRACE2D(" << #v << ", " << (s1) << ", " << (s2) << "): "; F(i,s1) { cout << endl << "\t"; F(j,s2) cout << v[i][j] << " "; } cout << endl; }
#define TRACE2DS(v) { cout << "TRACE2DS(" << #v << "): "; F(i,v.size()) { cout << endl << "\t"; F(j,v[i].size()) cout << v[i][j] << " "; } cout << endl; }
#define FOREACH(it, s) for (auto it = s.begin(); it != s.end(); it++)

#define MAXLEN 111

ULL charToUI(char Achar[MAXLEN]) {
    ULL num = 0, c = 0;
    while (Achar[c] != '\0') {
        num *= 10;
        num += Achar[c] - '0';
        c++;
    }

    return num;
}

bool isPalindrome(ULL num) {
    UC D[20], dc = 0;
    while (num) {
        D[dc++] = num % 10;
        num /= 10;
    }

    UC a = 0, b = dc - 1;
    while (a < b) {
        if (D[a] != D[b]) {
            return false;
        }
        a++;
        b--;
    }

    return true;
}

UI getFairandSquareCountBF(char Achar[MAXLEN], char Bchar[MAXLEN]) {
    ULL A = charToUI(Achar), B = charToUI(Bchar);
    ULL Asqrt = sqrt(A), Bsqrt = sqrt(B);

    UI c = 0;
    FOR(i,Asqrt,Bsqrt + 1) {
        ULL Isq = ((ULL)i) * ((ULL)i);
        if (Isq >= A && Isq <= B && isPalindrome(i) && isPalindrome(Isq)) {
            //TRACE(i);
            //TRACE(Isq);
            c++;
        }
    }

    return c;
}

UI getFairandSquareCount(char A[MAXLEN], char B[MAXLEN]) {

    return 0;
}

void solve(char *in, char *out) {
    if (in != NULL) {
        freopen(in, "r", stdin);
    }

    if (out != NULL) {
        freopen(out, "w", stdout);
    }

    UI t;
    cin >> t;
    FOR(i,1,t + 1) {
        char A[MAXLEN], B[MAXLEN];
        cin >> A >> B;
        //cout << "Case #" << i << ": " << getFairandSquareCount(A, B) << endl;
        cout << "Case #" << i << ": " << getFairandSquareCountBF(A, B) << endl;
    }
}

void assert(bool b, const char *msg = NULL) {
    static int test = 0;
    test++;

    if (!b) {
        if (msg == NULL) {
            cout << "Error :: " << test << endl;
        } else {
            cout << "Error :: " << test << " :: " << msg << endl;
        }
    }
}

void tests() {

}

int main(int argc, char **argv) {
    //srand(time(NULL));
    char *in, *out;
    if (argc == 3) {
        in = argv[1];
        out = argv[2];
    } else {
        in = NULL;
        out = NULL;
    }

    tests();
    solve(in, out);
    return 0;
}

