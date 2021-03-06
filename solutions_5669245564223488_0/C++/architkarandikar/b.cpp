#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
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
#include <ctime>
#include <limits>
#include <string>
#include <cassert>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define forup(i,a,b) for(int i=a; i<b; ++i)
#define fordn(i,a,b) for(int i=a; i>b; --i)
#define rep(i,a) for(int i=0; i<a; ++i)

#define dforup(i,a,b) for(i=a; i<b; ++i)
#define dfordn(i,a,b) for(i=a; i>b; --i)
#define drep(i,a) for(i=0; i<a; ++i)

#define slenn(s,n) for(n=0; s[n]!=13 and s[n]!=0; ++n);s[n]=0

#define gi(x) scanf("%d",&x)
#define gl(x) cin>>x
#define gd(x) scanf("%lf",&x)
#define gs(x) scanf("%s",x)

#define pis(x) printf("%d ",x)
#define pin(x) printf("%d\n",x)
#define pls(x) cout<<x<<" "
#define pln(x) cout<<x<<"\n"
#define pds(x) printf("%.12f ",x)
#define pdn(x) printf("%.12f\n",x)
#define pnl() printf("\n")

#define fs first
#define sc second

#define pb push_back

const int inv=1000000000;
const int minv=-inv;

const int max_n=10+5;

int T;
int n;
string s[max_n];
string c;
int a[max_n];

int mino[26],maxo[26],numo[26];

int main()
{
	gi(T);

	rep(z,T)
	{
		printf("Case #%d: ",z+1);

		gi(n);

		rep(i,n)
			cin>>s[i];

		rep(i,n)
			a[i]=i;

		int res=0;
		do
		{
			c="";
			rep(i,n)
				c+=s[a[i]];

			fill(mino,mino+26,inv);
			fill(maxo,maxo+26,minv);
			fill(numo,numo+26,0);
			rep(i,(int)c.size())
			{
				int ch=(int(c[i]-'a'));
				mino[ch]=min(mino[ch],i);
				maxo[ch]=max(maxo[ch],i);
				++numo[ch];
			}

			bool valid=true;
			rep(ch,26)
				if(numo[ch]>0 and maxo[ch]-mino[ch]+1!=numo[ch])
				{
					valid=false;
					break;
				}

			res+=valid;

		} while(next_permutation(a,a+n));

		pin(res);
	}
	
	return 0;
}