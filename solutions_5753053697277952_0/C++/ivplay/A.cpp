/*
Problem Name:
Problem Link:
Algorithm:
Solution Author:
Date:
Verdict:
*/

#include <bits/stdc++.h>
using namespace std;
/***************************************************************************************************************************************/
typedef long long int LLI;
typedef unsigned long long int ULLI;
#define MP(X,Y)         make_pair(X,Y)
#define fill(a,v)       memset(a,v,sizeof(a))
#define DEBUG(x)        cout << #x << ": " << x << endl;
#define all(x)          (x).begin(),(x).end()
#define SORT(x)         sort(all(x))
#define VI              vector<int>
#define SI              set<int>
#define VS              vector<string>
#define PB              push_back
#define REV(a)          reverse(all(a))
#define BRPS(n,bit)     bitset<bit>(n)
#define LB(A, x)        (lower_bound(all(A), x) - A.begin())//exactly where it starts
#define UB(A, x)        (upper_bound(all(A), x) - A.begin())
#define UNQ(x)          SORT(x),(x).erase(unique(all(x)),x.end())
#define FOR(i,a,b)      for(int i=(int)(a);i<=(int)(b);i++)
#define foreach(e,x)    for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define DBG(v)          std::copy( v.begin(), v.end(), std::ostream_iterator < typeof( *v.begin() )> ( std::cout, " " ) )
#define INF             0x7FFFFFFF
#define INFL            0x7FFFFFFFFFFFFFFF

typedef pair<int, int>PII;
typedef pair<LLI, LLI>PLL;

template<class T> inline T BIGMOD(T n, T m, T mod)
{
    LLI ans = 1;
    LLI k = n;
    while (m)
    {
        if (m & 1)
        {
            ans *= k;
            if (ans > mod) ans %= mod;
        }
        k *= k;
        if (k > mod) k %= mod;
        m >>= 1;
    }
    return ans;
}
#define eps 1e-11
template<class T> string toString(T n)
{
    ostringstream ost;
    ost << n;
    ost.flush();
    return ost.str();
}
template<class T> string toBinary(T n)
{
    string ret = "";
    while (n)
    {
        if (n % 2 == 1)ret += '1';
        else ret += '0';
        n >>= 1;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
void combination(int n, vector< vector<int> > &ret)
{
    ret.resize(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        ret[i][0] = ret[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
        }
    }
}
int toInt(string s)
{
    int r = 0;
    istringstream sin(s);
    sin >> r;
    return r;
}
LLI toLInt(string s)
{
    LLI r = 0;
    istringstream sin(s);
    sin >> r;
    return r;
}
vector<string> parse(string temp)
{
    vector<string> ans;
    ans.clear();
    string s;
    istringstream iss(temp);
    while (iss >> s)ans.PB(s);
    return ans;
}
template<class T> inline T gcd(T a, T b)
{
	if (a < 0)return gcd(-a, b);
	if (b < 0)return gcd(a, -b);
	while (b) b ^= a ^= b ^= a %= b;
	return a;
}
template<class T> inline T lcm(T a, T b)
{
	if (a < 0)return lcm(-a, b);
	if (b < 0)return lcm(a, -b);
	return a / gcd(a, b) * b;
}
template<class T> inline T power(T b, int p)
{
    if (p < 0)return -1;
    if (b <= 0)return -2;
    if (!p)return 1;
    return b*power(b, p - 1);
}

template<class T> inline int asd(T &ret)
{
    char r;
    bool start = false, neg = false;
    ret = 0;
    bool isaNumber = false;
    while (true)
    {
        r = getchar();
        if (r == EOF)
        {
            return 0;
        }
        if ((r - '0' < 0 || r - '0'>9) && r != '-' && !start)
        {
            continue;
        }
        if ((r - '0' < 0 || r - '0'>9) && r != '-' && start)
        {
            break;
        }
        if (start)ret = (ret<<3)+(ret<<1);//ret *= 10;
        start = true;
        if (r == '-')neg = true;
        else ret += r - '0';
    }
    if (neg)
        ret *= -1;
    return 1;
}

// Yet to Test
template<class T> inline int asd(T &ret1, T &ret2)
{
    asd(ret1);
    asd(ret2);
    return 2;
}
template<class T> inline int asd(T &ret1, T &ret2, T &ret3)
{
    asd(ret1, ret2);
    asd(ret3);
    return 3;
}
template<class T> inline int asd(T &ret1, T &ret2, T &ret3, T &ret4)
{
    asd(ret1, ret2);
    asd(ret3, ret4);
    return 4;
}

template<class T> inline void asdasd(T x,char endWith)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    char buf[21], *p = buf;
    do
    {
        *p++ = '0' + x % 10;
        x /= 10;
    }
    while (x);
    do
    {
        putchar(*--p);
    }
    while (p > buf);
    putchar(endWith);
}

template<class T> inline void asdasd(T x1,T x2,char separateBy,char endWith)
{
    asdasd(x1,separateBy);
    asdasd(x2,endWith);
}

template<class T> inline void asdasd(T x1,T x2,T x3,char separateBy,char endWith)
{
    asdasd(x1,x2,separateBy,separateBy);
    asdasd(x3,endWith);
}
template<class T> inline void asdasd(T x1,T x2,T x3,T x4,char separateBy,char endWith)
{
    asdasd(x1,x2,x3,separateBy,separateBy);
    asdasd(x4,endWith);
}


/*vector IO*/
template < typename value_type >
istream & operator>> (istream & in, vector < value_type > & a)
{
    typedef typename vector < value_type >::iterator iterator;
    if (!a.size())
    {
        size_t n;
        asd(n);
        a.resize(n);
    }
    for (iterator iter = a.begin(); iter != a.end(); ++iter)
        asd(*iter);
    return in;
}

//vector1D OUT
template < typename value_type >
ostream & operator<< (ostream & out, const vector <  value_type > & a)
{
    int sz = a.size();
    FOR(i, 0, sz - 1)asdasd(a[i], i != sz);
    return out;
}

//vector2D OUT
template < typename value_type >
ostream & operator<< (ostream & out, const vector < vector< value_type > > & a)
{
    int sza = a.size();
    int szb = a[0].size();
    FOR(i, 0, sza - 1)
    {
        FOR(j, 0, szb - 1)asdasd(a[i][j], j != sza);
        puts("");
    }
    return out;
}
//set OUT
template < typename value_type >
ostream & operator<< (ostream & out, const set <  value_type > & a)
{
    foreach(e, a)asdasd(*e, e != a.end());
    return out;
}
//MAP OUT
template < typename key_type, typename value_type >
ostream & operator<< (ostream & in, map < key_type, value_type > & a)
{
    foreach(e, a)
    {
        cout << (*e).first << " -> " << (*e).second << endl;
    }
    return in;
}
/*END OF STL IO*/
template < typename key_type, typename value_type >
istream & operator>> (istream & in, pair < key_type, value_type > & p)
{
    in >> p.first >> p.second;
    return in;
}
template < typename key_type, typename value_type >
ostream & operator<< (ostream & out, const pair < key_type, value_type > & p)
{
    out << "(" << p.first << ", " << p.second << ")";
    return out;
}

template<class T> void ModInverseArray(vector<T> & ModInveres,T n, T m)
{
	ModInveres.clear();
	ModInveres.resize(n + 1, 0);
	ModInveres[1] = 1;
	for (long long i = 2; i <= n; i++)
	{
		ModInveres[i] = (-(m / i) * ModInveres[m % i]) % m + m;
	}
}


pair<LLI, pair<LLI, LLI> > extendedEuclid(LLI a, LLI b)
{
    LLI x = 1, y = 0;
    LLI xLast = 0, yLast = 1;
    LLI q, r, m, n;
    while (a != 0)
    {
        q = b / a;
        r = b % a;
        m = xLast - q * x;
        n = yLast - q * y;
        xLast = x, yLast = y;
        x = m, y = n;
        b = a, a = r;
    }
    return make_pair(b, make_pair(xLast, yLast));
}

LLI modInverse(LLI a, LLI m)
{
    return (extendedEuclid(a, m).second.first + m) % m;
}


long long addMod(long long a, long long b, long long m)
{
    return (((((a - m) % m) + ((b - m) % m)) % m) + m) % m;
}

long long multiplyMod(long long a, long long b, long long m)
{
    if (b == 0 || a <= INFL / b)return a * b % m;
    long long result = 0;
    if (a > b) swap(a,b);
    while (a > 0)
    {
        if ((a & 1) != 0)
        {
            result = addMod(result, b, m);
        }
        a >>= 1;
        b -= m - b;
        if (b < 0)b += m;
    }
    return result;
}

#define printCaseSpace(caseNo) printf("Case %d: ",caseNo);
#define printCaseHashSpace(caseNo) printf("Case #%d: ",caseNo);
#define printCaseNewLine(caseNo) printf("Case %d:\n",caseNo);

#define filein(x) freopen(x,"r",stdin)
#define fileout(x) freopen(x,"w",stdout)
#define fst first
#define snd second
#define mod97 1000000007
#define mod99 1000000009
void Void(int n)
{
	return;
}

//istringstream(temp) >> data >> value >> stamp;
//mod1 = 1000000007, mod2 = 1000000009;
//.016-.040-.900-2.48 loops
//78498 primes in range 1000000

/***************************************************************************************************************************************/


struct Z
{
	int amount;
	char ch;
	Z() {}
	Z(int a, char c)
	{
		amount = a;
		ch = c;
	}
};

bool comp(Z A, Z B)
{
	return A.amount > B.amount;
}
#define Mx 30
Z Arr[Mx];
int N;
void PreProcess()
{

}

void Init()
{

}


void Input()
{
	asd(N);
	int p;
	for (int i = 0; i < N; i++)
	{
		asd(p);
		Arr[i].amount = p;
		Arr[i].ch = 'A' + i;
	}
}


vector<string>result;

void Process()
{
	result.clear();
	while (true)
	{
		sort(&Arr[0], &Arr[0] + N, comp);

		if (Arr[0].amount == 0)return;
		if (Arr[0].amount == 1)
		{
			int idx = 0;
			while (idx < N)
			{
				if (Arr[idx].amount == 0)break;
				idx++;
			}
			if ((idx + 1) % 2 == 0)//odd
			{
				result.push_back(toString(Arr[0].ch));
				for (int x = 1; x < idx; x += 2)
				{
					result.push_back(toString(Arr[x].ch) + toString(Arr[x + 1].ch));
				}
			}
			else
			{
				for (int x = 0; x < idx; x += 2)
				{
					result.push_back(toString(Arr[x].ch) + toString(Arr[x + 1].ch));
				}
			}
			return;
		}
		if (Arr[0].amount == 2 && Arr[1].amount==1 && (N==2 || Arr[0].amount==0))
        {
            result.push_back(toString(Arr[0].ch));
            result.push_back(toString(Arr[0].ch) + toString(Arr[1].ch));
            return ;
        }
		else
		{
			result.push_back(toString(Arr[0].ch) + toString(Arr[1].ch));
			Arr[0].amount--;
			Arr[1].amount--;
		}
	}
}



void Solve()
{
	cout << result[0];
	for (int i = 1; i < result.size(); i++)
	{
		cout << " " << result[i];
	}
	cout << endl;
}
void UnitTest()
{


}


int main()
{
    filein("A-small-attempt0.in");
    fileout("A-small-attempt0_out.txt");
	UnitTest();
	PreProcess();
	int numberOfTestCases;
	asd(numberOfTestCases);
	for (int currentCase = 1; currentCase <= numberOfTestCases; currentCase++)
	{
		Init();
		Input();
		Process();
		printCaseHashSpace(currentCase);
		//printCaseSpace(currentCase);
		//printCaseNewLine(currentCase);
		Solve();
	}
	return 0;
}

