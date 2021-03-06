/*
    "وَقُلْ جَاءَ الْحَقُّ وَزَهَقَ الْبَاطِلُ ۚ إِنَّ الْبَاطِلَ كَانَ زَهُوقًا"
    "And say, "Truth has come, and falsehood has departed. Indeed is falsehood, [by nature], ever bound to depart.""
    [Al-Isra, 17:81]
*/

/**

  Author: Zafar Ahmad
  Reg.No: 2008331028
        SUST

**/

#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <complex>
#include <cstddef>
#include <cstdio>
#include <ctime>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <ctype.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#ifdef __GNUC__
typedef long long ll;typedef unsigned long long ull;
#else
typedef __int64 ll;  typedef unsigned __int64 ull;
#endif

#define REP(i,n)    for(i=0;i<n;i++)
#define REV(i,n)    for(i=n;i>=0;i--)
#define FOR(i,x,y)  for(i=x;i<=y;i++)

#define acu(x)      accumulate(x.begin(),x.end(),0)
#define EQ(a,b)     (fabs(a-b)<ERR)
#define maximum(v)  *max_element(all(v))
#define mem(x,with) memset(x,(with),sizeof(x))
#define minimum(v)  *min_element(all(v))
#define MP(X,Y)     make_pair(X,Y)
#define popcount(x) __builtin_popcount(x)
#define Reverse(x)  reverse(x.begin(),x.end())

#define Sort(x)         sort(x.begin(),x.end())
#define StableSort(x)   stable_sort(x.begin(),x.end()) // maintain initial order if two key are similar

#define SZ(x)       (int)x.size()
#define UN(v)       sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())

#define CROSS(a,b,c,d)  ((b.x-a.x)*(d.y-c.y) - (d.x-c.x)*(b.y-a.y))
#define DOT(a,b,c,d)    ((b.x-a.x)*(d.x-c.x) + (b.y-a.y)*(d.y-c.y))

#define two(X)          (1<<(X))
#define twoL(X)         (((ll)(1))<<(X))
#define setBit(mask,i)  (mask|two(i))

#define all(x)      (x).begin(), (x).end()
#define bug(x)      cout<< "->" <<#x<<": "<<x<<endl
#define CLR(x)      x.clear()
#define iter(c)     __typeof((c).begin())
#define MARK(n)     printf("MARK %d  LINE: %d\n",n,__LINE__);
#define tr(c, i)    for (iter(c) i = (c).begin(); i != (c).end(); ++i)

#define PB          push_back
#define PF          push_front
#define fs          first
#define sc          second

#define ERR         1e-9
#define INF         (1<<28)
#define MAXN        1000

#define endl        '\n'
const double PI=acos(-1.0);

typedef pair<int,int>             pii;
typedef pair<double,double>       pdd;
typedef vector<int>               vi;
typedef vector<double>            vd;
typedef vector<ll>                vll;
typedef vector<string>            vs;
typedef vector<vector<int> >      vii;
typedef vector<vector<ll> >       vvll;
typedef vector<vector<double> >   vvd;
typedef vector<pair<int,int> >    vpii;
typedef map<string,int>           msi;
typedef map<int,int>              mii;
typedef map<pair<int,int> ,int>   mpi;
typedef list<int>                 li;
typedef istringstream             iss;

/** Printing **/
template<class T> void out(const vector<T> &a) { cout<<"array: "; for (int i=0;i<SZ(a);i++) cout<<a[i]<<" "; cout<<endl; cout.flush(); }
void binprint(int mask,int n)/**print a number in binary format with n length**/
  {int i;string s="";do{s+=(mask%2+'0');mask/=2;}while(mask);Reverse(s);s=string(max(n-SZ(s),0),'0')+s;for(i=SZ(s)-n;i<SZ(s);i++) printf("%c",s[i]);printf("\n");}
void ASCII_Chart() /**ASCII Chart**/
  {int i,j,k;printf("ASCII Chart:(30-129)\n");FOR(i,30,50){REP(j,5){k=i+j*20;printf("%3d---> '%c'   ",k,k);}printf("\n");}}

/**  MATH   **/
template<class T> inline T gcd(T a,T b) {if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> T Abs(T x) {return x > 0 ? x : -x;}
template<class T> inline T sqr(T x){return x*x;}/** NOTES:sqr **/
template<class T> inline T Mod(T n,T m) {return (n%m+m)%m;} /** For Positive Negative No. **/
int BigMod(ll B,ll P,ll M) /** compute b^p%m **/
  { ll R=1;	while(P>0)	{if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;}	return (int)R;}
ll mulmod(ll a,ll b,ll c) /**calculates (a*b)%c taking into account that a*b might overflow **/
  { ll x = 0,y=a%c; while(b>0){ if(b%2 == 1){x=(x+y)%c;} y=(y*2)%c;b/= 2;}return x%c;}
ll mpow(ll x,ll k) { if( k==0) return 1; ll r=mpow(x,k/2); return k%2?(r*r*x):(r*r); }    // Power Calculation function

/** Genarator **/
vector<string> SubstringGenerate(string str)/** Substring Generator **/
  {int i,j,len;vs store;len=SZ(str);REP(i,len) FOR(j,i,len)store.PB(str.substr(i,j-i+1));return store;}

/** Dicission **/
template<class T> inline bool isPrime(T n){if(n<=1)return false;for (T i=2;i*i<=n;i++) if (n%i==0) return false;return true;}
bool IsVowel(char ch){ch=tolower(ch);if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;return false;}
bool isUpperCase(char c){return c>='A' && c<='Z';}
bool isLowerCase(char c){return c>='a' && c<='z';}
bool isLetter(char c){return c>='A' && c<='Z' || c>='a' && c<='z';}//NOTES:isLetter(
bool isDigit(char c){return c>='0' && c<='9';}//NOTES:isDigit(

/** Conversion **/
double deg2rad(double x){ return (PI*x)/180.0; }
double rad2deg(double x){ return (180.0*x)/PI; }
template<class T> string toString(T n)/** NOTES:int,double is converted to string **/
  {ostringstream oss;oss<<n;oss.flush();return oss.str();}
int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;} /** String to Int **/
ll toLl(string s){ll r=0;istringstream sin(s); sin>>r; return r;}  /** String to Int **/
double toDouble(string s){double r=0;istringstream sin(s);sin>>r;return r;} /**NOTES:toDouble(**/
template<typename T> static void splitstr(const string &s, vector<T> &out)/**String TO vector**/
  { istringstream in(s);out.clear();copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));}

/**For debugging **/
#define debug_array(a,n) for(int iii=0;iii<n;iii++) cerr<<a[iii]<<" "; cerr<<endl;
#define debug_matrix(mat,row,col) for(int iii=0;iii<row;iii++) {for(int jjj=0;jjj<col;jjj++) cerr<<mat[iii][jjj]<<" ";cerr<<endl;}
#define debug(args...) {dbg,args; cerr<<endl;}
struct debugger{template<typename T> debugger& operator , (const T& v){cerr<<v<<"\t"; return *this; }}dbg;

//struct pq{    int cost,node;bool operator<(const pq &b)const{return cost>b.cost;}};// Min Priority Queue
//typedef struct{int x,y;}P;P pvt;

/** max sizes in TC : [16000000] , [4000][4000] , [250][250][250] **/
/** max loop in TC  : n^2 =>> 42000 **/

//int month[]={31,28,31,30,31,30,31,31,30,31,30,31};  //Not Leap Year
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

struct Point{
    int x,y;
    Point(int _x=0,int _y=0)
    {
        x = _x;
        y = _y;
    }
};

bool com(int a,int b)
{
    return a<b;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(false);
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int test, i, j, n, cas = 0;
    string s;
    vs v;

    cin>>test;
    while(test--)
    {
        CLR(v);
        cin>>n;
        REP(i, n)
        {
            cin>>s;
            v.PB(s);
        }

        string ss, str = "", tmp;
        tmp = v[0];
        tmp = " " + tmp;
        FOR(i, 1, SZ(tmp)-1)
            if(tmp[i] != tmp[i-1])
                str += tmp[i];
//        debug(str);

        bool fl = 1;
        for(i=1; i<=SZ(v)-1; i++)
        {
            tmp = " " + v[i];
            ss ="";
            FOR(j, 1, SZ(tmp)-1)
                if(tmp[j] != tmp[j-1])
                    ss += tmp[j];
//            debug(ss);
            if(ss != str)
            {
                fl = 0;
                break;
            }
        }
        printf("Case #%d: ", ++cas);
        if(!fl)
        {
            cout<<"Fegla Won"<<endl;
            continue;
        }

        vii c;
        REP(i, n)
        {
            vi t;
            tmp = v[i];

            int cnt = 1;
            FOR(j, 1, SZ(tmp)-1)
            {
                if(tmp[j] != tmp[j-1])
                {
                    t.PB(cnt);
                    cnt = 1;
                }
                else
                    cnt++;
            }
//            debug(i);
            t.PB(cnt);
//            out(t);
            c.PB(t);
        }

        int ans = 0;
        REP(j, SZ(c[0]))
        {
            vi t;
            REP(i, SZ(c))
            {
                t.PB(c[i][j]);
            }
            Sort(t);
            int med = t[SZ(t)/2];
            REP(i, SZ(t))
                ans += Abs(t[i] - med);
        }
        cout<<ans<<endl;
    }


    return 0;
}











