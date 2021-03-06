/*
 * Bidhan Roy
 * University of Dhaka
 */

using namespace std;
#include <bits/stdc++.h>

#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define sgn(x,y) ((x)+eps<(y)?-1:((x)>eps+(y)?1:0))
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define mem(x,val) memset((x),(val),sizeof(x));
#define rite(x) freopen(x,"w",stdout);
#define read(x) freopen(x,"r",stdin);
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define clr clear()
#define inf (1<<30)
#define ins insert
#define xx first
#define yy second
#define eps 1e-9

typedef long long i64;
typedef unsigned long long ui64;
typedef string st;
typedef vector<int> vi;
typedef vector<st> vs;
typedef map<int,int> mii;
typedef map<st,int> msi;
typedef set<int> si;
typedef set<st> ss;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

#define mx 0

int main(){
    time_t start=clock();
    read("in.txt");
    rite("out.txt");

    ios_base::sync_with_stdio(0);

    int TEST, KAS=0;
    cin>>TEST;
    while( TEST-- ){
        int a,b,k;
        cin>>a>>b>>k;
        //cout<<a<<" "<<b<<" "<<k<<endl;
        int ans=0;
        for(int i=0; i<a; i++) for(int j=0; j<b; j++) {
            //cout<<i<<" "<<j<<endl;
            if( (i&j)<k ) ans++;//, cout<<"ok"<<endl;
        }
        cout<<"Case #"<<++KAS<<": ";
        cout<<ans<<endl;
        //return 0;
    }

    cerr << " Program has run "<< ( clock()-start ) / 1000 << " s " << endl;
    return 0;
}
