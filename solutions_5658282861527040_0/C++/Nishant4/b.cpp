#include <iostream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <ctime>
#include <math.h>
#include <algorithm>
#include <iomanip>
#include <assert.h>
#include <map>
#include <queue>
#include <cstring>
#include <set>
#include <stack>
#include <numeric>
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;
#define vi vector<int>
#define vvi vector< vector<int> >
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define pi pair<int,int>
#define pb push_back
#define out(a) cout<<(a)<<endl
#define pout(a) cout<<(a).first<<' '<<(a).second<<endl
#define sz(c) (int)(c).size()
#define fr(n,i) for(int (i)=0;(i)<(n);(i)++)
#define rng(s,e,i) for(int (i)=(s);(i)<=(e);(i)++)
#define all(c) (c).begin(),(c).end()
#define ifBit(n,i) ( ((n) >> (i)) & 1 )
#define mp make_pair
template<typename typ> void vout(vector<typ>& v){for(int vint=0;vint<sz(v);vint++){cout<<(v)[vint];if(vint==sz(v)-1) cout<<endl;else cout<<' ';}}
template<typename typ> void arrout(typ* arr,int l){for(int i=0;i<l;i++){cout<<arr[i];if(i<l-1) cout <<' ';else cout<<endl;}}

#ifdef DEBUG
	#define debug(args...)            {dbg,args; cerr<<endl;}
#else
	#define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
	template<typename T> debugger& operator , (const T& v)
	{
		cerr<<v<<" ";
		return *this;
	}
}dbg;

int main()
{
	int T;
	cin >> T;
	for(int t = 1 ; t <= T ; t++) {
		int a, b, k;
		cin >> a >> b >> k;
		int ans = 0;
		for(int i = 0 ; i < a ; i++) {
			for(int j = 0 ; j < b ; j++) {
				if( (i & j) < k ) {
					ans++;
				}
			}
		}
		printf("Case #%d: %d\n", t, ans);
	}
}