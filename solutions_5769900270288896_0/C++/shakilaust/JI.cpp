//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define ff first
#define ss second
#define re return
#define QI queue<int>
#define SI stack<int>
#define SZ(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define ms(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))
#define II ( { int a ; read(a) ; a; } )
#define LL ( { Long a ; read(a) ; a; } )
#define DD ({double a; scanf("%lf", &a); a;})

double const EPS=3e-8;
using namespace std;

#define FI freopen ("input.txt", "r", stdin)
#define FO freopen ("2.txt", "w", stdout)

typedef long long Long;
typedef long long int64;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef set<int> si;
typedef vector<Long>vl;
typedef pair<int,int>pii;
typedef pair<string,int>psi;
typedef pair<Long,Long>pll;
typedef pair<double,double>pdd;
typedef vector<pii> vpii;

// For loop

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }

//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */
const int NX = 10000 + 10 ;
int ddx[] = {0,1};
int ddy[] = {1,0};
string inp[NX];
int r , c , tot ;
bool ok( int x , int y )
{
    if( x < 0 || x >= r || y < 0 || y >= c ) return 0 ;
    return 1 ;
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
   FI ;
   FO ;
   int cs , t = II ;
   for ( cs = 1 ; cs <= t ; cs++ )
   {
       r = II , c = II , tot = II ;
       if( r > c ) swap( r , c );
       int mul = r * c ;
       int ans = 0 ;
       if( (mul + 1)/2 >= tot ) ans = 0 ;
       else if( r == 1 || c == 1 )
       {
           if( tot == mul )
           {
               ans = tot + 1 ;           }
           else

           ans = tot ;
       }
       else if( r == 2 )
       {
           if( tot == mul ) ans = ( tot + 1 ) ;
           else {
           tot -= ( mul + 1)/2 ;
           ans = tot * 2 ;
           }
       }
       else if ( r == 3)
       {
           if( c == 3 )
           {
               if( tot == 6 ) ans = 3 ;
               else if( tot == 7 ) ans = 6 ;
               else if ( tot == 8 ) ans = 8 ;
               else ans = 11 ;

           }
           else if ( c == 4 )
           {
               if( tot == 7 ) ans = 3 ;
               else if( tot == 8 ) ans = 6 ;
               else if( tot == 9 ) ans = 8 ;
               else if( tot == 10 ) ans = 10 ;
               else if( tot == 11 ) ans = 13 ;
               else ans = 14 ;
           }
           else
           {
               if( tot == 9 ) ans = 3 ;
               else if( tot == 10 ) ans = 6 ;
               else if( tot == 11 ) ans = 8 ;
               else if( tot == 12 ) ans = 10 ;
               else if( tot == 13 ) ans = 13 ;
               else if( tot == 14 ) ans = 16 ;
               else ans = 20 ;
           }

       }
       else
       {
               if( tot == 9 ) ans = 3 ;
               else if( tot == 10 ) ans = 6 ;
               else if( tot == 11 ) ans = 8 ;
               else if( tot == 12 ) ans = 10 ;
               else if( tot == 13 ) ans = 12 ;
               else if( tot == 14 ) ans = 14;
               else if ( tot == 15 ) ans = 18 ;
               else ans = 22 ;
       }
       printf("Case #%d: %d\n",cs,ans);

   }
    return 0;
}
