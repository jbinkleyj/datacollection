#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;
#define D long double

void solve(){
  D C,F,X;
  cin>>C>>F>>X;
  D ct=0;
  int cf=0;
  D rate = 2.0;
  while(true){
    rate = F * cf + 2.0;
    D direct = X/rate;
    D buy = C/rate + X/(rate+F);
    if(direct <= buy)
      break;
    cf++;
    ct += C/rate;
  }
  D res = ct + X/rate;
  cout<<setprecision(7)<<fixed<<res;
}

int main(){
  int NC;
  cin>>NC;
  for(int i=0;i<NC;i++){
    cout<<"Case #"<<i+1<<": ";
    solve();
    cout<<endl;
  }
  return 0;
}
