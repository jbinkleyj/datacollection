// Artur Kraska, II UWr

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <list>
#include <set>
#include <map>

#define forr(i, n)                  for(int i=0; i<n; i++)
#define FOREACH(iter, coll)         for(typeof(coll.begin()) iter = coll.begin(); iter != coll.end(); ++iter)
#define FOREACHR(iter, coll)        for(typeof(coll.rbegin()) iter = coll.rbegin(); iter != coll.rend(); ++iter)
#define lbound(P,R,PRED)            ({typeof(P) X=P,RRR=(R), PPP = P; while(PPP<RRR) {X = (PPP+(RRR-PPP)/2); if(PRED) RRR = X; else PPP = X+1;} PPP;})
#define testy()                     int _tests; scanf("%d", &_tests); FOR(_test, 1, _tests)
#define CLEAR(tab)                  memset(tab, 0, sizeof(tab))
#define CONTAIN(el, coll)           (coll.find(el) != coll.end())
#define FOR(i, a, b)                for(int i=a; i<=b; i++)
#define FORD(i, a, b)               for(int i=a; i>=b; i--)
#define MP                          make_pair
#define PB                          push_back
#define deb(X)                      X;

#define M 1000000007
#define INF 1000000007

using namespace std;

long long k, c, s;

int main()
{
    testy()
    {
        scanf("%lld %lld %lld", &k, &c, &s);
        long long ile = 0, mn = 1;
        if(k > s*c)
        {
            printf("Case #%d: IMPOSSIBLE\n", _test);
            continue;
        }
        printf("Case #%d:", _test);
        for(int i=0; i < k; i++)
        {
            ile += mn*i;
            mn *= k;
            if(i == k-1 || i % c == c-1)
            {
                printf(" %lld", ile+1);
                ile = 0;
                mn = 1;
            }
        }
        printf("\n");
    }

    return 0;
}
