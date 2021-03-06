#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
#define FZ(n) memset((n),0,sizeof(n))
#define FMO(n) memset((n),-1,sizeof(n))
#define F first
#define S second
#define PB push_back
#define ALL(x) begin(x),end(x)
#define SZ(x) ((int)(x).size())
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
template<typename A, typename B>
ostream& operator <<(ostream &s, const pair<A,B> &p) {
  return s<<"("<<p.first<<","<<p.second<<")";
}
template<typename T>
ostream& operator <<(ostream &s, const vector<T> &c) {
  s<<"[ ";
  for (auto it : c) s << it << " ";
  s<<"]";
  return s;
}
// Let's Fight!

const int MAXN = 2525;

int N;
int arr[MAXN][MAXN];
int cnt[MAXN];

int main() {
  IOS;

  int T;
  cin>>T;
  for(int t=1; t<=T; t++)
  {
    cin>>N;
    for(int i=0; i<2*N-1; i++)
      for(int j=0; j<N; j++)
        cin>>arr[i][j];

    for(int i=0; i<MAXN; i++)
      cnt[i] = 0;
    for(int i=0; i<2*N-1; i++)
      for(int j=0; j<N; j++)
        cnt[arr[i][j]]++;

    vector<int> vans;
    for(int i=1; i<MAXN; i++)
      if(cnt[i] % 2)
        vans.PB(i);

    cout<<"Case #"<<t<<":";
    for(int i=0; i<N; i++)
      cout<<" "<<vans[i];
    cout<<endl;
  }
  return 0;
}
