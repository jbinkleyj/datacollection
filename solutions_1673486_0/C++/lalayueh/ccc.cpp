#include <cstdio>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <cmath>

using namespace std ;
int main()
{
  freopen( "A-small-practice.in", "r", stdin ) ;
  freopen( "output.txt", "w", stdout ) ;
  int T ;
  cin >> T ;
  for ( int n = 1 ; n <= T ; n++ )
  {
    int a ;
    int b ;
    vector<double> pro ;
    cin >> a >> b ;
    for ( int i = 0 ; i < a ; i++ )
    {
      double d ;
      cin >> d ;
      pro.push_back( d ) ;
    }


    vector<double> typePro ;
    double d = 1 ;
    for ( int i = 0 ; i < a ; i++ )
    {
      d *= pro[i] ;
      typePro.push_back( d ) ;
    }

    reverse( typePro.begin(), typePro.end() ) ;

    vector<double> result ;
    result.push_back( b + 2 ) ;
    for ( int i = 0 ; i < typePro.size() ; i++ )
    {
      double rate = b - a + 1 + 2 * i ;
      //cout << rate << " " << rate + b + 1 << " " << endl ;
      //cout << typePro[i] << " " << 1 - typePro[i] << endl ;
      result.push_back( ( typePro[i] * rate )+ ( ( 1.0 - typePro[i] ) * ( rate + b + 1 ) ) );
    }
    
    double ans = *min_element( result.begin(), result.end() ) ;

    printf( "Case #%d: %.6lf\n", n, ans ) ;
  }
}