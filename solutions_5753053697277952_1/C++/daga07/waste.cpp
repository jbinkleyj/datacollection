#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
#include <functional>
using namespace std;

#define MP(x, y) make_pair(x, y)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define ll long long
#define ld long double
#define mod 1000000007
#define inf 1061109567LL
#define pii pair< int, int >
#define pll pair< ll, ll >
#define psi pair< string, int >
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	int T = 1;
	while(t--){
		int n;
		cin>>n;
		pair <int,char> a[n];
		int sum=0;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			sum+=x;
			a[i]=MP(x,'A'+i);
		}
		cout<<"Case #"<<T<<": ";
		T++;
		sort(a,a+n);
		if(sum&1){
			cout<<a[n-1].ss<<" ";
			a[n-1].ff--;
		}
		sort(a,a+n);
		while(a[n-1].ff){
			sort(a,a+n);
			cout<<a[n-1].ss<<a[n-2].ss<<" ";
			a[n-1].ff--;
			a[n-2].ff--;
		}
		cout<<endl;
	}
	return 0;
}