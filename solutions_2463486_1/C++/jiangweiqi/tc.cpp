#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <string.h>

using namespace std; 

#define ALL(X)       (X).begin(),(X).end()
#define SIZE(X)      ((int)(X).size())
#define FORI(x,a,b)  for(x=(a);x<=(b);x++)
#define FORD(x,a,b)  for(x=(a);x>=(b);x--)
#define min(a,b)     ((a)<(b)?(a):(b))
#define max(a,b)     ((a)<(b)?(b):(a))
#define MEM(X,with)  memset((X),(with),sizeof(X))
#define Contains(X,item)    ((X).find(item)!=(X).end())
#define Contains_n(X,item)    (find((X).begin(),(X).end(),(item))!=(X).end())
#define rep(i,m,n) for((i)=m;(i)<(int)(n);(i)++)
#define PQ priority_queue
#define LB lower_bound
#define UB upper_bound
#define NXETSORT next_permutation
#define PREVSORT prev_permutation
#define ONLYONE(A,B,n) unique_copy(A,A+n,B)
#define IT iterator
#define N 100005
#define EPS 1e-6
#define Mod 1000000007
//bool prime[N];

const int inf =(1<<30)-1;
const long long linf = (1ll<<62)-1;
const int dirx[]={-1,0,0,1,-1,-1,1,1}, diry[]={0,-1,1,0,-1,1,-1,1};
const double ERR = 1e-11, PI=(2*acos(0.0));


typedef long long ll;
typedef unsigned long long ull;
typedef stringstream   SS;
typedef vector<string> VS;
typedef vector<double> VD;
typedef vector<ll>     VL;
typedef vector<int>    VI;

template<class T> bool cmpmin(T a, T b){return a<b;}
template<class T> bool cmpmax(T a, T b){return a>b;}
template<class T> inline T ABS(T a) {return ((a<0)?(-a):(a));}
template<class T> T GCD(T a,T b) {return ((!b)?(a):GCD(b,a%b));}
template<class T> T fastPow(T Base,T Power) {T Result=1; while(Power>0){if(Power&((T)1))Result*=Base; Power>>=1; Base*=Base;} return Result;}
//template<class T> T fastModPow(T Base,T Power,T Mod) {T Result=1;while(Power>0){if(Power&((T)1))Result=(Result*Base)%Mod; Power>>=1; Base=(Base*Base)%Mod;} return (Result%Mod);}
inline int compDouble(double x,double y) {double d=x-y; if(d-ERR>0.0) return 1; else if(d+ERR<0.0) return -1; else return 0;}
inline void file(){freopen("C-large-1.in","r",stdin);freopen("C.txt","w",stdout);}
//void prim(){prime[0]=1;prime[1]=1;int i;long long j;for(i=2;i<N;i++){if(prime[i]==0){for(j=i,j=j*i;j<N;j+=i){prime[j]=1;}}}}

ll Eular(ll n){int i;ll ret=n;for(i=2;i*i<=n;++i){if(n%i==0){ret-=ret/i;while(n%i==0)n/=i;if(n==1)break;}}if(n!=1)ret-=ret/n;return ret;}

/*int cross(int a, int b, int c, int d){
return a * d - b * c;
}*/

/*
bool test(ll a){
	int arr[14],len=0,i;
	while(a){
		arr[len++] = a%10;
		a /= 10;
	}
	for(i=0;i<len/2;i++){
		if(arr[i]!=arr[len-1-i])return 1;
	}
	return 0;
}
int main(){
	file();
	int a,b=10000000;
	for(a=1;a<=b;a++){
		ll c = (ll)a*(ll)a;
		if(test((ll)a) || test(c))continue;
		printf("%d,",a);
	}
	return 0;
}*/

int arr[40]={1,2,3,11,22,101,111,121,202,212,
1001,1111,2002,10001,10101,10201,11011,11111,11211,20002,
20102,100001,101101,110011,111111,200002,1000001,1001001,1002001,1010101,
1011101,1012101,1100011,1101011,1102011,1110111,1111111,2000002,2001002};
int main(){
	file();
	int t,cas,i;
	scanf("%d",&t);
	for(cas=1;cas<=t;cas++){
		ll a,b,c;
		int ans = 0;
		cin>>a>>b;
		for(i=0;i<40;i++){
			if(arr[i]==0)continue;
			c = ll(arr[i]) *(arr[i]);
			if(c>=a && c<=b){
				ans++;
			}
		}
		printf("Case #%d: %d\n",cas,ans);
	}
	return 0;
}
