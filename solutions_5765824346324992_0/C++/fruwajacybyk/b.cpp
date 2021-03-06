#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(v) (v).begin(),(v).end()

#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debug2(x,y) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y <<endl; } 
#define debug3(x,y,z) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y << ", " << #z << " = " << z <<endl; } 
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define debugt(t,n) {{cerr <<#t <<" = "; FOR(it,0,(n)) cerr <<t[it] <<", "; cerr <<endl; }}

#define make( x) int (x); scanf("%d",&(x));
#define make2( x, y) int (x), (y); scanf("%d%d",&(x),&(y));
#define make3(x, y, z) int (x), (y), (z); scanf("%d%d%d",&(x),&(y),&(z));
#define make4(x, y, z, t) int (x), (y), (z), (t); scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define makev(v,n) VI (v); FOR(i,0,(n)) { make(a); (v).pb(a);} 
#define IOS ios_base::sync_with_stdio(0)
#define HEAP priority_queue

#define read( x) scanf("%d",&(x));
#define read2( x, y) scanf("%d%d",&(x),&(y));
#define read3(x, y, z) scanf("%d%d%d",&(x),&(y),&(z));
#define read4(x, y, z, t) scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define readv(v,n) FOR(i,0,(n)) { make(a); (v).pb(a);}

using namespace std;

#define max_n 100005

int b,n;
VI m;

lint f(lint a){
  lint res = 0;
  FOR(i,0,b){
    res += (a+(m[i]-1))/m[i];
  }
  return res;
}



void solve(){
  m.clear();
  read2(b,n);
  FOR(i,0,b){
    make(a);
    m.pb(a);
  }
  lint l = 0, r = (n+1)*1LL*1e5;
  while(r-l>1){
    lint mid = (l+r)/2;
    if(f(mid)>=n) r = mid;
    else l = mid;
  }

//  debug3(f(r),f(l),n);
//  debug2(r,l);
  // f(r) >= n && f(l)<n
  int zost = n-f(l);
  //debug(zost);
  FOR(i,0,b){
    if(l%m[i]==0) zost--;
    if(zost==0){
      printf("%d\n",i+1);
      return ;
    }
  }
  FOR(i,0,b){
    if(r%m[i]==0){
      printf("%d\n",i+1);
      break;
    }
  }

  
}

int main(){
  make(z);
  FOR(tt,1,z+1){
    printf("Case #%d: ",tt);
    solve();
  }
}
